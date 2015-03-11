#include <iostream>

using namespace std;

int main()
{
    // for test case9 
    /*int sum = 0  ;
    int product,digit;
    for(int a=1;a<3;a++)
    {
        for(int d=1 ; d < 4 && d != a ; d++)
        {
            for ( int b = 1 ; b<10 && b!= a && b != d; b++)
            {
                for(int c = 1 ; c < 10 && c != 5 && c!= a && c != d && c != b; c++)
                {
                    for(int e = 1 ; e < 10 && e != 5 && e!= a && e != d && e != b && e != c; c++)
                    {
                        product = (e + 10*d) * ( c + 10*(b + 10*a) );
                        if()
                        
                    }

                }
            }
        }
    }*/

    //for(int a= 1 ; a < 10 ; a++)
    //{
       // int b = a%9 + 1 ;
       // int c = b%9 + 1 ;
       // int d = c%9 + 1 ; 
       // cout << " " << a << " " << b << " " << c << " " << d << endl;
        for(int i = 1 ; i < 5 ; i ++ )
        {
            int j = i%5 + 1 ;
            while(j != i)
            {
                int k = j%5 +1 ;
                while(k!=j)
                {
                    cout << " " << i << " " << j << " " << k << " " << endl;
                    k = j%5 +1 ;
                    k++ ;
                }
                j = i%5 + 1 ;  
                j++ ;          
            }
        }
//    }

    /*for(int i = 1 ; i  < 10 ;i++)
    {
        for(int j = i%9 + 1 ; j<10 ; j++)
        {
            for ( int k = j%9 + 1 ; k < 10 ; k ++ )
            {
                cout << "i " << i << "  j  " << j << "   k  " << k << endl;               
            }
        }
    }*/

    return 0;
}