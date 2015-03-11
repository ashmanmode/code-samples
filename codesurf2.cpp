#include <iostream>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )

int main()
{
	int t ;
	cin >> t;
	int w1,w2,n1,n2,count;
	fr(i,t)
	{
		count = 0 ;
		cin >> w1 >> w2 >> n1 >> n2 ;
		if(w1 >= 2*n2)
		{
			count += 2*n2;
			w1 -= 2*n2;
			n2 = 0 ;
		}
		else
		{
			count += (w1/2)*2;
			n2 -= (w1/2);
			w1 = 1 ;
		}
		if(n2 != 0)
		{
			if(w2 >= 2*n2)
			{
				count += 2*n2;
				w2 -= 2*n2; 
			}
			else
			{
				count += (w2/2)*2;
				w2 = 1 ;
			}
		}
		if(w1 + w2 >= n1)
			count += n1;
		else
			count += (w1+w2);
		cout << count << endl;
	}	
}
