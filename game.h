#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>
#include<Windows.h>
#include<assert.h>
#pragma comment(lib,"winmm.lib")
#define UNIT 70//���õ�Ԫ���С
int Choosewhetherbegin();//���������ж�
void Initarr(int arr[11][10]);//��ÿ�����ӽ������⸳ֵ
void Initgraphic(int arr[11][10], int x, int y);//��ӡ�������̼�������
void Step();//��ʼ����
void game();//��ʼ����
int judge(int x1, int y1, int x2, int y2,int arr[11][10], int  i);//�ж��ܷ����
int car(int x1, int y1, int x2, int y2, int arr[11][10], int i);//���Ĺ���
int gen(int x1, int y1, int x2, int y2, int arr[11][10], int i);//���Ĺ���
int ele(int x1, int y1, int x2, int y2, int arr[11][10], int i);//��Ĺ���
int gun(int x1, int y1, int x2, int y2, int arr[11][10], int i);//�ڵĹ���
int bac(int x1, int y1, int x2, int y2, int arr[11][10], int i);//ʿ�Ĺ���
int solider(int x1, int y1, int x2, int y2, int arr[11][10], int i);//���Ĺ���
int horse(int x1, int y1, int x2, int y2, int arr[11][10], int i);//��Ĺ���
int jiangjun( int arr[11][10], int i);//�������ж�
void iniway(int p[11][10], int arr[11][10]);
void iniarr(int p[11][10], int arr[11][10]);
void qipu();//���׹���
void Initqipugraph(int arr[11][10],int x,int y);//�鿴����ʱ��������
void guide(int a);//����ʹ���߲鿴�������׻������������