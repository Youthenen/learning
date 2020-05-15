#include <iostream>
using namespace std;
const int MAX = 100001;
typedef struct
{
	char ch[MAX];
	int length;
	
}SString;
void copy_string(string s ,SString &S)
//将串s复制成为SString 
{
	int j = 1;
	for(int i=0; i<s.length(); i++)
	{ 
		S.ch[j++] = s[i];	
	}
	
	
}
void get_next(SString &T,int next[])
//获取模式串T的next函数 
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while(i < T.length)
	{
		if(j == 0 || T.ch[i] == T.ch[j])
		{
			i++;
			j++;
			next[i] = j;
//			cout << next[i] << endl;
			
		}
		else
		{
			j = next[j];
		}
		
		
	}
}
int Index_KMP(SString S,SString T,int next[])
//匹配过程：模式串匹配成功则返回第一个字符在主串中的位置 ，否则返回0 
{
	int i;
	i = 1;
	int j = 1;
	while(i <= S.length && j<= T.length)
	{
		if( j == 0 || S.ch[i] == T.ch[j])
		{
			i++;
			j++; 
	
		}
		else
		{
			j = next[j];
		}
	}
	if(j > T.length)
	{

		return i-T.length;
		
	} 
	return 0;	
}
void output(SString S,int a)
{
	for(int i=a; i<=S.length; i++)
	{
		
		cout << S.ch[i];
	}	
	cout << endl; 
}
int main()
{
	int n;
	
	SString S,T;
	string s,t;
	cin >> s;
	cin >> n;
	copy_string(s,S);
	S.length = s.length();
	while(n--)
	{
		cin >> t;
		copy_string(t,T);
		T.length = t.length();
//		cout << T.length;
//		cout << t.length();
		int next[t.length()] = {0};
		get_next(T,next);	
			if(Index_KMP(S,T,next)!=0)
			{
				int	a = Index_KMP(S,T,next);
//				cout << a;
				output(S,a);
			
			}
			
			else
 				cout << "Not Found" << endl;
		
	}
	
	
}


