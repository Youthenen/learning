#include <iostream>
using namespace std;
#define MAXSIZE 20
typedef struct{
	char *base;
	char *top;
	int stacksize;
}SqStack;
void InitStack(SqStack &S)
{
	S.base = new char[MAXSIZE];
	if(!(S.base))
		exit(-1);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
void EnStack(SqStack &S)
{
	char ch;
	int count = 0;
	while((ch = getchar())!='\n')
	{
		if(count < 20)
		{
			*S.top = ch;
			S.top++;
			count++;
		}
    else break;
		
	}
}
bool judge(SqStack &S)
{
	if(S.top == S.base)  //栈空 
		return false; 
	while(S.base-S.top!=1)  //奇数个 
	{
		if(*(S.top-1) == *S.base)
		{
			if(S.top - S.base == 2)   //偶数个 
				return true;
			else{
				S.top--;
				S.base++;
			}
		}
		else return false;
	}
	return true;
	
	
}
int main()
{
	SqStack S;
	InitStack(S);
	EnStack(S);
	if(judge(S))
		cout << "YES";
	else
		cout << "NO";
 } 
