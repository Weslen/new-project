
#ifndef EepromFileSystem_h
#define EepromFileSystem_h


#include "my_stdint.h"




#define EepromFile_Error_FilesMax20	1
#define EepromFile_CreateOK			2
#define EepromFile_HaveThisFile		3
#define EepromFile_HaveNotThisFile		4
#define EepromFile_OpenOk				5
#define EepromFile_SEEK_CUR			6
#define EepromFile_SEEK_END			7
#define EepromFile_SEEK_SET			8
#define EepromFile_Error_SeekFlag		9
#define EepromFile_SeekOK				10
#define EepromFile_Error_SeekOutofArea	11
#define EepromFile_Error_NoContext		12
#define EepromFile_ReadOk				13
#define EepromFile_WriteOk				14
#define EepromFile_DeleteOk			15
#define EepromFile_Error_AreaNotEnough	16
#define EepromFile_OperateNormal		17
#define EepromFile_FileNameToLong		18




struct EepromFile{
	unsigned char Name[12];
	unsigned short Size;
	unsigned short StartPage;

	unsigned short CurPos;	//这个不需要存在eeprom中
};

typedef struct EepromFile *pEFILE;
typedef struct EepromFile EFILE;



unsigned char EepromFile_readPage(unsigned char *buff,unsigned int page);
unsigned char EepromFile_WritePage(unsigned char *buff,unsigned int page);



void EepromFile_FileSystemFormat(void);
unsigned char EepromFile_Create(unsigned char Name[12],pEFILE efp);
unsigned char EepromFile_Open(unsigned char Name[12],pEFILE efp);
unsigned char EepromFile_Seek(pEFILE efp,int size,unsigned char flag);
unsigned char EepromFile_read(unsigned char *buffer, unsigned int size,  pEFILE efp);
unsigned char EepromFile_Write(unsigned char *buffer, unsigned int size,  pEFILE efp);




unsigned char EepromFile_CheckFileExist(unsigned char *name);
unsigned char EepromFile_WriteData(const unsigned char *buff,unsigned int wLen,const unsigned char *filename);
unsigned char EepromFile_ReadData(unsigned char *buff,unsigned int rLen,const unsigned char *filename);
unsigned char EepromFile_Delete(unsigned char *Name);
void EepromFile_GetFileName(unsigned char *Name,unsigned char number);


#endif





