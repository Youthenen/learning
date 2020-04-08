#include <iostream>
using namespace std;
 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;   //创建结点类型 

void CreateList(LinkList head,int a[])  //加不加&符号 （不加） 
//用头插法将a数组的数据创造一个链表 
{
	LinkList p = head;  //p指向头结点 
	for(int i=0; i<6; i++)
	{
		LinkList s = new LNode; //创建新节点，并用指针s指向它 
		s->data = a[i];
		s->next = p->next;
		p->next = s;
	}

}
void CreateListTail(LinkList head,int a[]) //尾插法创建链表 
{
	LinkList rear = head; // rear指向尾结点，初始的尾结点和头结点是同一个 
	for(int i=0; i<6; i++)
	{
		LinkList s = new LNode;
		s->data = a[i];
		s->next = NULL;
		rear->next = s; // 将s所指的结点 接在 rear 所指的结点后面 
		rear = s; 		// 把rear 指向尾结点 
	}	
//	rear->next = NULL;
	
} 
void PrintList(LinkList head)  //输出 
{
	LinkList p = new LNode;
	
	p = head->next; //p指针指向首元结点（头结点的next域为首元结点的地址） 
 
	while(p)
	{
		cout << p->data << '\t';
		p=p->next;	
	
	} 	 
}

void InserttoList(LinkList head,int i,int number) //将number 插入链表的第i个位置 
{
	LinkList p= head->next;   //p 和 j 的初始化问题 
	int j=1;
	while(p&&j<i-1)
	{
		p = p->next; //往后移动 
		j++; //计数器 
	}
	if(!p || j>i)
		cout << "插入失败";
	else
	{
		LinkList new_LNode = new LNode;
		new_LNode -> data = number;
		new_LNode -> next = p -> next;
		p->next = new_LNode;
		PrintList(head);
	}
 } 
int	Search_Number(LinkList head,int number) //在链表中查找number ，找得到则返回序号，找不到则返回0 
{
	LinkList p = head-> next;
	int j = 1;
	while(p && p->data!=number)
	{
		p = p->next;
		j++;
	}
	if(!p)
		return 0;
	else
		return j;
}
int main()
{
	LinkList head = new LNode;
	head->next = NULL; //头结点next为null 
	int a[] = {1,2,3,4,5,6}; 
	
	CreateList(head,a);
	PrintList(head); 
	cout << endl; 
	
	CreateListTail(head,a);
	PrintList(head);
	cout << endl;
	
	cout << "请输入要插入的数字以及位置："; 
	int number;
	cin >> number;
	int loaction;
	cin >> loaction; 
	printf("将数字%d插入第%d个位置\n",number,loaction); 
	InserttoList(head,loaction,number);
	cout << '\n' <<  "请输入要查找的数据：";
	int n; 
	cin >> n; 
	int result = Search_Number(head,n);
	if(result)
		printf("%d在链表中的下标为：%d",n,result);
	else
		printf("链表中没有该数字"); 
} 
 
