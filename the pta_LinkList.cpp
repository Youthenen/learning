/*Ҫ��ʹ�õ�����ṹʵ�֣�д������������Ͷ��塢������ĳ�ʼ����������Ĺ�����
����������*/ 
 
#include <iostream>
using namespace std;
typedef struct LNode 
{
	int data;
	struct LNode *next;
}LNode,*LinkList;
void create(LinkList L,int n)
{
	LinkList rear = L;
	for(int i=0; i<n; i++)
	{
		LinkList s = new LNode;
		cin >> s->data;
		s->next = NULL;
		rear->next = s;
		rear = s;
	}
}
void print(LinkList L,int n)
{
	LinkList p = L->next;
	n--;
	while(n--)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data;
}
int main()
{
	LinkList L = new LNode;
	L->next = NULL;
	int n;
	cin >> n;
	if(n)
	{
		create(L,n); 
		print(L,n);
	}

	
}
