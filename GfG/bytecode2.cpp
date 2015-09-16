#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int compstring(string a,string b)
{
	int n = a.length();
	int count = 0 ;
	fr(i,n)
		if(a[i]==b[i])
			count++;
	return count;
}

int process(vector<string> a,vector<string> b)
{
	bool flag;
	int m = a.size();
	int ans = a[0].length();
	int max = 0 ;
	int pos;
	fr(i,m)
	{
		max = 0  ;
		fr(j,b.size())
		{
			if(compstring(a[i],b[j]) > max)
				max = compstring(a[i],b[j]);	
		}
		if(max < ans)
			ans = max ; 
	}
	for(int i = 0 ; i < m ; i++)
	{
		flag = true;
		fr(j,b.size())
		{
			if(compstring(a[i],b[j]) == ans)
			{
				b.erase(b.begin() + j); 
				flag = false;
				break;	
			}
		}
		if(flag)
			return -1;
	}
	return a[0].length() - ans ;
}

int main()
{
	int t ;
	cin >> t ; 
	int m , n;
	string tmp;
	fr(i,t)
	{
		cin >> m >> n ; 
		vector<string> a;
		vector<string> b;
		fr(j,m) 
		{
			cin >> tmp ;
			a.pb(tmp);
		}
		fr(j,m) 
		{
			cin >> tmp ;
			b.pb(tmp);
		}
		cout << process(a,b) << endl;
	}
}