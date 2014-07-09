
#include "setting.h"
#include "kmy_Time.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "key.h"
#include "lcd.h"
#include "main.h"
#include "global_extern_variable.h"
#include "gprs.h"
#include "MenuOperate.h"
#include "SelfTest.h"
//#include "des.h"
#include "mypure_library.h"
#include "ShuRuFa.h"
#include "kmy_EEPROMDrv.h"
#include "EepromFileSystem.h"
#include "kmy_Misc.h"
#include "Version.h"
#include "kmy_USART1Drv.h"
#include "FoodOrder.h"

const unsigned char efile_Config[] = {"Config"};
const unsigned char Configfile_des3key[25] = {"106QDabcdefg106QD1234567"};
unsigned char dataledflag;


unsigned char LightPercent[4];				//light percent
unsigned char ServerIpPortBuf[28];			//ip 地址220.162.237.128,65167
unsigned char UpgradeFlag[1+1];
unsigned char Domain[50 + 1];	//20131129 change from 24->50		
unsigned char ApnApn[50 + 1];
unsigned char ApnUsername[21 + 1];
unsigned char ApnPassword[21 + 1];
unsigned char EnterAdvancedSetPassWord[22];	//高级设置密码
unsigned char SIM_PIN[5];					//PIN name
unsigned char beepKG[2];
unsigned char ScreenOffTimeout[3];			//PIN name

unsigned char TerminalID[17];				//终端id
unsigned char TerminalPassword[17];			//终端密码
unsigned char VersionURL[100+1];
unsigned char UpgradeURL[100+1];

//--------------------the parameter below are for canada orders project----------
unsigned char RequestWebURL[150+1];
unsigned char CallbackURL[150+1];
unsigned char RejectReason[200+1];
unsigned char ResID[10+1];
unsigned char LoginWebUsername[20+1];
unsigned char LoginWebPassword[20+1];

unsigned char BeepDuration[2+1];
unsigned char AcceptTimeMode[1+1];
unsigned char CheckOrderInterval[3+1];
unsigned char GPRSOpenTime[5+1];
unsigned char GPRSCloseTime[5+1];
unsigned char PrintNewLineFlag[3+1];
unsigned char PrintDateFormat[1+1];
unsigned char PrintTimeFormat[1+1];
unsigned char PrintPageHeader[30+1];
unsigned char PrintPageFooter[30+1];

unsigned char PrintReceiptCount[1+1];
unsigned char AutoAcceptOrder[1+1];
unsigned char AcceptTimeOptions[100+1];
unsigned char Version[50+1];
unsigned char AutoReboot12Hours[2];
unsigned char AutoPrintString[25+1];

// ---- total 35 array 1225
// 0x540+1225=2569=0xA09
// 3K=0xC00

const unsigned char locallanguage[sizeof (Language)] = {OTHER_LANGUAGE, 0};


struct storeFile XStor[STORESIZE+1] =  	//the parameters are store in the eeprom address 0x540
{
	{beepKG, "1"},
	{LightPercent, "44"},
	{Language, locallanguage},
	{ServerIpPortBuf, "117.53.163.74,80"},	// 117.53.163.74,80
	{UpgradeFlag,"0"},
	{Domain, "www.eatnow.com.au"},
	{VersionURL, "http://www.eatnow.com.au/gprs/gprsVersion.html?"},
	{UpgradeURL, "http://static.eatnow.com.au/kmy/prod/"},
	{ScreenOffTimeout, "60"},
	{EnterAdvancedSetPassWord, "000000"},
	
	{TerminalID, "12345678"},
	{TerminalPassword, "123456"},
	{RequestWebURL, "http://www.eatnow.com.au/gprs/orderRequest.html?"},
	{CallbackURL, "http://www.eatnow.com.au/gprs/orderCallback.html?"},
	{RejectReason, "TOO BUSY;FOOD UNAVAILABLE;Delivery Unavailable;Restaurant Closed;"},
	{BeepDuration, "1"},
	{AcceptTimeMode, "1"},	
	{CheckOrderInterval, "30"},
	{GPRSOpenTime, "00:01"},
	{GPRSCloseTime, "23:59"},
	
	{PrintNewLineFlag, ""},
	{PrintDateFormat, ""},
	{PrintTimeFormat, ""},
	{PrintPageHeader, "EatNow Order"},	
	{PrintPageFooter, ""},
	{PrintReceiptCount, ""},
	{AutoAcceptOrder, "1"},	
	{AcceptTimeOptions,  "Time Requested;10 Minutes;20 Minutes;30 Minutes;45 Minutes;60 Minutes;75 Minutes;90 Minutes;"},
	{Version, (const unsigned char*)VersionString},
	{AutoReboot12Hours, "1"},
	{NULL, NULL} 	//后面不用的务必赋成&SFNULL，否则会引起segmentationfault
};

//  below for test
/*

struct storeFile XStor[STORESIZE+1] =  	//the parameters are store in the eeprom address 0x540
{
	{beepKG, "1"},
	{LightPercent, "44"},
	{Language, locallanguage},
	{ServerIpPortBuf, "117.53.163.74,80"},	// 117.53.163.74,80
	{UpgradeFlag,"0"},
	{Domain, ""},
	{VersionURL, "http://117.53.163.74/gprs/gprsVersion.html?"},
	{UpgradeURL, "http://static.eatnow.com.au/kmy/test/"},
	{ScreenOffTimeout, "60"},
	{EnterAdvancedSetPassWord, "000000"},
	
	{TerminalID, "12345678"},
	{TerminalPassword, "123456"},
	{RequestWebURL, "http://117.53.163.74/gprs/orderRequest.html?"},
	{CallbackURL, "http://117.53.163.74/gprs/orderCallback.html?"},
	{RejectReason, "TOO BUSY;FOOD UNAVAILABLE;UNABLE TO DELIVER;"},
	{BeepDuration, "1"},
	{AcceptTimeMode, "1"},	
	{CheckOrderInterval, "30"},
	{GPRSOpenTime, "00:01"},
	{GPRSCloseTime, "23:59"},
	
	{PrintNewLineFlag, ""},
	{PrintDateFormat, ""},
	{PrintTimeFormat, ""},
	{PrintPageHeader, "EatNow Order"},	
	{PrintPageFooter, ""},
	{PrintReceiptCount, ""},
	{AutoAcceptOrder, "1"},	
	{AcceptTimeOptions,  "Time Requested;10 Minutes;20 Minutes;30 Minutes;45 Minutes;60 Minutes;75 Minutes;90 Minutes;"},
	{Version, (const unsigned char*)VersionString},
	{AutoReboot12Hours, "1"},
	{NULL, NULL} 	//后面不用的务必赋成&SFNULL，否则会引起segmentationfault
};
*/

struct storeFile LocalStore[LocalNum]=
{
	{ApnApn, "internet"},//internet
	{ApnUsername, ""},	
	{ApnPassword, ""},
	{ResID, "1845"},
	{LoginWebUsername, "print"},	
	{LoginWebPassword, "magic"},	
	{SIM_PIN, ""},
	{AutoPrintString,"As requested"},
};

void StoreLocalSettings(void)
{
	unsigned char buff[100]={0};
	unsigned char i;

	for (i = 0; i < LocalNum; i++)
	{
		strcat ( (s8*) buff, (sc8*) (LocalStore[i].Viarable) );
		strcat ( (s8*) buff, "\t");
	}
	kmy_EepromWrite(0x9001,buff,strlen((char*)buff)+1);
	
}

void InitLocalSettings(void)
{
	unsigned char buff[100]={0};
	unsigned char i;
	unsigned char *p;
	char *pt;

	memset(buff,0,sizeof(buff));
	kmy_EepromReadByte(0x9000,&i);
	if(i!=0x55)
	{
		for (i = 0; i < LocalNum; i++)
		{
			strcpy ( (s8*)(LocalStore[i].Viarable),(s8*)(LocalStore[i].initVal) );
			strcat ( (s8*) buff, (sc8*) (LocalStore[i].initVal) );			
			strcat ( (s8*) buff, "\t");
		}
		
		kmy_EepromWrite(0x9001,buff,strlen((char*)buff)+1);
		kmy_EepromWriteByte(0x9000,0x55);
	}
	else
	{
		kmy_EepromReadSequent(0x9001,buff,sizeof(buff));
		
		pt = (char*)buff;
		for (i = 0; i < LocalNum; i++)
		{
			pt=strstr(pt,"\t");
			if(pt==NULL)
			{
				printf("LocalStore[%d] lack one segment\r\n",i);
				kmy_EepromWriteByte(0x9000,0x00);
				SystemReset();
			}
			pt++;
		}
		if(strstr(pt,"\t")!=NULL)	
		{
			printf("LocalStore[%d] add segment\r\n",i);
			memset(buff,0,sizeof(buff));
			kmy_EepromWriteByte(0x9000,0x00);
			SystemReset();

		}// if XStor[i] add one segment
		
		p = buff;
		for (i = 0; i < LocalNum; i++)
		{
			my_strcpy_EncounterHexEnd ( (LocalStore[i].Viarable), p, 30, '\t');
			my_MovePointToHex (&p, &buff[sizeof (buff) - 1], '\t');
			p++;
			printf (" local%d=%s\r\n", i, LocalStore[i].Viarable);
		}
		
	}
}



unsigned char StorageVariable (void)
{
	unsigned char buff[1500]={0};
	unsigned char i;
	unsigned char retval;
	struct EepromFile efp;

	buff[0] = 0;

	for (i = 0; i < STORESIZE; i++)
	{
		strcat ( (s8*) buff, (sc8*) (XStor[i].Viarable) );
		strcat ( (s8*) buff, "\t");
	}

	retval = EepromFile_Open ((unsigned char*)efile_Config, &efp);

	if (retval != EepromFile_OpenOk)
	{
		{
			printf ("[StorageVariable error]=EepromFile_Open\r\n");
		}
		return 0;
	}

	retval = EepromFile_Write (buff, strlen ( (sc8*) buff) + 1, &efp);

	if (retval != EepromFile_WriteOk)
	{
		{
			printf ("[StorageVariable error]=EepromFile_Write\r\n");
		}
		return 0;
	}

	return 1;
}


unsigned char RestoreConfigFile (void)
{
	unsigned char buff[1500]={0};
	unsigned char i;
	unsigned char retval;
	//struct EepromFile efp;

	buff[0] = 0;

	for (i = 0; i < STORESIZE; i++)
	{
		printf ("%d==%s\r\n", i, XStor[i].initVal);
		if(i!=8) // do not recover the 8 intem 8=APN
		{
			strcpy ( (s8*) (XStor[i].Viarable), (sc8*) (XStor[i].initVal) );
		}
		strcat ( (s8*) buff, (sc8*) (XStor[i].initVal) );
		strcat ( (s8*) buff, "\t");
	}

	retval = EepromFile_Delete ((unsigned char*)efile_Config);

	if (retval == EepromFile_HaveNotThisFile)
	{
		{
			printf ("EepromFile_HaveNot Config file\r\n");
		}
		//return 0;
	}

	retval = EepromFile_WriteData (buff, strlen ( (sc8*) buff) + 1, efile_Config);

	if (retval != EepromFile_WriteOk)
	{
		{
			printf ("[RestoreConfigFile error]=EepromFile_Write\r\n");
		}
		return 0;
	}

	return 1;
}

unsigned char RestoreGlobalVariable (void)
{
	unsigned char buff[1500];
	unsigned char i;
	unsigned char retval;
	unsigned char *p;
	char *pt;

	
	struct EepromFile efp;

	retval = EepromFile_Open ((unsigned char*)efile_Config, &efp);

	if (retval != EepromFile_OpenOk)
	{
		{
			printf ("[RestoreGlobalVariable error]=EepromFile_Open\r\n");
		}
		return 0;
	}

	retval = EepromFile_read (buff, sizeof (buff) - 1, &efp);

	if (retval != EepromFile_ReadOk)
	{
		{
			printf ("[RestoreGlobalVariable error]=EepromFile_read\r\n");
		}
		return 0;
	}
	
	pt =(char*) buff;
	for (i = 0; i < STORESIZE; i++)// if XStor[i] lack one segment
	{
		pt=strstr(pt,"\t");
		if(pt==NULL)
		{
			printf("XStor[%d] lack one segment\r\n",i);
			return 2;
		}
		pt++;
	}
	if(strstr(pt,"\t")!=NULL)	
	{
		printf("XStor[%d] lack add segment\r\n",i);
		memset(buff,0,sizeof(buff));
		kmy_EepromWrite(0x540,buff,sizeof(buff));
		return 2;

	}// if XStor[i] add one segment
	
	p = buff;
	for (i = 0; i < STORESIZE; i++)
	{
		my_strcpy_EncounterHexEnd ( (XStor[i].Viarable), p, 300, '\t');// 200
		my_MovePointToHex (&p, &buff[sizeof (buff) - 1], '\t');
		p++;
		printf ("%d=%s\r\n", i, XStor[i].Viarable);	
	}
	if(strcmp((char*)Version,(char*)VersionString)!=0)
	{
		return 2;
	}

	return 1;
}


static char ContrastSet (char *msg)	//2.screen constract setting
{
#if 0
	return (abeyant() );
#else
	signed int NewPercent	= atoi ( (sc8*) LightPercent);
	signed int 	CurCursor	= 39 + ( (NewPercent - 56) / 4 * 3);
	signed int  OldCursor   = CurCursor;
	unsigned char Buf[50] = {'\0'};
	unsigned char keyval;

	clear_lcd();
	text_out_to_row_x_Language2 (0, 28, "【亮度设定】", "Contrast Set");

	text_out (17, 25, "-");
	text_out (105, 25, "+");
	draw_rect (26, 25, 77, 10, mode_OnlyEdge);
	draw_line (26, 30, 26 + 75 + 1, 30, 1);

	fill_rect (26 + 1 + CurCursor, 26, 3, 8, mode_Reverse);	//3*8

	memset (Buf, '\0', sizeof (Buf) );
	sprintf ( (s8*) Buf, "%d", NewPercent);
	strcat ( (s8*) Buf, "%");
	text_out (58, 48, Buf);

	while (1)
	{
		keyval = GetKeyValue();

		if (keyval == KEY_NONE) continue ;

		KeyEventPost();

		switch (keyval)
		{
			case KEY_UP:
				if (NewPercent + 4 <= 100)
				{
					NewPercent += 4;
					CurCursor += 3;
				}

				break;

			case KEY_DOWN:
				if (NewPercent - 4 >= 4)
				{
					NewPercent -= 4;
					CurCursor -= 3;
				}

				break;

			case KEY_Enter:
				sprintf ( (s8*) Buf, "%d", NewPercent);
				Buf[3] = 0;
				strcpy ( (s8*) LightPercent, (sc8*) Buf);

				if (!StorageVariable() )
				{
					DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
					WaitkeyAndAutoExit (10);
				}

				return KEY_Enter;

			case KEY_ReturnPrevious:
				NewPercent = atoi ( (sc8*) LightPercent);
				set_contrast (NewPercent);
				return KEY_ReturnPrevious;

			case KEY_ReturnInitInterface:
			case KEY_WaitTimeout:
				NewPercent = atoi ( (sc8*) LightPercent);
				set_contrast (NewPercent);
				return KEY_ReturnInitInterface;

			default:
				break;
		}

		memset (Buf, '\0', sizeof (Buf) );
		text_out (58, 48, "    ");
		sprintf ( (s8*) Buf, "%d", NewPercent);
		strcat ( (s8*) Buf, "%");
		text_out (58, 48, Buf);
		KeyIsResponse();

		if (OldCursor != CurCursor)
		{
			fill_rect (26 + 1 + OldCursor, 26, 3, 8, mode_Reverse);	//3*8
			fill_rect (26 + 1 + CurCursor, 26, 3, 8, mode_Reverse);	//3*8
			OldCursor = CurCursor;
		}

#ifdef DEBUG_PRINTF
		printf ("NewPercent=%d\n", NewPercent);
#endif

		set_contrast (NewPercent);		// 24---52
	}

#endif
}


static char Polish_Display_Keytone_Close (char *msg)
{
	memset (beepKG, 0, sizeof (beepKG) );
	beepKG[0] = '0';

	if (!StorageVariable() )
	{
		DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
		WaitkeyAndAutoExit (10);
	}

	return 0;
}

static char Polish_Display_Keytone_Open (char *msg)
{
	memset (beepKG, 0, sizeof (beepKG) );
	beepKG[0] = '1';

	if (!StorageVariable() )
	{
		DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
		WaitkeyAndAutoExit (10);
	}

	return 0;
}

static char BasicKeyTone (char *msg)	//key tone setting
{
	 static unsigned char ToneClose1[20] = {"1.关闭   "};
	 static unsigned char ToneClose2[20] = {"1.Close  "};
	 static unsigned char ToneOpen1[20] = {"2.打开   "};
	 static unsigned char ToneOpen2[20] = {"2.Open   "};

	static struct MenuFuc_Language2 Menu[2] =
	{
		{ToneClose1, ToneClose2, Polish_Display_Keytone_Close},
		{ToneOpen1, ToneOpen2, Polish_Display_Keytone_Open}
	};
	struct MenuOperate_Language2 MenuOp =
	{
		(struct MenuFuc_Language2*) Menu,
		2,
		0,
		0,
		0,
		MaxRowOneScr,
		1,
		0,
		0
	};

	my_strdel (ToneClose1, '*');
	my_strdel (ToneClose2, '*');
	my_strdel (ToneOpen1, '*');
	my_strdel (ToneOpen2, '*');

	if (beepKG[0] == '0')
	{
		strcat ( (s8*) ToneClose1, "*");
		strcat ( (s8*) ToneClose2, "*");
	}
	else
	{
		strcat ( (s8*) ToneOpen1, "*");
		strcat ( (s8*) ToneOpen2, "*");
	}

	while (1)
	{
		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (msg);

			if (MenuOp.FucRetVal == KEY_WaitTimeout || MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				CurProc = CurProc_Return;
				return MenuOp.FucRetVal;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
				my_strdel (ToneClose1, '*');
				my_strdel (ToneClose2, '*');
				my_strdel (ToneOpen1, '*');
				my_strdel (ToneOpen2, '*');

				if (beepKG[0] == '0')
				{
					strcat ( (s8*) ToneClose1, "*");
					strcat ( (s8*) ToneClose2, "*");
				}
				else
				{
					strcat ( (s8*) ToneOpen1, "*");
					strcat ( (s8*) ToneOpen2, "*");
				}
			}
		}
		else
		{
			return MenuOp.RetVal;
		}
	}
}


static char PowerOffScreenTime (char *msg)	//key tone setting
{
	unsigned char temp[20];
	unsigned char retval;
	PasswordInputArgument arg;

	clear_lcd();
	DrawTitle_to_row_Language2 (0, "【屏保时间设置】", "Timeout set");

	if (Language[0] == LOCAL_LANGUAGE)
	{
		strcpy ( (s8*) temp, "当前屏保时间:");
	}
	else
	{
		strcpy ( (s8*) temp, "Current time");
	}

	strcat ( (s8*) temp, (sc8*) ScreenOffTimeout);
	DrawTitle_to_row_Language2 (1, temp, temp);

	PassWordArgDeInit (&arg, temp, 2);
	arg.DiplayRow = 2;
	arg.LocalTitle = NULL;
	arg.xingflag = 0;
	arg.clearlcdflag = 0;
	retval = PassWordInput_MiddledDisplay (&arg);

	if (retval == KEY_Enter)
	{
		strcpy ( (s8*) ScreenOffTimeout, (sc8*) temp);
		retval = atoi ( (sc8*) temp);

		if (retval == 0) strcpy ( (s8*) ScreenOffTimeout, "30");

		if (!StorageVariable() )
		{
			DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
		}
		else
		{
			DrawTitle_to_row_Language2 (3, "更改成功!", "change success!");
		}

		retval = WaitkeyAndAutoExit (10);
	}

	return retval;
}


static char LanguageSet_English (char *msg)
{
	memset (Language, 0, sizeof (Language) );
	Language[0] = OTHER_LANGUAGE;

	if (!StorageVariable() )
	{
		DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
		WaitkeyAndAutoExit (10);
	}

	return 0;
}
static char LanguageSet_Chinese (char *msg)
{
	memset (Language, 0, sizeof (Language) );
	Language[0] = LOCAL_LANGUAGE;

	if (!StorageVariable() )
	{
		DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
		WaitkeyAndAutoExit (10);
	}

	return 0;
}
static char LanguageSet (char *msg)	//key tone setting
{
	static unsigned char ToneClose1[20] = {"1.中文   "};
	static unsigned char ToneClose2[20] = {"1.Chinese  "};
	static unsigned char ToneOpen1[20] = {"2.英文   "};
	static unsigned char ToneOpen2[20] = {"2.English  "};

	static struct MenuFuc_Language2 Menu[2] =
	{
		{ToneClose1, ToneClose2, LanguageSet_Chinese},
		{ToneOpen1, ToneOpen2, LanguageSet_English}
	};
	struct MenuOperate_Language2 MenuOp =
	{
		(struct MenuFuc_Language2*) Menu,
		2,
		0,
		0,
		0,
		MaxRowOneScr,
		1,
		0,
		0
	};

	my_strdel (ToneClose1, '*');
	my_strdel (ToneClose2, '*');
	my_strdel (ToneOpen1, '*');
	my_strdel (ToneOpen2, '*');

	if (Language[0] == LOCAL_LANGUAGE)
	{
		strcat ( (s8*) ToneClose1, "*");
		strcat ( (s8*) ToneClose2, "*");
	}
	else
	{
		strcat ( (s8*) ToneOpen1, "*");
		strcat ( (s8*) ToneOpen2, "*");
	}

	while (1)
	{
		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (msg);

			if (MenuOp.FucRetVal == KEY_WaitTimeout || MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				CurProc = CurProc_Return;
				return MenuOp.FucRetVal;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
				my_strdel (ToneClose1, '*');
				my_strdel (ToneClose2, '*');
				my_strdel (ToneOpen1, '*');
				my_strdel (ToneOpen2, '*');

				if (Language[0] == LOCAL_LANGUAGE)
				{
					strcat ( (s8*) ToneClose1, "*");
					strcat ( (s8*) ToneClose2, "*");
				}
				else
				{
					strcat ( (s8*) ToneOpen1, "*");
					strcat ( (s8*) ToneOpen2, "*");
				}
			}
		}
		else
		{
			return MenuOp.RetVal;
		}
	}
}




static char DisplayCID (char *msg)
{
#if 0
	return (abeyant() );
#else
	unsigned char CmdBuff[50];
	unsigned char temp[50];

	//ReadDatasFromtty(fd_ttyS1,CmdBuff,sizeof(CmdBuff),0,50000);

	clear_lcd();
	DrawTitle_to_row_Language2 (0, "SIM卡CID码", "SIM cid");

	GetCCID (temp);

	if (strlen ( (sc8*) temp) > 16)
	{
		memset (CmdBuff, 0, 30);
		memcpy (CmdBuff, temp, 16);
		DrawTitle_to_row (1, CmdBuff);
		DrawTitle_to_row (2, temp + 16);
	}
	else
	{
		DrawTitle_to_row (1, temp);
	}

	WaitkeyAndAutoExit (10);
	return 0;
#endif
}

static char Display_IMEI (char *msg)
{
	unsigned char buff[50];

	clear_lcd();
	DrawTitle_to_row (0, "IMEI");

	GetIMEI (buff);

	DrawTitle_to_row (2, buff);
	return (WaitkeyAndAutoExit (10) );
}

static char Display_ChipId (char *msg)
{
	unsigned char buff[50];

	clear_lcd();
	DrawTitle_to_row_Language2 (0, "芯片id", "Chip ID");

	kmy_MiscGetChipUniqueId (buff);

	DrawTitle_to_row (3, &buff[12]);
	buff[12] = 0;
	DrawTitle_to_row (2, &buff[0]);
	return (WaitkeyAndAutoExit (30) );
}


static char Display_RandomNumber (char *msg)
{
	unsigned char buff[21];

	clear_lcd();
	DrawTitle_to_row_Language2 (0, "随机数", "Random num");

	kmy_MiscGetRandomNumber (buff, sizeof (buff) - 1);

	DrawTitle_to_row (2, buff);
	return (WaitkeyAndAutoExit (30) );
}

static char Display_KMY_LibVersion (char *msg)
{
	unsigned char buff[21];

	clear_lcd();
	DrawTitle_to_row_Language2 (0, "KMY库版本", "KMY LibVersion");

	kmy_MiscGetLibraryVersion (buff);

	DrawTitle_to_row (2, buff);
	return (WaitkeyAndAutoExit (30) );
}

static char BasicApnSetApn (char *msg)
{
	unsigned char buff[sizeof (ApnApn)];
	unsigned char retval;
	char temp_ONOFF=0;
	
	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) ApnApn);

	retval = GetString_abcABC123PYWuBi_Language2 ("输入Apn", "Input Apn", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=1;//close check order

	clear_lcd();
	strcpy ( (s8*) ApnApn, (sc8*) buff);
	
	StoreLocalSettings();
	DrawTitle_to_row (2, "setting,pleas wait...");
	retval = set_apn();

	if (retval != TCP_OK)
	{
		DrawTitle_to_row (3, "Set APN error");
	}
	else
	{
		DrawTitle_to_row (3, "Set APN success");
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order

	return (WaitkeyAndAutoExit (10) );
}
static char BasicApnSetUsername (char *msg)
{
	unsigned char buff[sizeof (ApnUsername)];
	unsigned char retval;
	char temp_ONOFF=0;
	
	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) ApnUsername);

	retval = GetString_abcABC123PYWuBi_Language2 ("输入Apn用户名", "Input ApnUsername", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) ApnUsername, (sc8*) buff);

	StoreLocalSettings();

	
	DrawTitle_to_row (2, "setting,pleas wait...");
	retval = set_apn();

	if (retval != TCP_OK)
	{
		DrawTitle_to_row (3, "Set APN error");
	}
	else
	{
		DrawTitle_to_row (3, "Set APN success");
	}
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return (WaitkeyAndAutoExit (10) );
}
static char BasicApnSetPassword (char *msg)
{
	unsigned char buff[sizeof (ApnPassword)];
	unsigned char retval;	
	char temp_ONOFF=0;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) ApnPassword);

	retval = GetString_abcABC123PYWuBi_Language2 ("I输入Apn密码", "Input ApnPassword", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) ApnPassword, (sc8*) buff);

	StoreLocalSettings();

	
	DrawTitle_to_row (2, "setting,pleas wait...");
	retval = set_apn();

	if (retval != TCP_OK)
	{
		DrawTitle_to_row (3, "Set APN error");
	}
	else
	{
		DrawTitle_to_row (3, "Set APN success");
	}
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return (WaitkeyAndAutoExit (10) );
}

char BasicApnSet (char *msg)
{
	const static struct MenuFuc_Language2 Menu[3] =
	{
		{"1.APN", "1.APN", BasicApnSetApn},
		{"2.APN用户名", "2.User", BasicApnSetUsername},
		{"3.APN密码", "3.Password", BasicApnSetPassword},
	};

	struct MenuOperate_Language2 MenuOp =
	{
		(struct MenuFuc_Language2*) Menu,
		3,
		0,
		0,
		0,
		MaxRowOneScr,
		1,
		0,
		0
	};

	while (1)
	{
		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (msg);

			if (MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				return KEY_ReturnInitInterface;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
			}
		}
		else
		{
			return MenuOp.RetVal;
		}
	}
}





char ReadSomeMessage (char *msg)
{
	const static struct MenuFuc_Language2 Menu[6] =
	{
		{"1.版本信息", "1.Version", DisplayVersion},
		{"2.SIM卡CID码", "2.SIM card CID", DisplayCID},
		{"3.IMEI号", "3.IMEI number", Display_IMEI},
		{"4.读芯片唯一ID", "4.Chip unique ID", Display_ChipId},
		{"5.读随机数", "5.Random number", Display_RandomNumber},
		{"6.读KMY库版本", "6.KMY_LibVersion", Display_KMY_LibVersion},
	};
	struct MenuOperate_Language2 MenuOp =
	{
		(struct MenuFuc_Language2*) Menu,
		6,
		0,
		0,
		0,
		MaxRowOneScr,
		1,
		0,
		0
	};

	while (1)
	{
		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (msg);

			if (MenuOp.FucRetVal == KEY_WaitTimeout || MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				CurProc = CurProc_Return;
				return MenuOp.FucRetVal;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
			}
		}
		else
		{
			CurProc = CurProc_Return;
			return MenuOp.RetVal;
		}
	}
}


unsigned char TranslateKeyToDecimal(unsigned char KeyValue)
{
	switch(KeyValue)
	{
	 	case KEY0:
			return 0;

	 	case KEY1:
			return 1;

	 	case KEY2:
			return 2;

	 	case KEY3:
			return 3;

	 	case KEY4:
			return 4;

	 	case KEY5:
			return 5;

	 	case KEY6:
			return 6;

	 	case KEY7:
			return 7;

	 	case KEY8:
			return 8;

	 	case KEY9:
			return 9;

		default:
		break;
	}
	return 0;
}
unsigned char SetBitOfDecimal(int OldDecimal, unsigned char ValueOfBit, unsigned char bit)
{
	unsigned char NewDecimal=0;
	
	if(bit == 0)
	{
		NewDecimal = OldDecimal%10;
		NewDecimal += ValueOfBit*10;
	}
	else if(bit == 1)
	{
		NewDecimal = (OldDecimal/10)*10;
		NewDecimal += ValueOfBit;
	}
	
	return NewDecimal;
}
unsigned char GetBitOfDecimal(unsigned char Decimal, unsigned char bit)
{
	if(bit == 0)
	{
	 	return ((Decimal/10)%10);
	}
	else if(bit == 1)
	{
	 	return ((Decimal/1)%10);
	}
	return 0;
}



static char TimeDateSet (char *msg) //1.time data setting
{
	unsigned char FlashFlag = 0x01 | 0x02 | 0x04;
	unsigned int year = 0;
	static unsigned char year_H=0;
	static unsigned char year_L=0;
	static unsigned char month = 0;
	static unsigned char day = 0;
	static unsigned char hour = 0;
	static unsigned char minute = 0;
	static unsigned char second = 0;
	unsigned char sBuff[100]={0};

	unsigned char TempKey = KEY_NONE;
	unsigned char Index=0;
	unsigned char MoveFlag=0;
	unsigned char ret=0;
#define startx 7
#define Row 2
#define MaxArray 14
	char YearofMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

	unsigned char	CursorArray[MaxArray][4] = {
		//Min, x, y, Max
		{0, startx+6*0, (Row+1)*13-2, 9},
		{0, startx+6*1, (Row+1)*13-2, 9},	
		{0, startx+6*2, (Row+1)*13-2, 9},
		{0, startx+6*3, (Row+1)*13-2, 9},

		{0, startx+6*5, (Row+1)*13-2, 9},
		{0, startx+6*6, (Row+1)*13-2, 9},

		{0, startx+6*8, (Row+1)*13-2, 9},
		{0, startx+6*9, (Row+1)*13-2, 9},

		{0, startx+6*11, (Row+1)*13-2, 9},
		{0, startx+6*12, (Row+1)*13-2, 9},	//4

		{0, startx+6*14, (Row+1)*13-2, 9},
		{0, startx+6*15, (Row+1)*13-2, 9},

		{0, startx+6*17, (Row+1)*13-2, 9},
		{0, startx+6*18, (Row+1)*13-2, 9},
	};
	typedef struct
	{
		unsigned char *DestValue;
		unsigned char Subtract;
	}DT;

	DT dt[] = {
	{&year_H, 0},
	{&year_H, 0},
	{&year_L, 2},
	{&year_L, 2},

	{&month, 4},
	{&month, 4},

	{&day, 6},
	{&day, 6},

	{&hour, 8},
	{&hour, 8},

	{&minute, 10},
	{&minute, 10},

	{&second, 12},
	{&second, 12},
	};

	kmy_TimeGetTime (&year, &month, &day, &hour, &minute, &second, NULL);
	year_H=year/100;
	year_L=year%100;
	clear_lcd();
	DrawTitle_to_row_Language2 (0, "Time Date", "Time Date");
	kmy_PostKey(KEY_pseudo);
	while (1)
	{
		TempKey = kmy_GetKeyValue();

		if (TempKey == KEY_NONE) continue;

		switch (TempKey)
		{
			case KEY_pseudo:
				if((FlashFlag & 0x01) == 0x01)
				{
					kmy_LcdClear();
					DrawTitle_to_row_Language2 (0, "Time Date", "Time Date");

					FlashFlag &= ~0x01;
				}
				if((FlashFlag & 0x02) == 0x02)
				{
					memset(sBuff, 0, sizeof(sBuff));
					sprintf((char *)sBuff, "%02d%02d-%02d-%02d %02d:%02d:%02d", year_H,year_L, month, day, hour, minute, second);
					text_out_to_row_x(Row, startx,	sBuff);

					FlashFlag &= ~0x02;
				}
				if((FlashFlag & 0x04) == 0x04)
				{
			#define CURSOR_HEIGHT 5
					Lcd_ClearArea(0, CursorArray[Index][2], 132, CursorArray[Index][2]+CURSOR_HEIGHT);

					Lcd_DrawRect(CursorArray[Index][1], CursorArray[Index][2], 5, CURSOR_HEIGHT, mode_Black);

					FlashFlag &= ~0x04;
				}
				if(MoveFlag)
				{
					kmy_PostKey (KEY_RIGHT);//move Index to next
					MoveFlag = 0;
				}
				break;
			case KEY0:
			case KEY1:
			case KEY2:
			case KEY3:
			case KEY4:
			case KEY5:
			case KEY6:
			case KEY7:
			case KEY8:
			case KEY9:
				if((TranslateKeyToDecimal(TempKey) >= CursorArray[Index][0]) && (TranslateKeyToDecimal(TempKey) <= CursorArray[Index][3]))
				{
					*dt[Index].DestValue = SetBitOfDecimal(*dt[Index].DestValue, TranslateKeyToDecimal(TempKey),Index-dt[Index].Subtract);
					FlashFlag |= 0x02;
					kmy_PostKey(KEY_pseudo);
				}
				
				MoveFlag = 1;
				break;
			case KEY_LEFT:
				
				BeepNormal();
				if ( (Index - 1) >= 0)
				{
					Index -= 1;
				}
				else
				{
					Index = MaxArray - 1;
				}
				FlashFlag |= 0x04;
				kmy_PostKey(KEY_pseudo);
				break;

			case KEY_RIGHT:
				
				BeepNormal();
				if ( (Index + 1) < MaxArray)
				{
					Index += 1;
				}
				else
				{
					Index = 0;
				}
				FlashFlag |= 0x04;
				kmy_PostKey(KEY_pseudo);
				break;
			case KEY_UP:
			case KEY_DOWN:
				
				BeepNormal();
				if(TempKey == KEY_UP)
				{
					ret = GetBitOfDecimal(*dt[Index].DestValue, Index-dt[Index].Subtract);
					if(ret +1 <= CursorArray[Index][3])
					{
						ret += 1;
						*dt[Index].DestValue = SetBitOfDecimal(*dt[Index].DestValue, ret, Index-dt[Index].Subtract);
					}												
				}
				else
				{
					ret = GetBitOfDecimal(*dt[Index].DestValue, Index-dt[Index].Subtract);
					if(ret -1 >= CursorArray[Index][0])
					{
						ret -= 1;
						*dt[Index].DestValue = SetBitOfDecimal(*dt[Index].DestValue, ret, Index-dt[Index].Subtract);
					}												
				}
				FlashFlag |= 0x02;
				kmy_PostKey(KEY_pseudo);
				break;
			case KEY_Enter:
				
				BeepNormal();
				year=year_H*100+year_L;

				
				if(day>YearofMonth[month])
				{
					if(month==2)
					{
						if(year%4==0&&year%100!=0||year%400==0)
						{
							if(day>29)month=0;
						}
						else
						{
							month=0;
						}
					}
					else
					{
						month=0;
					}
					
				}
				if(month==0||month>12||hour>24||minute>60||second>60)
				{
					kmy_LcdClear();
					DrawTitle_to_row(1,"Time date format");
					DrawTitle_to_row(2," error");
					WaitkeyAndAutoExit(2);
				}
				else
				{
					//printf("year=%d,month=%d,day=%d\r\nhour=%d,min=%d,sec=%d",year, month, day, hour, minute, second);
					kmy_TimeSetTime (year, month, day, hour, minute, second);
					msleep(500);
				}

				return KEY_Enter;
			case KEY_ReturnInitInterface:
			case KEY_ReturnPrevious:
				
				BeepNormal();
					return TempKey;
			default:break;
		}
	}
}



char StoreParam(char *Buff)
{
	char *p;
	p=Buff;
	p=p+2;

	memset(ApnApn,0,sizeof(ApnApn));
	strcpy((char*)ApnApn,p);
	p=p+50;

	memset(ApnUsername,0,sizeof(ApnUsername));
	strncpy((char*)ApnUsername,p,20);
	p=p+20;
	
	memset(ApnPassword,0,sizeof(ApnPassword));
	strncpy((char*)ApnPassword,p,20);
	p=p+20;
	
	memset(ServerIpPortBuf,0,sizeof(ServerIpPortBuf));
	strncpy((char*)ServerIpPortBuf,p,15);
	p=p+15;
	strcat((char*)ServerIpPortBuf,",");
	strcat((char*)ServerIpPortBuf,p);
	p=p+5;
	
	memset(RequestWebURL,0,sizeof(RequestWebURL));
	strcpy((char*)RequestWebURL,p);
	p=p+150;
	
	memset(CallbackURL,0,sizeof(CallbackURL));
	strcpy((char*)CallbackURL,p);
	p=p+150;

	// -------
	memset(VersionURL,0,sizeof(VersionURL));
	strcpy((char*)VersionURL,p);
	p=p+150;

	memset(UpgradeURL,0,sizeof(UpgradeURL));
	strcpy((char*)UpgradeURL,p);
	p=p+150;

	// ------
	
	memset(RejectReason,0,sizeof(RejectReason));
	strcpy((char*)RejectReason,p);
	p=p+200;
	
	memset(ResID,0,sizeof(ResID));
	strcpy((char*)ResID,p);
	p=p+10;
	
	memset(LoginWebUsername,0,sizeof(LoginWebUsername));
	strcpy((char*)LoginWebUsername,p);
	p=p+20;
	
	memset(LoginWebPassword,0,sizeof(LoginWebPassword));
	strcpy((char*)LoginWebPassword,p);
	p=p+20;
	
	memset(BeepDuration,0,sizeof(BeepDuration));
	strncpy((char*)BeepDuration,p,2);	
	p=p+2;
	
	memset(beepKG,0,sizeof(beepKG));
	strncpy((char*)beepKG,p,1);
	p=p+1;
	
	memset(AcceptTimeMode,0,sizeof(AcceptTimeMode));
	strncpy((char*)AcceptTimeMode,p,1);
	p=p+1;
	
	memset(CheckOrderInterval,0,sizeof(CheckOrderInterval));
	strncpy((char*)CheckOrderInterval,p,3);
	p=p+3;
	
	memset(GPRSOpenTime,0,sizeof(GPRSOpenTime));
	strncpy((char*)GPRSOpenTime,p,5);
	p=p+5;
	
	memset(GPRSCloseTime,0,sizeof(GPRSCloseTime));
	strncpy((char*)GPRSCloseTime,p,5);	
	p=p+5;
	
	memset(PrintNewLineFlag,0,sizeof(PrintNewLineFlag));
	strncpy((char*)PrintNewLineFlag,p,3);
	p=p+3;

	memset(PrintDateFormat,0,sizeof(PrintDateFormat));
	strncpy((char*)PrintDateFormat,p,1);
	p=p+1;

	memset(PrintTimeFormat,0,sizeof(PrintTimeFormat));
	strncpy((char*)PrintTimeFormat,p,1);
	p=p+1;

	memset(PrintPageHeader,0,sizeof(PrintPageHeader));
	strncpy((char*)PrintPageHeader,p,30);
	p=p+30;

	memset(PrintPageFooter,0,sizeof(PrintPageFooter));
	strncpy((char*)PrintPageFooter,p,30);
	p=p+30;

	memset(PrintReceiptCount,0,sizeof(PrintReceiptCount));
	strncpy((char*)PrintReceiptCount,p,1);
	p=p+1;
	
	memset(AutoAcceptOrder,0,sizeof(AutoAcceptOrder));
	strncpy((char*)AutoAcceptOrder,p,1);
	p=p+1;

	memset(AcceptTimeOptions,0,sizeof(AcceptTimeOptions));
	strncpy((char*)AcceptTimeOptions,p,100);
	p=p+100;

	memset(Version,0,sizeof(Version));
	strncpy((char*)Version,p,50);
	p=p+50;
	
	memset(SIM_PIN,0,sizeof(SIM_PIN));
	strncpy((char*)SIM_PIN,p,4);
	p=p+4;
	
	memset(AutoReboot12Hours,0,sizeof(AutoReboot12Hours));
	strncpy((char*)AutoReboot12Hours,p,1);
	p=p+1;
	
	memset(AutoPrintString,0,sizeof(AutoPrintString));
	strncpy((char*)AutoPrintString,p,25);

	if(StorageVariable()==1)
	{
		StoreLocalSettings();
		return 0;
	}
	else
	{
		return 1;
	}
}

unsigned short GetSum(unsigned char buff[], int len)
{
    unsigned short sum = 0;
    int i = 0;
    for (i = 0; i < len; i++)
    {
        sum += buff[i];
    }
    return sum;
}

char UpdateParameter(char *msg)
{
	unsigned char RecvBuff[1300] = {0}, retval = 0;
	int RecvLen = 0;
	char State = 0;
	int ReadLen = 0;
	int ReadLen2 = 0;
	int ReadPos = 0;
	unsigned short CheckSum = 0;
	char temp_ONOFF=0;
//	int i=0;


	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=1;//close check order
	clear_lcd();
	DrawTitle_to_row_Language2(0,"更新中...","Updating...");
	kmy_USART1ReceiveReset();
	
	while(1)
	{
		retval=GetKeyValue();
		if(retval != KEY_NONE)break;

		switch(State)
		{
			case 0://read AT
				RecvLen = 0;
				memset(RecvBuff, 0, sizeof(RecvBuff));
				
				RecvLen = kmy_USART1ReceiveData(RecvBuff, 2, 100);
				if(RecvLen == 2)
				{
					if(strstr((char*)RecvBuff, "AT"))
					{
						State++;
					}
				}
				break;

			case 1://send OK
				kmy_USART1ReceiveReset();
				kmy_USART1SendString("OK");
				State++;
				break;

			case 2://read 2 bytes of len
				RecvLen = 0;
				memset(RecvBuff, 0, sizeof(RecvBuff));
				
				RecvLen = kmy_USART1ReceiveData(RecvBuff, 2, 100);
				if(RecvLen == 2)
				{
					ReadLen = (RecvBuff[0]<<8) | RecvBuff[1];
					ReadLen2 = ReadLen;
					State++;

					ReadPos = 0;
					ReadPos += 2;
				}
				break;

			case 3://read "ReadLen" bytes datas
				RecvLen = 0;
				RecvLen = kmy_USART1ReceiveData(RecvBuff + ReadPos, ReadLen, 100);
				ReadPos += RecvLen;
				ReadLen -= RecvLen;

				if(ReadLen == 0)
				{
					State++;
				}
				break;
			case 4://check parity, send ok or error
				//有效数据位置是从2开始到ReadLen2的数据
				//kmy_USART1SendData(RecvBuff, 2+ReadLen2);

				CheckSum = (RecvBuff[ReadLen2 + 0] << 8) | RecvBuff[ReadLen2 + 1];
				if(CheckSum == GetSum(RecvBuff, ReadLen2))
				{
					kmy_USART1SendString("OK");
					if(StoreParam((char*)RecvBuff)==0)
					{
						clear_lcd();
						DrawTitle_to_row_Language2(0,"Update Success","Update Success");
						
						kmy_GPRSTimeSet(0);
						gCheckOrderLock=0;
						WaitkeyAndAutoExit(10);
					}
					else
					{
						clear_lcd();
						DrawTitle_to_row_Language2(0,"Update Fail","Update Fail");
						WaitkeyAndAutoExit(10);
					}
					
					/*	
					//for test the datas
					while(1)
					{
						retval=GetKeyValue();
						if(retval == KEY_NONE)continue;
						if(retval==KEY1)
						{
							for(i=0;i<RecvLen;i++)
							printf("%02x ",RecvBuff[i]);
						}
						printf("\r\n--------------\r\n");
						break;
					}
					*/
					if(temp_ONOFF==0)GPRS_ONOFF=0;//if	previous state is open then open check order
					return 0;
				}
				else
				{
					kmy_USART1SendString("ERROR");
					if(temp_ONOFF==0)GPRS_ONOFF=0;//if	previous state is open then open check order
					return 0;
				}
		}
	}
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return 0;
}


char BasicSettings (char *msg)
{
	const static struct MenuFuc_Language2 Menu[9] =
	{
		{"1.GPRS APN", "1.GPRS APN", BasicApnSetApn},
		{"2.GPRS APN username", "2.GPRS APN username", BasicApnSetUsername},
		{"3.GPRS APN password", "3.GPRS APN password", BasicApnSetPassword},	
		{"4.屏幕对比度设置", "4.Contrast", ContrastSet},
		{"5.按键音设置", "5.Keytone", BasicKeyTone},
		{"6.时间日期设置", "6.DateTime", TimeDateSet},
		{"7.屏保时间设置", "7.Timeout", PowerOffScreenTime},
		{"8.语言设置", "8.Language", LanguageSet},
		{"9.读取相关信息", "9.Version Info", ReadSomeMessage},
	//	{"7.更新参数", "7.Update Parameter", UpdateParameter},
		//	{"4.APN设置", "4.APN set", BasicApnSet},
	};
	struct MenuOperate_Language2 MenuOp =
	{
		(struct MenuFuc_Language2*) Menu,
		9,
		0,
		0,
		0,
		MaxRowOneScr,
		1,
		0,
		0
	};

	while (1)
	{
		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (msg);

			if (MenuOp.FucRetVal == KEY_WaitTimeout || MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				CurProc = CurProc_Return;
				return MenuOp.FucRetVal;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
			}
		}
		else
		{
			CurProc = CurProc_Return;
			return MenuOp.RetVal;
		}
	}
}






char DomainSet (char *msg) //
{
	unsigned char buff[24];
	unsigned char retval;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) Domain);
	

	retval = GetString_abcABC123PYWuBi_Language2 ("【输入域名网址】", "Input Server Domain", SRF_123 | SRF_ABC | SRF_abc, SRF_abc, buff, sizeof (buff) - 1, 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();

	
	memset (Domain, 0, sizeof (Domain) );
	strcpy ( (s8*) Domain, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
	}
	else
	{
		DrawTitle_to_row_Language2 (3, "更改成功!", "change success!");
	}

	return (WaitkeyAndAutoExit (10) );
}


char TerminalIDSet (char *msg) //
{
	unsigned char buff[24];
	unsigned char retval;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) TerminalID);
	DrawTitle_to_row_Language2 (0, "【当前终端ID】", "Current ID");
	text_out_to_row_Language2 (1, buff, buff);
	text_out_to_row_Language2 (3, "更改:请按确认", "Change: Confirm");
	text_out_to_row_Language2 (4, "退出:请按取消", "Exit: Return");

	retval = WaitkeyAndAutoExit (10);

	if (retval != KEY_Enter) return retval;

	retval = GetString_abcABC123PYWuBi_Language2 ("【输入终端ID】", "TerminalID edit", SRF_123 | SRF_ABC | SRF_abc, SRF_123, buff, sizeof (buff) - 1, 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();

	if (strlen ( (sc8*) buff) == 0)
	{
		DrawTitle_to_row_Language2 (2, "长度不能为0", "Length error!");
	}
	else
	{
		memset (TerminalID, 0, sizeof (TerminalID) );
		strcpy ( (s8*) TerminalID, (sc8*) buff);

		if (!StorageVariable() )
		{
			DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
		}
		else
		{
			DrawTitle_to_row_Language2 (3, "更改成功!", "change success!");
		}
	}

	return (WaitkeyAndAutoExit (10) );
}

char TerminalPasswordSet (char *msg) //
{
	unsigned char buff[24];
	unsigned char retval;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) TerminalPassword);
	DrawTitle_to_row_Language2 (0, "【当前终端密码】", "TerminalPassword");
	text_out_to_row_Language2 (1, buff, buff);
	text_out_to_row_Language2 (3, "更改:请按确认", "Change: Confirm");
	text_out_to_row_Language2 (4, "退出:请按取消", "Exit: Return");

	retval = WaitkeyAndAutoExit (10);

	if (retval != KEY_Enter) return retval;

	retval = GetString_abcABC123PYWuBi_Language2 ("【输入终端密码】", "TerminalPassword", SRF_123 | SRF_ABC | SRF_abc, SRF_123, buff, sizeof (buff) - 1, 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();

	if (strlen ( (sc8*) buff) == 0)
	{
		DrawTitle_to_row_Language2 (2, "长度不能为0", "Length error!");
	}
	else
	{
		memset (TerminalPassword, 0, sizeof (TerminalPassword) );
		strcpy ( (s8*) TerminalPassword, (sc8*) buff);

		if (!StorageVariable() )
		{
			DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
		}
		else
		{
			DrawTitle_to_row_Language2 (3, "更改成功!", "change success!");
		}
	}

	return (WaitkeyAndAutoExit (10) );
}


static char IpAddSet (char *msg) //IP地址设置
{
	unsigned char buff[24];
	unsigned char retval;
	char temp_ONOFF=0;

	
	abcABC123PYWuBiArgument argAa1;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) ServerIpPortBuf);

	abcABC123PYWuBiArgDeInit (&argAa1, buff, 28);
	argAa1.srfFlag = SRF_123 | SRF_ABC | SRF_abc;
	argAa1.LocalTitle = "【输入IP地址】";
	argAa1.OtherTitle="Input IP, port";
	argAa1.HaveoldFlag = 1;
	retval = GetString_abcABC123PYWuBi2 (&argAa1);

	if (retval != KEY_Enter) return retval;
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();

	if (strlen ( (sc8*) buff) > 21 || strlen ( (sc8*) buff) < 9)
	{
		DrawTitle_to_row_Language2 (2, "错误:IP地址不对!", "Error:IP wrong!");
	}
	else
	{
		memset (ServerIpPortBuf, 0, sizeof (ServerIpPortBuf) );
		strcpy ( (s8*) ServerIpPortBuf, (sc8*) buff);

		if (!StorageVariable() )
		{
			DrawTitle_to_row_Language2 (2, "更改失败!", "change failure!");
		}
		else
		{
			DrawTitle_to_row_Language2 (2, "更改成功!", "change success!");
		}
	}

	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return (WaitkeyAndAutoExit (10) );
}



static char PIN_OpenClose (char *msg)
{
#if 0
	char retval, buff[1024];
	char temp[20];
	char PinTimes[2], PukTimes[3];

loop:
	retval = ReadPINPUKTimes (PinTimes, PukTimes);

	if (retval == 0)
	{
		if (PinTimes[0] > '0')
		{
			clear_lcd();
			DrawTitle_to_row_Language2 (0, "输入PIN", "Input PIN");

			if (Language[0] == '1')
			{
				strcpy (buff, "remain times:");
			}
			else
			{
				strcpy (buff, "剩余次数:");
			}

			strcat (buff, PinTimes);
			DrawTitle_to_row_Language2 (1, buff, buff);
			retval = PassWordInput2 (NULL, temp, 5, 1, 0, KEY_NONE, 2);

			if (retval != KEY_Enter) return 0;

			if (strlen (temp) != 4)
			{
				clear_lcd();
				DrawTitle_to_row_Language2 (1, "长度错误", "length error");
				sleep (2);
				return 0;
			}

			strcpy (buff, "AT+CLCK=\"SC\",");			//AT+CLCK="SC",1,"0907"

			if (RequirePin == NO)
			{
				strcat (buff, "1");
			}
			else
			{
				strcat (buff, "0");
			}

			strcat (buff, ",\"");
			strcat (buff, temp);
			strcat (buff, "\"\r");

			if (send_at_cmd_and_receive (buff, sizeof (buff), 2000, "OK\r") != TCP_OK)
			{
				clear_lcd();
				DrawTitle_to_row_Language2 (2, "PIN 错误", "PIN error");
				sleep (2);
				goto loop;
			}
			else
			{
				clear_lcd();

				if (RequirePin == 0)
				{
					DrawTitle_to_row_Language2 (2, "启用pin成功", "Enble PIN success");
					RequirePin = 1;
				}
				else
				{
					DrawTitle_to_row_Language2 (2, "禁用pin成功", "Disable PIN success");
					RequirePin = 0;
				}

				sleep (2);
				return 0;
			}
		}
		else
		{
			clear_lcd();
			DrawTitle_to_row_Language2 (2, "PIN 被锁", "PIN locked");
			sleep (2);
			PUK_Required();
			return 0;
		}
	}

	return 0;
#else
	return 0;
#endif
}
char SIM_PINset (char *msg) 
{
	unsigned char ret;
	unsigned char pin[7];

	clear_lcd();
	strcpy ( (s8*) pin, (sc8*) SIM_PIN);
	DrawTitle_to_row_Language2 (0, "PIN", "PIN");
	text_out_to_row_Language2 (1, "****", "****");
	text_out_to_row_Language2 (3, "修改:请按确认键", "change:confirm");
	text_out_to_row_Language2 (4, "返回:请按返回键", "exit:return");

	ret = WaitkeyAndAutoExit (10);

	if (ret != KEY_Enter) return ret;

	if (Language[0] == '1')
	{
		ret = PassWordInput2 ("Input PIN", pin, 6, 1, 1, KEY_NONE, 1);
	}
	else
	{
		ret = PassWordInput2 ("【输入PIN】", pin, 6, 1, 1, KEY_NONE, 1);
	}

	if (ret != KEY_Enter) return ret;

	if (strlen ( (sc8*) pin) != 4)
	{
		clear_lcd();
		DrawTitle_to_row_Language2 (2, "长度错误", "longth error");
		return (WaitkeyAndAutoExit (10) );
	}

	clear_lcd();
	strcpy ( (s8*) SIM_PIN, (sc8*) pin);
	StoreLocalSettings();
	DrawTitle_to_row_Language2 (3, "修改成功", "Change success!");
	

	return (WaitkeyAndAutoExit (10) );
}
static char PIN_Change (char *msg) //AT+CPWD="SC","0909","0505"
{
#if 0
	PasswordInputArgument arg;
	unsigned char oldpassword[5];
	unsigned char newpassword1[5];
	unsigned char newpassword2[200];
	unsigned char retval;

	if (RequirePin == YES)  	//启用pin  之后才能改pin
	{
		PassWordArgDeInit (&arg, oldpassword, 4);
		arg.LocalTitle = "【输入原PIN】";
		retval = BT_PassWordInput_MiddledDisplay (&arg);

		if (retval != KEY_Enter) return retval;

again:
		PassWordArgDeInit (&arg, newpassword1, 4);
		arg.LocalTitle = "【输入新PIN】";
		retval = BT_PassWordInput_MiddledDisplay (&arg);

		if (retval != KEY_Enter) return retval;

		PassWordArgDeInit (&arg, newpassword2, 4);
		arg.LocalTitle = "【再次输入新PIN】";
		retval = BT_PassWordInput_MiddledDisplay (&arg);

		if (retval != KEY_Enter) return retval;

		if (strcmp (newpassword1, newpassword2) != 0)
		{
			clear_lcd();
			DrawTitle_to_row (1, "你两次输入的");
			DrawTitle_to_row (2, "新PIN不一致");
			DrawTitle_to_row (3, "请重新输入");
			retval = WaitkeyAndAutoExit (10);

			if (retval == KEY_Enter) goto again;
			else
			{
				return retval;
			}
		}

		//AT+CPWD="SC","0909","0505"
		strcpy (newpassword2, "AT+CPWD=\"SC\",\"");
		strcat (newpassword2, oldpassword);
		strcat (newpassword2, "\",\"");
		strcat (newpassword2, newpassword1);
		strcat (newpassword2, "\"\r");
		retval = send_at_cmd_and_return (newpassword2, 5000, "OK", "ERROR");

		clear_lcd();

		if (retval == TCP_OK)
		{
			DrawTitle_to_row (2, "修改成功");
		}
		else
		{
			DrawTitle_to_row (2, "修改失败");
		}

		return WaitkeyAndAutoExit (10);
	}
	else
	{
		clear_lcd();
		DrawTitle_to_row (2, "请先启用PIN");
		return WaitkeyAndAutoExit (10);
	}

	return 0;
#else
	return 0;
#endif
}

char PinSet (char *msg)
{
#if 0
	return (abeyant() );
#else
	static unsigned char BuffLocal[30], BuffOther[30];


	const static struct MenuFuc_Language2 Menu[3] =
	{
		{BuffLocal, BuffOther, PIN_OpenClose},
		{"2.修改 PIN", "2.Change PIN", PIN_Change},
		{"3.存储 PIN", "3.Store PIN", SIM_PINset},
	};
	struct MenuOperate_Language2 MenuOp =
	{
		(struct MenuFuc_Language2*) Menu,
		3,
		0,
		0,
		0,
		MaxRowOneScr,
		1,
		0,
		0
	};

	while (1)
	{
		if (RequirePin == 0)
		{
			strcpy ( (s8*) BuffLocal, "1.禁用 PIN");
			strcpy ( (s8*) BuffOther, "1.Close PIN");
		}
		else
		{
			strcpy ( (s8*) BuffLocal, "1.启用 PIN");
			strcpy ( (s8*) BuffOther, "1.Open PIN");
		}

		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (msg);

			if (MenuOp.FucRetVal == KEY_WaitTimeout || MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				CurProc = CurProc_Return;
				return MenuOp.FucRetVal;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
			}
		}
		else
		{
			return MenuOp.RetVal;
		}
	}

#endif
}
void FormatLocalSetting(void)
{
	kmy_EepromWriteByte(0x9000,0x00);// initial local setting flag
}
static char RestoreChuChangSet (char *msg)
{
	unsigned char retval;

	clear_lcd();
	DrawTitle_to_row_Language2 (0, "特别警告:", "Warning:");
	DrawTitle_to_row_Language2 (1, "恢复出厂设置将导致,", "Are you sure");
	DrawTitle_to_row_Language2 (2, "此终端机成为一新机", "reset to the");
	DrawTitle_to_row_Language2 (3, "确定恢复:请按确认", "factory settings?");
	DrawTitle_to_row_Language2 (4, "退出:请按任意键", NULL);

	retval = WaitkeyAndAutoExit (20);

	if (retval != KEY_Enter) return retval;
	EepromFile_FileSystemFormat();
	FormatLocalSetting();
	retval = RestoreConfigFile();
	clear_lcd();

	if (retval == 1)
	{
		DrawTitle_to_row_Language2 (2, "出厂设置恢复成功!", "Reset success");
	}
	else
	{
		DrawTitle_to_row_Language2 (2, "出厂设置恢复失败!", "Reset error");
	}

	return (WaitkeyAndAutoExit (10) );
}



static char OpPsword (char *msg) //终端操作密码设置，最多20  位密码
{
	unsigned char buff[16], buff2[16];
	char retval;
	PasswordInputArgument arg;

	PassWordArgDeInit (&arg, buff, sizeof (buff) );
	arg.LocalTitle = "【输入新密码】";
	arg.OtherTitle = "Input new password";
	retval = PassWordInput_MiddledDisplay (&arg);

	if (retval != KEY_Enter) return retval;

	PassWordArgDeInit (&arg, buff2, sizeof (buff2) );
	arg.LocalTitle = "【再次确认新密码】";
	arg.OtherTitle = "Again Input";
	retval = PassWordInput_MiddledDisplay (&arg);

	if (retval != KEY_Enter) return retval;

	clear_lcd();

	if (strcmp ( (sc8*) buff, (sc8*) buff2) == 0)
	{
		memset (EnterAdvancedSetPassWord, 0, sizeof (EnterAdvancedSetPassWord) );
		strcpy ( (s8*) EnterAdvancedSetPassWord, (sc8*) buff);

		if (!StorageVariable() )
		{
			DrawTitle_to_row_Language2 (3, "更改失败!", "change failure!");
		}
		else
		{
			DrawTitle_to_row_Language2 (3, "更改成功!", "change success!");
		}
	}
	else
	{
		DrawTitle_to_row_Language2 (2, "错误!你两次输入", "Error,Two times");
		DrawTitle_to_row_Language2 (3, "的密码不一致!", "Input not same");
	}

	return (WaitkeyAndAutoExit (10) );
}




char Console (char *msg)
{
	//exit(1);
	return 0;
}


char VersionURL_Set(char *msg)
{
	unsigned char buff[sizeof (VersionURL)];
	unsigned char retval=0;
	char temp_ONOFF=0;
	
	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) VersionURL);
	
	retval = GetString_abcABC123PYWuBi_Language2 ("Input Version URL", "Input Version URL", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) VersionURL, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	
	return WaitkeyAndAutoExit(10);
}

char UpgradeURL_Set(char *msg)
{
	unsigned char buff[sizeof (UpgradeURL)];
	unsigned char retval=0;
	char temp_ONOFF=0;
	
	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) UpgradeURL);
	
	retval = GetString_abcABC123PYWuBi_Language2 ("Input Upgrade URL", "Input Upgrade URL", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) UpgradeURL, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	
	return WaitkeyAndAutoExit(10);
}

char OrderURL_set(char *msg)
{
	unsigned char buff[sizeof (RequestWebURL)];
	unsigned char retval=0;
	char temp_ONOFF=0;
	
	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) RequestWebURL);
	
	retval = GetString_abcABC123PYWuBi_Language2 ("Input Web URL", "Input Web URL", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) RequestWebURL, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return WaitkeyAndAutoExit(10);
}
char Callback_set(char *msg)
{
	unsigned char buff[sizeof (CallbackURL)];
	unsigned char retval=0;
	char temp_ONOFF=0;
	
	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) CallbackURL);
	
	retval = GetString_abcABC123PYWuBi_Language2 ("Input Callback URL", "Input Callback URL", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order
	
	clear_lcd();
	strcpy ( (s8*) CallbackURL, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return WaitkeyAndAutoExit(10);

}
char RejectReason_set(char *msg)
{
	char retval=0;
	char temp_ONOFF=0;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order
	
	retval=GetRecjectReasonAndInput();
	if(retval==KEY_Enter)
	{
		if (!StorageVariable() )
		{
			clear_lcd();
			DrawTitle_to_row (2, "Change falure!");
		}
		else
		{	
			clear_lcd();
			DrawTitle_to_row (2, "Change success!");
		}
		
		if(temp_ONOFF==0)GPRS_ONOFF=0;//if	previous state is open then open check order		
		return WaitkeyAndAutoExit(10);
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return retval;
}
char RestaurantID_set(char *msg)
{
	unsigned char buff[sizeof (ResID)];
	unsigned char retval;
	char temp_ONOFF=0;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) ResID);
	
	retval = GetString_abcABC123PYWuBi_Language2 ("Input Res ID ", "Input Res ID ", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) ResID, (sc8*) buff);

	StoreLocalSettings();
	DrawTitle_to_row (2, "Change success!");
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return WaitkeyAndAutoExit(10);

}

char LoginUsername_set(char *msg)
{
	unsigned char buff[sizeof (LoginWebUsername)];
	unsigned char retval;
	char temp_ONOFF=0;
	
	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) LoginWebUsername);
	
	retval = GetString_abcABC123PYWuBi_Language2 ("Input Web Username", "Input Web Username", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) LoginWebUsername, (sc8*) buff);
	StoreLocalSettings();
	DrawTitle_to_row (2, "Change success!");
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return WaitkeyAndAutoExit(10);

}

char LoginPassword_set(char *msg)
{
	unsigned char buff[sizeof (LoginWebPassword)];
	unsigned char retval;	
	char temp_ONOFF=0;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) LoginWebPassword);

	retval = GetString_abcABC123PYWuBi_Language2 ("Input Web Password ", "Input Web Password ", SRF_abc | SRF_ABC | SRF_123, SRF_123, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) LoginWebPassword, (sc8*) buff);
	StoreLocalSettings();
	DrawTitle_to_row (2, "Change success!");

	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return WaitkeyAndAutoExit(10);

}

char CheckOrderInterval_set(char *msg)
{
	unsigned char buff[sizeof (CheckOrderInterval)];
	unsigned char retval;
	char temp_ONOFF=0;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) CheckOrderInterval);

	retval = GetString_abcABC123PYWuBi_Language2 ("Interval (seconds)", "Interval (seconds)",  SRF_123, SRF_123, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order

	clear_lcd();
	strcpy ( (s8*) CheckOrderInterval, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return WaitkeyAndAutoExit(10);
}
char GPRSOpenTime_set(char *msg)
{
	char buff[sizeof (GPRSOpenTime)];
	char temp_ONOFF=0;

	clear_lcd();
	strcpy ( buff, (sc8*) GPRSOpenTime);
	
	GetString_123TimeInput ("Input GPRS Open Time",SRF_123,SRF_123,(u8*)buff,6,1);

	if(CheckTimeFormat(buff)==1)
	{
		clear_lcd();
		DrawTitle_to_row (2, "Incorrect time format");
		return WaitkeyAndAutoExit(10);
	}
	if(strcmp((char*)GPRSOpenTime,buff)==0) return KEY_ReturnPrevious;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order
	
	clear_lcd();
	strcpy ( (s8*) GPRSOpenTime, buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{	
		kmy_GPRSTimeSet(0);
		DrawTitle_to_row (2, "Change success!");
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return WaitkeyAndAutoExit(10);	
}
char GPRSCloseTime_set(char *msg)
{
	char buff[sizeof (GPRSCloseTime)];
	char temp_ONOFF=0;

	
	clear_lcd();
	strcpy ( buff, (sc8*) GPRSCloseTime);

	GetString_123TimeInput ("Input GPRS Close Time",SRF_123,SRF_123,(u8*)buff,6,1);

	if(CheckTimeFormat(buff)==1)
	{
		clear_lcd();
		DrawTitle_to_row (2, "Incorrect time format");
		return WaitkeyAndAutoExit(10);
	}
	if(strcmp((char*)GPRSOpenTime,(char*)buff)==0) return KEY_ReturnPrevious;
	
	temp_ONOFF=GPRS_ONOFF;
	GPRS_ONOFF=0;//open check order
	
	clear_lcd();
	strcpy ( (s8*) GPRSCloseTime, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		kmy_GPRSTimeSet(0);
		DrawTitle_to_row (2, "Change success!");
	}
	
	if(temp_ONOFF==0)GPRS_ONOFF=0;//if  previous state is open then open check order
	return WaitkeyAndAutoExit(10);
}
char BeepDuration_set(char *msg)
{
	unsigned char buff[sizeof (BeepDuration)];
	unsigned char retval;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) BeepDuration);

	retval = GetString_abcABC123PYWuBi_Language2 ("Input Duration", "Input Duration", SRF_123, SRF_123, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();
	strcpy ( (s8*) BeepDuration, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	return WaitkeyAndAutoExit(10);

}


char AcceptTimeMode_set(char *msg)
{
	unsigned char buff[sizeof (AcceptTimeMode)];
	unsigned char retval;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) AcceptTimeMode);

	retval = GetString_abcABC123PYWuBi_Language2 ("Accept time mode", "Accept time mode", SRF_123, SRF_123, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();
	strcpy ( (s8*) AcceptTimeMode, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	return WaitkeyAndAutoExit(10);

}

char PrintNewlineFlag_set(char *msg)
{
	clear_lcd();
	DrawTitle_to_row(1,"This function reserve");
	return WaitkeyAndAutoExit(8);

}
char PrintDateFormat_set(char *msg)
{
	clear_lcd();
	DrawTitle_to_row(1,"This function reserve");
	return WaitkeyAndAutoExit(8);
}
char PrintTimeFormat_set(char *msg)
{
	clear_lcd();
	DrawTitle_to_row(1,"This function reserve");
	return WaitkeyAndAutoExit(8);
}
char PrintPageHeader_set(char *msg)
{
	unsigned char buff[sizeof (PrintPageHeader)];
	unsigned char retval=0;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) PrintPageHeader);
	
	retval = GetString_abcABC123PYWuBi_Language2 ("Input PrintPageHeader", "Input PrintPageHeader", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();
	strcpy ( (s8*) PrintPageHeader, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	return WaitkeyAndAutoExit(10);
}

char PrintPageFooter_set(char *msg)
{
	unsigned char buff[sizeof (PrintPageFooter)];
	unsigned char retval=0;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) PrintPageFooter);
	
	retval = GetString_abcABC123PYWuBi_Language2 ("Input PrintPageFooter", "Input PrintPageFooter", SRF_abc | SRF_ABC | SRF_123, SRF_abc, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();
	strcpy ( (s8*) PrintPageFooter, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	return WaitkeyAndAutoExit(10);
}


char PrintReceptCount_set(char *msg)
{
	clear_lcd();
	DrawTitle_to_row(1,"This function reserve");
	return WaitkeyAndAutoExit(8);
}
/*

char AutoAccpetOrder_set(char *msg)
{
	unsigned char buff[sizeof (AutoAcceptOrder)];
	unsigned char retval;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) AutoAcceptOrder);

	retval = GetString_abcABC123PYWuBi_Language2 ("Auto accept order", "Auto accept order", SRF_123, SRF_123, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();
	strcpy ( (s8*) AutoAcceptOrder, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		DrawTitle_to_row (2, "Change success!");
	}
	return WaitkeyAndAutoExit(10);

}
*/

char LCDIdelIest_set(char *msg)
{
	clear_lcd();
	DrawTitle_to_row(1,"This function reserve");
	return WaitkeyAndAutoExit(8);
}

char TestText_set(char *msg)
{
	clear_lcd();
	DrawTitle_to_row(1,"This function reserve");
	return WaitkeyAndAutoExit(8);
}

char AutoReboot(char *msg)
{
	unsigned char buff[sizeof (AutoReboot12Hours)];
	unsigned char retval;

	clear_lcd();
	strcpy ( (s8*) buff, (sc8*) AutoReboot12Hours);

	retval = GetString_abcABC123PYWuBi_Language2 ("Reboot every 12hour", "Reboot every 12hour", SRF_123, SRF_123, buff, sizeof (buff), 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();
	strcpy ( (s8*) AutoReboot12Hours, (sc8*) buff);

	if (!StorageVariable() )
	{
		DrawTitle_to_row (2, "Change falure!");
	}
	else
	{
		gflagSeconds=kmy_TimeGetRtcSeconds();	
		DrawTitle_to_row (2, "Change success!");
	}
	return WaitkeyAndAutoExit(10);

}

char AutoPrintTime(char *msg)
{
	unsigned char time[2]={0};
	unsigned char buff[sizeof (AutoPrintString)]={0};
	unsigned char retval;

	clear_lcd();

	retval = GetString_abcABC123PYWuBi_Language2 ("On=1 Off=0", "On=1 Off=0", SRF_123, SRF_123, time, sizeof (time), 1);

	if (retval != KEY_Enter) return retval;

	clear_lcd();
	gCountDown=atoi((char*)time);
	printf("gCountDown=%d\r\n",gCountDown);
	strncpy ( (s8*) buff, (sc8*) AutoPrintString,sizeof (AutoPrintString)-1);
	retval = GetString_abcABC123PYWuBi_Language2 ("Response string", "Response string", SRF_abc| SRF_ABC|SRF_123, SRF_abc, buff, sizeof (buff), 1);
	
	if (retval != KEY_Enter) return retval;
	clear_lcd();
	strcpy ( (s8*) AutoPrintString, (sc8*) buff);

	StoreLocalSettings();
	DrawTitle_to_row_Language2 (3, "修改成功", "Change success!");

	return WaitkeyAndAutoExit(10);

}

char InitParameterSet(char *msg)
{
	const static struct MenuFuc_Language2 Menu[21] =
	{
		{"1.Update Paras", "1.Update Paras", UpdateParameter},
		{"2.Res ID", "2.Res ID", RestaurantID_set},
		{"3.IP and Port", "3.IP and Port", IpAddSet},			
		{"4.Server Domain", "4.Server Domain", DomainSet},
		{"5.Version URL", "5.Version URL", VersionURL_Set},
		{"6.Upgrade URL", "6.Upgrade URL", UpgradeURL_Set},
		{"7.Order URL", "7.Order URL", OrderURL_set},
		{"8.Callback URL", "8.Callback URL", Callback_set},		
		{"9.Login username", "9.Login username", LoginUsername_set},
		{"10.Login password", "10.Login password", LoginPassword_set},
		{"11.Beep enable", "11.Beep enable", BasicKeyTone},
		{"12.Check interval", "12.Check interval", CheckOrderInterval_set},
		{"13.GPRS open time", "13.GPRS open time", GPRSOpenTime_set},
		{"14.GPRS close time", "14.GPRS close time", GPRSCloseTime_set},
		{"15.Beep duration", "15.Beep duration", BeepDuration_set},	
		{"16.Reject Reason", "16.Reject Reason", RejectReason_set},
		{"17.Print page header", "17.Print page header", PrintPageHeader_set},
		{"18.Print page footer", "18.Print page footer", PrintPageFooter_set},
		{"19.Accept time mode","19.Accept time mode",AcceptTimeMode_set},					
		{"20.Auto reboot", "20.Auto reboot", AutoReboot},
		{"21.Auto print order", "21.Auto print order", AutoPrintTime},
		//{"23.Auto print order", "23.Auto print order", AutoAccpetOrder_set},
	};
	struct MenuOperate_Language2 MenuOp =
	{
		(struct MenuFuc_Language2*) Menu,
		21,
		0,
		0,
		0,
		MaxRowOneScr,
		1,
		0,
		0
	};

	while (1)
	{
		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (msg);

			if (MenuOp.FucRetVal == KEY_WaitTimeout || MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				CurProc = CurProc_Return;
				return MenuOp.FucRetVal;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
			}
		}
		else
		{
			CurProc = CurProc_Return;
			return MenuOp.RetVal;
		}
	}
}




char AdvancedSet (char *msg)
{
	unsigned char OperateCode[30];
	char retval;
	PasswordInputArgument arg;
	const static struct MenuFuc_Language2 Menu[4] =
	{
		{"1.高级设置密码设置", "1.Advanced Password", OpPsword},		//注意:  第一个字符串的长度不能大于MaxByteOneLine-1
		{"2.初始化变量设置", "2.FoodOrder paras", InitParameterSet},
		{"3.PIN设置", "3.PIN set", PinSet},
		{"4.恢复出厂设置", "4.Reset Factory", RestoreChuChangSet},
	};
	struct MenuOperate_Language2 MenuOp = {
		(struct MenuFuc_Language2*) Menu,
			4, 
			0,
			0, 
			0, 
			MaxRowOneScr, 
			1,
			0, 
			0
			};

	PassWordArgDeInit (&arg, OperateCode, 16);
	arg.LocalTitle = "【请输入密码】";
	retval = PassWordInput_MiddledDisplay (&arg);

	if (retval != KEY_Enter) return retval;

	if (strcmp ( (sc8*) EnterAdvancedSetPassWord, (sc8*) OperateCode) != 0)
	{
		DrawTitle_to_row_Language2 (2, "密码错误!", "Password error");
//		return (WaitkeyAndAutoExit (10) );
	}

	while (1)
	{
		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (NULL);

			if (MenuOp.FucRetVal == KEY_WaitTimeout || MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				CurProc = CurProc_Return;
				return MenuOp.FucRetVal;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
			}
		}
		else
		{
			return (MenuOp.RetVal);
		}
	}
}



char MainMenuScreen_Settings (char *msg)
{
	const static struct MenuFuc_Language2 Menu[2] =
	{
		{"1.基本设置", "1.Basic Settings", BasicSettings},
		{"2.高级设置", "2.Advanced Settings", AdvancedSet},
	};
	struct MenuOperate_Language2 MenuOp =
	{
		(struct MenuFuc_Language2*) Menu,
		2,
		0,
		0,
		0,
		MaxRowOneScr,
		1,
		0,
		0
	};

	while (1)
	{
		MenuHandler_Language2 (&MenuOp);

		if (MenuOp.RetVal == KEY_Enter)
		{
			MenuOp.FucRetVal = MenuOp.Menu->MenuFuc (msg);

			if (MenuOp.FucRetVal == KEY_WaitTimeout || MenuOp.FucRetVal == KEY_ReturnInitInterface)
			{
				CurProc = CurProc_Return;
				return MenuOp.FucRetVal;
			}
			else
			{
				clear_lcd();
				MenuOp.flashflag = 1;
			}
		}
		else
		{
			CurProc = CurProc_Return;
			return MenuOp.RetVal;
		}
	}
}


