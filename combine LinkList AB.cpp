/*已知两个集合A和B,现要求一个新的集合A=AUB。(用链表实现)
A=(7,5,3,11)
B=(2, 6, 3) */
#include<iostream>
using namespace std;

typedef struct LNode
{
	int data;							
	struct LNode *next;						
}LNode,*List;					


void InitList(List &L)						//初始化链表
{
	L=new LNode;
	L->next=NULL;
} 
int find(int number,List &LA)  //在LA表中查找是否有number这个数字 
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
void insert(int number,List &LA) //将number 加入到A表中(头插法) 
{
	LNode *s = new LNode;
	s->data = number; 
	s->next = LA->next;  //错点！！ 
	LA->next = s;
}
void build(List &L,int n) // 输入表的数据 
{
	LNode *p = L; //这里应该指向头结点！！ 
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
	cout << "请输入A表的元素个数：";
	int n1,n2;
	cin >> n1;
	cout << "请输入B表的元素个数：";
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
	cout << "请输出合并后的A表：";
	print(LA);
		

} 
