#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1234567
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

int main()
{
	clock_t start = clock();
	ull m,x1,y1,x2,y2,h1,a1,h2,a2,current ;
	cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2 ;

	bool notposs = false;
	bool notposs1 = false;
	ull loca,locb ;
	loca = 0 ;
	locb = 0 ;
	int sa,sb,last;
	sa = 0 ; sb = 0 ;
	current = h1 ; 
	ull h3 = ( x1*current + y1 )%m;
	do{
		sa++;
		cout << current << " " ;
		if(current == a1)
			loca = sa-1 ;
		last = current;
		current = ( x1*current + y1 )%m;
		if(last == current)
		{
			notposs = true ;
			break;
		}
		if(current == h3 && sa > 1)
		{
			sa-- ;
			break;
		}
	}while(current != h1); cout << endl ;
	current = h2 ; 
	ull h4 = ( x2*current + y2 )%m;
	do{
		sb++;
		cout << current << " " ;
		if(current == a2)
			locb =sb-1 ;
		last = current ;
		current = ( x2*current + y2 )%m;
		if(last == current)
		{
			notposs1 = true ;
			break;
		}

		if(current == h4 && sb > 1)
			break;
	}while(current != h2); cout << endl ;

	clock_t mid = clock();
	cout << "time 1" << (float)(mid - start)*1000/CLOCKS_PER_SEC << " ms" << endl;

	if(loca == 0 || locb == 0)
	{
		cout << -1 << endl ;
		return 0 ;
	}

	int repeting = -1,periodic = -1,period; 
	if((!notposs && notposs1))
	{
		periodic = loca;
		repeting = locb;
		period = sa;
	}
	else if((notposs && !notposs1))
	{
		periodic = locb;
		repeting = loca;
		period = sb;
	}
	if(periodic != -1 )
	{
		if(repeting <= periodic)
			cout << periodic << endl;
		else
			cout << periodic + (1+(repeting-periodic)/period)*period << endl;
		return 0;
	}


	
	ull ans = 0;
	fr(i,0,m)
	{
		if( (i*sa + loca)%sb == locb )
		{ 
			ans = i*sa + loca ; 
			break;
		}
 	}
	if(ans == 0)
		cout << -1 << endl ;
	else
		cout << ans << endl ;

	cout << "time 2" << (float)(clock() - start)*1000/CLOCKS_PER_SEC << " ms" << endl;
}