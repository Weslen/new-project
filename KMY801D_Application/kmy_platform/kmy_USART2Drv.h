#ifndef __KMY_USART2DRV_H
#define __KMY_USART2DRV_H


#define USART2MAXBUFFSIZE 3072

void kmy_USART2Init(unsigned long BaudRate);
//函数功能：串口初始化
//函数参数：brd: 波特率
//返回值：无
//注意事项：无




void kmy_USART2SendString(const unsigned char *Buff);
//函数功能： 发送字符串
//函数参数：
//	Buff: 发送字符串的buff
//返回值：无
//注意事项：无




void kmy_USART2SendData(const unsigned char *Buff, unsigned int SendSize);
//函数功能：  发送数据
//函数参数：
//	Buff:  发送数据的buff
//	SendSize:发送数据的长度
//返回值：无
//注意事项：无





void kmy_USART2ReceiveReset(void);
//函数功能： 把USART2已接受的所有字节丢弃
//函数参数：无
//返回值：无
//注意事项：无




unsigned int kmy_USART2ReceiveData(unsigned char *Buff,unsigned int RecSize,unsigned long timeout_MilliSeconds);
//函数功能： 接受串口的数据
//函数参数：
//	Buff: 接受数据存放的地方
//	RecSize: 接受多少个字节
//	timeout_MilliSeconds: 超时的毫秒数
//返回值：返回接受的总字节数
//注意事项：无


char kmy_USART2CheckBuff(char *ExpectString) ;
void kmy_USART2ShowBuff(void);
unsigned int kmy_USART2ReadToEnd(char *Buff, unsigned int BuffSize);

#endif

