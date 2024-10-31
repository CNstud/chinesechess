#include"game.h"
void Initqipugraph(int arr[11][10], int x, int y) {
	int i, j;
	IMAGE background, blackcar, blackhorse, blackele, blackbac, blackgen, blackgun, blacksolider,
		redcar, redhorse, redele, redbac, redgen, redgun, redsolider, dise;
	loadimage(&background, L"纸质背景.jpg", 14 * UNIT, 12 * UNIT);
	loadimage(&dise, L"dise.jpg", 1 * UNIT, 1 * UNIT);
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
	roundrect(10.2 * UNIT, 5.5 * UNIT, 12.7 * UNIT, 6.5 * UNIT, 0.5 * UNIT, 0.5 * UNIT);
	outtextxy(10.45 * UNIT, 5.6 * UNIT, L"回 退");
	roundrect(10.2 * UNIT, 4 * UNIT, 12.7 * UNIT, 5 * UNIT, 0.5 * UNIT, 0.5 * UNIT);
	outtextxy(10.35 * UNIT, 4.1 * UNIT, L"下一步");
	roundrect(10.2 * UNIT, 2.5 * UNIT, 12.7 * UNIT, 3.5 * UNIT, 0.5 * UNIT, 0.5 * UNIT);
	outtextxy(10.35 * UNIT, 2.6 * UNIT, L"复 盘");
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 10; j++) {
			if (arr[i][j] < 0) {
				if (arr[i][j] == -1) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackcar, SRCPAINT);//利用原图和掩码图矢量异或打印出透明图
				}
				if (arr[i][j] == -2) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackhorse, SRCPAINT);
				}
				if (arr[i][j] == -3) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackele, SRCPAINT);
				}
				if (arr[i][j] == -4) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackbac, SRCPAINT);
				}
				if (arr[i][j] == -5) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackgen, SRCPAINT);
				}
				if (arr[i][j] == -6) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blackgun, SRCPAINT);
				}
				if (arr[i][j] == -7) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &blacksolider, SRCPAINT);
				}
			}
			if (arr[i][j] > 0) {
				if (arr[i][j] == 1) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redcar, SRCPAINT);
				}
				if (arr[i][j] == 2) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redhorse, SRCPAINT);
				}
				if (arr[i][j] == 3) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redele, SRCPAINT);
				}
				if (arr[i][j] == 4) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redbac, SRCPAINT);
				}
				if (arr[i][j] == 5) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redgen, SRCPAINT);
				}
				if (arr[i][j] == 6) {
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &dise, SRCAND);
					putimage((j - 0.5) * UNIT, (i - 0.5) * UNIT, &redgun, SRCPAINT);
				}
				if (arr[i][j] == 7) {
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

void guide(int a) {
	initgraph(14 * UNIT, 12 * UNIT);
	int(*arr)[10] = (int(*)[10])malloc(13 * 10 * sizeof(int));
	int count = 0,record = 0;
	int i, j, k,counter = 1,x1,y1,x2,y2;
	FILE* pf= fopen("canju2.txt", "r");
	if (NULL == arr) {
		printf("棋谱arr内存申请失败");
		return;
	}
	int(*way)[11][10] = (int(*)[11][10])malloc(40 * 11 * 10 * sizeof(int));
	if (NULL == way) {
		printf("棋谱way内存申请失败");
		return;
	}
	switch (a) {
	case 1:
		pf = fopen("canju1.txt", "r");break;
	case 2:
		pf = fopen("canju2.txt", "r");break;
	case 3:
		pf = fopen("canju3.txt", "r");break;
	case 4:
		pf = fopen("canju4.txt", "r");break;
	case 5:
		pf = fopen("canju5.txt", "r");break;
	case 6:
		pf = fopen("canju6.txt", "r");break;
	case 7:
		pf = fopen("canju7.txt", "r");break;
	case 9:
		pf = fopen("my_qipu.txt", "r"); break;
	}
	fscanf(pf, "%d", &count);
	for (i = 0; i < count; i++) {
		for (j = 1; j < 11; j++) {
			for (k = 1; k < 10; k++) {
				fscanf(pf, " %d", &way[i][j][k]);
			}
		}
	}
	iniarr(*way,arr);
	Initqipugraph(arr, 0, 0);
	int(*ini)[11][10] = way;
	i = 1;
	while (1) {
		if (counter == count) {
			Sleep(3000);
			if (a == 9) {
				MessageBox(NULL, L"你的棋谱只记录到这里", NULL, MB_APPLMODAL);
			}
			else {
				MessageBox(NULL, L"红方已绝杀对方", NULL, MB_APPLMODAL);
			}
			Sleep(3000);
			break;
		}
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (m.x >= 10.2 * UNIT && m.y >= 4 * UNIT && m.x <= 12.7 * UNIT && m.y <= 5 * UNIT&&record==0) {//下一步,在用户自由点击时不能点下一步
				if (counter <= count) {
					way++;
					counter++;
					if ((way - ini) % 2 == 0)i = 1;
					else i = -1;
					iniarr(*way, arr);
					Initqipugraph(arr, 0, 0);
					mciSendString(_T("close luozi "), NULL, 0, NULL);
					mciSendString(L"open luozi.mp3 alias luozi", 0, 0, 0);
					mciSendString(_T("play luozi"), NULL, 0, NULL);
					if (jiangjun(arr, -i)) {
						Sleep(100);
						//播放音乐将军
						mciSendString(_T("close jiangjun "), NULL, 0, NULL);
						mciSendString(L"open jiangjun.mp3 alias jiangjun", 0, 0, 0);
						mciSendString(_T("play jiangjun"), NULL, 0, NULL);
					}
				}
			}
			else if (m.x >= 10.2 * UNIT && m.y >= 5.5 * UNIT && m.x <= 12.7 * UNIT && m.y <= 6.5 * UNIT) {//回退
				if ((way - ini) % 2 == 0)i = 1;
				else i = -1;
				iniarr(*way,arr);
				Initqipugraph(arr, 0, 0);
				record = 0;
				counter = (int)(way-ini+1);
				continue;
			}
			else if (m.x >= 10.2 * UNIT && m.y >= 2.5 * UNIT && m.x <= 12.7 * UNIT && m.y <= 3.5 * UNIT) {//复盘
				i = 1;
				way = ini;
				iniarr(*way,arr);
				Initqipugraph(arr, 0, 0);
				counter = 1;
				record = 0;
				continue;
			}
			else if (m.x >= (UNIT / 2) && m.x <= 9.5 * UNIT && m.y >= (UNIT / 2) && m.y <= 10.5 * UNIT) {//处于棋盘中开始自由操作
				x1 = (m.y + UNIT / 2) / UNIT;
				y1 = (m.x + UNIT / 2) / UNIT;
			again:
				if (i * arr[x1][y1] > 0) {
					Initqipugraph(arr, x1, y1);
					while (1) {
						m = GetMouseMsg();
						if (m.uMsg == WM_LBUTTONDOWN) {
							x2 = (m.y + UNIT / 2) / UNIT;
							y2 = (m.x + UNIT / 2) / UNIT;
							if (arr[x2][y2] * arr[x1][y1] > 0) {
								x1 = x2;
								y1 = y2;
								goto again;
							}
							if (arr[x1][y1] * arr[x2][y2] <= 0) {
								if (judge(x1, y1, x2, y2, arr, i)) {
									record = 1;
									mciSendString(_T("close luozi "), NULL, 0, NULL);
									mciSendString(L"open luozi.mp3 alias luozi", 0, 0, 0);
									arr[x2][y2] = arr[x1][y1];
									arr[x1][y1] = 0;
									Initqipugraph(arr, x2, y2);
									mciSendString(_T("play luozi"), NULL, 0, NULL);
									if (jiangjun(arr, i)) {
										Sleep(100);               
										mciSendString(_T("close jiangjun "), NULL, 0, NULL);
										mciSendString(L"open jiangjun.mp3 alias jiangjun", 0, 0, 0);
										mciSendString(_T("play jiangjun"), NULL, 0, NULL);
									}
									i = -i;
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}