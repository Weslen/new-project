#ifndef global_extern_variable_H
#define global_extern_variable_H

#include "main.h"

//#include "global_extern_variable.h"


extern MyCallFuction	CurProc_Return;
extern MyCallFuction	CurProc;


extern char InitFlag;
extern char NoElecFlashLed;
extern char ShortcutKeyEnterFlag;				//快捷键进入标志


//extern const unsigned char softwareversion[9];
extern char RequirePin;
extern unsigned char gEnterPowerDownFlag;
extern unsigned char gFlashDataLED;

extern char ATsendreceive_Lock;
extern char gCheckOrderLock;
extern char gCheckOrderFail;
extern char GPRS_ONOFF;//GPRS_ONOFF=0 on; GPRS_ONOFF=1 off;
extern unsigned char gCountDown;
extern unsigned long gflagSeconds;

#endif

