/*要求使用顺序表结构实现；写出顺序表的类型定义、顺序表的初始化、
顺序表的数据输入构建、顺序表的输出显示的等算法(带有互动提示) 
*/
#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct 
{
	int length;
	int *elem;  //存储空间的基地址 
	
}SqList; 
void InitList(SqList &L)
{				                     //顺序表的初始化
	L.elem=new int[MAXSIZE];		 //构造一个空的顺序表L,为顺序表分配一个大小为MAXSIZE的数组空间
	L.length=0;					     //空表长度为0
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
	cout << "1. 建立顺序表\n";
	cout << "2. 输入数据\n";
	cout << "3. 输出数据\n";
	cout << "0. 退出\n\n";
	int choose;
	choose = -1;
	while(choose != 0 )
	{
		cout << "请选择功能："; 
		cin >> choose;
		switch(choose)
		{
			case 1: cout << "请输入顺序表的长度n:";
					InitList(L);   //初始化需要放在n之前，否则影响length 
					int n;
					cin >> n; 
					L.length = n;
					cout << "成功建立顺序表\n" << endl;
					break;
			case 2: printf("请输入要存储的%d个数据：",n); 
					inputdata(L);
//					cout << L.length;
					cout << "成功存储数据\n\n";
					break;
			case 3: printf("这是顺序表中的数据：\n"); 
					outputdata(L);
					break;
		}
	}
	
	
 } 

