#include"game.h"
int judge(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	switch (arr[x1][y1] * arr[x1][y1]) {
	case 1:
		return car(x1, y1, x2, y2, arr, i);
	case 4:
		return horse(x1, y1, x2, y2, arr, i);
	case 9:
		return ele(x1, y1, x2, y2, arr, i);
	case 16:
		return bac(x1, y1, x2, y2, arr, i);
	case 25:
		return gen(x1, y1, x2, y2, arr, i);
	case 36:
		return gun(x1, y1, x2, y2, arr, i);
	case 49:
		return solider(x1, y1, x2, y2, arr, i);
	}
	return 0;
}

int Choosewhetherbegin() {
	initgraph(700,300);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(0, L"begin.jpg");
	settextstyle(70, 0, L"楷体");
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	outtextxy(215,30, L"中国象棋");
	settextcolor(BLACK);
	settextstyle(35, 0, L"楷体");
	outtextxy(120,140, L"开始游戏");
	outtextxy(400,140, L"退出游戏");
	outtextxy(120, 210, L"我的棋谱");
	outtextxy(400, 210, L"系统棋谱"); 
	while (1) {
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (m.x >= 120 && m.y >= 140 && m.x <= 260 && m.y <= 190)
				return 1;//开始游戏
			if (m.x >= 400 && m.y >= 140 && m.x <= 540 && m.y <= 190)
				return 0;//退出游戏
			if (m.x >= 120 && m.y >= 210 && m.x <= 260 && m.y <= 250)
				return 2;//我的棋谱
			if (m.x >= 400 && m.y >= 210 && m.x <= 540 && m.y <= 250)
				return 3;//系统棋谱
		}
	}
}

void Initarr(int arr[11][10]) {
	int i,j;
	for (i = 0; i < 11; i++) {
		for (j = 0; j < 10; j++)
			arr[i][j] = 0;
	}
	for (i = 0; i < 10; i++) {
		arr[0][i] = 1;
	}
	for (i = 0; i < 11; i++) {
		arr[i][0] = 1;
	}
	for (i = 1; i <= 9; i++) {
		if (i < 5) {
			arr[1][i] = -i;
			arr[10][i] = i;
		}
		if (i >= 5) {
			arr[1][i] = i - 10;
			arr[10][i] = 10 - i;
		}
	}
	for (i = 1; i <= 5; i++) {
		arr[4][2 * i - 1] = -7;
		arr[7][2 * i - 1] = 7;
	}
	arr[3][2] = -6;
	arr[3][8] = -6;
	arr[8][2] = 6;
	arr[8][8] = 6;
}

void Step() {
	int(*arr)[10] = (int(*)[10])malloc(11 * 10 * sizeof(int));
	if (NULL == arr) {
		printf("arr内存申请失败");
		exit(0);
	}
	Initarr(arr);
	int i = 1;//保证红先以及双方依次行棋的状态量
	int temp = 0;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, count = 0, songjiang_count = 0;
	int a, j, k;
	Initgraphic(arr, 0, 0);//打印象棋棋盘及各个子
	//int temp_x1=0, temp_y1=0, temp_x2 = 0, temp_y2 = 0;
	//用temp为悔棋增添记录量，以免取消选中的时候x1,x2更改造成悔棋失效
	int(*way)[11][10] = (int(*)[11][10]) malloc(50 * 11 * 10 * sizeof(int));
	int(*p)[11][10] = way;
	if (NULL == way) {
		printf("way内存申请失败");
		exit(0);
	}
	if (way != NULL) {
		iniway(*way, arr);
	}
	way++;
	while (1) {
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (m.x >= 10.2 * UNIT && m.y >= 4 * UNIT && m.x <= 12.7 * UNIT && m.y <= 5 * UNIT) {//记录棋谱
				FILE* pf = fopen("my_qipu.txt", "w");
				if (pf == NULL) {
					printf("未打开成功");
					exit(0);
				}
				fprintf(pf, "%d ", (int)(way - p ));//(*p + a)[j][k]
				for (a = 0; a < (way - p); a++) {//需要多记录一步
					for (j = 1; j < 11; j++) {
						for (k = 1; k < 10; k++) {
							fprintf(pf, "%d ", p[a][j][k]);//(*p + a)[j][k]
						}
					}
				}
				MessageBox(NULL, L"棋谱记录成功，请到我的棋谱查看详情", NULL, MB_APPLMODAL);
				fclose(pf);
				pf = NULL;
			}
			if (m.x >= 10 * UNIT && m.y >= 5.5 * UNIT
				&& m.x <= 12.5 * UNIT && m.y <= 6.5 * UNIT) {//处于悔棋按钮的区域,此时利用temp更改
				if (p != way-1) {
					way--;
					i = -i;
					iniarr(*(way-1), arr);
					Initgraphic(*(way - 1), 0, 0);
				}
				else {
					MessageBox(NULL, L"不能再悔棋了", NULL, MB_APPLMODAL);
				}
				continue;
			}
			if (!(m.x >= (UNIT / 2) && m.x <= 9.5 * UNIT && m.y >= (UNIT / 2) && m.y <= 10.5 * UNIT)) {//边界判断，让第一次点击处于棋盘内
				continue;
			}
			x1 = (m.y + UNIT / 2) / UNIT;//利用c语言int之间相除不保留小数的特性
			y1 = (m.x + UNIT / 2) / UNIT;//easyx和数组的x，y相反
		again:
			if (i * arr[x1][y1] > 0) {//保证依次行棋，红先行
				Initgraphic(arr, x1, y1);
				while (1) {
					m = GetMouseMsg();
					if (m.uMsg == WM_LBUTTONDOWN) {
						if (!(m.x >= (UNIT / 2) && m.x <= 9.5 * UNIT && m.y >= (UNIT / 2) && m.y <= 10.5 * UNIT) &&
							(!(m.x >= 10.2 * UNIT && m.y >= 5.5 * UNIT && m.x <= 12.7 * UNIT && m.y <= 6.5 * UNIT)) &&
							(!(m.x >= 10.2 * UNIT && m.y >= 4 * UNIT && m.x <= 12.7 * UNIT && m.y <= 5 * UNIT))) {//处于取消选中，但不是悔//棋的位置直接取消选中再次获取第一次点击
							Initgraphic(arr, 0, 0);
							break;
						}
						x2 = (m.y + UNIT / 2) / UNIT;
						y2 = (m.x + UNIT / 2) / UNIT;
						if (arr[x2][y2] * arr[x1][y1] > 0) {
							x1 = x2;
							y1 = y2;
							goto again;
						}
						if (arr[x1][y1] * arr[x2][y2] <= 0) {
							if (judge(x1, y1, x2, y2, arr, i)) {//保证不吃自己子力judge2函数限制走位，i状态量（i正标志红方行棋，反之亦然），各组员依据需求使用i
								mciSendString(_T("close luozi "), NULL, 0, NULL);
								mciSendString(L"open luozi.mp3 alias luozi", 0, 0, 0);
								arr[x2][y2] = arr[x1][y1];
								arr[x1][y1] = 0;
								if (jiangjun(arr, -i)) {//如果走之后对方是将军，那么判断为送将
									songjiang_count++;
									if (songjiang_count == 2) {
										way = NULL;
										p = NULL;
										free(way);
										if (i < 0) {
											MessageBox(NULL, L"红方赢了！", NULL, MB_APPLMODAL);
										}
										else
										{
											MessageBox(NULL, L"黑方赢了！", NULL, MB_APPLMODAL);
										}
										Sleep(3000);
										exit(0);
									}
									MessageBox(NULL, L"不能送将，请变招\n否则将判定负", NULL, MB_APPLMODAL);
									iniarr(*(way-1), arr);//arr已经改变，直接把上一步的way赋给arr
									Initgraphic(arr, 0, 0);
									break;
								}
								songjiang_count = 0;
								iniway(*way, arr);
								Initgraphic(arr, x2, y2);
								mciSendString(_T("play luozi"), NULL, 0, NULL);
								if (jiangjun(arr, i)) {
									Sleep(100);//播放音乐将军                       
									mciSendString(_T("close jiangjun "), NULL, 0, NULL);
									mciSendString(L"open jiangjun.mp3 alias jiangjun", 0, 0, 0);
									mciSendString(_T("play jiangjun"), NULL, 0, NULL);
								}
								i = -i;
								way++;
								count++;
								break;
							}
						}
					}
				}
			}
		}
	}
}