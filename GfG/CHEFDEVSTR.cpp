#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
typedef unsigned long long int ull;

void doit(string s) //k==1 case
{
	string copy = s ;

	char current = s[0];
	ull flips1 = 0 ;
	fr(i,1,s.length())
	{
		if(s[i] == current)
		{
			flips1++;
			if(s[i] == '1')
				s[i] = '0';
			else
				s[i] = '1';
		}
		current = s[i] ;
	}

	//method 2
	if(copy[0] == '1')
		copy[0] = '0';
	else
		copy[0] = '1';
	current = copy[0];
	ull flips2 = 1 ;
	fr(i,1,copy.length())
	{
		if(copy[i] == current)
		{
			flips2++;
			if(copy[i] == '1')
				copy[i] = '0';
			else
				copy[i] = '1';
		}
		current = copy[i] ;
	}

	if(flips1 <= flips2)
	{
		cout << flips1 << endl ;
		cout << s << endl ;
	}
	else
	{
		cout << flips2 << endl ;
		cout << copy << endl ;
	}
}

int main()
{
	ull test,n,k;
	string s ;
	cin >> test ;
	fr(i,0,test)
	{
		cin >> n >> k ; 
		cin >> s ; 
		if(k==1)
		{
			doit(s);
			continue;
		}
		char current = s[0];
		int sum = 1 ;
		int start = 0 ;
		ull flips = 0 ;
		fr(i,1,s.length()+1)
		{
			if(s[i] == current && i != s.length())
				sum++;
			else
			{
				if(sum > k)
				{
					flips += (sum/(k+1));
					for(int j = start + k ; j < sum + start - 1; j+=(k+1) )
					{
						if(s[j] == '1')
							s[j] = '0';
						else
							s[j] = '1';
					}
					if((sum/(k+1))*(k+1)==sum)
					{
						if(s[sum+start-2] == '1')
							s[sum+start-2] = '0';
						else
							s[sum+start-2] = '1';
					}
				}
				current = s[i] ;
				start = i ;
				sum = 1;
			}
		}
		cout << flips << endl ;
		cout << s << endl ;
	}
	return 0;
}