#ifndef __KMY_PRINTERDRV_H
#define __KMY_PRINTERDRV_H



#define Printer_OK							1
#define Printer_NoPaper						2
#define Printer_TooHot						3
#define Printer_InitError					4
#define Printer_InitOK						5
#define Printer_15sNoResponse				6	//��ӡ�ַ���ʱ15s�ڴ�ӡ��δ����ȱֽ�����Ӧ



extern const unsigned char WidthZoom1[3];
extern const unsigned char WidthZoom2[3];
extern const unsigned char WidthZoom3[3];
extern const unsigned char WidthZoom4[3];
extern const unsigned char WidthZoom5[3];
//const unsigned char WidthZoom0[3]={"\x1B\x55\x00"};

extern const unsigned char HighZoom1[3];
extern const unsigned char HighZoom2[3];
extern const unsigned char HighZoom3[3];
extern const unsigned char HighZoom4[3];
extern const unsigned char HighZoom5[3];



unsigned char kmy_PrinterInit(void);
//�������ܣ���ӡ����ʼ��
//������������
//����ֵ��
//	��ʼ����������Printer_InitOK
//	��ʼ���쳣����Printer_InitError
//ע�������


char kmy_PrinterSetcommand(const unsigned char * command,unsigned char len);
//�������ܣ���ӡ����������
//����������
//	command:  �����ַ���
//	len: �����
//����ֵ��
//	���óɹ�����(�궨��)Printer_OK
//ע�������


char kmy_PrinterString(const unsigned char * ch);
//�������ܣ���ӡ����ӡ�ַ���
//����������
//	ch:  �ַ���
//����ֵ��
//	��ӡ��ɷ���(�궨��)Printer_OK
//	ȱֽ����(�궨��)Printer_NoPaper
//	��ӡͷ̫�ȷ���(�궨��)Printer_TooHot
//	15s δ�յ�ȱֽ�����Ӧ����(�궨��)Printer_15sNoResponse
//ע�����
//	1. ch�������ַ������Ⱦ���С��2048bytes



char kmy_PrinterBitmap(const unsigned char *p,unsigned int width, unsigned int height,unsigned int LeftMarginNum);
//�������ܣ���ӡ����ӡλͼ
//����������
//	p:  λͼ���ݻ������׵�ַ
//	width:  λͼ���
//	height:  λͼ�߶�
//	LeftMarginNum:  λͼ������ĵ㿪ʼ����
//����ֵ��
//	��ӡ��ɷ���(�궨��)Printer_OK
//	ȱֽ����(�궨��)Printer_NoPaper
//	��ӡͷ̫�ȷ���(�궨��)Printer_TooHot
//ע�����
//	λͼ��ʽΪ:��ɫ����Һ����ģ������ȡģ���ֽڵ���
//	LeftMarginNum+width��ֵӦ��С��384��
//	λͼ���Ŀ��Ϊ384



#endif
