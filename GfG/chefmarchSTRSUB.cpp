//Counting strings
#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%llu",&a)
#define sc(a) scanf("%c",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%llu",a)
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << "\t" ;
typedef unsigned long long int ull;
typedef signed long long int sll;

string ip(int n)
{
    string i="";
    int temp = getchar_unlocked();
    while(n--)
    {
        temp = getchar_unlocked();
        i+=(char)temp;
    }
    return i;
}

sll f(sll a)
{
	return (a*(a+1))/2 ;
}

int main()
{
	int t; 
	si(t) ;
	int n,k,q;
	string str;
	while(t--)
	{
		si(n);si(k);si(q); 
		str = ip(n) ; 

		//preprocessing
		int i,j,zero,one;
		vector<sll> c(n);
		zero = 0 ; one = 0 ; 
		i = 0 ; j = 0 ;
		while(1)
		{
			if( str[j] == '0' )
				zero++;
			else
				one++;

			//violation check
			while(zero > k || one > k || j == n)
			{
				if(i == 0)
					c[i] = j - i ;
				else
					c[i] = j - i + c[i-1]; 
				if(str[i] == '0') zero--;
				else one -- ;
				i++ ;
				if( i == n)
					break;
			}
			j++ ;
			if(i == n)
				break;  
		}
		//printvect(c,n); cout << endl ;

		//cutting
		vector<sll> cut(n);
		zero = 0 ; one = 0 ; 
		i = n-1 ; j = n-1 ;
		while(1)
		{
			if( str[j] == '0' )
				zero++;
			else
				one++;

			//violation check
			while(zero > k || one > k || j == -1)
			{
				cut[i] = j; 
				if(str[i] == '0') zero--;
				else one -- ;
				i-- ;
				if( i == -1)
					break;
			}
			j-- ;
			if(i == -1)
				break;  
		}
		//printvect(cut,n); cout << endl ;
	
		//query handling
		sll l,r,cum;
		fr(x,0,q)
		{
			sl(l);sl(r); l-- ; r-- ;
			if(cut[r] == -1 ) cum = 0 ;
			else cum = c[cut[r]];

			if(cut[r] < l)
				cout <<  f(r-l+1)  << endl ;
			else if(l == 0)
				cout << f(r-cut[r]) + cum << endl ;
			else
				cout << f(r-cut[r]) + cum - c[l-1] << endl ;
		}

		c.clear();
		cut.clear();
	}
	return 0;
}