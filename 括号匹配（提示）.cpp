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
	S.base = new char[MAXSIZE]; //ʹbaseָ�����ַ����ջ��
	if (!S.base)
		exit(-1);
	S.top = S.base;  //��ջ
	S.stacksize = MAXSIZE;
}
void push(SqStack &S, char ch)
{
	*S.top = ch;
	S.top++;
}
void pop(SqStack &S)  //ɾ��ջ��Ԫ��
{
	S.top--;
}
bool search(SqStack &S)  //����ƥ�䣬�ɹ��򷵻�true
{
	char ch;
	bool flag = 1;
    int count = 0;
    cout << "��������ʽ��"; 
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
			if (S.base == S.top)  // ջ��
				flag = 0;
			else if (*(S.top - 1) != '[') //ջ����ƥ��
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
		cout << "���ʽƥ���Ƿ�ɹ���" << "yes";
	else
		cout <<"���ʽƥ���Ƿ�ɹ���" << "no";
}


