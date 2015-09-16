//chef sept 2014 long challange (Chef and Rainbow Array - 2)
#include <iostream>
#include <fstream>
using namespace std;

typedef unsigned long long int ull;
ofstream file("chef3.txt") ;


ull fact(ull a)
{
   //taking r = 6 so r-1 = 5
   ull out = 1 ;
   for ( ull i = 1 ; i < 6 ; i ++ )
   {
      file << "i"<< i<<"  a* " << a*out << endl ;
      out = ( out * a )/i ;
      file <<"fact  " << out << endl ;
      a-- ;
   }
   return out ;
}

int main()
{
   int n;
   cin >> n ;
   ull count = 0 ;
   if ( n % 2 == 0)
   {
      for(int i = 2 ; i < n-11 ; i = i + 2 )
      {
         count = count + fact((n-i-2)/2) ;
         file << fact((n-i-2)/2) << endl ;
      }
   }
   else
   {
      for(int i = 1 ; i < n-11 ; i = i + 2 )
      {
         count = count + fact((n-i-2)/2) ;
         file << fact((n-i-2)/2) << endl ;
      }
   }
   cout << count << endl ;
   return 0 ;
}