#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define F first
#define S second
#define fr(i,k,n) for(int i = k ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
#define point pair<int,int>
#define pii pair<int,int>
#define pib pair<int,bool>
#define vectin(a,n)
typedef unsigned long long int ull;

struct card
{
	int id;
	int w;
	int h;
};

bool myfun1 (card i,card j) 
{ 
	return (i.w < j.w); 
}

bool myfun2 (card i,card j) 
{ 
	return (i.h < j.h); 
}

int main()
{
	int n;
	cin >> n ;

	vector<card> c ;
	fr(i,0,n+1)
	{
		card a ;
		a.id = i;
		cin >> a.w >> a.h ;
		c.pb(a);
	} 

	sort(c.begin(),c.end(),myfun1);

	int count1 = 0 ;
	vector<int> se1 ;
	bool flag =  false;
	int current = -1 ;
	fr(i,0,n+1)
	{
		if(c[i].id == 0)
		{
			flag = true;
			current = c[i].h ;
		}
		if(flag && c[i].h > current )
		{
			current = c[i].h ;
			count1++ ; 
			se1.pb(c[i].id);
		}
	}

	sort(c.begin(),c.end(),myfun2);

	int count2 = 0 ;
	vector<int> se2 ;
	flag =  false;
	current = -1 ;
	fr(i,0,n+1)
	{
		if(c[i].id == 0)
		{
			flag = true;
			current = c[i].w ;
		}
		if(flag && c[i].w > current )
		{
			current = c[i].w ;
			count2++ ; 
			se2.pb(c[i].id);
		}
	}

	if(count1 > count2)
	{
		cout << count1 << endl ;
		if(count1 != 0)
		{
			for(int i = 0 ; i < se1.size() ; i++ )
				cout << se1[i] << " ";
			cout << endl ;
		}
	}
	else
	{
		cout << count2 << endl ;
		if(count1 != 0)
		{
			for(int i = 0 ; i < se2.size() ; i++ )
				cout << se2[i] << " ";
			cout << endl ;
		}
	}
	return 0;
}