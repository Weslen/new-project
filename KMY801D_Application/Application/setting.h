#ifndef Setting_H
#define Setting_H

#include "my_stdint.h"


#define STORESIZE			30		//if XStor  added entries, the STORESIZE  must added too
#define LocalNum 			8


struct storeFile{
	unsigned char *Viarable;		//Viarable
	const unsigned char *initVal;	//init value
};


extern struct storeFile XStor[STORESIZE+1];
extern struct storeFile LocalStore[LocalNum];

extern const unsigned char efile_Config[];
extern unsigned char dataledflag;
extern const unsigned char Configfile_des3key[25];



extern unsigned char LightPercent[4];				//light percent
extern unsigned char EnterAdvancedSetPassWord[22];	//∏ﬂº∂…Ë÷√√‹¬Î
extern unsigned char ServerIpPortBuf[28];			//ip µÿ÷∑220.162.237.128,65167
extern unsigned char SIM_PIN[5];					//PIN name
extern unsigned char UpgradeFlag[1+1];
extern unsigned char Domain[50+1];			
extern unsigned char ApnApn[50+1];
extern unsigned char ApnUsername[21+1];
extern unsigned char ApnPassword[21+1];
extern unsigned char beepKG[2];
extern unsigned char ScreenOffTimeout[3];			//PIN name
extern unsigned char TerminalID[17];				//÷’∂Àid
extern unsigned char TerminalPassword[17];			//÷’∂À√‹¬Î
extern unsigned char VersionURL[100+1];
extern unsigned char UpgradeURL[100+1];


/////////////////////the parameter is below is for canada orders
extern unsigned char RequestWebURL[150+1];
extern unsigned char CallbackURL[150+1];
extern unsigned char RejectReason[200+1];
extern unsigned char ResID[10+1];
extern unsigned char LoginWebUsername[20+1];
extern unsigned char LoginWebPassword[20+1];
extern unsigned char BeepDuration[2+1];
extern unsigned char AcceptTimeMode[1+1];
extern unsigned char CheckOrderInterval[3+1];
extern unsigned char GPRSOpenTime[5+1];
extern unsigned char GPRSCloseTime[5+1];
extern unsigned char PrintNewLineFlag[3+1];
extern unsigned char PrintDateFormat[1+1];
extern unsigned char PrintTimeFormat[1+1];
extern unsigned char PrintPageHeader[30+1];
extern unsigned char PrintPageFooter[30+1];
extern unsigned char PrintReceiptCount[1+1];
extern unsigned char AutoAcceptOrder[1+1];
extern unsigned char AcceptTimeOptions[100+1];
extern unsigned char Version[50+1];
extern unsigned char AutoReboot12Hours[2];
extern unsigned char AutoPrintString[25+1];



#define KMY_printer			'0'
#define JieNa_printer		'1'




char BasicSettings(char *msg);
char MainMenuScreen_Settings(char *msg);
unsigned char RestoreConfigFile(void);
unsigned char RestoreGlobalVariable(void);
unsigned char StorageVariable (void);

char PinSet(char *msg);
char SIM_PINset (char *msg);

void InitLocalSettings(void);

void StoreLocalSettings(void);

#endif

