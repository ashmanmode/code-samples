//codechef long december
#include <iostream>
#include <vector>
using namespace std;

int bit_length(int num)
{
	if(num >= 512) return 10 ;
	if(num >= 256) return 9 ;
	if(num >= 128) return 8 ;
	if(num >= 64) return 7 ;
	if(num >= 32) return 6 ;
	if(num >= 16) return 5 ;
	if(num >= 8) return 4 ;
	if(num >= 4) return 3 ;
	if(num >= 2) return 2;
	if(num >= 1) return 1;
	else return 0;
}

int max_XOR(vector<int> array,int k)
{
	//find max XOR in a set if we have unique bit lengths
	//array must be in decreasing order of lengths. here we are
	//already getting such array as input from prev step
	int xor_max = k ;
	for(int i = 0 ; i < array.size() ; i++ )
	{
		if((xor_max ^ array[i]) > xor_max ) 
			xor_max = (xor_max ^ array[i]) ;
	}
	return xor_max ;
}

int main()
{
	int test_cases;
	cin >> test_cases ;
	int n,k,num;
	for(int t = 0 ; t < test_cases ; t++ )
	{ 
		cin >> n >> k;
		vector<int> array ; 

		//**//guass elimination methon for varying lengths
		vector< vector<int> > hasht ;
		vector<int> list;
		for(int i = 0 ; i < 10 ;i++ )
			hasht.push_back(list);

		//inserting according to lengths in hash table
		for(int i = 0 ; i < n ; i++ )
		{
			cin >> num; 
			hasht[bit_length(num) - 1].push_back(num);
		}

		//guass eliminating step
		for(int i = 9 ; i > -1 ; i-- )
		{	
			if(hasht[i].size() > 0 )
				array.push_back(hasht[i][0]);
			else
				continue;
			for(int j = 1 ; j < hasht[i].size(); j++)
			{
				num = hasht[i][0] ^ hasht[i][j] ;
				if(bit_length(num) > 0)
					hasht[bit_length(num) - 1].push_back(num);
			}
		}
		//**//gauss elimination over

		//for the generated spanning set find max_XOR
		cout << max_XOR(array,k) << endl ;
		array.clear();
		hasht.clear();
	}
	return 0;
}