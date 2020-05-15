#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e6 + 10;

typedef struct node
{
    int num[MAXN];
	int length;
}SString;

SString S, T;
string s,t;
int next_[MAXN];

void copy_string(string s ,SString &S)
//将串s复制成为SString
{
	int j = 1;
	for(int i=0; i<s.length(); i++)
	{
		S.num[j++] = s[i] - 48 ;
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
		if(j == 0 || T.num[i] == T.num[j])
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
int Index_KMP(SString &S,SString &T,int next[])
//匹配过程：模式串匹配成功则返回第一个字符在主串中的位置 ，否则返回0
{
	int i;
	i = 1;
	int j = 1;
	while(i <= S.length && j<= T.length)
	{
		if( j == 0 || S.num[i] == T.num[j])
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
		return i-T.length-1;
	}
	return -1;
}

void output(SString S,int a)
{
	for(int i=a; i<=S.length; i++)
	{
		cout << S.num[i];
	}
	cout << endl;
}

int main()
{
	cin >> s;
	copy_string(s,S);
	S.length = s.length();
	cin >> t;
	copy_string(t,T);
	T.length = t.length();
	get_next(T,next_);
	cout << Index_KMP(S,T,next_);
	return 0;
}



