#include"game.h"
struct dianji {
	int x;
	int y;
}record;

void Interface(struct dianji * record) {
	int i;
	initgraph(720, 850);
	IMAGE qipubk;
	loadimage(&qipubk, L"qipubk.jpg", 720,850);
	putimage(0, 0, &qipubk);
	setbkmode(TRANSPARENT);
	settextstyle(70, 0, L"����");
	settextcolor(RED);
	outtextxy(150, 25, L"�� �� �� ��");
	settextstyle(50, 0, L"����");
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	for (i = 0; i <= 6; i++) {
		rectangle(75, 140 + 80 * i, 620, 200 + 80 * i);
	}
	settextcolor(BLACK);
	outtextxy(75+125, 144, L"������ʤ��ʿ");
	outtextxy(75+175, 224, L"��������");
	outtextxy(75+125, 304, L"������ʤȱ��");
	outtextxy(75+125, 384, L"������ʤȱʿ");
	outtextxy(75+75, 464, L"���߱�ʿʤ����ʿ");
	outtextxy(75+100, 544, L"˫����ʤʿ��ȫ");
	outtextxy(75+100, 624, L"����ʿ��ʤ˫ʿ");
	outtextxy(270, 740, L"�� ��");
	while (1) {
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) {
			record->x = m.x;
			record->y = m.y;
			return;
		}
	}
}

void qipu() {
	int i, j;
	Interface(&record);
	int a = (record.y - 140) / 80;
	if (a==7||a==8) {
		game();
		return;
	}
	guide(a+1);
}