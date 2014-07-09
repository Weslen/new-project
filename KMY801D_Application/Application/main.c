
#include "main.h"

#include "stm32f10x.h"
//#include "stm32_eval.h"
#include "stm32f10x_flash.h"
#include "stm32f10x_rcc.h"

#include "kmy_LCDDrv.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "MenuOperate.h"
#include "lcd.h"
#include "key.h"
#include "SelfTest.h"
#include "kmy_LEDDrv.h"
#include "kmy_BeepDrv.h"
#include "kmy_Time.h"
#include "kmy_FlashDrv.h"
#include "kmy_EEPROMDrv.h"
#include "kmy_MagcardDrv.h"
#include "kmy_USART1Drv.h"
#include "kmy_USART2Drv.h"
#include "kmy_USART3Drv.h"
#include "kmy_PrinterDrv.h"
#include "kmy_TamperDrv.h"
#include "kmy_Misc.h"
#include "kmy_BattaryDrv.h"
#include "kmy_GprsDrv.h"
#include "kmy_WatchDogDrv.h"

#include "gprs.h"
#include "SelfTest.h"
#include "global_variable.h"
#include "setting.h"
//#include "Transaction.h"
#include "Tool.h"
//#include "CallRecord.h"
#include "EepromFileSystem.h"
#include "mypure_library.h"
#include "message.h"
#include "FoodOrder.h"
#include "Version.h"
#include "ShuRuFa.h"



#define InitSimModule
extern char LcdBlackLightFlash;


const unsigned char PoweronLogo[] =
{
	/*------------------------------------------------------------------------------
	;  Դ�ļ� / ���� : F:\KMY\FoodOrder Project\KMY801D FoodOrder_Australia_Anthony Daisy\�Ĵ���������Ҫ��\poweron.BMP��ģ
	;  ����ߣ����أ�: 128��64
	------------------------------------------------------------------------------*/
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x80,0xC0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0xC0,0xE0,0xE0,0xF0,
	0xF0,0xF8,0x78,0x78,0x78,0x70,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xC0,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFC,0x7E,0x1F,
	0x07,0x03,0x03,0xC3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xE0,0xF8,0x7C,0xFE,0xFE,
	0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF0,0xF8,
	0x78,0x78,0xF8,0xF0,0xE0,0x00,0x00,0x00,0x00,0xC0,0xE0,0xF8,0xFC,0xFC,0xFE,0xFE,
	0x1C,0xC0,0xE0,0xE0,0xE0,0xE0,0x00,0xF8,0xFE,0xFF,0xFF,0xFF,0x7F,0x1F,0x80,0x80,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE3,0xC1,
	0xC4,0xDE,0xDE,0xDC,0xDC,0xDC,0x0F,0x0F,0x07,0x00,0x00,0x00,0x00,0x80,0x80,0x80,
	0x80,0x80,0x80,0xE0,0xF0,0xF0,0xF0,0xE0,0x00,0x00,0x00,0x00,0x60,0xF0,0xF0,0xFC,
	0xFF,0xFF,0xFF,0xFF,0x3F,0x3B,0x38,0x38,0x00,0x00,0x00,0x7F,0xFF,0xFF,0x80,0x00,
	0x00,0xF0,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x0F,0x03,0x01,0xE0,0xFC,0xFF,0xFF,
	0xFF,0xFF,0xFF,0x0F,0x01,0xC0,0xE0,0xF8,0xFC,0xFF,0xFF,0xFF,0xFF,0x1F,0x03,0xF8,
	0xF8,0xFC,0xFF,0xFF,0xFF,0xE0,0x78,0x3E,0xDF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC1,
	0xFC,0xFF,0xFF,0xFF,0xCF,0xC3,0xE0,0xFF,0x7F,0x3F,0x1F,0x1F,0x1E,0x0F,0x07,0x01,
	0x00,0x00,0x80,0xE0,0xF0,0xF8,0xFC,0xFE,0xFE,0xFF,0x7F,0x1F,0x0F,0x87,0xC3,0xE7,
	0xE7,0x77,0x77,0xE3,0xE3,0xC1,0x80,0xC0,0xF0,0xFC,0xFE,0xFF,0xFF,0xFF,0x3F,0x0F,
	0x87,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x07,0xC0,0xE0,0xF8,0xFC,0xFF,0xFF,0xFF,0xFF,
	0xFF,0x7F,0x07,0xC0,0xE0,0xF0,0x70,0x30,0x00,0x00,0x00,0x00,0x01,0x07,0xC7,0xFE,
	0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x38,0x1C,0x0C,0x00,0xFE,0xFF,0xFF,0xFF,0xFF,
	0xFF,0xFF,0x78,0x3C,0x1F,0x07,0x07,0x1F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3E,0x1E,0x1F,
	0x0F,0x07,0x01,0x01,0x81,0x80,0xC0,0xC0,0x03,0x07,0x07,0xC7,0xE7,0x07,0x07,0xC3,
	0xE1,0x01,0x03,0x03,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE1,0xC0,0x80,0x00,0x0F,0x0F,0x03,
	0x80,0x80,0xC0,0xF0,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0x78,0x3C,0xFF,
	0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x1E,0x0F,0x07,0x03,0x0C,0x1F,0x3F,0x3F,0x3F,0x3F,
	0x1F,0x0F,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,
	0x07,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF9,0xF9,0x8D,0x99,
	0x40,0x78,0xCC,0xE6,0x7E,0x1C,0xF0,0x7E,0x0E,0x7C,0x7E,0x07,0x3F,0x30,0x18,0x00,
	0x30,0x30,0x00,0x0E,0x1F,0x19,0x0C,0x1F,0x08,0x04,0x07,0x0F,0x09,0x04,0x02,0x0F,
	0x09,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x03,0x07,0x07,0x0F,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x0F,0x0F,
	0x0F,0x07,0x07,0x03,0x00,0x00,0x01,0x01,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x01,0x01,0x01,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

};


const unsigned char logo[] =
{
	/*------------------------------------------------------------------------------
	;  Դ�ļ� / ���� : C:\Users\ThinkPad\Desktop\δ����-1.bmp��ģ
	;  ����ߣ����أ�: 52��18
	------------------------------------------------------------------------------*/
	0x00,0x00,0x00,0xC0,0xE0,0xF0,0xB0,0x10,0x50,0x70,0x20,0x00,0x00,0x00,0x00,0x80,
	0x00,0x00,0x80,0x80,0xE0,0xE0,0x80,0x00,0xC0,0x38,0x0C,0xC6,0xFE,0x3C,0x30,0xF8,
	0xFC,0xFC,0x08,0x80,0xE0,0x70,0x30,0x90,0xF0,0xC0,0x70,0xF8,0xF8,0x80,0xF0,0x80,
	0xF8,0xF8,0x40,0x00,0x00,0x60,0xF8,0xFC,0x9F,0x87,0x83,0x93,0xCB,0x78,0x30,0x7C,
	0x66,0x23,0x7F,0x7F,0x21,0x38,0x3E,0x37,0x31,0x18,0x0C,0x00,0x01,0x32,0x3E,0x1F,
	0x07,0x04,0x04,0x1F,0x1F,0x0F,0x01,0x07,0x0F,0x0E,0x07,0x03,0x01,0x00,0x00,0x01,
	0x03,0x01,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

void SystemReset(void)
{
	NVIC_SystemReset();
}

//The Lib call this function one milisecond inerval
void OneMiliSecondCallThread (void)
{
	static unsigned int cnt;
	static unsigned char dataledcnt;
	static unsigned char lcdcnt=0;
	
	cnt++;

	if (gFlashDataLED == 1)
	{
		if (cnt % 60 == 0)
		{
			dataledcnt++;

			if (dataledcnt % 2 == 0) kmy_LedDataLedOn();
			else kmy_LedDataLedOff();
		}
	}
	else if (gFlashDataLED == 0)
	{
		kmy_LedDataLedOff();
		gFlashDataLED = 2;
	}
	if (cnt % 60 == 0)kmy_WatchDogResetCounter();
	if(LcdBlackLightFlash==1)// for LCD flash
	{
		if(cnt%1000==0)
		{
			lcdcnt++;
			if(lcdcnt%2==0)
			{
				kmy_LcdBlackLightOn();
			}
			else
			{
				kmy_LcdBlackLightOff();
			}
		}	
	}	
}



char MainMenuScreen (char *msg)
{
	const static struct MenuFuc_Language2 Menu[1] =
	{
		//{"0.Latest Orders", "0.Latest Orders", Latest_Orders},		
		//{"2.Confirm Orders", "2.Confirm Orders", Confirm_Orders},
		//{"3.Reject Orders", "3.Reject Orders", Reject_Orders},
		{"1.Recent Orders", "1.Recent Orders", Confirm_Orders},		
	};
	struct MenuOperate_Language2 MenuOp = { (struct MenuFuc_Language2*) Menu, 1, 0, 0, 0, MaxRowOneScr, 1, 0, 0};



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

/*

char MainMenuScreen (char *msg)
{
	const static struct MenuFuc_Language2 Menu[5] =
	{
		{"1.GPRS ����", "1.GPRS Test", SelfTest_GPRS},
		{"2.�绰��¼", "2.CallRecords", MainMenuScreen_Calls},
		{"3.�ն�����", "3.Settings", MainMenuScreen_Settings},
		{"4.Ӧ�ù���", "4.Toolbox", MainMenuScreen_ToolBox},
		{"5.Ӳ���Բ�", "5.SelfTest", SelfTest},
	};
	struct MenuOperate_Language2 MenuOp = { (struct MenuFuc_Language2*) Menu, 5, 0, 0, 0, MaxRowOneScr, 1, 0, 0};

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
*/

static char ProcStandbyKey (char *msg);
extern char SelfTest_Soft (char*);
static void StandbyResponseUserMenu (unsigned char keyval)
{
	switch (keyval)
	{
		case KEY0:
			break;

		case KEY1:	

			break;

		case KEY2:		
			break;

		case KEY3:		
			break;

		case KEY4:		
			break;

		case KEY5:		
			break;

		case KEY6:		
			break;

		case KEY7:	
			break;

		case KEY8:	

			break;

		case KEY9:	

			break;

		case KEYJING:
		
			break;

		case KEYXING:		

			break;
		case KEY_UP:
		case KEY_DOWN:
			Confirm_Orders(NULL);
			
			InitFlag = 1;
			break;

		case KEY_Enter:	
			CurProc = MainMenuScreen;
			CurProc_Return = ProcStandbyKey;
			InitFlag = 1;
			ShortcutKeyEnterFlag = 1;
			break;

		case KEY_R2:

			break;

		case KEY_R3:
			CurProc = MainMenuScreen_Settings;
			CurProc_Return = ProcStandbyKey;
			InitFlag = 1;
			ShortcutKeyEnterFlag = 1;
			break;

		case KEY_R4:
			CurProc = SelfTest;
			CurProc_Return = ProcStandbyKey;
			InitFlag = 1;
			ShortcutKeyEnterFlag = 1;
			break;
		case KEY_R5:
			ReprintLastOrder();
			InitFlag = 1;
			break;
		default:
			break;
	}
}


static void DisplayHourMinuteSecond (unsigned long second)
{
	unsigned long temp;
	unsigned char buff[4];

	temp = second % (24 * 60 * 60);
	temp = temp / (60 * 60);
	sprintf ( (char *) buff, "%02d:", temp);
	text_out (8, 18, buff);

	temp = second % (60 * 60);
	temp = temp / 60;
	sprintf ( (char *) buff, "%02d:", temp);
	text_out (3 * 6 + 8, 18, buff);

	temp = second % 60;
	sprintf ( (char *) buff, "%02d", temp);
	text_out (6 * 6 + 8, 18, buff);
}


static void DisplayYearMothDayWeek (unsigned long second)
{
	unsigned char Buf[20];

	const unsigned char NumData[7][5] =  		// width*height(pixel): 4��5
	{
		{0x1F, 0x15, 0x1F, 0x00},	//  0
		{0x00, 0x00, 0x1F, 0x00},	//  1
		{0x1D, 0x15, 0x17, 0x00},	//  2
		{0x15, 0x15, 0x1F, 0x00},  	//  3
		{0x07, 0x04, 0x1F, 0x00},  	//  4
		{0x17, 0x15, 0x1D, 0x00},  	//  5
		{0x1F, 0x15, 0x1D, 0x00}   	//  6
	};

	unsigned int year;
	unsigned char mon;
	unsigned char day;
	unsigned char weekday;

	memset (Buf, 0, sizeof (Buf) );		
	kmy_TimeGetTime (&year, &mon, &day, NULL, NULL, NULL, &weekday);
	sprintf ( (char *) Buf, "%04d-%02d-%02d", year, mon, day);
	text_out (0, 34, Buf);
	draw_pic (NumData[weekday], 61, 35, 4, 5);
}

const unsigned char CSPNs[5][15] = {"������������", "�й��ƶ�", "�й���ͨ", "�й�����", "��������"};
static const unsigned char* GetNetName (unsigned char *netname)
{
	if (strstr ( (const char *) netname, "CHINA MOBILE") != NULL)  			
	{
		return CSPNs[1];
	}
	else if (strstr ( (const char *) netname, "UNICOM") != NULL)  	
	{
		return CSPNs[2];
	}
	else if (strstr ( (const char *) netname, "CHINA TELECOM") != NULL)  	
	{
		return CSPNs[3];
	}
	else if (strstr ( (const char *) netname, "\"") != NULL)  	
	{
		return CSPNs[4];
	}
	else
	{
		return CSPNs[0];
	}
}



const unsigned char pstr[5][24] =
{

	{0xF0, 0xFC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xFC, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03},
	{0xF0, 0xFC, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0xF4, 0x04, 0xFC, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03},
	{0xF0, 0xFC, 0x04, 0x04, 0x04, 0x04, 0x04, 0xF4, 0x04, 0xF4, 0x04, 0xFC, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03},
	{0xF0, 0xFC, 0x04, 0x04, 0x04, 0xF4, 0x04, 0xF4, 0x04, 0xF4, 0x04, 0xFC, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03},
	{0xF0, 0xFC, 0x04, 0xF4, 0x04, 0xF4, 0x04, 0xF4, 0x04, 0xF4, 0x04, 0xFC, 0x00, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03}
};

static void DisplayElectricity (int temp)
{
	if (temp < 6500) temp = 0;
	else if (temp >= 6500 && temp < 7000) temp = 1;
	else if (temp >= 7000 && temp < 7500) temp = 2;
	else if (temp >= 7500 && temp < 8000) temp = 3;
	else temp = 4;

	draw_pic (pstr[temp], 116, 0, 12, 12);
}


static void DisplayPleaseCharge (void)
{
	static char timecnt;
	unsigned char keyval;

	timecnt++;

	if (timecnt > 55 / 5)
	{
		timecnt = 0;
		clear_lcd();
		DrawTitle_to_row_Language2 (2, "�������㣬����", "Please Charge");

		KeyIsResponse();

		while (1)
		{
			keyval = GetKeyValue();

			if (keyval != KEY_NONE) break;
		}

		InitFlag = 1;
	}
}

static void DisplaySignalQuality (int temp)
{
	const unsigned char pstr[6][24] =
	{
		{0x06, 0x0A, 0x3E, 0x0A, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x06, 0x0A, 0x3E, 0x8A, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x06, 0x0A, 0x3E, 0x8A, 0x06, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{0x06, 0x0A, 0x3E, 0x8A, 0x06, 0xE0, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00},
		{0x06, 0x0A, 0x3E, 0x8A, 0x06, 0xE0, 0x00, 0xF0, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x02, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00},
		{0x06, 0x0A, 0x3E, 0x8A, 0x06, 0xE0, 0x00, 0xF0, 0x00, 0xFC, 0x00, 0xFF, 0x00, 0x02, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03}
	};

	if (temp > 32)
	{
		temp = 0;
	}
	else
	{
		temp /= 5;

		if (temp > 5) temp = 5;
	}

	draw_pic (pstr[temp], 0, 0, 12, 12);
}


void UpgradeSignalQuality (void)
{
	unsigned char Buf[100];
	char *p;
	unsigned char retval;

	static int SignalQuality;

	if(ATsendreceive_Lock==1)
	{
		DisplaySignalQuality (SignalQuality);
		return;
	}
	else
	{
		kmy_EnableDisableTime3(0);
			
		strcpy ( (char*) Buf, "AT+CSQ\r");	//check signal quality
		retval = send_at_cmd_and_receive (Buf, sizeof (Buf) - 3, 100, "OK");
	
		if (retval == TCP_OK)
		{
			//printf("Signal ok\r\n");
			p = strstr ( (char *) Buf, "+CSQ: ");
	
			if (p != NULL)
			{
				SignalQuality = atoi (p + sizeof ("+CSQ: ") - 1);
				DisplaySignalQuality (SignalQuality);
			}
		}
		else
		{
			//printf("Signal no ok\r\n");
		}
		
		kmy_EnableDisableTime3(1);
	}
	
}


static void DisplayChargeElectricity (void)
{
	static unsigned char cnt;

	cnt++;

	if (cnt > 4) cnt = 0;

	draw_pic (pstr[cnt], 116, 0, 12, 12);
}

static u8 chargeflag;
void UpgradeElectricity (void)
{
	unsigned char Buf[100];
	char *p;
	char HaveAcPowerFlag = 0;
	unsigned char retval;

	static int Electricity;
	static unsigned char AcNewIn;

	if(ATsendreceive_Lock==0)
	{
		kmy_EnableDisableTime3(0);
		strcpy ( (char*) Buf, "AT+QADC?\r");	//check electricity
		retval = send_at_cmd_and_receive (Buf, sizeof (Buf) - 3, 100, "OK");
	
		if (retval == TCP_OK)
		{
	//		printf ("%s\r\n", Buf);
			p = strstr ( (char *) Buf, "+QADC:");	//+QADC:1,2088
	
			if (p != NULL)
			{
				p = strstr (p, ",");
	
				if (p != NULL)
				{
					p++;
					Electricity = atoi (p);
					Electricity *= 4;
				}
			}
		}
		else
		{
			printf ("AT+QADC no ok\r\n");
		}
		
		kmy_EnableDisableTime3(1);
	}
	HaveAcPowerFlag = kmy_BatGetACStatus(); //check if get AC power source

	if (HaveAcPowerFlag == AcStatus_Plug)	//HaveAcPowerFlag!=0 already insert AC power source
	{
	//	printf("check Electricity=%d\r\n",Electricity);
		if (Electricity < 8280) 			//display charging icon
		{
			if (Electricity > 1200)
			{
				if (kmy_BatGetChargeStatus() == ChargeStatus_Charge)
				{
					chargeflag = 1;
				}
				else
				{
					chargeflag = 0;
				}
			}
			else
			{
				//if voltage<1200mv, then do not display charging icon
				// because it maybe no battery, or other problems
				chargeflag = 0;
			}
		}
		else
		{
			if (Electricity >= 8340 && AcNewIn == 1)
			{
				AcNewIn = 0;
				clear_lcd();
				DrawTitle_to_row_Language2 (2, "��ص����ѳ���", "Electricity Full");
				WaitkeyAndAutoExit (2000);
				InitFlag = 1;
			}

			DisplayElectricity (Electricity);
			chargeflag = 0;
		}
	}
	else	
	{
		if (Electricity > 6700) 			//display battery quantity
		{
			DisplayElectricity (Electricity);
		}
		else			//battery not power enough,prompt please charge 
		{
			DisplayPleaseCharge();
			DisplayElectricity (Electricity);
		}

		AcNewIn = 1;
		chargeflag = 0;
	}
}


void UpgradeCSPN (void)
{
	unsigned char Buf[100];
	unsigned char retval;
	char *p;
	const unsigned char *p2;
	static unsigned char CSPNbuf[20]={0};
	//static unsigned char Buf

	if(ATsendreceive_Lock==1)
	{
		DrawTitle_to_row_Language2 (0, CSPNbuf, CSPNbuf);
		return;
	}
	else
	{
		kmy_EnableDisableTime3(0);

		strcpy ( (char*) Buf, "AT+COPS?\r");
		retval = send_at_cmd_and_receive (Buf, sizeof (Buf) - 3, 100, "OK");

		if (retval == TCP_OK)
		{
			//+COPS: 0,0,"CHINA MOBILE"
			p = strstr ( (const char *) Buf, "COPS");

			if (p != NULL)
			{
				p = strstr ( (const char *) p, "\"");

				if (p != NULL)
				{
					p++;
					my_strcpy_EncounterHexEnd (Buf, (unsigned char*) p, 16, '\"');
				}
				else
				{
					strcpy ( (char *) Buf, "Searching net");
				}
			}
			else
			{
				strcpy ( (char *) Buf, "Searching net");
			}

			clear_area (20, 0, 84, 12);
			p2 = GetNetName (Buf);
			strcpy((char*)CSPNbuf,(char*)Buf);
			DrawTitle_to_row_Language2 (0, p2, Buf);
		}
		else
		{
			//printf("CSPN no ok\r\n");
		}	
		kmy_EnableDisableTime3(1);
	}
}

static char GetVersion(char *versionbuf)
{
	char *p;
	char *pt;
	
	p=(char*)VersionString;
	p=strstr(p,"ver");
	if(p!=NULL)
	{
		pt=p;
		pt=strstr(pt,".bin");
		if(p!=NULL)
		{
			strncpy(versionbuf,p,pt-p);
			return 0;
		}
	}
	return 1;
}


static char ProcStandbyKey (char *msg)
{
	unsigned char keyval;
	unsigned long cnt;
	static unsigned long PrevSeconds;
	static unsigned char powerdowntimecnt = 0;
	char retval=0;
	char Version[10]={0};
	
	if (InitFlag)  		// call the inintial menu first time
	{
		InitFlag = 0;	// put the flag here
		clear_lcd();
		PrevSeconds = kmy_TimeGetRtcSeconds();		// update date and time
		DisplayHourMinuteSecond (PrevSeconds);
		DisplayYearMothDayWeek (PrevSeconds);

		UpgradeSignalQuality();	//update signal quality
		UpgradeElectricity();	//update electricity quantity

		if (chargeflag) DisplayChargeElectricity();

		UpgradeCSPN();			//display CPSN

		draw_pic (logo, 74, 20, 52, 18);	

		if(gCountDown!=0)
		{
			text_out_to_row_Language2 (4, "Auto print mode", "Auto print mode");
		}
		else
		{
			text_out_to_row_Language2 (4, "Welcome to EatNow", "Welcome to EatNow");
		}

		powerdowntimecnt = 0;
	}
	else
	{
		cnt = kmy_TimeGetRtcSeconds();			//Update date and time

		if (PrevSeconds != cnt)
		{
			PrevSeconds = cnt;
			DisplayHourMinuteSecond (PrevSeconds);
			DisplayYearMothDayWeek (PrevSeconds);

			if (chargeflag) DisplayChargeElectricity();

			cnt = PrevSeconds % 5;

			if (cnt == 0)
			{
				UpgradeCSPN();			//update CSPN such as China mobile or unicom
			}
			else if (cnt == 1)
			{
				UpgradeElectricity();
			}
			else if (cnt == 2)
			{
				UpgradeSignalQuality(); 		
			}
			else if (cnt == 3)
			{						
				if(CheckOrderFailWarn()==0)
				{		
					retval=HaveReceiveOrder(1);
					
					if(retval==KEY_Enter)
					{
						//if(AutoAcceptOrder[0]=='1')
						//{
							AutoPrintOrder();
							CurProc= ProcStandbyKey;
							InitFlag = 1;	
						/*}
						else
						{
							retval=HaveReceiveOrder(0);
							
							if(retval==KEY_Enter)
							{
								Latest_Orders(NULL);			
								CurProc= ProcStandbyKey;
								InitFlag = 1;	
							}
						}
						*/
					}
					
						
						
					if(retval!=0)
					{
						InitFlag=1;
					}
				}
				else
				{
					InitFlag=1;
				}
			}
			else
			{	
				kmy_GPRSTimeSet(0);
			}
			if(AutoReboot12Hours[0]=='1')
			{
				if(gflagSeconds!=0)
				{
					if(kmy_TimeGetRtcSeconds()-gflagSeconds>43200)//43200= 12 hours
					{					
						NVIC_SystemReset();
					}
				}
			}

			powerdowntimecnt++;

		//	if (powerdowntimecnt > 30) gEnterPowerDownFlag = 1;
		}
	}
	if(GetVersion(Version)==0)text_out(74, 40,(unsigned char*)Version);
	keyval = GetKeyValue();

	if (keyval == KEY_NONE || keyval == KEY_WaitTimeout) return KEY_NONE;
	if (beepKG[0] == '1')
	{			
		BeepNormal();
	}
	powerdowntimecnt = 0;
	kmy_LcdBlackLightOn();
	kmy_AutoOffLcdLight (10);
	kmy_AutoPostKey (10);
	StandbyResponseUserMenu (keyval);

	KeyIsResponse();
	return KEY_NONE;
}

unsigned char ApplicationInit (void)
{
	u8 retval;

	kmy_RCCInit();

	kmy_USART1Init (115200);	//put this initial here in case other function use printf(); sentence

	kmy_LedInit();

	kmy_LcdInit();
	kmy_LcdBlackLightOn();
	kmy_LcdClear();
	kmy_LcdDrawBitMap (PoweronLogo, 0, 0, 128, 64);
	
	kmy_KeyInit();

	kmy_BeepInit();

	kmy_TimeInit();

	kmy_FlashInit();

	kmy_EepromInit();
	
	InitLocalSettings();

	//if it is an empty chip,then format the eeprom
	if (kmy_EepromCheckWhetherBlackChip() == 1)
	{
		EepromFile_FileSystemFormat();		
	}
	
	kmy_MagcardInit();

	kmy_MiscInit();

	kmy_BatInit();
	kmy_WatchDogInit();

#ifdef InitSimModule
	kmy_GprsInit();
#endif

	msleep (1000);

	if (kmy_PrinterInit() != Printer_InitOK)
	{
		clear_lcd();
		DrawTitle_to_row (2, "Printer init error");
		WaitkeyAndAutoExit (100);
	}

	retval = EepromFile_CheckFileExist ((unsigned char*)efile_Config);

	if (retval == EepromFile_FileNameToLong)
	{
		clear_lcd();
		DrawTitle_to_row_Language2 (2, "�����ļ���̫��", "FileName too long");
	}
	else if (retval == EepromFile_HaveThisFile)
	{
		retval = RestoreGlobalVariable();

		if (retval != 1)
		{
			clear_lcd();
		//	DrawTitle_to_row_Language2 (2, "�ָ�ȫ�ֱ���ʧ��", "Restore Variable");
			printf("Restore Variable reset\r\n");
			EepromFile_FileSystemFormat();
			RestoreConfigFile();
			NVIC_SystemReset();
			//WaitkeyAndAutoExit (10);
		}
	}
	else if (retval == EepromFile_HaveNotThisFile)
	{
		EepromFile_FileSystemFormat();
		retval = RestoreConfigFile();
		printf("Restore Variable reset\r\n");
		NVIC_SystemReset();

	//	if (retval != 1)
	//	{
	//		clear_lcd();
			//DrawTitle_to_row_Language2 (2, "�ָ������ļ�ʧ��", "Restore File Fail");
		//	WaitkeyAndAutoExit (10);
		//}
	}

	set_contrast (atoi ( (const char*)LightPercent) );
	kmy_BackUpInit();

	
	Sim900B_init();

	return 1;
}



void DestroyFunc (void)
{
	unsigned char secretkey[6] = {0}; 	//decode the secretkey
	//unsigned char secretflag[2]={0xa5,0x3c};
	unsigned char temp;
	unsigned char count = 0;
	unsigned int retval;

	clear_lcd();
	DrawTitle_to_row_Language2 (2, "�Ƿ����", "Illegal open");
	DrawTitle_to_row_Language2 (3, "оƬ���Ի�", "Chip destroied");

	while (1)
	{
		retval = kmy_GetKeyValue();

		if (retval == KEY_NONE) continue;

		if (beepKG[0] == '1')
		{			
			BeepNormal();
		}

		switch (retval)
		{
			case KEY1 :
				temp = '1';
				printf ("key is 1 \r\n");
				break;

			case KEY2 :
				temp = '2';
				printf ("key is 2 \r\n");
				break;

			case KEY3 :
				temp = '3';
				printf ("key is 3 \r\n");
				break;

			case KEY4 :
				temp = '4';
				printf ("key is 4 \r\n");
				break;

			case KEY5 :
				temp = '5';
				printf ("key is 5 \r\n");
				break;

			case KEY6 :
				temp = '6';
				printf ("key is 6 \r\n");
				break;

			case KEY7 :
				temp = '7';
				printf ("key is 7 \r\n");
				break;

			case KEY8 :
				temp = '8';
				printf ("key is 8 \r\n");
				break;

			case KEY9 :
				temp = '9';
				printf ("key is 9 \r\n");
				break;

			case KEY0 :
				temp = '0';
				printf ("key is 0 \r\n");
				break;

			case KEYJING :
				temp = '#';
				printf ("key is JING \r\n");
				break;

			case KEYXING :
				memset (secretkey, 0, sizeof (secretkey) );
				count = 0;
				printf ("key is XING \r\n");
				continue;

			default:
				break;
		}

		if (count < sizeof (secretkey) - 1)
		{
			secretkey[count] = temp;
			count++;

			if (strcmp ( (const char *) secretkey, "#123#") == 0)
			{
				kmy_ClearTamper();
				printf ("unlock!!!\r\n");
				return;
			}
		}
		else
		{
			memset (secretkey, 0, sizeof (secretkey) );
			count = 0;
		}
	}
}



#if 1
int main (void)
{
	ApplicationInit();
	kmy_LcdBlackLightOn();
	kmy_AutoOffLcdLight (20);
	
	kmy_GPRSTimeSet(1);

	printf ("fixdate=2013-11-1 2st\r\n");
	CurProc = ProcStandbyKey;

	while (1)
	{
		CurProc (NULL);

		/*if (kmy_CheckTamper() == TAMPER_TRIGGERED)
		{
			DestroyFunc();
			InitFlag = 1;
		}
		else
		*/if (gEnterPowerDownFlag == 1)
		{
//			kmy_EnterPowerDownMode();
			gEnterPowerDownFlag = 0;
			InitFlag = 1;
			kmy_LcdBlackLightOn();
		}
	}
}
#endif

#if 0
#include "Chinese.h"
int main (void)
{
	kmy_RCCInit();

	kmy_LedInit();

	kmy_LcdInit();
	kmy_LcdBlackLightOn();
	kmy_LcdClear();
	kmy_LcdDrawBitMap (templogo, 0, 0, 128, 64);

	kmy_KeyInit();
	kmy_BeepInit();

	kmy_TimeInit();

	kmy_USART1Init (115200);

	kmy_FlashInit();
	//kmy_FlashTest();

	kmy_EepromInit();
	kmy_Eepromtest();

	clear_lcd();
	DrawTitle_to_row (2, "upgrading chinese");

	kmy_FlashEraseBulk();

	kmy_FlashWriteBuffer (chinese_12x12, 0L, 60000);
	kmy_FlashWriteBuffer (&chinese_12x12[60000], 0L + 60000, 32160);

	DrawTitle_to_row (3, "complete");

	while (1)
	{
	}
}
#endif

#if 0
#include "Chinese2.h"
int main (void)
{
	kmy_RCCInit();

	kmy_LedInit();

	kmy_LcdInit();
	kmy_LcdBlackLightOn();
	kmy_LcdClear();
	kmy_LcdDrawBitMap (templogo, 0, 0, 128, 64);

	kmy_KeyInit();
	kmy_BeepInit();

	kmy_TimeInit();

	kmy_USART1Init (115200);

	kmy_FlashInit();

	clear_lcd();
	DrawTitle_to_row (2, "upgrading chinese2");
	kmy_FlashWriteBuffer (chinese_12x12, 0L + 60000 + 32160, 60000);
	kmy_FlashWriteBuffer (&chinese_12x12[60000], 0L + 0L + 60000 + 32160 + 60000, 30576);

	DrawTitle_to_row (3, "complete");

	while (1)
	{
	}
}
#endif


#if 0
int main (void)
{
	NVIC_Configuration();

	/* Enable PWR and BKP clock */
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

	/* Enable write access to Backup domain */
	PWR_BackupAccessCmd (ENABLE);

	/* Disable Tamper pin */
	BKP_TamperPinCmd (DISABLE);

	/* Disable Tamper interrupt */
	BKP_ITConfig (DISABLE);

	/* Tamper pin active on low level */
	BKP_TamperPinLevelConfig (BKP_TamperPinLevel_Low);

	/* Clear Tamper pin Event(TE) pending flag */
	BKP_ClearFlag();

	/* Enable Tamper interrupt */
	BKP_ITConfig (ENABLE);

	/* Enable Tamper pin */
	BKP_TamperPinCmd (ENABLE);

	/* Write data to Backup DRx registers */
	WriteToBackupReg (0xA53C);

	/* Check if the written data are correct */
	if (CheckBackupReg (0xA53C) == 0x00)
	{
	}
	else
	{
	}

	while (1)
	{
	}
}
#endif

