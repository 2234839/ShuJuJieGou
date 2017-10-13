// 二叉树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;
typedef struct{
	char data;		//节点
	int weight;	//权重
	int parent;		//父节点
	int lchild;		//左
	int rchild;		//右
}HTNode;

void gouzao(int n,HTNode ht[]){
	int min1,min2;
	min1=min2=1000;
	for (int i = 0; i < 9; i++)
	{
		if(ht[i].parent!=-1){
			if(ht[i].weight<min1){
				min2=min1;min1=ht[i].weight;
			}
			else if(ht[i].weight<min2){
				min2=ht[i].weight;
			}
		}
	}
	cout<<min1<<<<min2
}
void 输出(HTNode ht[]){
	cout<<"data\t"<<"weight\t"<<"lchild\t"<<"parent\t"<<"rchild\t"<<endl;
	for(int i=0;i<9;i++)
		cout<<ht[i].data<<"\t"<<ht[i].weight<<"\t"<<ht[i].lchild<<"\t"<<ht[i].parent<<"\t"<<ht[i].rchild<<"\t"<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HTNode ht[9];HTNode a;
	char ch[5]={'a','b','c','d','e'};

	a.data=NULL;
	a.weight=NULL;
	a.parent=-1;
	a.lchild=-1;
	a.rchild=-1;

	for (int i = 0; i < 9; i++)
	{
		ht[i]=a;
	}
	for (int i = 0; i < 5; i++)
	{
		ht[i].data=ch[i];
		ht[i].weight=i+1;
	}

	输出(ht);
	return 0;
}

