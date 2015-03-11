#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long int ui;

int main()
{
	int test_cases;
	cin >> test_cases ;
	int n,k,m;
	bool done_for_one;
	vector<ui> array;
	ui sum,required; //for taking input this will be used as tmp variable
	for(int i = 0 ; i < test_cases ; i++ )
	{
		cin >> n >> k ; 
		sum = 0 ;
		for(int j = 0 ; j < n ; j++ )
		{
			cin >> required ;
			array.push_back(required );
			sum += required ;
		}
		sort(array.begin(),array.end());
		if(sum != (sum/k)*k ||  array[n-1] > sum/k)
		{
			cout << "no" << endl ;
			goto end;
		}
		else
		{
			//now required contribution to everyone is (sum/k)
			//checking if that can be done
			for(int j = 0 ; j < k ; j++ ) // checks for all contributions
			{
				required = sum/k;
				if(array[array.size() - 1] == required)
					array.erase(array.begin() + array.size() - 1 );
				else
				{
					done_for_one = false;
					required = required - array[array.size() - 1];
					array.erase(array.begin() + array.size() - 1 );
					while(1)
					{
						for(m = 0 ; m < array.size() ; m++ )
						{
							if(required == array[m])
							{
								array.erase(array.begin() + m);
								done_for_one = true ; break;
							}
						}
						if(done_for_one)
							break;
						else
						{
							for(m = 0 ; m < array.size() ; m++)
							{
								if(array[m] > required )
									break;
							}
							if(m == 0) //case when no additions can be made
							{
								cout << "no" << endl ;
								goto end ;
							}
							else
							{
								required = required - array[m-1];
								array.erase(array.begin() + m - 1);
							}
						}
					}
				}
			}
			cout << "yes" << endl ;
		}
		end:;
		array.clear();
	}
	return 0 ;
}