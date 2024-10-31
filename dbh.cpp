#include"game.h"
int car(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	int temp1, temp2, count = 0;
	if (x1 == x2) {//车只能在直线上移动
		temp1 = y1 > y2 ? y2 : y1;
		temp2 = y1 > y2 ? y1 : y2;
		for (i = temp1 + 1; i < temp2; i++) {
			if (arr[x1][i] != 0)
				count++;
		}//判断车与目标位置中间是否有子
		if (count == 0)
			return 1;//中间无子时可以行进
	}
	if (y1 == y2) {
		temp1 = x1 > x2 ? x2 : x1;
		temp2 = x1 > x2 ? x1 : x2;
		for (i = temp1 + 1; i < temp2; i++) {
			if (arr[i][y1] != 0)
				count++;
		}//判断车与目标位置中间是否有子
		if (count == 0)
			return 1;//中间无子时可以行进
	}
	return 0;
}

int gun(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	int temp1, temp2, count = 0;
	if (x1 == x2) {//炮只能在直线上移动
		temp1 = y1 > y2 ? y2 : y1;
		temp2 = y1 > y2 ? y1 : y2;
		for (i = temp1 + 1; i < temp2; i++) {
			if (arr[x1][i] != 0)
				count++;
		}//判断炮与目标位置中间是否有子
		if ((count == 0 && arr[x2][y2] == 0) || (count == 1 && arr[x2][y2] != 0))
			return 1;//中间和末位置无子或中间有炮架时可行
	}
	if (y1 == y2) {//炮只能在直线上移动
		temp1 = x1 > x2 ? x2 : x1;
		temp2 = x1 > x2 ? x1 : x2;
		for (i = temp1 + 1; i < temp2; i++) {
			if (arr[i][y1] != 0)
				count++;
		}//判断炮与目标位置中间是否有子
		if ((count == 0 && arr[x2][y2] == 0) || (count == 1 && arr[x2][y2] != 0))
			return 1;//中间和末位置无子或中间有炮架时可行
	}
	return 0;
}