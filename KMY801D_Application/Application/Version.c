#include "Version.h"
//#include "Stm32f10x.h"
#include "LCD.h"
#include "kmy_LCDDrv.h"
#include "key.h"
#include <stdio.h>
#include <string.h>


const char VersionString[] = "main_ver1.08.bin";//2013 10 23	 
const char VersionDate[] = __DATE__" "__TIME__;

char DisplayVersion (char *msg)
{
	char buff[60];
	char buffother[60];
	strcpy (  buff,  VersionString);
	strcpy (  buffother,  VersionString);
	clear_lcd();
	DrawTitle_to_row_Language2 (0, "终端机信息", "Machine Ver");
	text_out_to_row_Language2 (1, (unsigned char*)buff, (unsigned char*)buffother);
	text_out_to_row_Language2 (2,(unsigned char*)VersionDate,(unsigned char*)VersionDate);
	text_out_to_row_Language2 (3, "硬件版本:20100525", "HardVer:20100525");
	text_out_to_row_Language2 (4, "备注:KMY801D", "Mark:KMY801D");
	return (WaitkeyAndAutoExit (15) );
}




