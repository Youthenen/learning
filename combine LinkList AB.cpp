/*��֪��������A��B,��Ҫ��һ���µļ���A=AUB��(������ʵ��)
A=(7,5,3,11)
B=(2, 6, 3) */
#include<iostream>
using namespace std;

typedef struct LNode
{
	int data;							
	struct LNode *next;						
}LNode,*List;					


void InitList(List &L)						//��ʼ������
{
	L=new LNode;
	L->next=NULL;
} 
int find(int number,List &LA)  //��LA���в����Ƿ���number������� 
{
	LNode *p = LA->next;
	while(p)
	{
		if(p->data == number)
		{
			return 1;
		}
		p = p->next;	
	}
	return 0;
}
void insert(int number,List &LA) //��number ���뵽A����(ͷ�巨) 
{
	LNode *s = new LNode;
	s->data = number; 
	s->next = LA->next;  //��㣡�� 
	LA->next = s;
}
void build(List &L,int n) // ���������� 
{
	LNode *p = L; //����Ӧ��ָ��ͷ��㣡�� 
	for(int i=0; i<n; i++)
	{
		LNode *s = new LNode;
		cin >> s->data;
		s->next = p->next;
		p->next = s;
	}
	
}
void print(List L)
{
	LNode *s = L->next;
	while(s)
	{
		cout << s->data << " ";
		s = s->next;
	}

}
int main()
{
	List LA,LB;
	InitList(LA);
	InitList(LB);
	cout << "������A���Ԫ�ظ�����";
	int n1,n2;
	cin >> n1;
	cout << "������B���Ԫ�ظ�����";
	cin >> n2;
	build(LA,n1);
	build(LB,n2); 
	LNode *q = LB->next;
	while(q)
	{
		if(!find(q->data,LA))
		{
			insert(q->data,LA);
			
		}
		q = q->next;	
	}
	cout << "������ϲ����A��";
	print(LA);
		

} 
