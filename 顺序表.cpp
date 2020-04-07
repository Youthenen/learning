#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct 
{
	int length;
	int data[MAXSIZE];
	
}SqList;
void create(SqList &L, int n)  //L必须要加引用符号 
{
	for(int i=0; i<n; i++)
	{
		cin >> L.data[i];
		L.length++;
	}
}
void print(SqList &L)
{
	int i;
	for(i=0; i<L.length-1; i++)
	{
		cout << L.data[i] << " ";
	}
	cout << L.data[i];	
}
int main()
{
	SqList L;
	L.length = 0;
	int n;
	cin >> n;
	if(n)
	{
		create(L,n);
		print(L);
	}
	return 0;
 } 
