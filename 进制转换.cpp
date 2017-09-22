#include "stdafx.h"
#include <stdio.h> 
#include <iostream>
using namespace std;
#define MaxSize 100    //不用分号
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;   //栈顶指针[伪]    栈顶元素的下标
}SqStack;
SqStack s;
ElemType e;

void 初始化(SqStack &s){
	s.top = -1;
}

int 取栈的长度(SqStack s){
	return(s.top + 1);
}

bool 栈是否为空(SqStack s){
	return(s.top == -1);
}

void 进栈(SqStack &s,ElemType e) {
	if (s.top == MaxSize)//犯过只用一个等号的错误
		cout << "栈满!"<<s.top<<endl;
	else
	{
		s.top++;
		s.data[s.top] = e;
		//cout<<s.data[s.top];
	}
}

void 出栈(SqStack &s,ElemType &e) {
	if (s.top == -1)
		cout << "空栈!" << endl;
	else
	{
		e = s.data[s.top];
		s.top--;
	}
}

void 取栈顶元素(SqStack s, ElemType &e) {
	if (s.top == -1)
		cout << "栈空  不存在该元素!" << endl;
	else
		e = s.data[s.top];
}

void 转进制(int a,int b){
	char x;
	if(a==0){
		cout<<"结束";
		return ;
	}
	if(a%b>9){
		x=64+a%b-9;
		进栈(s, x);
		cout<<x<<"\t";
	}
	else{
		进栈(s, a%b);
		cout<<a%b<<"\t";
	}
	a=a/b;
	return(转进制(a,b));
}
int _tmain(int argc, _TCHAR* argv[])
{
	char c;
	int a,b;
	cout<<"请输入要转进制的数：\n";
	cin>>a;
	cout<<"请输入要转的进制：\n";
	cin>>b;
	初始化(s);
	//十进制转二进制(4);
	转进制(a,b);
	cout<<"\n"<<b<<"进制：";
	while (!栈是否为空(s))
	{
		出栈(s,e);
		if(e>9){
			c=e;
			cout<<c;
		}
		else
			cout<<e;
	}
	return 0;
}
