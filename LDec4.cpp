#include <iostream>
#include <vector>
#include <cmath>
//#include <fstream>
#include <algorithm>
//#include "time.h"
using namespace std;

typedef signed long long int si;
#define printvect(a) for(int q= 0 ; q < a.size() ; q++ ){cout << a[q] << " " ;}cout << endl ;
#define mod 1000000007
vector< pair<si,bool> > list;
vector< vector<si> > combi;

si fsum(int init,int from,vector<int> vect) //helper for calculate_subsequence
{
	si sum = 0 ;
	if( init == 1 )
	{
		for(int i=from; i < vect.size() ;i++ )
			sum += vect[i];
	}
	else
	{
		for(int i = from ; i < vect.size() - init+1 ; i++ )
			sum = sum + vect[i]*fsum(init-1,i+1,vect);
	}
	return sum;
}

si calculate_subsequences(vector<si> vect)
{
	//actual possible subsequences even with repeatations(except null)
	vect.push_back(-2);
	si same; int same_num;
	vector<int> same_vect;
	same = -1 ;same_num = 0 ;
	for(int j = 0 ; j < vect.size() ; j++ )
	{
		if(vect[j] != same)
		{ 
			same_vect.push_back(same_num);
			same = vect[j]; 
			same_num = 0 ;
		}
		else
			same_num++;
	}
	same_vect.erase(same_vect.begin());
	si return_value = pow(2,same_vect.size()) - 1 ;
	for(int i = 0 ; i < same_vect.size() ; i++ )
	{
		return_value += pow(2,same_vect.size() - 1 - i)*fsum(i+1,0,same_vect);
	}
	return return_value;
}


si get_combinations()
{
	si count = 0 ;
	bool check[100];
	int x,y;
	vector<si> similar_vect;
	vector<si> covered_vect;
	for(si i = 0 ; i < combi.size() ; i++ )
	{
		//printvect(combi[i]);
		sort(combi[i].begin(),combi[i].end());
		count += calculate_subsequences(combi[i]);
		for(int q = 0 ; q < combi[i].size() ; q++ )  check[q] = false ;
		for(si j = 0 ; j < i ; j++ )
		{
			x = 0 ; y = 0 ; 
			while(x < combi[i].size() && y < combi[j].size())
			{
				if(combi[i][x] == combi[j][y])
				{
					similar_vect.push_back(combi[i][x]); 
					if(check[x] == true)
						covered_vect.push_back(combi[i][x]);
					check[x] = true;
					x++ ; y++ ; 
				}
				else if(combi[i][x] > combi[j][y])
					y++;
				else
					x++;
			}
			count = count - calculate_subsequences(similar_vect) + calculate_subsequences(covered_vect);
		}
	}
	return count + 1 ;
}

vector<si> case_no_with(int i,vector<si> stack)
{
	//cout << "case : with" << endl ;
	int size = stack.size() - 1 ;
	for(int j = size ; j > -1 ;j--)
	{
		if(stack[j] < -1*list[i].first)
			stack.erase(stack.begin() + j);
	}
	return stack;
}

vector<si> case_no_without(int k,vector<si> stack)
{
	//cout << "case : without" << endl ;
	for(int  i = stack.size() - 1 ; i > -1 ;i--)
	{
		if(stack[i] == -1*list[k].first)
		{
			stack.erase(stack.begin() + i);
			return stack ;
		}
	}
}

bool in_stack(int k,vector<si> stack)
{
	for(int i = 0 ; i < stack.size() ;i++ )
	{
		if(stack[i] == -1*list[k].first)
			return true;
	}
	return false;
}

void mainiterator(int z,vector<si> stack,vector<si> current)
{
	//cout << "new call" << endl;
	int i ;
 	for(i = z ; i < list.size() ; i++)
	{
		//printvect(stack);
		if(list[i].first < 0)
			stack.push_back(list[i].first);
		else
		{
			if(stack[stack.size() - 1] == -1*list[i].first)
			{
				stack.erase(stack.begin()+stack.size() - 1);
				current.push_back(list[i].first);
			}
			else //violation
			{
				if(in_stack(i,stack))
					break;
			}
		}
	}
	if(stack.size() != 0)
	{
		//cout << "came here for " << list[i].first << endl;
		//making copy of stack
		vector<si> stack_0;
		for(int y = 0 ; y < stack.size(); y++)
			stack_0.push_back(stack[y]);
		//case 1: with
		mainiterator(i,case_no_with(i,stack),current);
		//case 2: without
		mainiterator(i+1,case_no_without(i,stack_0),current);
	}
	else
		combi.push_back(current);
}

int main()
{
	//ifstream file("inpChef.txt");
	//clock_t start = clock();
	int n;
	cin >> n ;
	pair<si,bool> tmp ;
	tmp.second = false;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> tmp.first;
		list.push_back(tmp);
	}
	//removing unnecessory brackets
	for(int i = 0 ; i < n ; i++ )
	{
		if(list[i].first < 0)
		{
			for(int j = i+1; j<n ; j++)
			{
				if(list[i].first*-1 == list[j].first)
				{
					list[i].second = true;
					list[j].second = true;
				}
			}
		}
	}
	for(int i = 0 ; i < list.size() ;i++)
	{
		if(list[i].second == false)
		{
			list.erase(list.begin()+i);
			i--;
		}
	}
	//input check -> printvect(list);

	//iterating through every element and finding violations
	vector<si> stack; 
	vector<si> current;
	mainiterator(0,stack,current);
	cout << get_combinations()%mod << endl;
	//cout << "time " << (float)(clock() - start)*1000/CLOCKS_PER_SEC << " ms" << endl;
	return 0 ;
}	