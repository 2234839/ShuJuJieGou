#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct  Node
{
	int data;
	struct Node *next;
}LiList;
int h = 30;//设置共有多少人
int ii = 1;//用来计数

void CreateListR(LiList *&L, int a[], int n) {//尾插法创建单链表
	LiList *s, *r;
	int i; L = new LiList;
	r = L;
	for (i = 0; i < n; i++)
	{
		s = new LiList();
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}
int diguisharen(LiList *&L, Node *p,int x) {
	if (h == x)//递归终止条件
		return x;
	if (ii == 8) {//该杀人了
		ii = 1; //重新开始数数
		Node *r;
		r = p->next;//r成为了第九个节点

		if (r->next != NULL)//此判断结构用于链接表尾与表头  防止非法访问地址
			p->next = r->next;//连接p节点前一个与后面一个个节点
		else
			p->next = L->next;

		cout << "杀" << r->data << "号\t";
		delete r;//删除节点

		if (p->next == NULL)
			p = L->next;
		else
			p = p->next;

		h--;
		return diguisharen(L, p,x);
	}
	else//往下数人头
	{
		if (p->next == NULL) {//从表尾跳到表头
			p = L->next;
			ii++;
			return diguisharen(L, p,x);
		}
		else//读取下一个节点
		{
			p = p->next;
			ii++;
			return diguisharen(L, p,x);
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[30];
	for (int i = 1; i < h + 1; i++)//数组赋值
		a[i - 1] = i;
	LiList *L;
	CreateListR(L, a, h);
	Node *p = L->next, *s = L->next;
	cout<<"\n还存活"<<diguisharen(L, p,1);//L=人员链表  p=用于处理的节点   杀到剩1人
	cout << "人\n";
	return 0;
}
