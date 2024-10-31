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
	settextstyle(70, 0, L"����");
	settextcolor(RED);
	setbkmode(TRANSPARENT);
	outtextxy(215,30, L"�й�����");
	settextcolor(BLACK);
	settextstyle(35, 0, L"����");
	outtextxy(120,140, L"��ʼ��Ϸ");
	outtextxy(400,140, L"�˳���Ϸ");
	outtextxy(120, 210, L"�ҵ�����");
	outtextxy(400, 210, L"ϵͳ����"); 
	while (1) {
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			if (m.x >= 120 && m.y >= 140 && m.x <= 260 && m.y <= 190)
				return 1;//��ʼ��Ϸ
			if (m.x >= 400 && m.y >= 140 && m.x <= 540 && m.y <= 190)
				return 0;//�˳���Ϸ
			if (m.x >= 120 && m.y >= 210 && m.x <= 260 && m.y <= 250)
				return 2;//�ҵ�����
			if (m.x >= 400 && m.y >= 210 && m.x <= 540 && m.y <= 250)
				return 3;//ϵͳ����
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
		printf("arr�ڴ�����ʧ��");
		exit(0);
	}
	Initarr(arr);
	int i = 1;//��֤�����Լ�˫�����������״̬��
	int temp = 0;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, count = 0, songjiang_count = 0;
	int a, j, k;
	Initgraphic(arr, 0, 0);//��ӡ�������̼�������
	//int temp_x1=0, temp_y1=0, temp_x2 = 0, temp_y2 = 0;
	//��tempΪ���������¼��������ȡ��ѡ�е�ʱ��x1,x2������ɻ���ʧЧ
	int(*way)[11][10] = (int(*)[11][10]) malloc(50 * 11 * 10 * sizeof(int));
	int(*p)[11][10] = way;
	if (NULL == way) {
		printf("way�ڴ�����ʧ��");
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
			if (m.x >= 10.2 * UNIT && m.y >= 4 * UNIT && m.x <= 12.7 * UNIT && m.y <= 5 * UNIT) {//��¼����
				FILE* pf = fopen("my_qipu.txt", "w");
				if (pf == NULL) {
					printf("δ�򿪳ɹ�");
					exit(0);
				}
				fprintf(pf, "%d ", (int)(way - p ));//(*p + a)[j][k]
				for (a = 0; a < (way - p); a++) {//��Ҫ���¼һ��
					for (j = 1; j < 11; j++) {
						for (k = 1; k < 10; k++) {
							fprintf(pf, "%d ", p[a][j][k]);//(*p + a)[j][k]
						}
					}
				}
				MessageBox(NULL, L"���׼�¼�ɹ����뵽�ҵ����ײ鿴����", NULL, MB_APPLMODAL);
				fclose(pf);
				pf = NULL;
			}
			if (m.x >= 10 * UNIT && m.y >= 5.5 * UNIT
				&& m.x <= 12.5 * UNIT && m.y <= 6.5 * UNIT) {//���ڻ��尴ť������,��ʱ����temp����
				if (p != way-1) {
					way--;
					i = -i;
					iniarr(*(way-1), arr);
					Initgraphic(*(way - 1), 0, 0);
				}
				else {
					MessageBox(NULL, L"�����ٻ�����", NULL, MB_APPLMODAL);
				}
				continue;
			}
			if (!(m.x >= (UNIT / 2) && m.x <= 9.5 * UNIT && m.y >= (UNIT / 2) && m.y <= 10.5 * UNIT)) {//�߽��жϣ��õ�һ�ε������������
				continue;
			}
			x1 = (m.y + UNIT / 2) / UNIT;//����c����int֮�����������С��������
			y1 = (m.x + UNIT / 2) / UNIT;//easyx�������x��y�෴
		again:
			if (i * arr[x1][y1] > 0) {//��֤�������壬������
				Initgraphic(arr, x1, y1);
				while (1) {
					m = GetMouseMsg();
					if (m.uMsg == WM_LBUTTONDOWN) {
						if (!(m.x >= (UNIT / 2) && m.x <= 9.5 * UNIT && m.y >= (UNIT / 2) && m.y <= 10.5 * UNIT) &&
							(!(m.x >= 10.2 * UNIT && m.y >= 5.5 * UNIT && m.x <= 12.7 * UNIT && m.y <= 6.5 * UNIT)) &&
							(!(m.x >= 10.2 * UNIT && m.y >= 4 * UNIT && m.x <= 12.7 * UNIT && m.y <= 5 * UNIT))) {//����ȡ��ѡ�У������ǻ�//���λ��ֱ��ȡ��ѡ���ٴλ�ȡ��һ�ε��
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
							if (judge(x1, y1, x2, y2, arr, i)) {//��֤�����Լ�����judge2����������λ��i״̬����i����־�췽���壬��֮��Ȼ��������Ա��������ʹ��i
								mciSendString(_T("close luozi "), NULL, 0, NULL);
								mciSendString(L"open luozi.mp3 alias luozi", 0, 0, 0);
								arr[x2][y2] = arr[x1][y1];
								arr[x1][y1] = 0;
								if (jiangjun(arr, -i)) {//�����֮��Է��ǽ�������ô�ж�Ϊ�ͽ�
									songjiang_count++;
									if (songjiang_count == 2) {
										way = NULL;
										p = NULL;
										free(way);
										if (i < 0) {
											MessageBox(NULL, L"�췽Ӯ�ˣ�", NULL, MB_APPLMODAL);
										}
										else
										{
											MessageBox(NULL, L"�ڷ�Ӯ�ˣ�", NULL, MB_APPLMODAL);
										}
										Sleep(3000);
										exit(0);
									}
									MessageBox(NULL, L"�����ͽ��������\n�����ж���", NULL, MB_APPLMODAL);
									iniarr(*(way-1), arr);//arr�Ѿ��ı䣬ֱ�Ӱ���һ����way����arr
									Initgraphic(arr, 0, 0);
									break;
								}
								songjiang_count = 0;
								iniway(*way, arr);
								Initgraphic(arr, x2, y2);
								mciSendString(_T("play luozi"), NULL, 0, NULL);
								if (jiangjun(arr, i)) {
									Sleep(100);//�������ֽ���                       
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