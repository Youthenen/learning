/*Ҫ��ʹ��˳���ṹʵ�֣�д��˳�������Ͷ��塢˳���ĳ�ʼ����
˳�����������빹����˳���������ʾ�ĵ��㷨(���л�����ʾ) 
*/
#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct 
{
	int length;
	int *elem;  //�洢�ռ�Ļ���ַ 
	
}SqList; 
void InitList(SqList &L)
{				                     //˳���ĳ�ʼ��
	L.elem=new int[MAXSIZE];		 //����һ���յ�˳���L,Ϊ˳������һ����СΪMAXSIZE������ռ�
	L.length=0;					     //�ձ���Ϊ0
}
void inputdata(SqList &L)
{
	for(int i=0; i<L.length; i++)
	{
		cin >> L.elem[i];
	}
	
}
void outputdata(SqList &L)
{
	for(int i=0; i<L.length; i++)
	{
		cout << L.elem[i] << endl; 
	}
	
	
}
int main()
{
	SqList L; 
	cout << "1. ����˳���\n";
	cout << "2. ��������\n";
	cout << "3. �������\n";
	cout << "0. �˳�\n\n";
	int choose;
	choose = -1;
	while(choose != 0 )
	{
		cout << "��ѡ���ܣ�"; 
		cin >> choose;
		switch(choose)
		{
			case 1: cout << "������˳���ĳ���n:";
					InitList(L);   //��ʼ����Ҫ����n֮ǰ������Ӱ��length 
					int n;
					cin >> n; 
					L.length = n;
					cout << "�ɹ�����˳���\n" << endl;
					break;
			case 2: printf("������Ҫ�洢��%d�����ݣ�",n); 
					inputdata(L);
//					cout << L.length;
					cout << "�ɹ��洢����\n\n";
					break;
			case 3: printf("����˳����е����ݣ�\n"); 
					outputdata(L);
					break;
		}
	}
	
	
 } 

