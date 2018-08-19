#ifndef __FONT_H
#define __FONT_H

#include "font.h"

/**************************************************************************************************************
 //常用ASCII表
 //偏移量32
 //ASCII字符集: !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
 //PC2LCD2002取模方式設置：陰碼+逐列式+順向+C51格式
 //每個字符所佔用的字節數為:(size/8+((size%8)?1:0))*(size/2),其中size:是字庫生成時的點陣大小(12/16/24...)
 ****************************************************************************************************************/

//06*08==寬*高 ASCII字符集點陣 (Times New Roman)

const unsigned char asc2_0608[95][6] =
{
{0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x32,0x02,0x00,0x00},/*"!",1*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x40,0x40,0x40,0x00,0x00},/*""",2*/
/* (6 X 8 , Times New Roman ) */
{0x04,0x3E,0x14,0x14,0x7C,0x04},/*"#",3*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x36,0x52,0x2E,0x24,0x00},/*"$",4*/
/* (6 X 8 , Times New Roman ) */
{0x30,0x4A,0x3C,0x3E,0x4A,0x0E},/*"%",5*/
/* (6 X 8 , Times New Roman ) */
{0x0C,0x32,0x5E,0x36,0x0A,0x02},/*"&",6*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x40,0x00,0x00,0x00,0x00},/*"'",7*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x00,0x3E,0x41,0x00},/*"(",8*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x42,0x3C,0x00,0x00,0x00},/*")",9*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x18,0x1C,0x08,0x18,0x00},/*"*",10*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x08,0x18,0x08,0x00},/*"+",11*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x03,0x00,0x00,0x00,0x00},/*",",12*/
/* (6 X 8 , Times New Roman ) */
{0x10,0x10,0x10,0x10,0x10,0x10},/*"-",13*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x02,0x00,0x00,0x00,0x00},/*".",14*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x02,0x0C,0x10,0x60,0x00},/*"/",15*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x42,0x42,0x3E,0x00},/*"0",16*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x22,0x3E,0x00,0x00},/*"1",17*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x26,0x46,0x4A,0x32,0x00},/*"2",18*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x26,0x42,0x52,0x3E,0x00},/*"3",19*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x08,0x14,0x3E,0x04,0x00},/*"4",20*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x36,0x32,0x32,0x0E,0x00},/*"5",21*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x52,0x52,0x2E,0x00},/*"6",22*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x20,0x26,0x38,0x20,0x00},/*"7",23*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x52,0x4A,0x3E,0x00},/*"8",24*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3A,0x4A,0x4A,0x3C,0x00},/*"9",25*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x12,0x12,0x00,0x00},/*":",26*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x13,0x00,0x00,0x00},/*";",27*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x18,0x14,0x24,0x42,0x00},/*"<",28*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x18,0x18,0x18,0x18,0x00},/*"=",29*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x42,0x24,0x14,0x18,0x00},/*">",30*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x20,0x46,0x4A,0x30,0x00},/*"?",31*/
/* (6 X 8 , Times New Roman ) */
{0x18,0x26,0x5E,0x6A,0x36,0x18},/*"@",32*/
/* (6 X 8 , Times New Roman ) */
{0x02,0x0C,0x38,0x38,0x0E,0x00},/*"A",33*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x2A,0x2A,0x3A,0x04},/*"B",34*/
/* (6 X 8 , Times New Roman ) */
{0x18,0x26,0x42,0x42,0x42,0x24},/*"C",35*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x22,0x22,0x24,0x18},/*"D",36*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x2A,0x2A,0x22,0x00},/*"E",37*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x28,0x28,0x38,0x20},/*"F",38*/
/* (6 X 8 , Times New Roman ) */
{0x1C,0x22,0x42,0x42,0x26,0x00},/*"G",39*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x08,0x08,0x3E,0x00},/*"H",40*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x3E,0x22,0x00,0x00},/*"I",41*/
/* (6 X 8 , Times New Roman ) */
{0x01,0x01,0x01,0x3F,0x20,0x00},/*"J",42*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x10,0x2C,0x02,0x00},/*"K",43*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x02,0x02,0x02,0x00},/*"L",44*/
/* (6 X 8 , Times New Roman ) */
{0x0E,0x32,0x0E,0x08,0x3E,0x00},/*"M",45*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x10,0x08,0x3C,0x00},/*"N",46*/
/* (6 X 8 , Times New Roman ) */
{0x18,0x26,0x42,0x42,0x22,0x1C},/*"O",47*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x28,0x28,0x30,0x20},/*"P",48*/
/* (6 X 8 , Times New Roman ) */
{0x1C,0x22,0x46,0x42,0x23,0x1C},/*"Q",49*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x28,0x28,0x36,0x00},/*"R",50*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x32,0x52,0x4A,0x2E,0x00},/*"S",51*/
/* (6 X 8 , Times New Roman ) */
{0x20,0x20,0x3E,0x20,0x20,0x20},/*"T",52*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3E,0x02,0x02,0x3E,0x00},/*"U",53*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x30,0x0C,0x0C,0x30,0x00},/*"V",54*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x3C,0x28,0x3C,0x38,0x20},/*"W",55*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x22,0x14,0x1C,0x22,0x00},/*"X",56*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x20,0x1E,0x10,0x20,0x00},/*"Y",57*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x26,0x2A,0x32,0x22,0x00},/*"Z",58*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x7F,0x41,0x01,0x00},/*"[",59*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x60,0x10,0x0C,0x02,0x00},/*"\",60*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x01,0x41,0x7F,0x00,0x00},/*"]",61*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x80,0x80,0x80,0x80,0x00},/*"^",62*/
/* (6 X 8 , Times New Roman ) */
{0x01,0x01,0x01,0x01,0x01,0x01},/*"_",63*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x80,0x80,0x00,0x00,0x00},/*"`",64*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x06,0x1A,0x1A,0x0E,0x02},/*"a",65*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x7E,0x12,0x12,0x0E,0x00},/*"b",66*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x0E,0x12,0x12,0x02,0x00},/*"c",67*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x0E,0x12,0x12,0x7E,0x02},/*"d",68*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x0E,0x16,0x16,0x0A,0x00},/*"e",69*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x10,0x3E,0x30,0x30,0x00},/*"f",70*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x0F,0x17,0x17,0x1B,0x10},/*"g",71*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x7E,0x10,0x10,0x0E,0x00},/*"h",72*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x10,0x1E,0x02,0x00,0x00},/*"i",73*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x01,0x01,0x11,0x5E,0x00},/*"j",74*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x7E,0x08,0x1C,0x12,0x00},/*"k",75*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x7E,0x02,0x00,0x00},/*"l",76*/
/* (6 X 8 , Times New Roman ) */
{0x1E,0x12,0x12,0x0E,0x12,0x0E},/*"m",77*/
/* (6 X 8 , Times New Roman ) */
{0x10,0x1E,0x10,0x10,0x0E,0x00},/*"n",78*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x0E,0x12,0x12,0x0E,0x00},/*"o",79*/
/* (6 X 8 , Times New Roman ) */
{0x10,0x1F,0x12,0x12,0x0E,0x00},/*"p",80*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x0E,0x12,0x12,0x0F,0x00},/*"q",81*/
/* (6 X 8 , Times New Roman ) */
{0x10,0x12,0x0E,0x10,0x10,0x00},/*"r",82*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x0A,0x1A,0x16,0x16,0x00},/*"s",83*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x10,0x3E,0x12,0x12,0x00},/*"t",84*/
/* (6 X 8 , Times New Roman ) */
{0x10,0x1E,0x02,0x02,0x1E,0x02},/*"u",85*/
/* (6 X 8 , Times New Roman ) */
{0x10,0x18,0x04,0x04,0x18,0x00},/*"v",86*/
/* (6 X 8 , Times New Roman ) */
{0x10,0x1C,0x14,0x1C,0x1C,0x10},/*"w",87*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x12,0x1C,0x1C,0x12,0x00},/*"x",88*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x19,0x05,0x06,0x18,0x10},/*"y",89*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x12,0x16,0x1A,0x12,0x00},/*"z",90*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x00,0x7E,0x01,0x00},/*"{",91*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x00,0x00,0xFF,0x00,0x00},/*"|",92*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x01,0x7E,0x00,0x00,0x00},/*"}",93*/
/* (6 X 8 , Times New Roman ) */
{0x00,0x80,0x80,0x40,0x40,0x00},/*"~",94*/
/* (6 X 8 , Times New Roman ) */
};
//06*12==寬*高 ASCII字符集點陣 (Times New Roman)
const unsigned char asc2_0612[95][12] =
{
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x3E,0x40,0x00,0x00,0x00,0x00,0x00,0x00},/*"!",1*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x20,0x00,0xC0,0x00,0x20,0x00,0xC0,0x00,0x00,0x00},/*""",2*/
/* (6 X 12 , Times New Roman ) */
{0x09,0x00,0x3F,0xC0,0x09,0x00,0x3F,0xC0,0x09,0x00,0x00,0x00},/*"#",3*/
/* (6 X 12 , Times New Roman ) */
{0x18,0x80,0x24,0x40,0x7F,0xE0,0x22,0x40,0x11,0x80,0x00,0x00},/*"$",4*/
/* (6 X 12 , Times New Roman ) */
{0x1C,0x00,0x22,0xC0,0x1F,0x00,0x0B,0x80,0x34,0x40,0x03,0x80},/*"%",5*/
/* (6 X 12 , Times New Roman ) */
{0x03,0x80,0x1C,0x40,0x27,0x40,0x18,0x80,0x07,0x40,0x04,0x80},/*"&",6*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x1F,0x00,0x60,0xC0,0x80,0x20,0x00,0x00},/*"(",8*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x80,0x20,0x60,0xC0,0x1F,0x00,0x00,0x00,0x00,0x00},/*")",9*/
/* (6 X 12 , Times New Roman ) */
{0x09,0x00,0x06,0x00,0x1F,0x80,0x06,0x00,0x09,0x00,0x00,0x00},/*"*",10*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x04,0x00,0x04,0x00,0x1F,0x00,0x04,0x00,0x04,0x00},/*"+",11*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x20,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*",",12*/
/* (6 X 12 , Times New Roman ) */
{0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00},/*"-",13*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*".",14*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x20,0x00,0xC0,0x03,0x00,0x0C,0x00,0x30,0x00,0x40,0x00},/*"/",15*/
/* (6 X 12 , Times New Roman ) */
{0x1F,0x80,0x20,0x40,0x20,0x40,0x20,0x40,0x1F,0x80,0x00,0x00},/*"0",16*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x10,0x40,0x3F,0xC0,0x00,0x40,0x00,0x00,0x00,0x00},/*"1",17*/
/* (6 X 12 , Times New Roman ) */
{0x18,0xC0,0x21,0x40,0x22,0x40,0x24,0x40,0x18,0x40,0x00,0x00},/*"2",18*/
/* (6 X 12 , Times New Roman ) */
{0x10,0x80,0x20,0x40,0x24,0x40,0x24,0x40,0x1B,0x80,0x00,0x00},/*"3",19*/
/* (6 X 12 , Times New Roman ) */
{0x03,0x00,0x05,0x00,0x19,0x40,0x3F,0xC0,0x01,0x40,0x00,0x00},/*"4",20*/
/* (6 X 12 , Times New Roman ) */
{0x3E,0x80,0x24,0x40,0x24,0x40,0x24,0x40,0x23,0x80,0x00,0x00},/*"5",21*/
/* (6 X 12 , Times New Roman ) */
{0x0F,0x80,0x12,0x40,0x24,0x40,0x24,0x40,0x13,0x80,0x00,0x00},/*"6",22*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x20,0x00,0x23,0xC0,0x2C,0x00,0x30,0x00,0x00,0x00},/*"7",23*/
/* (6 X 12 , Times New Roman ) */
{0x1B,0x80,0x24,0x40,0x24,0x40,0x24,0x40,0x1B,0x80,0x00,0x00},/*"8",24*/
/* (6 X 12 , Times New Roman ) */
{0x1C,0x80,0x22,0x40,0x22,0x40,0x24,0x80,0x1F,0x00,0x00,0x00},/*"9",25*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x08,0x40,0x00,0x00,0x00,0x00,0x00,0x00},/*":",26*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x04,0x60,0x00,0x00,0x00,0x00,0x00,0x00},/*";",27*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x06,0x00,0x09,0x00,0x10,0x80,0x20,0x40,0x00,0x00},/*"<",28*/
/* (6 X 12 , Times New Roman ) */
{0x0A,0x00,0x0A,0x00,0x0A,0x00,0x0A,0x00,0x0A,0x00,0x0A,0x00},/*"=",29*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x20,0x40,0x10,0x80,0x09,0x00,0x06,0x00,0x00,0x00},/*">",30*/
/* (6 X 12 , Times New Roman ) */
{0x18,0x00,0x20,0x00,0x23,0x40,0x24,0x00,0x18,0x00,0x00,0x00},/*"?",31*/
/* (6 X 12 , Times New Roman ) */
{0x0F,0x00,0x10,0x80,0x27,0x40,0x2F,0x40,0x21,0x40,0x1E,0x80},/*"@",32*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x40,0x07,0xC0,0x39,0x00,0x0F,0x00,0x01,0xC0,0x00,0x40},/*"A",33*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x24,0x40,0x1B,0x80,0x00,0x00},/*"B",34*/
/* (6 X 12 , Times New Roman ) */
{0x1F,0x80,0x20,0x40,0x20,0x40,0x20,0x40,0x30,0x80,0x00,0x00},/*"C",35*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x20,0x40,0x20,0x40,0x1F,0x80,0x00,0x00},/*"D",36*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x2E,0x40,0x30,0xC0,0x00,0x00},/*"E",37*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x2E,0x00,0x30,0x00,0x00,0x00},/*"F",38*/
/* (6 X 12 , Times New Roman ) */
{0x0F,0x00,0x10,0x80,0x20,0x40,0x22,0x40,0x33,0x80,0x02,0x00},/*"G",39*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x04,0x00,0x04,0x00,0x3F,0xC0,0x20,0x40},/*"H",40*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x20,0x40,0x3F,0xC0,0x20,0x40,0x20,0x40,0x00,0x00},/*"I",41*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x30,0x20,0x10,0x20,0x10,0x3F,0xE0,0x20,0x00,0x20,0x00},/*"J",42*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x0A,0x00,0x31,0xC0,0x20,0x40},/*"K",43*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x20,0x40,0x00,0x40,0x00,0x40,0x00,0xC0},/*"L",44*/
/* (6 X 12 , Times New Roman ) */
{0x3F,0xC0,0x3C,0x00,0x03,0xC0,0x3C,0x00,0x3F,0xC0,0x20,0x40},/*"M",45*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x0C,0x40,0x23,0x00,0x3F,0xC0,0x20,0x00},/*"N",46*/
/* (6 X 12 , Times New Roman ) */
{0x1F,0x80,0x20,0x40,0x20,0x40,0x20,0x40,0x1F,0x80,0x00,0x00},/*"O",47*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x24,0x00,0x18,0x00,0x00,0x00},/*"P",48*/
/* (6 X 12 , Times New Roman ) */
{0x1F,0x80,0x21,0x40,0x21,0x40,0x20,0xE0,0x1F,0xA0,0x00,0x00},/*"Q",49*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x3F,0xC0,0x24,0x40,0x26,0x00,0x19,0xC0,0x00,0x40},/*"R",50*/
/* (6 X 12 , Times New Roman ) */
{0x18,0xC0,0x24,0x40,0x24,0x40,0x22,0x40,0x31,0x80,0x00,0x00},/*"S",51*/
/* (6 X 12 , Times New Roman ) */
{0x30,0x00,0x20,0x40,0x3F,0xC0,0x20,0x40,0x30,0x00,0x00,0x00},/*"T",52*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x00,0x3F,0x80,0x00,0x40,0x00,0x40,0x3F,0x80,0x20,0x00},/*"U",53*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x00,0x3E,0x00,0x01,0xC0,0x07,0x00,0x38,0x00,0x20,0x00},/*"V",54*/
/* (6 X 12 , Times New Roman ) */
{0x3C,0x00,0x03,0xC0,0x3E,0x00,0x03,0xC0,0x3C,0x00,0x00,0x00},/*"W",55*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x40,0x39,0xC0,0x06,0x00,0x39,0xC0,0x20,0x40,0x00,0x00},/*"X",56*/
/* (6 X 12 , Times New Roman ) */
{0x20,0x00,0x3C,0x40,0x03,0xC0,0x3C,0x40,0x20,0x00,0x00,0x00},/*"Y",57*/
/* (6 X 12 , Times New Roman ) */
{0x30,0x40,0x21,0xC0,0x26,0x40,0x38,0x40,0x20,0xC0,0x00,0x00},/*"Z",58*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0xFF,0xE0,0x80,0x20,0x80,0x20,0x00,0x00},/*"[",59*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x60,0x00,0x1C,0x00,0x03,0x80,0x00,0x60,0x00,0x00},/*"\",60*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x80,0x20,0x80,0x20,0xFF,0xE0,0x00,0x00,0x00,0x00},/*"]",61*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x40,0x00,0x80,0x00,0x40,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10},/*"_",63*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x80,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x02,0x80,0x05,0x40,0x05,0x40,0x03,0xC0,0x00,0x40},/*"a",65*/
/* (6 X 12 , Times New Roman ) */
{0x40,0x00,0x7F,0xC0,0x04,0x40,0x04,0x40,0x03,0x80,0x00,0x00},/*"b",66*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x03,0x80,0x04,0x40,0x04,0x40,0x06,0x80,0x00,0x00},/*"c",67*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x03,0x80,0x04,0x40,0x44,0x40,0x7F,0xC0,0x00,0x40},/*"d",68*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x03,0x80,0x05,0x40,0x05,0x40,0x03,0x40,0x00,0x00},/*"e",69*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x04,0x40,0x3F,0xC0,0x44,0x40,0x44,0x40,0x20,0x00},/*"f",70*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x02,0xA0,0x05,0x50,0x05,0x50,0x06,0x50,0x04,0x20},/*"g",71*/
/* (6 X 12 , Times New Roman ) */
{0x40,0x40,0x7F,0xC0,0x04,0x40,0x04,0x00,0x03,0xC0,0x00,0x40},/*"h",72*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x04,0x40,0x67,0xC0,0x00,0x40,0x00,0x00,0x00,0x00},/*"i",73*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x10,0x00,0x10,0x04,0x10,0x67,0xE0,0x00,0x00,0x00,0x00},/*"j",74*/
/* (6 X 12 , Times New Roman ) */
{0x40,0x40,0x7F,0xC0,0x01,0x00,0x06,0x80,0x04,0x40,0x00,0x00},/*"k",75*/
/* (6 X 12 , Times New Roman ) */
{0x40,0x40,0x40,0x40,0x7F,0xC0,0x00,0x40,0x00,0x40,0x00,0x00},/*"l",76*/
/* (6 X 12 , Times New Roman ) */
{0x07,0xC0,0x04,0x00,0x07,0xC0,0x04,0x00,0x03,0xC0,0x00,0x00},/*"m",77*/
/* (6 X 12 , Times New Roman ) */
{0x04,0x40,0x07,0xC0,0x04,0x40,0x04,0x00,0x03,0xC0,0x00,0x40},/*"n",78*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x03,0x80,0x04,0x40,0x04,0x40,0x03,0x80,0x00,0x00},/*"o",79*/
/* (6 X 12 , Times New Roman ) */
{0x04,0x10,0x07,0xF0,0x04,0x50,0x04,0x40,0x03,0x80,0x00,0x00},/*"p",80*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x03,0x80,0x04,0x40,0x04,0x50,0x07,0xF0,0x00,0x10},/*"q",81*/
/* (6 X 12 , Times New Roman ) */
{0x04,0x40,0x07,0xC0,0x02,0x40,0x04,0x00,0x04,0x00,0x00,0x00},/*"r",82*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x06,0x40,0x05,0x40,0x05,0x40,0x04,0xC0,0x00,0x00},/*"s",83*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x04,0x00,0x1F,0xC0,0x04,0x40,0x04,0x40,0x00,0x00},/*"t",84*/
/* (6 X 12 , Times New Roman ) */
{0x04,0x00,0x07,0x80,0x00,0x40,0x04,0x40,0x07,0xC0,0x00,0x40},/*"u",85*/
/* (6 X 12 , Times New Roman ) */
{0x04,0x00,0x07,0x00,0x00,0xC0,0x07,0x00,0x04,0x00,0x00,0x00},/*"v",86*/
/* (6 X 12 , Times New Roman ) */
{0x06,0x00,0x01,0xC0,0x07,0x00,0x01,0xC0,0x06,0x00,0x00,0x00},/*"w",87*/
/* (6 X 12 , Times New Roman ) */
{0x04,0x40,0x06,0xC0,0x01,0x00,0x06,0xC0,0x04,0x40,0x00,0x00},/*"x",88*/
/* (6 X 12 , Times New Roman ) */
{0x04,0x10,0x07,0x10,0x00,0xA0,0x00,0xC0,0x07,0x00,0x04,0x00},/*"y",89*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x04,0x40,0x05,0xC0,0x06,0x40,0x04,0x40,0x00,0x00},/*"z",90*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x04,0x00,0xFF,0xE0,0x80,0x20,0x00,0x00},/*"{",91*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x00},/*"|",92*/
/* (6 X 12 , Times New Roman ) */
{0x00,0x00,0x80,0x20,0xFB,0xE0,0x04,0x00,0x00,0x00,0x00,0x00},/*"}",93*/
/* (6 X 12 , Times New Roman ) */
{0x40,0x00,0x80,0x00,0x80,0x00,0x40,0x00,0x80,0x00,0x00,0x00},/*"~",94*/
/* (6 X 12 , Times New Roman ) */
};

//12*24==寬*高 ASCII字符集點陣 (Times New Roman)
const unsigned char asc2_1224[95][36] =
{
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xEE,0x38,0x0F,0xF0,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"!",1*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x06,0x00,0x00,0x0C,0x00,0x00,0x38,0x00,0x00,0x31,0x00,0x00,0x06,0x00,0x00,0x0C,0x00,0x00,0x38,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00},/*""",2*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0xC1,0x80,0x00,0xC1,0xF8,0x00,0xFF,0x80,0x0F,0xC1,0x80,0x00,0xC1,0x80,0x00,0xC1,0x80,0x00,0xC1,0x80,0x00,0xDF,0xF8,0x0F,0xE1,0x80,0x00,0xC1,0x80,0x00,0x00,0x00},/*"#",3*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0xE0,0x03,0xE0,0xF0,0x06,0x30,0x48,0x04,0x18,0x08,0x1F,0xFF,0xFE,0x04,0x8E,0x08,0x07,0x87,0xF0,0x03,0x81,0xE0,0x00,0x00,0x00,0x00,0x00,0x00},/*"$",4*/
/* (12 X 24 , Times New Roman ) */
{0x03,0xE0,0x00,0x0C,0x18,0x00,0x08,0x08,0x18,0x0C,0x18,0xE0,0x03,0xF3,0x00,0x00,0x1C,0x00,0x00,0x63,0xE0,0x03,0x8C,0x18,0x0C,0x08,0x08,0x00,0x0C,0x18,0x00,0x03,0xE0,0x00,0x00,0x00},/*"%",5*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x03,0xE0,0x00,0x07,0xF0,0x07,0xE8,0x18,0x0F,0xFC,0x08,0x08,0x1F,0x08,0x0F,0xE3,0xC8,0x07,0xC0,0xF0,0x00,0x10,0x70,0x00,0x1F,0x98,0x00,0x10,0x08,0x00,0x10,0x08,0x00,0x00,0x30},/*"&",6*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x00,0x32,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x01,0x80,0xC0,0x06,0x00,0x30,0x08,0x00,0x08,0x10,0x00,0x04,0x20,0x00,0x02,0x00,0x00,0x00},/*"(",8*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x20,0x00,0x02,0x10,0x00,0x04,0x08,0x00,0x08,0x06,0x00,0x30,0x01,0x80,0xC0,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*")",9*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x66,0x00,0x00,0x66,0x00,0x00,0x24,0x00,0x00,0x1C,0x00,0x00,0x08,0x00,0x03,0xFF,0xC0,0x01,0x18,0x00,0x00,0x3C,0x00,0x00,0x24,0x00,0x00,0x66,0x00,0x00,0x66,0x00},/*"*",10*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x01,0xFF,0xC0,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00},/*"+",11*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x00,0x32,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*",",12*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x00,0x00},/*"-",13*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x38,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*".",14*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x1C,0x00,0x00,0x70,0x00,0x01,0x80,0x00,0x0E,0x00,0x00,0x38,0x00,0x00,0xC0,0x00,0x07,0x00,0x00,0x1C,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00},/*"/",15*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x7F,0x80,0x01,0xFF,0xE0,0x03,0x80,0x70,0x06,0x00,0x18,0x04,0x00,0x08,0x04,0x00,0x08,0x06,0x00,0x18,0x03,0x80,0x70,0x01,0xFF,0xE0,0x00,0x7F,0x80,0x00,0x00,0x00},/*"0",16*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x08,0x02,0x00,0x08,0x02,0x00,0x08,0x03,0xFF,0xF8,0x07,0xFF,0xF8,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00},/*"1",17*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x01,0xC0,0x18,0x02,0xC0,0x38,0x04,0x00,0x48,0x04,0x00,0x88,0x04,0x03,0x08,0x04,0x06,0x08,0x06,0x0C,0x08,0x03,0xF8,0x08,0x01,0xE0,0x78,0x00,0x00,0x00,0x00,0x00,0x00},/*"2",18*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x03,0x80,0x70,0x03,0x80,0x70,0x04,0x00,0x08,0x04,0x08,0x08,0x04,0x08,0x08,0x06,0x18,0x08,0x03,0xF4,0x18,0x01,0xE7,0xF0,0x00,0x01,0xE0,0x00,0x00,0x00,0x00,0x00,0x00},/*"3",19*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x05,0x00,0x00,0x19,0x00,0x00,0x21,0x00,0x00,0xC1,0x08,0x01,0x01,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x00,0x01,0x08,0x00,0x01,0x08,0x00,0x01,0x00},/*"4",20*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0xFC,0xD0,0x04,0x08,0x08,0x04,0x10,0x08,0x04,0x10,0x08,0x04,0x10,0x08,0x04,0x18,0x38,0x04,0x0F,0xF0,0x04,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},/*"5",21*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x3F,0x80,0x01,0xFF,0xE0,0x03,0x84,0x30,0x02,0x08,0x18,0x04,0x10,0x08,0x04,0x10,0x08,0x04,0x10,0x08,0x07,0x18,0x10,0x03,0x0F,0xF0,0x00,0x07,0xC0,0x00,0x00,0x00},/*"6",22*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x80,0x00,0x06,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0xF8,0x04,0x07,0xF8,0x04,0x18,0x00,0x04,0xE0,0x00,0x07,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00},/*"7",23*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x01,0xC1,0xE0,0x03,0xF3,0xF0,0x06,0x36,0x10,0x04,0x18,0x08,0x04,0x08,0x08,0x04,0x0C,0x08,0x04,0x0C,0x08,0x06,0x16,0x18,0x03,0xF3,0xF0,0x01,0xC1,0xE0,0x00,0x00,0x00},/*"8",24*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0xF8,0x00,0x03,0xFC,0x30,0x03,0x06,0x38,0x04,0x02,0x08,0x04,0x02,0x08,0x04,0x02,0x08,0x04,0x04,0x10,0x03,0x08,0xF0,0x01,0xFF,0xC0,0x00,0x7F,0x00,0x00,0x00,0x00},/*"9",25*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x38,0x00,0x38,0x38,0x00,0x38,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*":",26*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x1B,0x00,0x30,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*";",27*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x14,0x00,0x00,0x22,0x00,0x00,0x41,0x00,0x00,0x80,0x80,0x01,0x00,0x40,0x02,0x00,0x20,0x04,0x00,0x10,0x08,0x00,0x08,0x00,0x00,0x00},/*"<",28*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,0x00,0x00},/*"=",29*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x08,0x04,0x00,0x10,0x02,0x00,0x20,0x01,0x00,0x40,0x00,0x80,0x80,0x00,0x41,0x00,0x00,0x22,0x00,0x00,0x14,0x00,0x00,0x08,0x00,0x00,0x00,0x00},/*">",30*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE0,0x00,0x02,0x60,0x00,0x02,0x00,0x00,0x04,0x00,0x38,0x04,0x07,0x38,0x04,0x08,0x38,0x04,0x18,0x00,0x06,0x10,0x00,0x03,0xF0,0x00,0x01,0xE0,0x00},/*"?",31*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x7F,0x00,0x03,0xFF,0xE0,0x07,0x00,0x70,0x04,0x1F,0x18,0x08,0xFF,0x88,0x09,0xC0,0x88,0x09,0x3F,0x88,0x05,0xE0,0x90,0x06,0x01,0x30,0x01,0xFE,0x40,0x00,0x00,0x00},/*"@",32*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x08,0x00,0x00,0x38,0x00,0x01,0xC8,0x00,0x1E,0x08,0x01,0xE2,0x00,0x06,0x02,0x00,0x07,0x82,0x00,0x00,0xFA,0x00,0x00,0x0F,0x88,0x00,0x01,0xF8,0x00,0x00,0x18,0x00,0x00,0x08},/*"A",33*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x08,0x08,0x04,0x08,0x08,0x04,0x08,0x08,0x06,0x18,0x08,0x03,0xF4,0x18,0x03,0xE7,0xF0,0x00,0x01,0xE0,0x00,0x00,0x00},/*"B",34*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x3F,0x80,0x01,0xFF,0xE0,0x03,0x80,0x70,0x02,0x00,0x18,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x08,0x06,0x00,0x10,0x07,0x00,0x30,0x01,0xC0,0xC0,0x00,0x00,0x00},/*"C",35*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x08,0x02,0x00,0x10,0x03,0x80,0x70,0x01,0xFF,0xE0,0x00,0x7F,0x80,0x00,0x00,0x00},/*"D",36*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x08,0x08,0x04,0x08,0x08,0x04,0x08,0x08,0x04,0x08,0x08,0x04,0x3F,0x08,0x06,0x00,0x08,0x06,0x00,0x18,0x01,0x80,0x60,0x00,0x00,0x00},/*"E",37*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x08,0x08,0x04,0x08,0x08,0x04,0x08,0x00,0x04,0x08,0x00,0x04,0x3F,0x00,0x06,0x00,0x00,0x06,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00},/*"F",38*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x3F,0x80,0x01,0xFF,0xE0,0x03,0x80,0x70,0x06,0x00,0x18,0x04,0x00,0x08,0x04,0x02,0x08,0x04,0x02,0x08,0x02,0x03,0xF0,0x01,0xC3,0xF0,0x00,0x02,0x00,0x00,0x02,0x00},/*"G",39*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x08,0x08,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x04,0x08,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x00,0x08},/*"H",40*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00},/*"I",41*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x07,0x04,0x00,0x01,0x04,0x00,0x01,0x04,0x00,0x03,0x07,0xFF,0xFE,0x07,0xFF,0xFC,0x04,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00},/*"J",42*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x0C,0x08,0x00,0x30,0x00,0x00,0x5C,0x00,0x05,0x87,0x00,0x07,0x01,0xC8,0x06,0x00,0x78,0x04,0x00,0x18,0x00,0x00,0x08,0x00,0x00,0x00},/*"K",43*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x00,0x08,0x04,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x18,0x00,0x00,0x60,0x00,0x00,0x00},/*"L",44*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xF0,0x08,0x00,0xFF,0x00,0x00,0x07,0xF0,0x00,0x01,0xE0,0x00,0x3E,0x00,0x03,0xC0,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x00,0x08,0x00,0x00,0x00},/*"M",45*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x08,0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0x80,0x08,0x01,0xE0,0x08,0x00,0x78,0x00,0x00,0x1E,0x00,0x04,0x03,0xC0,0x04,0x00,0xF0,0x07,0xFF,0xF8,0x04,0x00,0x00,0x04,0x00,0x00},/*"N",46*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x7F,0x80,0x01,0xFF,0xE0,0x03,0x80,0x70,0x06,0x00,0x18,0x04,0x00,0x08,0x04,0x00,0x08,0x06,0x00,0x18,0x03,0x00,0x30,0x01,0xFF,0xE0,0x00,0x7F,0x80,0x00,0x00,0x00},/*"O",47*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x04,0x08,0x04,0x04,0x08,0x04,0x04,0x00,0x04,0x04,0x00,0x04,0x0C,0x00,0x02,0x08,0x00,0x03,0xF8,0x00,0x01,0xF0,0x00,0x00,0x00,0x00},/*"P",48*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x7F,0x80,0x01,0xFF,0xE0,0x03,0x80,0x70,0x06,0x00,0x98,0x04,0x00,0x88,0x04,0x00,0xE8,0x06,0x00,0x3C,0x03,0x00,0x36,0x01,0xFF,0xE6,0x00,0x7F,0x84,0x00,0x00,0x00},/*"Q",49*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x08,0x08,0x04,0x08,0x00,0x04,0x08,0x00,0x04,0x0E,0x00,0x04,0x0B,0x80,0x06,0x10,0xE0,0x03,0xF0,0x78,0x01,0xE0,0x18,0x00,0x00,0x08},/*"R",50*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x01,0xE0,0xE0,0x03,0xF0,0x30,0x06,0x38,0x10,0x04,0x18,0x08,0x04,0x1C,0x08,0x04,0x0C,0x08,0x04,0x0E,0x08,0x02,0x07,0x18,0x07,0x87,0xF0,0x00,0x01,0xE0,0x00,0x00,0x00},/*"S",51*/
/* (12 X 24 , Times New Roman ) */
{0x01,0x80,0x00,0x06,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x08,0x04,0x00,0x08,0x07,0xFF,0xF8,0x07,0xFF,0xF8,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x00,0x06,0x00,0x00,0x01,0x80,0x00},/*"T",52*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x04,0x00,0x00,0x07,0xFF,0xE0,0x07,0xFF,0xF0,0x04,0x00,0x18,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x04,0x00,0x10,0x07,0xFF,0xE0,0x04,0x00,0x00,0x00,0x00,0x00},/*"U",53*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x00,0x06,0x00,0x00,0x07,0xE0,0x00,0x04,0x7E,0x00,0x00,0x07,0xE0,0x00,0x00,0x78,0x00,0x01,0xC0,0x00,0x1E,0x00,0x05,0xE0,0x00,0x06,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00},/*"V",54*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x00,0x07,0xC0,0x00,0x04,0xFF,0x00,0x00,0x03,0xF8,0x04,0x03,0xC0,0x06,0x3C,0x00,0x07,0xFC,0x00,0x04,0x0F,0xF8,0x00,0x01,0xE0,0x04,0x3E,0x00,0x07,0xC0,0x00,0x04,0x00,0x00},/*"W",55*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x04,0x00,0x08,0x06,0x00,0x18,0x07,0x80,0x68,0x04,0xE1,0x80,0x00,0x3E,0x00,0x00,0x17,0x00,0x04,0x61,0xC8,0x07,0x80,0x78,0x04,0x00,0x18,0x04,0x00,0x08,0x00,0x00,0x00},/*"X",56*/
/* (12 X 24 , Times New Roman ) */
{0x04,0x00,0x00,0x06,0x00,0x00,0x07,0x80,0x00,0x04,0xF0,0x08,0x00,0x3C,0x08,0x00,0x1F,0xF8,0x00,0x07,0xF8,0x00,0x18,0x08,0x04,0x60,0x08,0x05,0x80,0x00,0x06,0x00,0x00,0x04,0x00,0x00},/*"Y",57*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x01,0x80,0x08,0x07,0x00,0x38,0x06,0x00,0xE8,0x04,0x01,0x88,0x04,0x06,0x08,0x04,0x18,0x08,0x04,0x60,0x08,0x05,0xC0,0x08,0x07,0x00,0x18,0x04,0x00,0x60,0x00,0x00,0x00},/*"Z",58*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFE,0x20,0x00,0x02,0x20,0x00,0x02,0x20,0x00,0x02,0x20,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00},/*"[",59*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x00,0x03,0x00,0x00,0x00,0xE0,0x00,0x00,0x18,0x00,0x00,0x07,0x00,0x00,0x01,0xC0,0x00,0x00,0x30,0x00,0x00,0x0E,0x00,0x00,0x01,0x00,0x00,0x00},/*"\",60*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x02,0x20,0x00,0x02,0x20,0x00,0x02,0x20,0x00,0x02,0x3F,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"]",61*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x20,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x20,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x01},/*"_",63*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0xF0,0x00,0x19,0xF8,0x00,0x19,0x98,0x00,0x21,0x08,0x00,0x22,0x08,0x00,0x22,0x08,0x00,0x22,0x10,0x00,0x3F,0xF0,0x00,0x1F,0xF8,0x00,0x00,0x08,0x00,0x00,0x18},/*"a",65*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x04,0x00,0x00,0x07,0xFF,0xF8,0x0F,0xFF,0xF0,0x00,0x18,0x10,0x00,0x10,0x08,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x30,0x18,0x00,0x1F,0xF0,0x00,0x0F,0xC0,0x00,0x00,0x00},/*"b",66*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x07,0xC0,0x00,0x1F,0xF0,0x00,0x18,0x30,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x3C,0x08,0x00,0x1C,0x10,0x00,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00},/*"c",67*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x07,0xC0,0x00,0x1F,0xF0,0x00,0x38,0x18,0x00,0x20,0x08,0x00,0x20,0x08,0x04,0x20,0x08,0x04,0x10,0x10,0x07,0xFF,0xF8,0x0F,0xFF,0xF0,0x00,0x00,0x10,0x00,0x00,0x00},/*"d",68*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xC0,0x00,0x1F,0xF0,0x00,0x11,0x30,0x00,0x21,0x08,0x00,0x21,0x08,0x00,0x21,0x08,0x00,0x31,0x08,0x00,0x1F,0x10,0x00,0x07,0x20,0x00,0x00,0x00},/*"e",69*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x20,0x08,0x00,0x20,0x08,0x01,0xFF,0xF8,0x03,0xFF,0xF8,0x06,0x20,0x08,0x04,0x20,0x08,0x04,0x20,0x08,0x07,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00},/*"f",70*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x0E,0x7E,0x00,0x1F,0xF3,0x00,0x31,0xA1,0x00,0x20,0xA1,0x00,0x30,0xB1,0x00,0x3F,0xB3,0x00,0x2F,0x1E,0x00,0x30,0x1E,0x00,0x30,0x00,0x00,0x00,0x00},/*"g",71*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x04,0x00,0x08,0x07,0xFF,0xF8,0x0F,0xFF,0xF8,0x00,0x10,0x08,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x20,0x08,0x00,0x3F,0xF8,0x00,0x1F,0xF8,0x00,0x00,0x08,0x00,0x00,0x00},/*"h",72*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x20,0x08,0x06,0x3F,0xF8,0x06,0x7F,0xF8,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00},/*"i",73*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x03,0x00,0x20,0x01,0x00,0x20,0x01,0x06,0x20,0x03,0x06,0x3F,0xFE,0x06,0x7F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"j",74*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x04,0x00,0x08,0x07,0xFF,0xF8,0x0F,0xFF,0xF8,0x00,0x01,0x08,0x00,0x02,0x00,0x00,0x07,0x00,0x00,0x38,0xC8,0x00,0x20,0x78,0x00,0x20,0x18,0x00,0x00,0x08,0x00,0x00,0x00},/*"k",75*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x08,0x07,0xFF,0xF8,0x0F,0xFF,0xF8,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00},/*"l",76*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x20,0x08,0x00,0x3F,0xF8,0x00,0x3F,0xF8,0x00,0x10,0x08,0x00,0x20,0x08,0x00,0x3F,0xF8,0x00,0x1F,0xF8,0x00,0x10,0x08,0x00,0x20,0x08,0x00,0x3F,0xF8,0x00,0x3F,0xF8,0x00,0x00,0x08},/*"m",77*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x20,0x08,0x00,0x3F,0xF8,0x00,0x3F,0xF8,0x00,0x10,0x08,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x20,0x08,0x00,0x3F,0xF8,0x00,0x1F,0xF8,0x00,0x00,0x08,0x00,0x00,0x00},/*"n",78*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x07,0xC0,0x00,0x0F,0xF0,0x00,0x18,0x30,0x00,0x30,0x08,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x30,0x08,0x00,0x18,0x30,0x00,0x0F,0xF0,0x00,0x07,0xC0,0x00,0x00,0x00},/*"o",79*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x20,0x01,0x00,0x3F,0xFF,0x00,0x3F,0xFF,0x00,0x10,0x11,0x00,0x20,0x09,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x30,0x38,0x00,0x1F,0xF0,0x00,0x0F,0xC0,0x00,0x00,0x00},/*"p",80*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x07,0xC0,0x00,0x1F,0xF0,0x00,0x38,0x18,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x20,0x09,0x00,0x10,0x11,0x00,0x1F,0xFF,0x00,0x3F,0xFF,0x00,0x00,0x01,0x00,0x00,0x00},/*"q",81*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x3F,0xF8,0x00,0x3F,0xF8,0x00,0x08,0x08,0x00,0x10,0x08,0x00,0x20,0x08,0x00,0x20,0x00,0x00,0x38,0x00,0x00,0x18,0x00,0x00,0x00,0x00},/*"r",82*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x78,0x00,0x1E,0x18,0x00,0x33,0x08,0x00,0x23,0x08,0x00,0x21,0x88,0x00,0x21,0x98,0x00,0x30,0xF8,0x00,0x3C,0xF0,0x00,0x00,0x00,0x00,0x00,0x00},/*"s",83*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0xFF,0xF0,0x03,0xFF,0xF8,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x20,0x08,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00},/*"t",84*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x3F,0xF0,0x00,0x7F,0xF8,0x00,0x00,0x18,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x20,0x10,0x00,0x3F,0xF8,0x00,0x7F,0xF0,0x00,0x00,0x10,0x00,0x00,0x00},/*"u",85*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x30,0x00,0x00,0x3E,0x00,0x00,0x23,0xC0,0x00,0x00,0xF8,0x00,0x00,0x30,0x00,0x01,0xC0,0x00,0x2E,0x00,0x00,0x30,0x00,0x00,0x20,0x00,0x00,0x00,0x00},/*"v",86*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x20,0x00,0x00,0x38,0x00,0x00,0x2F,0x80,0x00,0x01,0xF8,0x00,0x20,0xF0,0x00,0x37,0x00,0x00,0x3F,0x00,0x00,0x21,0xF0,0x00,0x00,0xF0,0x00,0x27,0x00,0x00,0x38,0x00,0x00,0x20,0x00},/*"w",87*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x20,0x08,0x00,0x30,0x38,0x00,0x3C,0x48,0x00,0x27,0x80,0x00,0x03,0x80,0x00,0x24,0xC8,0x00,0x38,0x38,0x00,0x20,0x18,0x00,0x20,0x08,0x00,0x00,0x00},/*"x",88*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x20,0x03,0x00,0x3C,0x01,0x00,0x23,0x81,0x00,0x00,0xFE,0x00,0x00,0x70,0x00,0x23,0x80,0x00,0x3C,0x00,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x00,0x00},/*"y",89*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x18,0x00,0x20,0x78,0x00,0x20,0xC8,0x00,0x23,0x88,0x00,0x2E,0x08,0x00,0x38,0x08,0x00,0x30,0x18,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00},/*"z",90*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x14,0x00,0x1F,0xE3,0xFC,0x20,0x00,0x02,0x20,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00},/*"{",91*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"|",92*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x02,0x20,0x00,0x02,0x1F,0xE3,0xFC,0x00,0x14,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"}",93*/
/* (12 X 24 , Times New Roman ) */
{0x00,0x00,0x00,0x30,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x20,0x00,0x00,0x10,0x00,0x00,0x18,0x00,0x00,0x08,0x00,0x00,0x08,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00},/*"~",94*/
/* (12 X 24 , Times New Roman ) */
};
#endif
