#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<graphics.h>
#include<mmsystem.h>
#include<Windows.h>
#include<assert.h>
#pragma comment(lib,"winmm.lib")
#define UNIT 70//设置单元格大小
int Choosewhetherbegin();//己方子力判断
void Initarr(int arr[11][10]);//对每个棋子进行特殊赋值
void Initgraphic(int arr[11][10], int x, int y);//打印象棋棋盘及各个子
void Step();//开始行棋
void game();//初始界面
int judge(int x1, int y1, int x2, int y2,int arr[11][10], int  i);//判断能否吃子
int car(int x1, int y1, int x2, int y2, int arr[11][10], int i);//车的规则
int gen(int x1, int y1, int x2, int y2, int arr[11][10], int i);//将的规则
int ele(int x1, int y1, int x2, int y2, int arr[11][10], int i);//象的规则
int gun(int x1, int y1, int x2, int y2, int arr[11][10], int i);//炮的规则
int bac(int x1, int y1, int x2, int y2, int arr[11][10], int i);//士的规则
int solider(int x1, int y1, int x2, int y2, int arr[11][10], int i);//兵的规则
int horse(int x1, int y1, int x2, int y2, int arr[11][10], int i);//马的规则
int jiangjun( int arr[11][10], int i);//将军的判断
void iniway(int p[11][10], int arr[11][10]);
void iniarr(int p[11][10], int arr[11][10]);
void qipu();//棋谱功能
void Initqipugraph(int arr[11][10],int x,int y);//查看棋谱时绘制棋盘
void guide(int a);//引导使用者查看经典棋谱或已下棋局棋谱