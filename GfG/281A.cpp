#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string home,away;
	cin >> home >> away ;
	int num_fouls ;
	cin >> num_fouls ;

	vector<int> Time;
	vector<int> player;
	vector<bool> foul;
	vector<bool> team;

	int a,b,i,j,m;
	char s,f; bool w,t;
	for(i = 0 ; i < num_fouls ; i++ )
	{
		cin >> a >> s >> b >> f ;
		w = true ; t = true ;
		if(f == 'y')
			w = false ;
		if(s == 'h')
			t = false ;
		Time.push_back(a);
		player.push_back(b);
		foul.push_back(w);
		team.push_back(t);
	}

	// for all
	vector<int> Htaken,Ataken ;
	for(i = 0 ; i < Time.size() ; i++ )
	{
		if(foul[i] == true)
		{
			if(team[i] == false)
			{
				for(m = 0 ; m < Htaken.size() ; m++ )
				{
					if(Htaken[m] == player[i])
						break;
				}
				if(m==Htaken.size())
				{
					Htaken.push_back(player[i]);
					cout << home << " " << player[i] << " " << Time[i] << endl ;
				}
			}
			else
			{
				for(m = 0 ; m < Ataken.size() ; m++ )
				{
					if(Ataken[m] == player[i])
						break;
				}
				if(m==Ataken.size())
				{
					Ataken.push_back(player[i]);
					cout << away << " " << player[i] << " " << Time[i] << endl ;
				}
			}
		}
		else
		{
			if(team[i] == false)
			{
				for(j = 0 ; j < i ; j++  )
				{
					if(player[i] == player[j] && team[j] == false)
						break;
				}
				if( j != i )
				{
					for(m = 0 ; m < Htaken.size() ; m++ )
					{
						if(Htaken[m] == player[i])
							break;
					}
					if(m==Htaken.size())
					{
						Htaken.push_back(player[i]);
						cout << home << " " << player[i] << " " << Time[i] << endl ;
					}
				}
			}
			else
			{
				for(j = 0 ; j < i ; j++  )
				{
					if(player[i] == player[j] && team[j] == true)
						break;
				}
				if( j != i )
				{
					for(m = 0 ; m < Ataken.size() ; m++ )
					{
						if(Ataken[m] == player[i])
							break;
					}
					if(m==Ataken.size())
					{
						Ataken.push_back(player[i]);
						cout << away << " " << player[i] << " " << Time[i] << endl ;
					}
				}
			}
		}
	}
	return 0;
}