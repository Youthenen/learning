/*设某银行有A、B两个业务窗口，且处理业务的速度不一样，其中A窗口处理速度是
B窗口的2倍--即当A窗口每处理完2个顾客时，B窗口处理完1个顾客。
给定到达银行的顾客序列，请按业务完成的顺序输出顾客序列。
input： 
输入为一行正整数，其中第1个数字N(≤1000)为顾客总数，后面跟着N位顾客的编号。
编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。*/ 


#include  <iostream>
using namespace std;
typedef struct {
	int front;
	int rear;
	int data[1000];
	int length;
}queue;
void InitQueue(queue &Q) 
//初始化队列 
{
	Q.front = Q.rear = 0;
	Q.length = 0;
}
bool judge(queue &Q) 
//判断队列是否为空
{
	if(Q.rear == Q.front)
		return true;
	else return false;
}
void Enqueue(queue &A,queue &B,queue &C) 
 //将AB队的数据按顺序入C队
{

	
		for(int i=0; i<A.length; i++)
		{
			C.data[C.rear++] = A.data[A.front++];
			C.length++;
			if((i+1) % 2 == 0 && !judge(B)) 
			 //注意要判断队列是否为空
			{
				C.data[C.rear++] = B.data[B.front++];
				C.length++;
			}
			
		}
		while(!judge(B))    
		//当A队全部入队完毕，则将剩余的B队的数据入C队 
		{
			C.data[C.rear++] = B.data[B.front++];
			C.length++;
		}			
}
void DeQueue(queue C) 
 //出队 
{
	cout << "出队的顺序为：" ;
	for(int i=0; i<C.length; i++)
	{
		if(i == 0)
			cout << C.data[i];
		else
			cout << " " << C.data[i];
	}
}
int main()
{
	queue A,B,C;
	InitQueue(C);
	InitQueue(A);
	InitQueue(B);
	int N,x;
	int data[1000];
	cin >> N;
	for(int i=0; i<N; i++)    
	{
		cin >> x;
		if(x % 2 !=0)
		{
			A.data[A.rear++] = x;
			A.length++; 
		}
		else
		{
			B.data[B.rear++] = x;
			B.length++;
		}
			
	}
	cout << "请输入排队的总人数和全部序号：" ; 
	Enqueue(A,B,C);
	DeQueue(C);
	
}
