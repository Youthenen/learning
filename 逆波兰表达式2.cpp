#include <iostream>
#include <cmath>
using namespace std;
#define MAXSIZE_ 100
typedef struct{
	int *base2;
	int *top2; 
	int stacksize;
}NumStack;
void InitStack(NumStack &S)  //初始化栈 
{
	S.base2 = new int [MAXSIZE_];
	if(!(S.base2))
		exit(-1);
	S.top2 = S.base2;
	S.stacksize = MAXSIZE_;
}
void push(int result, NumStack &B)
{
	*B.top2 = result;
	B.top2++;
	
}
int calculate(NumStack &num,char ch)  //计算栈顶两个元素的值 
{
	if(ch == '+')
	{
		return *(num.top2-1) + *(num.top2-2);
	}
		
	if(ch == '-')
		return *(num.top2-2) - *(num.top2-1);
	else return *(num.top2-1) *  *(num.top2-2);
	
	
}
void pop(NumStack &A,int length)  //出栈 
{
	for(int i=0; i<length; i++)
	{
		A.top2--;
	}
	
}
int main()
{
	NumStack A,B;
	InitStack(A);
	InitStack(B);
	char ch;
	int result;
	int count = 0;
	while((ch = getchar()) != '\n')
	{
		count ++;
		if(count >397) //注意字符个数需要算上空格！！ 
		{
			break;
		}
		
		if(ch >= '0' && ch <='9')
		{
			push(ch-48,A);
		}	
		else if(ch == ' ' )
		{
			int num = 0;
			int length = A.top2 - A.base2;
//			cout << length << "*";
			for(int i=0; i<length; i++)
			{
				num = *(A.top2-1) * pow(10,i) + num;
				A.top2--;
			}
			if(length !=0)  //排除运算符后面的空格 
			{
				push(num,B);
//				cout << num << "...";
			}
		}
		else
		{
			switch(ch)
			{
				case '+':result = calculate(B,ch);  //计算结果 
					pop(B,2);     //去除参与运算的两个数 
					push(result,B);
					break;
			case '-':result = calculate(B,ch);
					pop(B,2);
					push(result,B);
					break;
			case '*':result = calculate(B,ch);
					pop(B,2);
					push(result,B);
					break;
			default:
				break;
				
				
			}			
		}
		
	 } 
	 cout << *(B.top2-1);
 } 
