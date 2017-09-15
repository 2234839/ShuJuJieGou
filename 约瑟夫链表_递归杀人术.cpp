#include "stdafx.h"
#include <iostream>
	using namespace std;
typedef struct  Node
{
	int data;
	struct Node *next;
}LiList;

void CreateListR(LiList *&L, int a[], int n) {
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
int h = 30;
void shuchu(LiList *&L) {
	Node *p = L;
	p = p->next;
	for (int i = 0; i <h; i++)
	{
		//cout << p << ":" << p->data << "\t";
		p = p->next;
	}
	//cout << "\n";
}

int ii = 1;
Node *t;
void 后移(LiList *&p, LiList *&L) {
	if (p->next=NULL)
		p = L->next;
	else
		p = p->next;
}
int diguisharen(LiList *&L, Node *p, Node *s) {
	
	//cout << p<<":"<<p->data<<"\n";
	if (ii == 8) {
		ii = 1; //重新开始数数
		Node *r;
		r = p->next;//r成为了第九个节点
		if (r->next != NULL)
			p->next = r->next;//连接第九与第十个节点
		else
			p->next = L->next;
		cout << "击杀" << r->data << "号\n";
		delete r;//删除第九个节点
		if (p->next == NULL)
			p = L->next;
		else
			p = p->next;

		h--;
		return diguisharen(L, p, s);
	}
	else
	{
		if (p->next == NULL) {
			p = t->next;
			ii++;
			//cout << "L的请况" << p->data << "||" <<p->next << "\n";
			shuchu(L);
			return diguisharen(L, p, s);
		}
		else
		{
			p = p->next;
			ii++;
			return diguisharen(L, p, s);
		}
	}
	return diguisharen(L, p, s);


}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[30];
	for (int i = 1; i < h + 1; i++)
	{
		a[i - 1] = i;
	}
	LiList *L;
	CreateListR(L, a, h);
	t=L;
	shuchu(L);
	Node *p = L->next, *s = L->next;
	cout << "返回值" << diguisharen(L, p, s);
	cout << "返回值" << diguisharen(L, p, s);
	shuchu(L);
	return 0;
}
