#include <iostream>
using namespace std;
 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;   //����������� 

void CreateList(LinkList head,int a[])  //�Ӳ���&���� �����ӣ� 
//��ͷ�巨��a��������ݴ���һ������ 
{
	LinkList p = head;  //pָ��ͷ��� 
	for(int i=0; i<6; i++)
	{
		LinkList s = new LNode; //�����½ڵ㣬����ָ��sָ���� 
		s->data = a[i];
		s->next = p->next;
		p->next = s;
	}

}
void CreateListTail(LinkList head,int a[]) //β�巨�������� 
{
	LinkList rear = head; // rearָ��β��㣬��ʼ��β����ͷ�����ͬһ�� 
	for(int i=0; i<6; i++)
	{
		LinkList s = new LNode;
		s->data = a[i];
		s->next = NULL;
		rear->next = s; // ��s��ָ�Ľ�� ���� rear ��ָ�Ľ����� 
		rear = s; 		// ��rear ָ��β��� 
	}	
//	rear->next = NULL;
	
} 
void PrintList(LinkList head)  //��� 
{
	LinkList p = new LNode;
	
	p = head->next; //pָ��ָ����Ԫ��㣨ͷ����next��Ϊ��Ԫ���ĵ�ַ�� 
 
	while(p)
	{
		cout << p->data << '\t';
		p=p->next;	
	
	} 	 
}

void InserttoList(LinkList head,int i,int number) //��number ��������ĵ�i��λ�� 
{
	LinkList p= head->next;   //p �� j �ĳ�ʼ������ 
	int j=1;
	while(p&&j<i-1)
	{
		p = p->next; //�����ƶ� 
		j++; //������ 
	}
	if(!p || j>i)
		cout << "����ʧ��";
	else
	{
		LinkList new_LNode = new LNode;
		new_LNode -> data = number;
		new_LNode -> next = p -> next;
		p->next = new_LNode;
		PrintList(head);
	}
 } 
int	Search_Number(LinkList head,int number) //�������в���number ���ҵõ��򷵻���ţ��Ҳ����򷵻�0 
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
	head->next = NULL; //ͷ���nextΪnull 
	int a[] = {1,2,3,4,5,6}; 
	
	CreateList(head,a);
	PrintList(head); 
	cout << endl; 
	
	CreateListTail(head,a);
	PrintList(head);
	cout << endl;
	
	cout << "������Ҫ����������Լ�λ�ã�"; 
	int number;
	cin >> number;
	int loaction;
	cin >> loaction; 
	printf("������%d�����%d��λ��\n",number,loaction); 
	InserttoList(head,loaction,number);
	cout << '\n' <<  "������Ҫ���ҵ����ݣ�";
	int n; 
	cin >> n; 
	int result = Search_Number(head,n);
	if(result)
		printf("%d�������е��±�Ϊ��%d",n,result);
	else
		printf("������û�и�����"); 
} 
 
