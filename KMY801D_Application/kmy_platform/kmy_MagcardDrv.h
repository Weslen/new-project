#ifndef __KMY_MAGCARDDRV_H
#define __KMY_MAGCARDDRV_H



#define ReadMagCardReturnInit		0x02
#define ReadMagCardReturnPrev		0x03
#define ReadMagCardTimeOut			0x04
#define ReadMagCardDateError		0x05
#define ReadMagCardReturnEnter		0x06

#define ReadMagCardSuccess			0x0a





void my_BuffBitsExchange(unsigned char *buff, unsigned int Size);
void my_BuffHeadTailExchange(unsigned char *buff, unsigned int Size);
void my_BuffAllByteShiftBytes(unsigned char *buff,unsigned char Size,unsigned char ShiftSize);
void my_BuffAllByteShiftBits(unsigned char *buff,unsigned char Size,unsigned char Shiftbits);







void kmy_MagcardInit(void);
//�������ܣ���������ʼ��
//������������
//����ֵ����
//ע�������






char kmy_MagcardRead(unsigned char *track1,unsigned char *track2, unsigned char *track3, unsigned int timeout_Seconds);
//�������ܣ�������������
//����������
//	track1:	��1�ŵ�������
//	track2:	��2�ŵ�������
//	track3:	��3�ŵ�������
//����ֵ��
//	�����ɹ�����(�궨��)ReadMagCardSuccess
//	�û���EXIT ������(�궨��)ReadMagCardReturnInit
//	�û���Return������(�궨��)ReadMagCardReturnPrev
//	�û���Confirm ������(�궨��)ReadMagCardReturnEnter
//	��ʱ����(�궨��)ReadMagCardTimeOut
//	�����ݴ��󷵻�(�궨��)ReadMagCardDateError
//ע�����
//	1. ���е�Ӳ��û��track1�����������ΪNULL
//	2. �������Ҫ��track3�����԰�����β���ΪNULL,����track2 һ������ΪNULL
//	3. �ŵ�1 �ܹ�752λ�������������ŵ����Ҷ���track1Ӧ�ô���752*5=150+20=170bytes
//	4. �ŵ�2 �ܹ�300λ����track2 Ӧ�ô���300/5=60+10=70bytes
//	5. �ŵ�3 �ܹ�735λ����track2 Ӧ�ô���735/5=147+20=160bytes






#endif
