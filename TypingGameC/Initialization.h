#pragma once
/* Initialization.h
 * -------------
 * 对变量的初始化内容
 */
#include "GameData.h"

void keyInit(); //初始化键盘参数
int keyX(char); //为对应的按键找到x坐标
int keyY(char); //为对应的按键找到y坐标

void blockInit(); //初始化砖块参数
void clearData(); //清除上一次游戏的数据
