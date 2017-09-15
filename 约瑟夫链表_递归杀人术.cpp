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
		cout << s << "\t";
	}
	r->next = NULL;
}
int h = 30;
void shuchu(LiList *&L) {
	Node *p = L;
	p = p->next;
	for (int i = 0; i <h; i++)
	{
		cout << p->data << "\t";
		p = p->next;
	}
}

void sharen(LiList *&L, int a, int b) {//隔几人杀一人  杀至几人
	int e;							   //liDelete(L,9);
	int s = 1, n = 0;

}
int ii = 1;
int diguisharen(LiList *&L, Node *p,Node *s) {
	cout << p<<"  s:"<<s<<"\n";
	if (ii == 8) {
		ii = 1;
		s = p->next;
		p = p->next;
		cout << "击杀" << p->data << "号\n";
		s->next = p->next;//
		Node *temp;
		temp = p;
		delete p;
		p->next = temp->next;
		cout <<"应该等于十"<< p;
		h--;
		//shuchu(L);
		return diguisharen(L, p, s);
	}
	else
	{
		if (p->next == NULL) {
			p = L;
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
	shuchu(L);
	Node *p = L->next, *s = L->next;
	cout << "返回值" << diguisharen(L,p,s);
	cout << "返回值" << diguisharen(L, p, s);
	shuchu(L);
	return 0;
}
