#include"game.h"
int car(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	int temp1, temp2, count = 0;
	if (x1 == x2) {//��ֻ����ֱ�����ƶ�
		temp1 = y1 > y2 ? y2 : y1;
		temp2 = y1 > y2 ? y1 : y2;
		for (i = temp1 + 1; i < temp2; i++) {
			if (arr[x1][i] != 0)
				count++;
		}//�жϳ���Ŀ��λ���м��Ƿ�����
		if (count == 0)
			return 1;//�м�����ʱ�����н�
	}
	if (y1 == y2) {
		temp1 = x1 > x2 ? x2 : x1;
		temp2 = x1 > x2 ? x1 : x2;
		for (i = temp1 + 1; i < temp2; i++) {
			if (arr[i][y1] != 0)
				count++;
		}//�жϳ���Ŀ��λ���м��Ƿ�����
		if (count == 0)
			return 1;//�м�����ʱ�����н�
	}
	return 0;
}

int gun(int x1, int y1, int x2, int y2, int arr[11][10], int i) {
	int temp1, temp2, count = 0;
	if (x1 == x2) {//��ֻ����ֱ�����ƶ�
		temp1 = y1 > y2 ? y2 : y1;
		temp2 = y1 > y2 ? y1 : y2;
		for (i = temp1 + 1; i < temp2; i++) {
			if (arr[x1][i] != 0)
				count++;
		}//�ж�����Ŀ��λ���м��Ƿ�����
		if ((count == 0 && arr[x2][y2] == 0) || (count == 1 && arr[x2][y2] != 0))
			return 1;//�м��ĩλ�����ӻ��м����ڼ�ʱ����
	}
	if (y1 == y2) {//��ֻ����ֱ�����ƶ�
		temp1 = x1 > x2 ? x2 : x1;
		temp2 = x1 > x2 ? x1 : x2;
		for (i = temp1 + 1; i < temp2; i++) {
			if (arr[i][y1] != 0)
				count++;
		}//�ж�����Ŀ��λ���м��Ƿ�����
		if ((count == 0 && arr[x2][y2] == 0) || (count == 1 && arr[x2][y2] != 0))
			return 1;//�м��ĩλ�����ӻ��м����ڼ�ʱ����
	}
	return 0;
}