
#include "stdafx.h"
#include<iostream>//下面不接using会莫名报错
using namespace std;

#define MaxSize 50
#define ElemType int
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

void CreateList(SqList &L, int n) {
	int i;
	for (i = 0; i<n; i++)
		L.data[i] = i + 1;
	L.length = n;
}

void DispList(SqList L) {
	cout << "\n幸存者的位置：\n";
	for (int i = 0; i < L.length; i++)
	{
		cout << L.data[i] << "\t";
		cout << endl;
	}
}

int ListDelete(SqList &L, int i, ElemType &e) {
	int j;
	if (i<1 || i>L.length)
		return 0;
	i--;
	e = L.data[i];
	for (j = i; j<L.length - 1; j++)
		L.data[j] = L.data[j + 1];//前移
	L.length--;
	return 1;
}

void Josephus(SqList &L, int m, int k) {//Josephus(sql,9,29);
	ElemType e;
	int s = 1, n = 0;
	cout << "被杀者的位置：\n";
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j < m; j++)
		{
			//n=n%L.length;
			//n++;
			n = (n + 1) % L.length;
		}
		ListDelete(L, n + 1, e);
		cout << e << '\t';
	}
}
int main() {
	SqList sql;
	CreateList(sql, 30);
	Josephus(sql, 9, 29);
	DispList(sql);
	return 0;
}
