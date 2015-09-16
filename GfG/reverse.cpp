#include <iostream>

using namespace std;

void reverse(int array[],int index,int n)
{
    int temp;
    for ( int i = index; i < index + (n-index)/2 ; i ++)
    {
        temp = array[i];
        array[i] = array[n - i + index - 1];
        array[n - i + index - 1] = temp;
    }
}

int main()
{
    int test_cases ;
    cin >> test_cases ;

    int n,k;
    for ( int i =0 ; i < test_cases ; i++ )
    { 
        cin >> n >> k ;
        int array[n];
        cout << "\nOriginal " << endl;
        for ( int j = 0 ; j < n ; j++ )
        {
            array[j] = j ;
            cout << j << " " ;            
        }
        for ( int j = 0 ; j < n-1 ; j++ )
        {
            reverse(array,j,n);    
            cout << "\nreverse  " << endl;
            for (int k = 0; k < (n); ++k)
                cout << array[k] << " " ;            
        }
        for (int j = 0 ; j < n ; j ++ )
        {
            if(array[j] == k)
            {
                cout << "\nanswer " << j << endl ;
                break;
            }
        }
    }
    return 0 ;
}