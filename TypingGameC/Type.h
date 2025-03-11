#pragma once
/* Type.h
 * ---------------
 * 三个结构体：被击打的砖块、下落的字母、按键
 */
struct Block {
	int xgrid; //x格数坐标
	int ygrid; //y格数坐标
	bool exist; //这个砖块是否存在
};

struct Letter {
	char letter; //字母的内容
	int xgrid; //x格数坐标
	int y; //y坐标
};

struct Key {
	bool press; //是否按下的状态
	int x; //按键的x坐标
	int y; //按键的y坐标
	char letter; //按键所对应的字母
};
