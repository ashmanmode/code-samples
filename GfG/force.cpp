#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<unsigned long long int> vull;
#define pb push_back
#define sz(a) a.size()

int main()
{
	int i=0,a[10];
	cout << a[0] << "  " << a[1] << "  " << endl;
	a[i] = i++ ;
	cout << a[i] << endl;
	cout << a[0] << "  " << a[1] << "  " << endl;
	return 0;
}