#ifndef Lcd_H
#define Lcd_H



#include "kmy_LCDDrv.h"



#define MaxRowOneScr 		5		//the total rows of one screen
#define EditAreaTotalRow	2		//edit area total rows
#define EditAreaStartLine	1		//edit area start row, 1  represents the second row
//#define ALineNum			18		//edit area a row of the numbers of asccii byte.
#define ALineNum			20		//edit area a row of the numbers of asccii byte.
#define MaxByteOneLine 		23		//a row total bytes
#define ALinePixNum			131		//a row total pixels
#define AAscciiPixNum		6		//a Asccii  cod contain pixels
#define AGB2312PixNum		12		//a chinese character contain pixels
#define ALineContainDotLine	13		//a line contian How many dot line



#define	OTHER_LANGUAGE	'1'
#define	LOCAL_LANGUAGE	'0'


extern unsigned char Language[2];					//”Ô—‘



#define  Lcd_Write_nByte				text_out_length
#define	 Lcd_WriteRow				text_out_to_row
#define	 Lcd_WriteRow_Language2		text_out_to_row_Language2
#define	 Lcd_WriteRow_x  			text_out_to_row_x
#define	 Lcd_WriteRow_x_Language2 	text_out_to_row_x_Language2
#define	 Lcd_WriteRow_fillSpace 		text_out_to_row_fillSpace
#define	 Lcd_WriteRow_x_fillSpace	text_out_to_row_x_fillSpace
#define  Lcd_WriteTitle 				DrawTitle_to_row
#define  Lcd_WriteTitle_Language2 	DrawTitle_to_row_Language2
#define  Lcd_ClearRow 				clear_area_to_row
#define  Lcd_ReverseRow 				reverse_area_to_row
#define  Lcd_DHighLightRow_x			DispHighLightRow_to_x
#define  Lcd_HighLightRow_x_width   DispHighLightRow_to_x_width
#define  Lcd_HighLightRow			DispHighLightRow
#define  Lcd_DrawPic					draw_pic
#define  Lcd_DrawLineRow				draw_line_to_row
#define  Lcd_DrawLine				draw_line
#define  Lcd_DrawRect				draw_rect
#define  Lcd_FillRect				fill_rect
#define  Lcd_ReverseArea				reverse_area
#define  Lcd_ClearArea				clear_area
#define  Lcd_SetContrast				set_contrast









#define text_out	kmy_LcdTextOut
#define clear_lcd	kmy_LcdClear
//#define draw_pic	kmy_LcdDrawBitMap


void text_out_length(char x,char y,const unsigned char *buff,unsigned char length);
void text_out_to_row(unsigned char row,const unsigned char *buff);
void text_out_to_row_Language2(unsigned char row,const unsigned char *StrLocal,const unsigned char *StrOther);
void text_out_to_row_x(unsigned char row,unsigned char x,const unsigned char *buff);
void text_out_to_row_x_Language2(unsigned char row,unsigned char x,const unsigned char *StrLocal,const unsigned char *StrOther);
void my_strcpy_fillspace(unsigned char *dest,const unsigned char *src);
void my_strcpy_fillspace_bytes(unsigned char *dest,const unsigned char *src,const unsigned char TotalBytes);
void text_out_to_row_fillSpace(unsigned char row,const unsigned char *buff);
void text_out_to_row_x_fillSpace(unsigned char row,unsigned char x,const unsigned char *buff);
void DrawTitle_to_row(unsigned char row,const unsigned char *str);
void DrawTitle_to_row_Language2(unsigned char row,const unsigned char *StrLocal,const unsigned char *StrOther);
void clear_area_to_row(unsigned int startrow,unsigned int endrow);
void reverse_area_to_row(unsigned int xpos,unsigned int rows,unsigned int width,unsigned int height);
void draw_line_to_row(unsigned int row);
void steaddraw_pic_to_row_x(const unsigned char *buff,unsigned int x,unsigned char row,unsigned int width,unsigned int height);
void DispHighLightRow_to_x(unsigned char x,unsigned int row);
void DispHighLightRow_to_x_width(int row,char x,char width);
void DispHighLightRow(unsigned int row);
void draw_pic(const unsigned char *pstr,int xpos,int ypos,int width,int height);



void draw_line(int x1,int y1,int x2,int y2,unsigned char mode);
void draw_rect(int xstart,int ystart,int xlen,int ylen,unsigned char mode);
void fill_rect(int xstart,int ystart,int xlen,int ylen,unsigned char mode);//mode 0 used space fill, mode 1 used solid fill, mode2 used take reverse
void reverse_area(int xpos,int ypos,int width,int height);
void clear_area(int xpos,int ypos,int width,int height);
void set_contrast(unsigned char level);

void kmy_DataLED_Flash(char flash);

#endif


