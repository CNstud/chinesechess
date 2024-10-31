#include"game.h"
void game() {
	int a= Choosewhetherbegin();
	if (a == 0) {
		return;
	}
	else if (a == 1) {
		initgraph(14 * UNIT, 12 * UNIT);
		Step();//¿ªÊ¼ÐÐÆå
	}
	else if (a == 2) {
		guide(9);
	}
	else {
		qipu();
	}
	return;
}

int main() {
	game();
	return 0;
}