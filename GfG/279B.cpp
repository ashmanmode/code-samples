#include <iostream>
#include <vector>
#include <algorithm>
#define ERR -452
using namespace std;

int b_search(pair<int,int> vect[],int first,int last,int s)
{
	int index;
	if(first >= last)
		index = ERR ;
	else
	{
		int mid = (first+last)/2;
		if(vect[mid].first == s)
			index = mid;
		else if(s < vect[mid].first)
			index = b_search(vect,first,mid,s);
		else
			index = b_search(vect,mid+1,last,s);			
	}
	return index;
}

int main()
{
	int n,x,y; 
	cin >> n ; 
	pair<int,int> a[n];
	pair<int,int> b[n];
	int q[n];
	for(int j = 0 ; j < n ; j++ )
	{
		cin >> x >> y ;
		a[j].first = x ; a[j].second = y;
		b[j].first = y ; b[j].second = x;
	}
	sort(&a[0],&a[n]);
	sort(&b[0],&b[n]);
	int i = 0 ; 
	x = 1 ;
	while(i != ERR)
	{
		if(a[i].second == 0)
			break;
		q[x] = a[i].second ; 
		x += 2 ; 
		i = b_search(a,0,n,a[i].second); 
	}
	
	//searching first element
	int f ; 
	for(int i = 0 ; i < n ;i++)
	{
		if(b_search(b,0,n,a[i].first) == ERR)
		{
			f = i ; 
			break;
		}
	}
	
	q[0] = a[f].first;
	i = f; 
	x = 2 ;
	while(i != ERR)
	{
		if(a[i].second == 0)
			break;
		q[x] = a[i].second ; 
		x += 2 ; 
		i = b_search(a,0,n,a[i].second); 
	}
	
	for(int i = 0 ; i < n ; i++)
		cout << q[i] << " ";
	cout << endl;
	return 0 ;
}