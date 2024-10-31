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
	settextstyle(70, 0, L"楷体");
	settextcolor(RED);
	outtextxy(150, 25, L"经 典 棋 谱");
	settextstyle(50, 0, L"楷体");
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	for (i = 0; i <= 6; i++) {
		rectangle(75, 140 + 80 * i, 620, 200 + 80 * i);
	}
	settextcolor(BLACK);
	outtextxy(75+125, 144, L"单马例胜单士");
	outtextxy(75+175, 224, L"单兵擒王");
	outtextxy(75+125, 304, L"单车例胜缺象");
	outtextxy(75+125, 384, L"单车例胜缺士");
	outtextxy(75+75, 464, L"车高兵士胜车单士");
	outtextxy(75+100, 544, L"双马例胜士象全");
	outtextxy(75+100, 624, L"单炮士例胜双士");
	outtextxy(270, 740, L"退 出");
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