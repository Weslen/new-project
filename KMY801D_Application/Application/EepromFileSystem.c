
//这个文件系统的思想是这样的:

//第0 页存放超级文件头信息，现在暂时只用了一个字节
//第0 页第一个字节(最最开始的那个字节)，代表总文件数

//第1到第5页总共5*64byte=320byte  用在文件属性头信息存放的
//地方，一个EFILE属性头占用16字节(见EFILE 结构体)所以总共
//可以有320byte/16=20个文件，一页为64byte，所以一页可以存
//放4个文件属性头信息，第一页存放4个文件属性头第2页
//也存放4个文件属性头，以此类推。然后文件头结构体的
//StartPage 记录文件的开始页. 我只要以这个文件开始页的信
//息，再根据后面的页与页之间的关联关系就可以找到一
//个文件的所有信息。然后文件头的Size 记录文件的大小，
//Size 为short 型，所以文件最大为64k

//第6页到第20 页记录页与页之间的关联关系。总共15*64byte
//=960byte, 所以可以表示480页每两个字节代表一个页的关系:
//定义以下特殊关系字节: 特殊字节范围(0x0000----0x0014)
//0x0000--->代表空(即未使用页)     0x0001--->代表这是尾页
//0x000f--->代表坏页  0x0015 或以上代表下一页为0x0015页
//例如: 如果第6  页的第1和第2字节为0x00,0x00，则说明第21页
//为未使用页，如果第6  页的第3 和第4 字节为0x00,0x01，则
//说明第22页为一个文件的尾页，如果第6  页的第5 和第6字
//节为0x00,0x0f，则说明第23页为一个坏页，如果第6  页的第
//7 和第8 字节为0x00,0x64，则说明第24页为一个文件的中间页
//紧接着下一页为第100页。



#define EepromFile_PageIdle		0x0000
#define EepromFile_PageTail		0x0001
#define EepromFile_PageBroken		0x000f
#define EepromFile_PageMaxKey		0x0014

#define EepromFile_MaxFiles			20


#define EEPROM_TOTALPAGE			500		//此处定义512页不行，因为15x32=480+21=501,所有此处最大定义501
#define EEPROM_PAGESIZE				64		//eeprom 页大小


#include "EepromFileSystem.h"


#include "kmy_EEPROMDrv.h"
#include <string.h>
#include <stdio.h>
#include "FoodOrder.h"


#define MAXEEPROMFILELONGTH		11 //eeprom 文件名最大字节数


const unsigned char InitKong[64] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char Buff0xff[64] =
{
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};



void EepromFile_DeleteAllPageArea (pEFILE efp);
unsigned int EepromFile_GetPageRelationAreaTwoByte (unsigned int RelationTwoByte);
unsigned char EepromFile_CheckWhetherHaveThisFile (unsigned char Name[12], unsigned char *filenumber, unsigned char *TheFirstIdlePosition);

//buff:要读出数据存放的buff，M24128 每页64byte，M2416,M2432,M2464的32byte
//page: 读第几页(128*1024/8)/64=256页，总共256页所以这里page最大EEPROM_TOTALPAGE。
unsigned char EepromFile_readPage (unsigned char *buff, unsigned int page)
{
	return kmy_EepromReadSequent (page * 64, buff, 64);
}
//buff:要读出数据存放的buff，M24128 每页64byte，16,32,64的32byte
//page: 读第几页(128*1024/8)/64=256页，总共256页所以这里page最大EEPROM_TOTALPAGE。
unsigned char EepromFile_WritePage (unsigned char *buff, unsigned int page)
{
	return kmy_EepromWritePage (page * 64, buff, 64);
}

//efp: efile 指针，
//filenumber: 文件的次序号(0x00--0x13)
void EepromFile_GetFileStruct (pEFILE efp, unsigned char filenumber)
{
	unsigned char buff[64];
	unsigned char bytes;
	unsigned char page;

	bytes = filenumber % 4; 	//确定文件所在的页的字节数
	bytes *= 16;
	page = 1;	//确定文件所在的页数
	page += filenumber / 4;

	EepromFile_readPage (buff, page);
	strcpy ( (s8 *) efp->Name, (sc8*) &buff[bytes]);
	efp->Size = (buff[bytes + 12] << 8) + buff[bytes + 12 + 1];
	efp->StartPage = (buff[bytes + 12 + 2] << 8) + buff[bytes + 12 + 1 + 2];
}

//返回总文件数量
unsigned char EepromFile_GetTotalFiles (void)
{
	unsigned char len;

	kmy_EepromReadSequent (0x0000, &len, 1);

	return len;
}

//写总文件数量
void EepromFile_SetTotalFiles (unsigned char number)
{
	kmy_EepromWriteByte (0x0000, number);
}


//返回空闲区域字节数
unsigned int EepromFile_GetIdleAreaSize (void)
{
	unsigned char buff[64];
	unsigned char i, j;
	unsigned int page = 0;
	unsigned int pagecnt = 0;

	for (i = 6; i <= 20; i++)
	{
		EepromFile_readPage (buff, i);	//读一个页关联区

		for (j = 0; j < 64; j += 2)
		{
			if (buff[j] == 0x00 && buff[j + 1] == 0x00)
			{
				page++;	//空闲页++
			}

			pagecnt++;	//总共查询的页++

			if (pagecnt >= EEPROM_TOTALPAGE - 21)
			{
				return page * 64;
			}
		}
	}

	return 0;
}


//Name[12]: 检查的文件名
//*filenumber: 如果成功找到这个文件，则文件的次序号码存在*filenumber
//例如1: *filenumber==0 则，名字为Name 的这个文件的属性头在
//第1  页的第0字节到第15 字节。
//例如2: *filenumber==4 则，名字为Name 的这个文件的属性头在
//第2 页的第0字节到第15 字节。
//*TheFirstIdlePosition: 第一个空闲文件头属性的位置,如果这个值为0xff，则没有空闲位置了
//返回: 有此文件返回EepromFile_HaveThisFile
//没有这个文件返回EepromFile_HaveNotThisFile
unsigned char EepromFile_CheckWhetherHaveThisFile (unsigned char Name[12], unsigned char *filenumber, unsigned char *TheFirstIdlePosition)
{
	unsigned char i;
	unsigned char buff[64];
	unsigned char *p;
	unsigned char flag = 0;

	//Name[11]=0;

	for (i = 1; i <= 5; i++)
	{
		EepromFile_readPage (buff, i);
		p = buff;

		if (*p == 0)
		{
			if (flag == 0)
			{
				if (TheFirstIdlePosition != NULL) *TheFirstIdlePosition = (i - 1) * 4 + 0;

				flag = 1;
			}
		}
		else
		{
			if (strcmp ( (sc8*) p, (sc8*) Name) == 0)
			{
				if (filenumber != NULL) *filenumber = (i - 1) * 4 + 0;

				return EepromFile_HaveThisFile;
			}
		}

		p += sizeof (struct EepromFile) - 2;

		if (*p == 0)
		{
			if (flag == 0)
			{
				if (TheFirstIdlePosition != NULL) *TheFirstIdlePosition = (i - 1) * 4 + 1;

				flag = 1;
			}
		}
		else
		{
			if (strcmp ( (sc8*) p, (sc8*) Name) == 0)
			{
				if (filenumber != NULL) *filenumber = (i - 1) * 4 + 1;

				return EepromFile_HaveThisFile;
			}
		}

		p += sizeof (struct EepromFile) - 2;

		if (*p == 0)
		{
			if (flag == 0)
			{
				if (TheFirstIdlePosition != NULL) *TheFirstIdlePosition = (i - 1) * 4 + 2;

				flag = 2;
			}
		}
		else
		{
			if (strcmp ( (sc8*) p, (sc8*) Name) == 0)
			{
				if (filenumber != NULL) *filenumber = (i - 1) * 4 + 2;

				return EepromFile_HaveThisFile;
			}
		}

		p += sizeof (struct EepromFile) - 2;

		if (*p == 0)
		{
			if (flag == 0)
			{
				if (TheFirstIdlePosition != NULL) *TheFirstIdlePosition = (i - 1) * 4 + 3;

				flag = 1;
			}
		}
		else
		{
			if (strcmp ( (sc8*) p, (sc8*) Name) == 0)
			{
				if (filenumber != NULL) *filenumber = (i - 1) * 4 + 3;

				return EepromFile_HaveThisFile;
			}
		}
	}

	if (flag == 0)
	{
		if (TheFirstIdlePosition != NULL) *TheFirstIdlePosition = 0xff;
	}

	return EepromFile_HaveNotThisFile;
}

static unsigned char EepromFile_SaveEfpAttibute (pEFILE efp)
{
	unsigned char filenumber;
	unsigned char TheFirstIdlePosition;
	unsigned char retval;
	unsigned char page;
	unsigned char buff[64];

	retval = EepromFile_CheckWhetherHaveThisFile (efp->Name, &filenumber, &TheFirstIdlePosition);

	if (retval == EepromFile_HaveNotThisFile)
	{
		printf ("[EepromFile error]=EepromFile_SaveEfpAttibute\r\n");
		return retval;
	}

	if (filenumber >= 20)
	{
		printf ("[EepromFile error]=EepromFile_SaveEfpAttibute\r\n");
		return EepromFile_Error_FilesMax20;
	}

	page = 1;
	page += filenumber / 4;	//得到文件属性头所在的页

	filenumber %= 4;		//得到文件属性头所在页的字节偏移数
	filenumber *= 16;

	EepromFile_readPage (buff, page);	//读此文件属性头的页

	memcpy ( (s8*) (&buff[filenumber]), (sc8*) (efp->Name), 12);	//写文件属性头到buff  所在的位置字节
	buff[filenumber + 12] = (unsigned char) (efp->Size >> 8);
	buff[filenumber + 12 + 1] = (unsigned char) (efp->Size & 0x00ff);
	buff[filenumber + 12 + 2] = (unsigned char) (efp->StartPage >> 8);
	buff[filenumber + 12 + 2 + 1] = (unsigned char) (efp->StartPage & 0x00ff);

	EepromFile_WritePage (buff, page);	//重写文件属性头的页

	return EepromFile_OperateNormal;
}



static void EepromFile_TotalFileAdd1 (void)
{
	unsigned char total;

	total = EepromFile_GetTotalFiles();

	if (total < EepromFile_MaxFiles) total++;

	EepromFile_SetTotalFiles (total);
}



static unsigned int EepromFile_GetPhysicalPage (unsigned int startpage, unsigned int offset)
{
	for (; offset != 0; offset--)
	{
		startpage = EepromFile_GetPageRelationAreaTwoByte (startpage);
	}

	return startpage;
}


static void EepromFile_readFileCurrentPage (unsigned char *buffer, pEFILE efp)
{
	unsigned int pages;

	//求出当前要读的页，相对于开始页的偏移
	pages = efp->CurPos / 64;	//

	//因为pages 不连续，所以要定位物理的page页
	pages = EepromFile_GetPhysicalPage (efp->StartPage, pages);

	//读物理的页到buffer
	EepromFile_readPage (buffer, pages);
}

//检查page 页是不是坏页
unsigned char EepromFile_checkThisPageWhetherOk (unsigned int page)
{
	unsigned char i, Buff[EEPROM_PAGESIZE];

	EepromFile_WritePage ((unsigned char*)Buff0xff, page);
	EepromFile_readPage (Buff, page);

	for (i = 0; i < sizeof (Buff); i++)
	{
		if (Buff[i] != Buff0xff[i]) return 1;
	}

	return 0;
}


//设置页标志
void EepromFile_SetPageArea (unsigned int thispage, unsigned int nextpage)
{
	unsigned int pages;
	unsigned int bytes;
	unsigned char buff[64];

	if (thispage <= EepromFile_PageMaxKey)
	{
		printf ("[EepromFile error]=SetPageArea\r\n");
	}

	pages = thispage - 0x0015;
	bytes = pages * 2;
	pages = 6 + bytes / 64;	//得到thispage 所在页关联区的页
	bytes %= 64;			//得到thispage 所在页关联区页的字节偏移

	EepromFile_readPage (buff, pages);

	buff[bytes] = (unsigned char) (nextpage >> 8);
	buff[bytes + 1] = (unsigned char) (nextpage & 0x00ff);

	EepromFile_WritePage (buff, pages);
}

//返回一个空闲的页
//例如1: 返回0x0015  则0x0015页为空闲，
//注意不可能返回小于0x0015的页
//例如2: 返回0xffff  则没有空闲页
unsigned int EepromFile_GetAIdlePage (void)
{
	unsigned char buff[64];
	unsigned char i, j;
	unsigned int page = 0;
	unsigned int pagecnt = 0;

	for (i = 6; i <= 20; i++)
	{
		EepromFile_readPage (buff, i);	//读一个页关联区

		for (j = 0; j < 64; j += 2)
		{
			if (buff[j] == 0x00 && buff[j + 1] == 0x00)
			{
				page = 0x0015 + (i - 6) * 32 + j / 2;

				if (EepromFile_checkThisPageWhetherOk (page) == 1)  	//检查此页是不是坏页
				{
					//如果是坏页则置坏页标志到页关联区域
					EepromFile_SetPageArea (page, EepromFile_PageBroken);
				}
				else
				{
					return page;
				}
			}

			pagecnt++;

			if (pagecnt > EEPROM_TOTALPAGE - 21) return 0xffff;
		}
	}

	return 0xffff;
}




unsigned int EepromFile_GetPageRelationAreaTwoByte (unsigned int RelationTwoByte)
{
	//为了提高读速度，加这两个静态变量
	static unsigned char buff[64];
	static unsigned int ReadedPage = 0xffff;

	unsigned int page;		//文件关联字节的起始位置
	unsigned int nextpage;

	RelationTwoByte -= 0x0015;	//求得与第6  页的相对位置
	RelationTwoByte *= 2;			//求得与第6  页的相对字节位置

	page = 6;
	page += RelationTwoByte / 64;	//得到RelationTwoByte 所在的页
	RelationTwoByte %= 64;		//得到RelationTwoByte 所在页的字节偏移

	if (ReadedPage != page)  	//为了提高读速度，加此语句
	{
		EepromFile_readPage (buff, page);
		ReadedPage = page;
	}

	nextpage = (buff[RelationTwoByte] << 8) + buff[RelationTwoByte + 1];

	return nextpage;
}


//RelationTwoByte: 要查找页的关联字节
//返回RelationTwoByte 位置的关联字节
//得到文件关联的字节
//例如1: RelationTwoByte==0x0015，则返回(第6  页的第1字节<<8)+第6  页的第2字节
//例如2: RelationTwoByte==0x0016，则返回(第6  页的第3字节<<8)+第6  页的第4字节
//例如3: RelationTwoByte==0x0035，则返回(第7  页的第1字节<<8)+第6  页的第2字节
//例如4: RelationTwoByte==0x0036，则返回(第7  页的第3字节<<8)+第6  页的第4字节
//例如5: RelationTwoByte==0x0055，则返回(第9  页的第1字节<<8)+第6  页的第2字节
unsigned int EepromFile_GetPageRelationAreaTwoByte_AndDelete (unsigned int RelationTwoByte)
{
	unsigned int page;		//文件关联字节的起始位置
	unsigned char buff[64];
	unsigned int nextpage;

	RelationTwoByte -= 0x0015;	//求得与第6  页的相对位置
	RelationTwoByte *= 2;			//求得与第6  页的相对字节位置

	page = 6;
	page += RelationTwoByte / 64;	//得到RelationTwoByte 所在的页
	RelationTwoByte %= 64;		//得到RelationTwoByte 所在页的字节偏移

	EepromFile_readPage (buff, page);

	nextpage = (buff[RelationTwoByte] << 8) + buff[RelationTwoByte + 1];

	//Delete 关联字节
	buff[RelationTwoByte] = 0x00;
	buff[RelationTwoByte + 1] = 0x00;
	EepromFile_WritePage (buff, page);

	return nextpage;
}

void EepromFile_DeleteAllPageArea (pEFILE efp)
{
	unsigned int RelationTwoByte;

	RelationTwoByte = efp->StartPage;

	if (RelationTwoByte <= EepromFile_PageMaxKey)
	{
		return;
	}

	//清除文件中间页字节标志
	while (RelationTwoByte > EepromFile_PageMaxKey)
	{
		RelationTwoByte = EepromFile_GetPageRelationAreaTwoByte_AndDelete (RelationTwoByte);
	}

	//清除尾字节标志
	EepromFile_GetPageRelationAreaTwoByte_AndDelete (RelationTwoByte);
}

unsigned char EepromFile_DeleteEfpAttibute (pEFILE efp)
{
	unsigned char filenumber;
	unsigned char page;
	unsigned char retval;
	unsigned char buff[64];

	retval = EepromFile_CheckWhetherHaveThisFile (efp->Name, &filenumber, &page);

	if (retval == EepromFile_HaveNotThisFile) return retval;

	if (filenumber >= 20)
	{
		printf ("[EepromFile error]=DeleteEfpAttibute\r\n");
	}

	page = 1;
	page += filenumber / 4;	//得到文件属性头所在的页

	filenumber %= 4;		//得到文件属性头所在页的字节偏移数
	filenumber *= 16;

	EepromFile_readPage (buff, page);	//读此文件属性头的页

	memset (&buff[filenumber], 0, 16);		//清除文件属性头所在的buff位置字节

	EepromFile_WritePage (buff, page);	//重写文件属性头的页

	return EepromFile_OperateNormal;
}

void EepromFile_TotalFilePlus1 (void)
{
	unsigned char total;

	total = EepromFile_GetTotalFiles();

	if (total) total--;

	EepromFile_SetTotalFiles (total);
}

void __EepromFile_Delete (pEFILE efp)
{
	EepromFile_DeleteAllPageArea (efp);
	EepromFile_DeleteEfpAttibute (efp);
	EepromFile_TotalFilePlus1();
}




//-------------------------------------以下为API-------------------------------------------

void EepromFile_FileSystemFormat (void)
{
	unsigned char i;

	for (i = 0; i < 21; i++)//init eeprom fist 20 pages, every page size is 64 bytes
	{
		EepromFile_WritePage ((unsigned char*)InitKong, i);
	}
	
	InitOrder();
}

unsigned char EepromFile_Create (unsigned char Name[12], pEFILE efp)
{
	unsigned char buff[64];
	unsigned char i;
	unsigned char page;

	if (strlen ( (sc8*) Name) > MAXEEPROMFILELONGTH) return EepromFile_FileNameToLong;

	i = EepromFile_GetTotalFiles();

	if (i >= EepromFile_MaxFiles)  	//page 0: 第一个字节为文件总数，总数不能大于20个
	{
		return EepromFile_Error_FilesMax20;
	}

	if (EepromFile_CheckWhetherHaveThisFile (Name, &i, &page) == EepromFile_HaveThisFile)
	{
		return EepromFile_HaveThisFile;
	}

	if (page == 0xff)
	{
		return EepromFile_Error_FilesMax20;
	}

	// 1到5页存文件信息
	i = page % 4;	//确定文件所在的页的位置数(0--3)
	page /= 4;	//确定文件所在的页数
	page += 1;	//文件属性头从1页开始所以加1
	EepromFile_readPage (buff, page);
	//Name[11]=0;
	strcpy ( (s8*) &buff[i * 16], (sc8*) Name);	//把文件名写到buff
	buff[i * 16 + 12] = 0;	//把大小写到buff
	buff[i * 16 + 12 + 1] = 0;
	buff[i * 16 + 12 + 2] = 0;	//把起始页写到buff
	buff[i * 16 + 12 + 2 + 1] = 0;
	EepromFile_WritePage (buff, page);

	strcpy ( (s8*) (efp->Name), (sc8*) Name);	//把文件名写到返回的指针
	memset ( (s8*) (&efp->Size), 0, 2);	//把大小写到返回的指针
	memset ( (s8*) (&efp->StartPage), 0, 2);	//把起始页写到返回的指针

	EepromFile_TotalFileAdd1();

	return EepromFile_CreateOK;
}

unsigned char EepromFile_Open (unsigned char Name[12], pEFILE efp)
{
	unsigned char i;
	unsigned char TheFirstIdlePosition;

	if (strlen ( (sc8*) Name) > MAXEEPROMFILELONGTH) return EepromFile_FileNameToLong;

	if (EepromFile_CheckWhetherHaveThisFile (Name, &i, &TheFirstIdlePosition) == EepromFile_HaveNotThisFile)
	{
		return EepromFile_HaveNotThisFile;
	}

	efp->CurPos = 0;

	EepromFile_GetFileStruct (efp, i);
	return EepromFile_OpenOk;
}

unsigned char EepromFile_Seek (pEFILE efp, int size, unsigned char flag)
{
	int temp;

	if (flag == EepromFile_SEEK_CUR)
	{
		temp = efp->CurPos + size;

		if (temp > efp->Size || temp < 0)
		{
			return EepromFile_Error_SeekOutofArea;
		}
		else
		{
			efp->CurPos = temp;
		}
	}
	else if (flag == EepromFile_SEEK_SET)
	{
		temp = size;

		if (temp > efp->Size || temp < 0)
		{
			return EepromFile_Error_SeekOutofArea;
		}
		else
		{
			efp->CurPos = temp;
		}
	}
	else if (flag == EepromFile_SEEK_END)
	{
		temp = efp->Size + size;

		if (temp > efp->Size || temp < 0)
		{
			return EepromFile_Error_SeekOutofArea;
		}
		else
		{
			efp->CurPos = temp;
		}
	}
	else
	{
		return EepromFile_Error_SeekFlag;
	}

	return EepromFile_SeekOK;
}

unsigned char EepromFile_read (unsigned char *buffer, unsigned int size,  pEFILE efp)
{
	//unsigned int pages;
	unsigned char buff[64];
	unsigned char temp;
	unsigned char pos;

	//如果文件的起始页为0，则文件为只创建了而已，没有内容
	if (efp->StartPage == 0x0000)
	{
		return EepromFile_Error_NoContext;
	}

	//如果要读的大小大于当前位置到文件尾部的总大小，
	//只拷贝当前位置到文件尾部的总大小，
	if (size > efp->Size - efp->CurPos) size = efp->Size - efp->CurPos;

	//pages=efp->CurPos/64;	//拷贝第一页
	EepromFile_readFileCurrentPage (buff, efp);	//拷贝当前位置的整个页到buff
	pos = efp->CurPos % 64;		//得到要拷贝第一页buff的位置
	temp = 64 - pos;			//得到要拷贝的字节数

	if (temp > size) temp = size;	//如果第一页拷贝的大小> 实际要拷贝的字节数，则只拷贝要拷贝的字节数

	memcpy (buffer, &buff[pos], temp);
	buffer += temp;		//对拷贝到的目的buff  进行偏移
	size -= temp;			//总共要拷的字节-已拷的字节
	efp->CurPos += temp;	//对当前位置偏移

	while (size >= 64)  	//拷贝中间的页
	{
		EepromFile_readFileCurrentPage (buff, efp);
		memcpy (buffer, buff, 64);
		efp->CurPos += 64;
		size -= 64;
		buffer += 64;
	}

	EepromFile_readFileCurrentPage (buff, efp);	//拷贝最后的字节页
	memcpy (buffer, buff, size);
	efp->CurPos += size;

	return EepromFile_ReadOk;
}

//
unsigned char EepromFile_Write (unsigned char *buffer, unsigned int size,  pEFILE efp)
{
	unsigned int pages;
	unsigned int temp;

	if (EepromFile_GetIdleAreaSize() + efp->Size < size)
	{
		return EepromFile_Error_AreaNotEnough;
	}

	//先删除这个文件的所有占用的文件关联区域
	EepromFile_DeleteAllPageArea (efp);

	pages = EepromFile_GetAIdlePage();	//先把第一页的位置写到文件属性头
	efp->StartPage = pages;
	efp->Size = size;
	EepromFile_SaveEfpAttibute (efp);

	//先把开始的那页的页关联区域置为尾页
	//以避免下面EepromFile_GetAIdlePage 中的函数
	//又读到此页
	EepromFile_SetPageArea (pages, EepromFile_PageTail);

	while (size >= 64)
	{
		EepromFile_WritePage (buffer, pages);
		buffer += 64;
		size -= 64;

		if (size == 0)
		{
			EepromFile_SetPageArea (pages, EepromFile_PageTail);
			break;
		}
		else
		{
			temp = EepromFile_GetAIdlePage();
			EepromFile_SetPageArea (pages, temp);
			EepromFile_SetPageArea (temp, EepromFile_PageTail);
			pages = temp;	//下一个空闲页赋值给pages ，上面写新的页
		}
	}

	if (size != 0)
	{
		//EepromFile_WritePage(buffer,pages);
		kmy_EepromWritePage (pages * 64, buffer, size);
		EepromFile_SetPageArea (pages, EepromFile_PageTail);
	}

	return EepromFile_WriteOk;
}


//	删除成功返回EepromFile_DeleteOk
//	没有这个文件返回EepromFile_HaveNotThisFile
unsigned char EepromFile_Delete (unsigned char *Name)
{
	unsigned char filenumber;
	unsigned char TheFirstIdlePosition;
	unsigned char retval;
	struct EepromFile efp;

	retval = EepromFile_CheckWhetherHaveThisFile (Name, &filenumber, &TheFirstIdlePosition);

	if (retval == EepromFile_HaveNotThisFile) return retval;

	EepromFile_Open (Name, &efp);

	__EepromFile_Delete (&efp);

	return EepromFile_DeleteOk;
}



//-----------------------------------------进一步封装API------------------------------------------
//filename: 文件名
//返回值:
//有此文件返回EepromFile_HaveThisFile
//没有这个文件返回EepromFile_HaveNotThisFile
//文件名字符长度>11byte,返回EepromFile_FileNameToLong
unsigned char EepromFile_CheckFileExist (unsigned char *name)
{
	if (strlen ( (sc8*) name) > MAXEEPROMFILELONGTH) return EepromFile_FileNameToLong;

	return EepromFile_CheckWhetherHaveThisFile (name, NULL, NULL);
}


//buff: 要写的源buff
//wLen: 要写的长度
//filename: 文件名
//写成功返回EepromFile_WriteOk，
//不成功返回的宏定义有以下:
//EepromFile_FileNameToLong---->代表文件名太长
//EepromFile_Error_FilesMax20---->代表已经到了最多存20个文件的上限
//EepromFile_Error_AreaNotEnough---->代表没有足够的空间存放当前的文件
unsigned char EepromFile_WriteData (const unsigned char *buff, unsigned int wLen, const unsigned char *filename)
{
	unsigned int retval;
	struct EepromFile efp;

	retval = EepromFile_Open ((unsigned char*)filename, &efp);

	if (retval == EepromFile_FileNameToLong) return retval;

	if (retval == EepromFile_HaveNotThisFile)
	{
		{
			printf ("ERROR-->EepromFile_WriteData-->EepromFile_Open\r\n");
		}

		retval = EepromFile_Create ((unsigned char*)filename, &efp);

		if (retval != EepromFile_CreateOK)
		{
			{
				printf ("ERROR-->EepromFile_WriteData-->EepromFile_Create\r\n");
			}
			return retval;
		}
	}

	//ReadEepromPage(NULL);
	retval = EepromFile_Write ((unsigned char*)buff, wLen, &efp);

	if (retval != EepromFile_WriteOk)
	{
		{
			printf ("ERROR-->EepromFile_WriteData-->EepromFile_Write\r\n");
		}

	}

	return retval;
}


//参数buff :为要读出文件的缓冲区
//参数rLen:为要读出文件长度
//参数filename: 文件名
//读成功返回EepromFile_ReadOk，
//不成功返回的宏定义有以下:
//EepromFile_FileNameToLong---->代表文件名太长
//EepromFile_HaveNotThisFile---->代表文件不存在
//EepromFile_Error_NoContext---->代表文件没有内容
unsigned char EepromFile_ReadData (unsigned char *buff, unsigned int rLen, const unsigned char *filename)
{
	unsigned char retval;
	struct EepromFile efp;

	retval = EepromFile_Open ((unsigned char*)filename, &efp);

	if (retval != EepromFile_OpenOk)
	{
		{
			printf ("ERROR-->CheckTamper-->EepromFile_Open\r\n");
		}
		return retval;
	}

	retval = EepromFile_read (buff, rLen, &efp);

	if (retval != EepromFile_ReadOk)
	{
		{
			printf ("ERROR-->CheckTamper-->EepromFile_read\r\n");
		}
	}

	return retval;
}


void EepromFile_GetFileName (unsigned char *Name, unsigned char number)
{
	unsigned char i;
	unsigned char buff[64];
	unsigned char *p;

	*Name = 0;

	for (i = 1; i <= 5; i++)
	{
		EepromFile_readPage (buff, i);

		p = buff;

		if (*p != 0)
		{
			if (number) number--;
			else
			{
				strcpy ( (char*) Name, (char*) p);
				return;
			}
		}

		p += sizeof (struct EepromFile) - 2;

		if (*p != 0)
		{
			if (number) number--;
			else
			{
				strcpy ( (char*) Name, (char*) p);
				return;
			}
		}

		p += sizeof (struct EepromFile) - 2;

		if (*p != 0)
		{
			if (number) number--;
			else
			{
				strcpy ( (char*) Name, (char*) p);
				return;
			}
		}

		p += sizeof (struct EepromFile) - 2;

		if (*p != 0)
		{
			if (number) number--;
			else
			{
				strcpy ( (char*) Name, (char*) p);
				return;
			}
		}
	}
}

