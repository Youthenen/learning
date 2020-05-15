#include <iostream>
using namespace std;
#define MAXSIZE 1000
typedef struct
{
	char ch [MAXSIZE];
	int length;
	
	
}Htring;
void input(Htring &key)
{
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')
	{
		key.ch[i++] = ch;
		
	}
	key.length = i;
}
void article(Htring &key)
{
	for(int i=0; i<key.length; i++)
	{
		if(key.ch[i] <='Z' && key.ch[i] >='A')
		{	
			key.ch[i] = (key.ch[i] - 'A' + 21) % 26 +'A' ;
		
		}	
//		if(key.ch[i] <='Z' && key.ch[i] >='F')
//		{
//			key.ch[i] = key.ch[i] - 5;
//		}	
	}
}
void output(Htring &key)
{
	for(int i=0; i<key.length; i++)
	{
//		cout << "YEA"; 
		cout << key.ch[i];
	
	}
	
	
}
int main()
{
	Htring key;
	input(key);
	article(key);
	output(key);
	
	
 } 
