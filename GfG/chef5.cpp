// chef sept. 2014 long challange ( chef and sequence) 
#include <iostream>
using namespace std;

typedef signed long int sl;
#define printarr(array,n) for(int i = 0 ; i < n ; i++){cout << array[i] << " " ; } cout << endl ;

int main()
{
   int n ,k;
   cin >> n >> k ;
   sl array[n];
   for (int i =0 ; i < n ; i++ )
      cin >> array[i];
   sl d[(n*(n-1))/2];
   int m = 0 ; 
   for(int i = 0 ; i < n-1 ; i++)
   {
      for(int j = i+1 ; j < n ; j++ )
      {
         d[m] = (array[j] - array[i])/(j-i) ;
         m++ ;
      }
   }
   cout << "D *** " ;
   printarr(d,(n*(n-1))/2);
   sl a[(n*(n-1))/2];
   m = 0 ;
   for(int i = 0 ; i < n-1 ; i++)
   {
      for ( int j = i+1 ; j < n ; j++ )
      {
         a[m] = array[i] - d[m]*i ;
         m++ ;
      }
   }
   cout << "A *** " ;
   printarr(a,(n*(n-1))/2);
   int changes;
   int final_a = 0;
   for(int i = 0 ; i < (n*(n-1))/2 ; i++)
   {
      changes = 0 ; 
      for(int j = 0 ; j < n ; j++)
      {
         cout << a[i] + d[i]*j << " " ;
         if(array[j] != (a[i] + d[i]*j))
            changes ++ ;
      }
      cout << " changes " << changes << endl;
      if(changes <= k && (a[i] < a[final_a] || (a[i] == a[final_a] && d[i] < d[final_a])))
         final_a = i ;
   }
   cout << "final  " << endl ;
   for(int j = 0 ; j < n ; j++)
      cout << a[final_a] + d[final_a]*j << " " ;
   cout << endl ;
   return 0;
}