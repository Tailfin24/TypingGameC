#pragma once
/* Draw.h
 * -------------
 * 绘制相关函数
 */
#include <graphics.h>
void drawChoice(); //绘制选项界面

void draw(); //总控：绘制整个界面

void drawMap(); //绘制地图
void drawText(); //绘制文字
void drawBlocks(); //绘制砖块
void drawKeyBoard(); //绘制键盘
void drawLetter(); //绘制字母
void drawEnd(); //绘制结束界面

void keyPress(int i); //绘制按键按下时变红
void keyDraw(int i); //绘制按键
