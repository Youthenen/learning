/*��ĳ������A��B����ҵ�񴰿ڣ��Ҵ���ҵ����ٶȲ�һ��������A���ڴ����ٶ���
B���ڵ�2��--����A����ÿ������2���˿�ʱ��B���ڴ�����1���˿͡�
�����������еĹ˿����У��밴ҵ����ɵ�˳������˿����С�
input�� 
����Ϊһ�������������е�1������N(��1000)Ϊ�˿��������������Nλ�˿͵ı�š�
���Ϊ�����Ĺ˿���Ҫ��A���ڰ���ҵ��Ϊż���Ĺ˿���ȥB���ڡ�*/ 


#include  <iostream>
using namespace std;
typedef struct {
	int front;
	int rear;
	int data[1000];
	int length;
}queue;
void InitQueue(queue &Q) 
//��ʼ������ 
{
	Q.front = Q.rear = 0;
	Q.length = 0;
}
bool judge(queue &Q) 
//�ж϶����Ƿ�Ϊ��
{
	if(Q.rear == Q.front)
		return true;
	else return false;
}
void Enqueue(queue &A,queue &B,queue &C) 
 //��AB�ӵ����ݰ�˳����C��
{

	
		for(int i=0; i<A.length; i++)
		{
			C.data[C.rear++] = A.data[A.front++];
			C.length++;
			if((i+1) % 2 == 0 && !judge(B)) 
			 //ע��Ҫ�ж϶����Ƿ�Ϊ��
			{
				C.data[C.rear++] = B.data[B.front++];
				C.length++;
			}
			
		}
		while(!judge(B))    
		//��A��ȫ�������ϣ���ʣ���B�ӵ�������C�� 
		{
			C.data[C.rear++] = B.data[B.front++];
			C.length++;
		}			
}
void DeQueue(queue C) 
 //���� 
{
	cout << "���ӵ�˳��Ϊ��" ;
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
	cout << "�������Ŷӵ���������ȫ����ţ�" ; 
	Enqueue(A,B,C);
	DeQueue(C);
	
}
