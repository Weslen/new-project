#ifndef global_variable_H
#define global_variable_H



MyCallFuction	CurProc_Return;
MyCallFuction	CurProc;

char ShortcutKeyEnterFlag=0;				//快捷键进入标志
char InitFlag = 0x01;
char NoElecFlashLed;





//const unsigned char softwareversion[9]="20120309";


char RequirePin=0;
unsigned char gEnterPowerDownFlag=0;
unsigned char gFlashDataLED=0;

char ATsendreceive_Lock=0;
char gCheckOrderLock=0;
char gCheckOrderFail=0;
char GPRS_ONOFF=0;//GPRS_ONOFF=0 on; GPRS_ONOFF=1 off;
unsigned char gCountDown=0;
unsigned long gflagSeconds=0;

#endif

