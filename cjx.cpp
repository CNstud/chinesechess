#include"game.h"
void Initgraphic(int arr[11][10], int x, int y) {
	int i, j;
	IMAGE background, blackcar, blackhorse, blackele, blackbac, blackgen, blackgun, blacksolider,
		redcar, redhorse, redele, redbac, redgen, redgun, redsolider, dise;
	loadimage(&background,L"纸质背景.jpg", 14 * UNIT, 12 * UNIT);
	loadimage(&dise, L"dise.jpg", 1*UNIT,1*UNIT);
	loadimage(&blackcar, L"blackcar.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&blackhorse, L"blackhorse.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&blackele, L"blackele.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&blackbac, L"blackbac.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&blackgen, L"blackgen.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&blackgun, L"blackgun.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&blacksolider, L"blacksolider.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&redcar, L"redcar.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&redhorse, L"redhorse.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&redele, L"redele.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&redbac, L"redbac.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&redgen, L"redgen.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&redgun, L"redgun.jpg", 1 * UNIT, 1 * UNIT);
	loadimage(&redsolider, L"redsolider.jpg", 1 * UNIT, 1 * UNIT);
	setbkcolor(YELLOW);
	clearrectangle(0, 0, 14 * UNIT, 12 * UNIT);
	putimage(0, 0, &background);
	setbkmode(TRANSPARENT);
	setlinestyle(PS_SOLID, 2);
	setcolor(RGB(0, 0, 0));
	line(1 * UNIT, 1 * UNIT, 1 * UNIT, 10 * UNIT);
	line(9 * UNIT, 1 * UNIT, 9 * UNIT, 10 * UNIT);
	line(1 * UNIT, 10 * UNIT, 9 * UNIT, 10 * UNIT);
	for (i = 2; i <= 8; i++)
		line(i * UNIT, 1 * UNIT, i * UNIT, 5 * UNIT);
	for (i = 2; i <= 8; i++)
		line(i * UNIT, 6 * UNIT, i * UNIT, 10 * UNIT);
	for (i = 1; i <= 10; i++)
		line(1 * UNIT, i * UNIT, 9 * UNIT, i * UNIT);
	line(4 * UNIT, 1 * UNIT, 6 * UNIT, 3 * UNIT);
	line(6 * UNIT, 1 * UNIT, 4 * UNIT, 3 * UNIT);
	line(4 * UNIT, 8 * UNIT, 6 * UNIT, 10 * UNIT);
	line(6 * UNIT, 8 * UNIT, 4 * UNIT, 10 * UNIT);
	settextstyle(UNIT * 4 / 5, 0, L"楷体");
	outtextxy(1.5 * UNIT, 5.1 * UNIT, L"楚  河");
	outtextxy(6.2 * UNIT, 5.1 * UNIT, L"汉  界");
	roundrect(10.2 * UNIT, 5.5 * UNIT, 12.7 * UNIT, 6.5 * UNIT,0.5*UNIT,0.5*UNIT);
	outtextxy(10.45 * UNIT, 5.6 * UNIT, L"悔 棋");
	roundrect(10.2 * UNIT, 4 * UNIT, 12.7 * UNIT, 5 * UNIT, 0.5 * UNIT, 0.5 * UNIT);
	settextstyle(UNIT * 3 / 5, 0, L"楷体");
	outtextxy(10.3 * UNIT, 4.2 * UNIT, L"记录棋谱");
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 10; j++) {
			if (arr[i][j] < 0) {
				if (arr[i][j] ==-1) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackcar, SRCPAINT);//利用原图和掩码图矢量异或打印出透明图
				}
				if (arr[i][j] ==-2) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackhorse, SRCPAINT);
				}
				if (arr[i][j] ==-3) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackele, SRCPAINT);
				}
				if (arr[i][j] ==-4) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackbac, SRCPAINT);
				}
				if (arr[i][j] ==-5) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackgen, SRCPAINT);
				}
				if (arr[i][j]==-6) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackgun, SRCPAINT);
				}
				if (arr[i][j] ==-7) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blacksolider, SRCPAINT);
				}
			}
			if (arr[i][j] > 0) {
				if (arr[i][j] ==1) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redcar, SRCPAINT);
				}
				if (arr[i][j] ==2) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redhorse, SRCPAINT);
				}
				if (arr[i][j] ==3) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redele, SRCPAINT);
				}
				if (arr[i][j] ==4) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redbac, SRCPAINT);
				}
				if (arr[i][j] ==5) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redgen, SRCPAINT);
				}
				if (arr[i][j] ==6) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redgun, SRCPAINT);
				}
				if (arr[i][j] ==7) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redsolider, SRCPAINT);
				}
			}
		}
	}
	if (x != 0 && y != 0) {
		rectangle((y - 0.5) * UNIT, (x - 0.5) * UNIT, (y + 0.5) * UNIT, (x + 0.5) * UNIT);
	}
	return;
}

int solider(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	if (i > 0) {//红方行棋时
		if (x1 > 5) {
			if (x2 - x1 == -1 && y1 == y2)
				return 1;//兵卒过河前只能前进，不可左右行进
		}
		if (x1 <= 5) {
			if ((y2 - y1) * (y2 - y1) == 1 && x1 == x2)
				return 1;//兵卒过河后可以左右行进
			else if (x2 - x1 == -1 && y1 == y2)
				return 1;//兵卒过河后可继续前进
		}
	}
	if (i < 0) {//黑方行棋时
		if (x1 < 6) {
			if (x2 - x1 == 1 && y1 == y2)
				return 1;//兵卒过河前只能前进，不可左右行进
		}
		if (x1 >= 6) {
			if ((y2 - y1) * (y2 - y1) == 1 && x1 == x2)
				return 1;//兵卒过河后可以左右行进
			else if (x2 - x1 == 1 && y1 == y2)
				return 1;//兵卒过河后可继续前进
		}
	}
	return 0;
}