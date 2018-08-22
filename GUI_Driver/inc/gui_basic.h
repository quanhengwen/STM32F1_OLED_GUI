/****************************************************************************************
* 文件名：GUI_BASIC.C
* 功能：GUI基本繪圖函數。進行基本繪圖運算，並調用相應的刷新程序更新LCD顯示。
* 作者：黃紹斌
* 日期：2004.02.26
* 備註：圖形操作層，進行各種圖形運算操作。
****************************************************************************************/
#ifndef  __GUI_BASIC_H
#define  __GUI_BASIC_H


#include "gui_config.h"
#include "lcmdrv.h"

/* 定義坐標數據結構 */
typedef  struct
{  
	uint32_t  x;				// x坐標變量
	uint32_t  y;			// y坐標變量
}PointXY;


/****************************************************************************
* 名稱：GUI_Rectangle()
* 功能：畫矩形。
* 入口參數： x0		矩形左上角的x坐標值
*           y0		矩形左上角的y坐標值
*           x1      矩形右下角的x坐標值
*           y1      矩形右下角的y坐標值
*           color	顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern  void  GUI_Rectangle(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color);


/****************************************************************************
* 名稱：GUI_RectangleFill()
* 功能：填充矩形。畫一個填充的矩形，填充色與邊框色一樣。
* 入口參數： x0		矩形左上角的x坐標值
*           y0		矩形左上角的y坐標值
*           x1      矩形右下角的x坐標值
*           y1      矩形右下角的y坐標值
*           color	填充顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_RectangleFill(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color);


/****************************************************************************
* 名稱：GUI_Square()
* 功能：畫正方形。
* 入口參數： x0		正方形左上角的x坐標值
*           y0		正方形左上角的y坐標值
*           with    正方形的邊長
*           color	顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_Square(uint32_t x0, uint32_t y0, uint32_t  with, TCOLOR  color);


/****************************************************************************
* 名稱：GUI_Line()
* 功能：畫任意兩點之間的直線。
* 入口參數： x0		直線起點的x坐標值
*           y0		直線起點的y坐標值
*           x1      直線終點的x坐標值
*           y1      直線終點的y坐標值
*           color	顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_Line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, TCOLOR color);


/****************************************************************************
* 名稱：GUI_LineWith()
* 功能：畫任意兩點之間的直線，並且可設置線的寬度。
* 入口參數： x0		直線起點的x坐標值
*           y0		直線起點的y坐標值
*           x1      直線終點的x坐標值
*           y1      直線終點的y坐標值
*           with    線寬(0-50)
*           color	顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_LineWith(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint8_t with, TCOLOR color);


/****************************************************************************
* 名稱：GUI_LineS()
* 功能：多個點之間的連續連線。從第一點連到第二點，再連到第三點...
* 入口參數： points  多個點坐標數據的指針，數據排列為(x0,y0)、(x1,y1)、(x2,y2)...
*           no      點數目，至少要大於1
*           color	顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_LineS(uint32_t const *points, uint8_t no, TCOLOR color);


/****************************************************************************
* 名稱：GUI_Circle()
* 功能：指定圓心位置及半徑，畫圓。
* 入口參數： x0		圓心的x坐標值
*           y0		圓心的y坐標值
*           r       圓的半徑
*           color	顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_Circle(uint32_t x0, uint32_t y0, uint32_t r, TCOLOR color);


/****************************************************************************
* 名稱：GUI_CircleFill()
* 功能：指定圓心位置及半徑，畫圓並填充，填充色與邊框色一樣。
* 入口參數： x0		圓心的x坐標值
*           y0		圓心的y坐標值
*           r       圓的半徑
*           color	填充顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_CircleFill(uint32_t x0, uint32_t y0, uint32_t r, TCOLOR color);


/****************************************************************************
* 名稱：GUI_Ellipse()
* 功能：畫正橢圓。給定橢圓的四個點的參數，最左、最右點的x軸坐標值為x0、x1，最上、最下點
*      的y軸坐標為y0、y1。
* 入口參數： x0		最左點的x坐標值
*           x1		最右點的x坐標值
*           y0		最上點的y坐標值
*           y1      最下點的y坐標值
*           color	顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_Ellipse(uint32_t x0, uint32_t x1, uint32_t y0, uint32_t y1, TCOLOR color);


/****************************************************************************
* 名稱：GUI_EllipseFill()
* 功能：畫正橢圓，並填充。給定橢圓的四個點的參數，最左、最右點的x軸坐標值為x0、x1，最上、最下點
*      的y軸坐標為y0、y1。
* 入口參數： x0		最左點的x坐標值
*           x1		最右點的x坐標值
*           y0		最上點的y坐標值
*           y1      最下點的y坐標值
*           color	填充顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_EllipseFill(uint32_t x0, uint32_t x1, uint32_t y0, uint32_t y1, TCOLOR color);


/****************************************************************************
* 名稱：GUI_FloodFill()
* 功能：圖形填充，將指定點內的封閉圖形進行填充。對指定點的顏色區域進行填充，即不是該顏色
*      的像素為邊界(如，指定點上的顏色為紅色，則其它顏色像素均為邊界)。
* 入口參數： x0		指定點的x坐標值
*           y0		指定點的y坐標值
*           color	填充顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍、指定點不在封閉圖形內。
****************************************************************************/
extern void  GUI_FloodFill(uint32_t x0, uint32_t y0, TCOLOR color);


/****************************************************************************
* 名稱：GUI_Arc4()
* 功能：畫弧。起點及終點只能為0度-90度、90度-180度、180度-270度、270度-0度等。即分別
*      為第1-4像限的90度弧。
* 入口參數： x0		圓心的x坐標值
*           y0		圓心的y坐標值
*           r       圓弧的半徑
*           angle	畫弧的像限(1-4)
*           color	顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_Arc4(uint32_t x, uint32_t y, uint32_t r, uint8_t angle, TCOLOR color);



/****************************************************************************
* 名稱：GUI_Arc()
* 功能：指定起點、終點及半徑畫弧(不能畫圓)。使用的是順時針方向畫圖。
* 入口參數： x			圓心的x坐標值
*           y			圓心的y坐標值
*           stangle 	起始角度(0-359度)
*           endangle	終止角度(0-359度)
*           r  			圓的半徑終點
*           color		顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_Arc(uint32_t x, uint32_t y, uint32_t r, uint32_t stangle, uint32_t endangle, TCOLOR color);


/****************************************************************************
* 名稱：GUI_Pieslice()
* 功能：指定起點、終點及半徑扇形(不能畫圓)。使用的是順時針方向畫圖。
* 入口參數： x			圓心的x軸坐標值
*           y			圓心的y軸坐標值
*           stangle 	起始角度(0-359度)
*           endangle	終止角度(0-359度)
*           r  			圓的半徑終點
*           color		顯示顏色
* 出口參數：無
* 說明：操作失敗原因是指定地址超出有效範圍。
****************************************************************************/
extern void  GUI_Pieslice(uint32_t x, uint32_t y, uint32_t r, uint32_t stangle, uint32_t endangle, TCOLOR color);


#endif