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
typedef unsigned long long int ull;

string s ; 

/* ------------------ start here ---------------------*/
ull X; // we assume that unsigned is a 32bit integer type
int A[200001];

void srand1(ull S)
{
	X = S;
}

ull nextInteger1(void)
{
 	X = X * 1103515245 + 12345;
  	return (X / 65536) % 32768;
}

void generator1(int N,ull S)
{
	srand1(S);
  	for(int i=0;i<N;i++)
		A[i] = nextInteger1() % 2; 
}
/* ------------------ end here -----------------------*/

typedef struct 
{
	int x;
	int y;
}point;

int main()
{
	map<int,int> a;
	a[10] = 45 ;
	a[45] = 57465 ;
	for(std::map<int,int>::const_iterator it = a.begin() ; it != a.end() ; ++it )
	{
		cout << it->first << " -> " << it->second << endl; 
	}
	return 0;
}