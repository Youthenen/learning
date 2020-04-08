#include <iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode *next;	
}LNode,*LinkList;
void createList(LinkList L)
{
	LinkList p = L;
	for(int i=0; i<6; i++)
	{
		LinkList s = new LNode;
		cin >> s->data;
		s->next = p->next;
		p->next = s;
		
	}
}
LinkList search_by_value1(LinkList L,int a)
//在链表中查找a值的地址，查找失败返回null 
{
	LinkList p = L->next;
	while(p && p->data!=a)
	{
		p = p->next;	
	}
	if(!p)
		return NULL;
	else
		return p; 
}
int search_by_value2(LinkList L,int a)
//按值查找返回序号 
{
	LinkList p = L->next;
	int j = 1;
	while(p && p->data!=a)
	{
		p = p->next;
		j++;	
	}
	if(!p)
		return NULL;
	else
		return j; 
}
LinkList search_by_loaction1(LinkList L,int a)
//按序号查找返回地址 
{
	LinkList p = L->next;
	int j = 1;
	while(p && j<a-1) 
	{
		p = p->next;
		j++;
	}
	if(!p || j>a-1)
		return NULL;
	else
		return p->next;
}
int search_by_loaction2(LinkList L,int a)
//按序号查找返回元素的值 
{
	LinkList p = L->next;
	int j = 1;
	while(p && j<a-1) 
	{
		p = p->next;
		j++;
	}
	if(!p || j>a-1)
		return NULL;
	else
		return p->next->data;
}
int main()
{
	int a,b;
	LinkList c,d;
	LNode *L = new LNode;
	L -> next = NULL;
	createList(L);
	c = search_by_value1(L,3);
	a = search_by_value2(L,3);
	d = search_by_loaction1(L,3);
	b = search_by_loaction2(L,3);
	cout << c << " " << a << " " << b << " " << d;
}
