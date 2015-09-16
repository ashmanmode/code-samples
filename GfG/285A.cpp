#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d ; 
	int score1 = (3*a)/10 ; 
	int score2 = (3*b)/10 ; 
	if((a - (a/250)*c) > score1)
		score1 = (a - (a/250)*c) ;
	if((b - (b/250)*d) > score2)
		score2 = (b - (b/250)*d) ; 
	if(score1 == score2)
		cout << "Tie" << endl ;
	else if ( score1 > score2 )
		cout << "Misha" << endl ;
	else
		cout << "Vasya" << endl ;
}