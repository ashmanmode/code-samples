#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<unsigned long long int> vull;
#define pb push_back
#define sz(a) a.size()

char mutate(char a, char b)
{
    if(a == b)
        return 'A';
    else if (( a=='A' && b == 'B') || ( a=='B' && b == 'A') )
        return 'B';
    else if (( a=='A' && b == 'C') || ( a=='C' && b == 'A'))
        return 'C';
    else if (( a=='A' && b == 'D') || ( a=='D' && b == 'A') )
        return 'D';
    else if (( a=='B' && b == 'C') ||( a=='C' && b == 'B') )
        return 'D';
    else if (( a=='B' && b == 'D') || ( a=='D' && b == 'B') )
        return 'C' ;
    else 
        return 'B';
}

int main()
{
   int n,k,temp;
   cin >> n >> k ;
   string s ;
   cin >> s; 
   for ( int i =0 ; i < k ; i++ )
   {
        temp =  s[0] ;
        for (int j = 0 ; j < n -1 ; j++)
        {
            s[j] = mutate(s[j],s[(j+1)%n]) ;
            cout << s[j] ; 
        }
        s[n-1] = mutate(temp ,s[n-1]) ;
        cout << s[n-1] << endl ;
   }
   for ( int i = 0 ; i < n ; i++ )
        cout << s[i] ; 
   cout << endl ; 
   return 0 ; 
}