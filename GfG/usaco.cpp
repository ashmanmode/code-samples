/*
ID: ash.man1
PROG: gift1
LANG: C++11                  
*/
#include <bits/stdc++.h>
using namespace std;

#define maxsiz 1000000
#define mod 1000000007
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

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np,m,k;
    fin >> np; 
    map<string,int> mp;
    string name;
    vector<string> names;
    fr(i,0,np)
    {
    	fin >> name ;
    	names.pb(name);
    	mp[name] = 0 ;
    }
    fr(i,0,np)
    {
    	fin >> name >> m >> k;
    	if(k!=0)
    		mp[name] -= m-(m%k);
    	fr(j,0,k)
    	{
    		fin >> name ;
    		mp[name] += m/k ;
    	}
    }
    fr(i,0,np)
    	fout << names[i] << " " << mp[names[i]] << endl ;
    return 0;
}