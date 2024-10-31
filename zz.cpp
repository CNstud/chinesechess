#include"game.h"
int horse(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	int detay = y2 - y1;
	int detax = x2 - x1;
	if (detay * detay + detax * detax == 5) {//马走“日”字
		if (detax*detax == 4) {//倒日字情况
			if (arr[(x1 + x2) / 2][y1] != 0)
				return 0;//蹩脚马情况时不能行棋
		}
		if (detay * detay == 4) {//正日字情况
			if (arr[x1][(y1 + y2) / 2] != 0)
				return 0;//蹩脚马情况时不能行棋
		}
		return 1;
	}
	return 0;
}

int bac(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	int detay = y2 - y1;
	int detax = x2 - x1;
	if (detay * detay + detax * detax == 2) {//士每步只能在九宫中斜向行一格
		if (i > 0) {//红方行棋情况
			if (x2 >= 8 && x2 <= 10 && y2 >= 4 && y2 <= 6)//限制士在九宫内行进
				return 1;
		}
		if (i < 0) {//黑方行棋情况
			if (x2 >= 1 && x2 <= 3 && y2 >= 4 && y2 <= 6)//限制士在九宫内行进
				return 1;
		}
	}
	return 0;
}

int jiangjun(int arr[11][10], int i) {
	int x=0, y=0,j=0,a,b,count=0;
	int storage[11][2] = { 0 };
	for (a = 1; a < 11; a++) {
		for (b = 1; b < 10; b++) {
			if (arr[a][b] == i * 7 || arr[a][b] == i * 6 || arr[a][b] == 2 * i || arr[a][b] == i) {
				storage[count][0] = a;
				storage[count][1] = b;
				count++;
			}
			if (arr[a][b] == -i * 5) {
				j = 1;
				x = a;
				y = b;
			}
		}
	}//同时遍历数组，找到对方将的位置以及我方车马炮兵的位置
	for (a = 0; a < count; a++) {
		if (j == 1 && judge(storage[a][0], storage[a][1], x, y, arr,i))
			return 1;
	}//对每一个车马炮兵判断是否可以走到，走到即将军
	return 0;
}

void iniway(int way[11][10], int arr[11][10]) {
	int i, j;
	for (i = 1; i <= 11; i++) {
		for (j = 1; j <= 10;j++) {
			way[i][j] = arr[i][j];
		}
	}
}

void iniarr(int way[11][10], int arr[11][10]) {
	int i, j;
	for (i = 1; i <= 11; i++) {
		for (j = 1; j <= 10;j++) {
			arr[i][j] = way[i][j];
		}
	}
}