#include "stdafx.h"
#include <iostream>
using namespace std;
#define MaxSize 100    //不用分号
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;   //栈顶指针[伪]    栈顶元素的下标
}SqStack;

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

int _tmain(int argc, _TCHAR* argv[])
{
	SqStack s;
	ElemType e;
	初始化(s);
	进栈(s, 10);
	进栈(s, 100);
	出栈(s, e);
	取栈顶元素(s,e);
	cout << e;
	return 0;
}
