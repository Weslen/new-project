#ifndef __KMY_GPRS_H
#define __KMY_GPRS_H



#define		fd_ttyS1	2


#define SendAtCommand_OK		0x01
#define SendAtCommand_ERROR		0x02


#define TCP_OK							0x10
#define TCP_RECEIVE_FAILUE				0x13
#define TCP_UserSelfReturn				0x14
#define TCP_NotINITIALState				0x15
#define TCP_CanNotSetCIPHEAD			0x16
#define TCP_SendAtTimeout				0x17
#define TCP_CONNECT_AND_RIGHT_RECEIVE	0x18
#define TCP_ErrorUnknow					0x19
#define TCP_XOR_FAILUE					0x20
#define TCP_ERROR						0x21
#define TCP_ERROR2						0x22
#define TCP_ERROR3						0x23


#define TCP_ConnectFailure				0x50
#define TCP_ConnectOK					0x51
#define TCP_SendFailure					0x52
#define TCP_SendOK						0x53
#define TCP_ReceiveBuffNotEnough		0x54
#define TCP_ReceiveMallocFailure		0x55
#define TCP_ReceiveTimeOut				0x56
#define TCP_ReceiveIPDHeadError			0x57
#define TCP_ReceiveOK					0x58



#define		GPRS_ReadTTY2				ReadDatasFromtty
#define		GPRS_ReadTTY2_GetOKstr		ReadDatasFromSIM300_OKstr
#define		GPRS_SendAtCmd				send_at_cmd
#define		GPRS_SendAtCmd_Receive 		send_at_cmd_and_receive
#define		GPRS_SendAtCmd_Return		send_at_cmd_and_return
#define		GPRS_SendAtCmd_NoReturn		send_at_cmd_and_return_NotResposeKey		
#define		GPRS_Connect				tcp_Connect
#define		GPRS_Send 					tcp_send
#define		GPRS_Receive				tcp_receive
#define		GPRS_DisConnect				tcp_DisConnect
#define		GPRS_PINandPUKTimes			ReadPINPUKTimes
#define		GPRS_PUK_Required			PUK_Required
#define		GPRS_GetIMEI				GetIMEI
#define		GPRS_GetCCID				GetCCID
#define		GPRS_SetAPN					set_apn










unsigned int ReadDatasFromtty(int fd,unsigned char *rcv_buf,unsigned int size,int sec,int usec);
void send_at_cmd(const unsigned char *cmd);
unsigned char SendAtCommand_UntillSuccess(unsigned char *cmd);
unsigned char send_at_cmd_and_receive(unsigned char * CmdBuff,int CmdBuffSize,int Ms,const unsigned char *OkStr);
unsigned char send_at_cmd_and_return(const unsigned char * cmd,int ms,const unsigned char *okstr,const unsigned char *errstr);
unsigned char send_at_cmd_and_return_NotResposeKey(const unsigned char * cmd,int ms,const unsigned char *okstr,const unsigned char *errstr);
unsigned char tcp_Connect(unsigned char *ipaddr);
unsigned char tcp_send(const unsigned char *buff,int len);
unsigned int tcp_receive(unsigned char *recBuff, unsigned int recBuffSize, unsigned short second, char *targetstring);

unsigned char tcp_receive_KMY(unsigned char *recBuff,unsigned int recBuffSize,unsigned short second);
void tcp_DisConnect(void);
unsigned char ReadPINPUKTimes(unsigned char PINTimes[2],unsigned char PUKTimes[3]);
void PUK_Required(void);
char GetIMEI(unsigned char *buff);
char GetCCID(unsigned char *buff);

unsigned int GetTotallen(unsigned char *p);
unsigned char ReadDatasFromSIM300_OKstr(unsigned char *rcv_buf,unsigned long size,unsigned long sec,unsigned char *OKstr);
char set_apn(void);



#endif

