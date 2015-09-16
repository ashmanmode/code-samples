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
#define arr vector<int> 
#define vectin(a,n) fr(i,0,n) { cin >> a[i] ; }
typedef unsigned long long int ull;
typedef signed long long int sll;

vector<int> store(123456,-1);
queue<int> a ;
int n,m ;
bool createlevel()
{
	//cout << a.front() << " " ;
	if(a.front()-1 > 0 && store[a.front()-1]==-1)
	{
		store[a.front()-1] = store[a.front()]+1;
		a.push(a.front()-1);
	}
	if(a.front()*2 < 2*m && store[a.front()*2]==-1)
	{
		store[a.front()*2] = store[a.front()]+1;
		a.push(a.front()*2);
	}
	if(a.front() - 1 == m || a.front()*2 == m)
		return true;

	a.pop();
	return false;
}

int main()
{
	cin >> n >> m ;
	a.push(n);
	store[n] = 0 ;

	int steps = 1 ;
	while(!createlevel()){ steps++;}
	cout << store[m] << endl ;
}