#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

int main()
{
	int t;
	cin >> t;
	string s;
	int c0,c1,max,count1;
	fr(i,t)
	{
		cin >> s ;
		c0 = 0 ; c1 = 0;
		fr(j,s.size())
		{
			if(s[j] == '0')
				c0++;
			else
				c1++;
		}
		max = 0 ; count1 = 0 ; 
		bool prevx,prevy; prevx = false ; prevy = false;
		for(int x = 0 ; x < s.size() - 1 ; x++ )
		{
			if(s[x] == '1')
			{
				count1++; c1--; 
				prevx = false;
				continue;
			}
			else if(prevx)
			{
				c0--;
				continue;
			}
			else 
			{
				prevx = true;
				for(int y = s.size() -1 ; y > x ; y-- )
				{
					if(s[y] == '1')
					{
						count1++; c1--;
						prevy = false;
						continue;
					}
					else if(prevy)
					{
						c0--;
						continue;
					}
					else 
					{	
						prevy = true;
						if(count1 + c0 > max)
							max = count1 + c0;
						c0--;
					}
				}
				c0--;
			}
		}
		cout << max << endl;
	}
	return 0;
}