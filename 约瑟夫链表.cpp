// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef struct  Node
{
	int data;
	struct Node *next;
}LiList;

void CreateListR(LiList *&L,int a[],int n){
	LiList *s,*r;
	int i;L=new LiList ;
	r=L;
	for (i = 0; i < n; i++)
	{
		s=new LiList();
		s->data=a[i];
		r->next=s;
		r=s;
		cout<<s<<"\t";
	}
	r->next=NULL;
}
int h=30;
void shuchu(LiList *&L){
	Node *p=L;
	p=p->next;
	for (int i = 0; i <h; i++)
	{
		cout<<p->data<<"\t";
		p=p->next;
	}
}


void liDelete(LiList *&L,int a){//删除掉第几个
	Node *p=L,*s=L;
	p=p->next;
	for (int i = 0; i <a-2; i++)
	{
		s=p->next;
		p=p->next;
		//cout<<s<<":"<<i<<"\t";
	}
	p=s->next;
	s->next=p->next;
	cout<<"击杀"<<p->data<<"号\n";
	delete p;
	h--;
}
void sharen(LiList *&L,int a,int b){//隔几人杀一人  杀至几人
	//liDelete(L,9);
	int s=1,n=0;
	cout<<"被杀者的位置：\n";
	for (int i = 1; i <= h-b; i++)
	{
		for (int j = 1; j < a+1; j++)
		{
			//n=n%L.length;
			//n++;
			n=(n+1)%h;
		}
		liDelete(L,n+1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[30];
	for (int i = 1; i < h+1; i++)
	{
		a[i-1]=i;
	}
	LiList *L;
	CreateListR(L,a,h);
	shuchu(L);
	sharen(L,8,15);
	shuchu(L);
	return 0;
}

