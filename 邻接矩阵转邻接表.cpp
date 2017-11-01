// 临时.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define MAX 4//邻接矩阵的大小

struct 弧结点{
	int 指向;
	struct 弧结点 *指针;
};
struct 邻接表头节点
{
	char 顶点信息;
	弧结点 弧结点;
};
void 初始化邻接表(邻接表头节点 邻接表[]) {
	弧结点 a;
	a.指向 = -1;
	a.指针 = NULL;
	for (int i = 0; i < MAX; i++)
	{
		邻接表[i].顶点信息 = 65+i;//由ascii码从 A 开始赋值
		邻接表[i].弧结点 = a;
	}
	邻接表[0].弧结点 = a;
}
void 添加弧结点(邻接表头节点 &邻接表头节点,int j) {
	if (邻接表头节点.弧结点.指向 == NULL)
		邻接表头节点.弧结点.指向 = j;
	else
	{
		弧结点 *temp=new 弧结点();
		temp->指向 = j;
		temp->指针 = NULL;
		弧结点 *指向= &邻接表头节点.弧结点;
		while (指向->指针 != NULL)
			指向 = 指向->指针;
		指向->指针 = temp;
	}
}
void 输出邻接表(邻接表头节点 邻接表[]) {
	弧结点 *指向;
	for (int i = 0; i < MAX; i++)
	{
		cout<<"\n" << 邻接表[i].顶点信息;
		指向 = &邻接表[i].弧结点;
		do
		{if(指向->指向!=-1)
			cout << "->" << char(指向->指向+65);
			指向 = 指向->指针;
		} while (指向 != NULL);
	}
}
int main()
{
	int 邻接矩阵[MAX][MAX] = {	{0,1,1,1},
								{1,0,0,0},
								{1,0,0,1},
								{1,0,1,0}};
	邻接表头节点 邻接表[MAX];
	初始化邻接表(邻接表);

	for (int i = 0; i < MAX; i++)//将邻接矩阵转为邻接表
	{
		for (int j = 0; j < MAX; j++)
		{
			if (邻接矩阵[i][j] == 1)
				添加弧结点(邻接表[i], j);
		}
	}

	输出邻接表(邻接表);
    return 0;
}

