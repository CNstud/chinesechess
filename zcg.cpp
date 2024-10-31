#include"game.h"
int ele(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	int detax = x2 - x1;
	int detay = y2 - y1;
	if (i > 0) {//红方行棋时
		if (x2 < 5)
			return 0;//不能过河
	}
	if (i < 0) {//黑方行棋时
		if (x2 > 5)
			return 0;//不能过河
	}
	if (detax * detax + detay * detay == 8) {//象走“田”字
		if (arr[x1 + detax / 2][y1 + detay / 2] == 0)
			return 1;//田字中心点无子时可以行棋
	}
	return 0;
}

int gen(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	int detax = x2 - x1;
	int detay = y2 - y1;
	int x = 1;
	int tmp = 0;
	if (!(detax * detax + detay * detay == 1))
		return 0;
	if (i < 0) {//黑方行棋时
		if (!(x2 <= 3 && x2 >= 1 && y2 >= 4 && y2 <= 6))
			return 0;
		for (x = 1; x <= 10; x++) {
			if (arr[x][y2] == 5)
				tmp = x;//判断y2轴上有无对方的将
		}
		if (tmp == 0)
			return 1;//没找到，直接返回1
		for (x = x2 + 1; x <= tmp - 1; x++) {
			if (arr[x][y2] != 0)
				return 1;
		}
	}
	if (i > 0) {//红方行棋时
		if (!(x2 <= 10 && x2 >= 8 && y2 >= 4 && y2 <= 6))
			return 0;
		for (x = 10; x >= 1; x--) {
			if (arr[x][y2] == -5)
				tmp = x;//判断y2轴上有无对方的将
		}
		if (tmp == 0)
			return 1;//没找到，直接返回1
		for (x = tmp + 1; x <= x2 - 1; x++) {
			if (arr[x][y2] != 0)
				return 1;
		}
	}
	return 0;
}