#include <iostream>
#include <string>

using namespace std ;

int main()
{
    int n,k ;
    cin >> n >> k ;
    string s;
    cin >> s ; 
    if(1 == k)
        cout << s << endl ;
    else
    {
        bool code[n];
        bool prev1 = false; 
        bool prev2 = false; 
        for ( int i = 0 ; i < n/2 + n%2; i++ )
        {
            if(prev1 == false)    //from starting 
                code[i] = (int)s[i] - 48 ;
            else
            {
                if((int)s[i] == 48)
                    code[i] = true ;
                else
                    code[i] = false ;
            }
        
            if(prev2 == false)  //from ending
                code[n-1-i] = (int)s[n+k-2-i] - 48 ;  
            else
            {
                if((int)s[n+k-2-i] == 48)
                    code[n-1-i] = true ;
                else
                    code[n-1-i] = false ;
            }
        
            if(i < k-1)
            {
                prev1 = (int)s[i] - 48 ;
                prev2 = (int)s[n+k-2-i] - 48 ;
            }
            else
            {
                prev1 = code[i] ;
                prev2 = code[n-1-i];
            }    
        }
        for(int i = 0 ; i < n ; i++)
            cout << code[i] ;
        cout  << endl ;
    }
    return 0 ;
}