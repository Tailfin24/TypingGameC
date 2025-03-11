#pragma once
/* GameData.h
 * -------------
 * 程序会用到的数据
 */
#include "Type.h"
#include <cctype>
#include <cstdlib>
#include <windows.h>

/*常量*/
const unsigned GRID = 32; //定义一格的像素大小
const unsigned WINDOW_X = 18 * GRID; //窗口的x坐标
const unsigned WINDOW_Y = 18 * GRID; //窗口的y坐标

const unsigned Q_X = 50; //Q键的x坐标
const unsigned Q_Y = 360; //Q键的y坐标
const unsigned SIZE_OF_KEY = 48; //一个键位的大小

const unsigned SPEED = 3; //字母一次循环移动的距离


const unsigned SIZE_OF_STRINGS = 5; //待选字符串数量
const unsigned TIME_OF_LETTER = 360; //过多少时间出现一个字母



/*变量*/
extern int choice; //储存选择的选项 
extern unsigned score; //分数
extern unsigned gameTime; //时间
extern Key key[26];
extern Block block[10][4];
extern Letter letterSaved[100], letterCurrent[100]; //分别表示未出现在屏幕上的字母、已出现在屏幕上的字母
extern int sizeSaved, sizeCurrent; //表示letterSaved和letterCurrent数组的大小

/*文本数据*/
extern char text1[];
extern char text2[];
extern char text3[];
extern char text4[];
extern char text5[];
extern char text6[];
extern char text7[];

/*其他*/
#define random(a,b) (rand() % (b - a + 1)) + a //重定义随机数
