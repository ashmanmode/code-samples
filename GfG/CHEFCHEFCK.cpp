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

int main()
{
	ull N,K,Q;
	ull a,b,c,d,e,f,r,s,t,m,a1;
	ull L1,La,Lc,Lm,D1,Da,Dc,Dm,L,R;
	cin >> N >> K >> Q ;
	cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> a1 ;
	cin >> L1 >> La >> Lc >> Lm >> D1  >> Da >> Dc >> Dm ;

	vector<ull> A(N+1) ;
	A[1] = a1 ;
	fr(x,2,N+1)
	{
		if( ((ull)pow(t,x))%s  <= r)        // Here t^x signifies "t to the power of x"
			A[x] = (a*(ull)pow(A[x-1],2) + b*A[x-1] + c) % m ;
		else
			A[x] = (d*(ull)pow(A[x-1],2) + e*A[x-1] + f) % m ;
	}
	fr(x,1,N+1)
		cout << A[x] << " " ;
	cout << endl ;

	cout << "Queries" << endl ;
	fr(i,0,Q)
	{
		L1 = (La * L1 + Lc) % Lm;
		D1 = (Da * D1 + Dc) % Dm; 
		L = L1 + 1;
		R = min(L + K - 1 + D1, N);
		cout << L << " " << R << endl ;
	}
	return 0;
}