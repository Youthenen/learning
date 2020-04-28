#include <iostream>
#include <stdio.h>
// #include <windows.h>
using namespace std;
#define MAXSIZE 105
typedef struct {
	char *base;
	char *top;
	int stacksize;

}SqStack;
void InitStack(SqStack &S)
{
	S.base = new char[MAXSIZE]; //使base指向基地址，即栈底
	if (!S.base)
		exit(-1);
	S.top = S.base;  //空栈
	S.stacksize = MAXSIZE;
}
void push(SqStack &S, char ch)
{
	*S.top = ch;
	S.top++;
}
void pop(SqStack &S)  //删除栈顶元素
{
	S.top--;
}
bool search(SqStack &S)  //括号匹配，成功则返回true
{
	char ch;
	bool flag = 1;
    int count = 0;
    cout << "请输入表达式："; 
	while ((ch = getchar()) != '\n' && (flag != 0))
	{
        count++;
        if(count > 200)
        {
            break;
        }
		switch (ch) {
		case '[':
			push(S, ch);
			break;
		case '(':
			push(S, ch);
			break; 
		case '{':
			push(S, ch);
			break;
		case ']':	
			if (S.base == S.top)  // 栈空
				flag = 0;
			else if (*(S.top - 1) != '[') //栈顶不匹配
				flag = 0;
			else
				pop(S);
				break;
		case ')':   
			if (S.base == S.top)
				flag = 0;
			else if (*(S.top - 1) != '(')
				flag = 0;
			else
				pop(S);
			break;
		case '}':   
			if (S.base == S.top)
				flag = 0;
			else if (*(S.top - 1) != '{')
				flag = 0;
			else
				pop(S);
			break;
		default:
			break;
		}
		
	}
	if (S.base == S.top && flag == 1)
		return true;
	return false;
}
int main()
{
	SqStack S;
	InitStack(S);
	if (search(S))
		cout << "表达式匹配是否成功：" << "yes";
	else
		cout <<"表达式匹配是否成功：" << "no";
}


