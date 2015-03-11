#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i = 0 ; i < n ; i++ )
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define printvect(a) fr(i,a.size()) cout << a[i] << " " ;
typedef unsigned long long int ull;


int main()
{
	string s,t ;
	cin >> s >> t ;
	int s_arr[26];
	int S_arr[26];
	int t_arr[26];
	int T_arr[26];
	fr(i,26)
	{
		s_arr[i] = 0 ;
		S_arr[i] = 0 ;
		t_arr[i] = 0 ;
		T_arr[i] = 0 ;
	}
	fr(i,s.length())
	{
		if(s[i] < '[')
			S_arr[(int)s[i]-65]++;
		else
			s_arr[(int)s[i]-97]++;
	}
	fr(i,t.length())
	{
		if(t[i] < '[')
			T_arr[(int)t[i]-65]++;
		else
			t_arr[(int)t[i]-97]++;
	}

	//calc
	int joy = 0 ; 
	int whoop = 0 ;

	//joy
	fr(i,26)
	{
		if(s_arr[i] < t_arr[i])
		{
			joy += s_arr[i];
			t_arr[i] -= s_arr[i];
			s_arr[i] = 0 ;
		}
		else
		{
			joy += t_arr[i];
			s_arr[i] -= t_arr[i];
			t_arr[i] = 0 ;
		}
	}
	fr(i,26)
	{
		if(S_arr[i] < T_arr[i])
		{
			joy += S_arr[i];
			T_arr[i] -= S_arr[i];
			S_arr[i] = 0 ;
		}
		else
		{
			joy += T_arr[i];
			S_arr[i] -= T_arr[i];
			T_arr[i] = 0 ;
		}
	}


	//whoop
	fr(i,26)
	{
		if(s_arr[i] < T_arr[i])
			whoop += s_arr[i];
		else
			whoop += T_arr[i];
	}
	fr(i,26)
	{
		if(S_arr[i] < t_arr[i])
			whoop += S_arr[i];
		else
			whoop += t_arr[i];
	}
	cout << joy << " " << whoop << endl ;
	return 0;
}