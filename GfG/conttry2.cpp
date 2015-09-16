#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<unsigned long long int> vull;
#define pb push_back
#define sz(a) a.size()

int findtotal(int h, int v)
{
    int min;
    int total = 1 ;
    if(h>v)
        min = v; 
    else
        min = h; 
    for(int i = 1 ; i < min+1 ; i++ )
    {
        total *= (h+v+1-i);
        total /= i;
    }
    return total;
   
}

int main()
{
    int test_cases;
    cin >> test_cases ;
    int h,v,k,total;
    for(int i = 0 ; i < test_cases ; i++)
    {
        cin >> h >> v >> k ;
        total = findtotal(h,v);
        for(int j = 0 ; j < h+v ; j++ )
        {
            if( k < total/2 + total%2 )
            {
                cout << 'h' ;
                total = total/2 - total%2;
                k = k + 1 ; 
            }
            else
            {
                cout << 'v' ;
                total = total/2 + total%2;
                k = k - total ; 
            }
                
        }
        cout << endl ;   
    }
    return 0;
}