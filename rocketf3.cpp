#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;

double inv(vector<int> vect)
{
	double inv = 0 ; 
	for(int i = 0 ;i < vect.size() - 1 ; i++ )
	{
		for(int j  =  i+1 ; j < vect.size() ; j++ )
		{
			if(vect[i] > vect[j])
				inv++ ;
		}
	}
	return inv;
}

double count(vector<int> arr,int call)
{
	if(call == 0)
		return inv(arr);

	double n = arr.size();
	double exp = 0.0  ;
	vector<int> copy(arr.size());
	for(int i =  0 ; i < arr.size() ; i++ )
	{
		for(int j = i; j < arr.size() ; j++ )
		{
			for(int k = 0  ;  k < arr.size() ; k++ )
			{
				if(k < i || k > j)
					copy[k] = arr[k];
				else
					copy[k] = arr[i+j-k];
			}
			exp += (2/(n*(n+1)))*count(copy,call-1);
		}
	} 
	return exp;
}

int main()
{
	int n,k;
	cin >> n >> k ; 
	vector<int>  arr(n);
	fr(i,n) cin >> arr[i] ;
	cout.precision(15);
	cout << fixed <<  count(arr,k) << endl;
}