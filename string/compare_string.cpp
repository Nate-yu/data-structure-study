#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
string s;

int StrLength(string S) {
	return S.length();
}

void SubString(string S, int pos, int len) {
	s = S.substr(pos,len);
}

int StrCompare(string sub, string T) {
	return sub.compare(T);
}

/*
 *	T为非空串，若主串S中第pos个字符之后存在与T相等的字串，
 *	则返回第一个这样的字串在S中的位置，否则返回0
 */
int Index(string S, string T, int pos) {
	int n,m,i;
	if (pos > 0)
	{
		n = StrLength(S);
		m = StrLength(T);
		i = pos;
		while(i <= n-m+1) {
			SubString(S,i,m); // 取主串第i个位置长度与T相等的字串给s
			if(StrCompare(s,T) != 0) {
				++i;
			}
			else {
				return i;
			}
		}
	}
	return 0;
}


int main() 
{
	string S,T;
	int pos;
	cout<< "input S,T,pos: "<<endl;
	cin>>S>>T>>pos
	cout<<Index(S,T,pos)<<endl;
	return 0;
}