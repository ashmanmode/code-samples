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
#define printvect(a,n) fr(i,0,n) cout << a[i] << " " ;
typedef unsigned long long int ull;

string ip(int n)
{
    string i="";
    int temp = getchar_unlocked();
    while(n--)
    {
        temp=getchar_unlocked();
        i+=(char)temp;
    }
    return i;
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
		for(int i = 0 ; i < n ; i++ )
		cout << str[i] << " ";
		cout << endl ; 		 

		vector<int> arr0(n);
		vector<int> arr1(n);
		vector<int> pos0(n);
		vector<int> pos1(n);

		int z,o; z = 1 ; o = 1 ;
		fr(i,0,n)
		{
			arr0[i] = z ;
			arr1[i] = o ;
			pos0[z] = i ;
			pos1[o] = i ;

			if(str[i] == '0')
				z++;
			else
				o++;
		}

		//vector checking
		/*cout << "0's"  << endl ;
		fr(i,0,n)
			cout << arr0[i] << " ";
		cout << endl;
		fr(i,0,n)
			cout << pos0[i] << " ";
		cout << endl;

		cout << "1's" << endl;
		fr(i,0,n)
			cout << arr1[i] << " ";
		cout << endl ;
		fr(i,0,n)
			cout << pos1[i]<< " ";
		cout << endl;*/
		
		vector<int> cumulative(n);
		fr(i,0,n)
		{
			int temp0;
			if(arr0[i] > 1 && pos0[arr0[i] + k] == 0)
				temp0 = n-i ;
			else
				temp0 = pos0[arr0[i] + k] - i ; 
		
			int temp1;
			if(arr1[i] > 1 && pos1[arr1[i] + k] == 0)
				temp1 = n-i ;
			else 
				temp1 = pos1[arr1[i] + k] - i ;

			if(temp1 < temp0)
				if(i > 0)
					cumulative[i] = cumulative[i-1] + temp1 ;
				else
					cumulative[i] = temp1;
			else 
				if(i > 0)
					cumulative[i] = cumulative[i-1] + temp0 ;
				else
					cumulative[i] = temp0;
		}
		
		cout << "cumulative check" << endl;
		fr(i,0,n)
			cout << cumulative[i] << " ";
		cout << endl;

		//reverse iteration
		z = 1 ; o = 1 ;
		fr(i,0,n)
		{
			arr0[i] = z ;
			arr1[i] = o ;
			pos0[z] = i ;
			pos1[o] = i ;

			if(str[n-i-1] == '0')
				z++;
			else
				o++;
		}

		//vector checking
		/*cout << "0's"  << endl ;
		fr(i,0,n)
			cout << arr0[i] << " ";
		cout << endl;
		fr(i,0,n)
			cout << pos0[i] << " ";
		cout << endl;

		cout << "1's" << endl;
		fr(i,0,n)
			cout << arr1[i] << " ";
		cout << endl ;
		fr(i,0,n)
			cout << pos1[i]<< " ";
		cout << endl;*/
		
		vector<int> cutting(n);
		fr(i,0,n)
		{
			int temp0;
			if(arr0[i] > 1 && pos0[arr0[i] + k] == 0)
				temp0 = n-i ;
			else
				temp0 = pos0[arr0[i] + k] - i ; 
		
			int temp1;
			if(arr1[i] > 1 && pos1[arr1[i] + k] == 0)
				temp1 = n-i ;
			else 
				temp1 = pos1[arr1[i] + k] - i ;

			if(temp1 < temp0)
				cumulative[i] = temp1 - 1;
			else 
				cumulative[i] = temp0 - 1;
		}
		
		cout << "cutting check" << endl;
		fr(i,0,n)
			cout << cutting[i] << " ";
		cout << endl;

		/*int l,r;
		ull ans ;
		fr(x,0,q)
		{
			si(l);si(r); l-- ; r-- ;
			ans = 0  ;
			
		}*/
	}
	return 0;
}