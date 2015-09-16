#include <bits/stdc++.h>
using namespace std;

int check(string s,int n)
{
	if(n == 0 )
	{
		if((int)(s[0] - '0')%8 == 0)
			return 0;
		else
			return 1;
	}
	if(n==1)
	{
		if(((int)(s[n] - '0') + 10*(int)(s[n-1] - '0'))%8 == 0 )
			return 0;
		int t = (int)(s[n] - '0') ;
		if(t%8 == 0)
			return 1;
		t = (int)(s[n-1] - '0') ;
		if(t%8 == 0)
			return 1;
		return 1 + check(s,n-1);	
	}
	if(n==2)
	{
		int t = (int)(s[n] - '0') + 10*(int)(s[n-1] - '0')  + 100*(int)(s[n-2] - '0' );
		if(t%8 == 0)
			return 0 ;
		t = (int)(s[n] - '0') + 10*(int)(s[n-1] - '0') ;
		if(t%8 == 0)
			return 1;
		t = (int)(s[n-1] - '0') + 10*(int)(s[n-2] - '0') ;
		if(t%8 == 0)
			return 1;
		t = (int)(s[n] - '0') + 10*(int)(s[n-2] - '0') ;
		if(t%8 == 0)
			return 1;
		return 1 + check(s,n-1);
	}
	if(n > 2)
	{
		int t = (int)(s[n] - '0') + 10*(int)(s[n-1] - '0')  + 100*(int)(s[n-2] - '0' );
		if(t%8 == 0)
			return 0 ;
		else
		{
			t = (int)(s[n-1] - '0') + 10*(int)(s[n-2] - '0')  + 100*(int)(s[n-3] - '0' );
			if(t%8 == 0)
				return 1 ;
			t = (int)(s[n] - '0') + 10*(int)(s[n-2] - '0')  + 100*(int)(s[n-3] - '0' );
			if(t%8 == 0)
				return 1 ;
			t = (int)(s[n] - '0') + 10*(int)(s[n-1] - '0')  + 100*(int)(s[n-3] - '0' );
			if(t%8 == 0)
				return 1 ;
			return 1 + check(s,n-1);
		}
	}
	return -1;
}

int main()
{
	freopen("inp.txt","r",stdin);
	int t;
	cin >> t ; 
	for(int  i = 0 ; i < t ; i++ )
	{
		string num;
		cin >> num ;
		int sol = check(num,num.size()-1) ;
		if(sol == num.size())
			cout << -1 << endl ;
		else
			cout << sol << endl;
	}
	return 0 ;
}