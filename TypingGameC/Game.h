#pragma once
/* Game.h
 * ---------------
 * 游戏内容
 */
#include "GameData.h"
char* readText(int); //选择字符串

void toSaved(char*); //将字符串转至letterSaved数组中

void createLetter(); //将letterSaved数组中的第一个元素转移到letterCurrent尾部

void getKey(); //接受按键

bool isCollision(Block&, Letter&); //判断是否发生碰撞

bool isCmpKey(char); //判断按键与第一个字母是否对应

void moveLetter(); //移动字母

void clearLetter(Letter* l,unsigned start, int& size); //删除一个字母数组中的第一个字母

bool gameEnd(); //判断游戏是否结束
