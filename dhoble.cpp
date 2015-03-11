#include <bits/stdc++.h>
const double eps = 1e-9;
using namespace std;

void printmat(vector< vector<int> > mat,vector<int> b)
{
	for(int i = 0 ; i < mat.size() ; i++ )
	{
		for(int j = 0 ; j < mat[i].size() ; j++ )
			cout << mat[i][j] << " ";
		cout << " " << b[i] << endl ;
	}
	cout << endl ;
}

void printvect(vector<double> a)
{
	for(int i = 0 ; i < a.size() ; i++ )
		cout << a[i] << " " ;
	cout << endl;
}

vector<double> gaussian(vector<vector<double> > A, vector<double> b)
{
	int n = A.size();
	for(int i=0; i<n; i++)	{
		for(int j=i+1; j<n; j++)	{
			double mul = A[i][i] / (A[j][i] + eps );
			for(int k=i; k<n; k++)	{
				A[j][k] *= mul;
				A[j][k] -= A[i][k];
			}
			b[j] *= mul;
			b[j] -= b[i];
		}
	}

	vector<double> ret(n);
	for(int i=n-1; i>=0; i--)	{
		double sub = 0.0;
		for(int j = i+1; j<n; j++)	{
			sub += ret[j] * A[i][j];
		}
		b[i] -= sub;
		ret[i] = b[i] / (A[i][i] + eps );
	}
	return ret;
}

int main()
{
	int eq,var,iterator;
	cin >> var >> eq;
	double arr[eq][var+1];
	for(int i = 0 ; i < eq ; i++ )
		for(int j = 0 ; j < var+1 ; j++ )
			cin >> arr[i][j] ;
	cout << "enter optimisation equation" << endl;
	vector<double> opeq(var);
	for(int i=0; i< var; i++)
		cin >> opeq[i];

	//Making a Matrix to solve
	string set;
	for(int i = 0 ; i < var; i++ )
	{
		if( i < (var-eq))
			set.append("0");
		else
			set.append("1");
	}

	double sum,max = 0;
	vector<double> finalsol(var) ;
	vector< vector<double> >   matA;
	vector<double> temp(var);
	for(int i = 0 ; i < var ; i++ )
		matA.push_back(temp);
	vector<double> matB(var);
	int i ;
	do
	{
		iterator = 0 ;
		for(i = 0 ; i < var ; i++ )
		{
			if(set[i] == '0')
			{
				for(int j = 0 ; j < var ; j++ )
					matA[i][j] = 0 ;
				matA[i][i] = 1; 
				matB[i] = 0 ;
			}
			else
			{
				for(int j = 0 ; j < var ; j++ )
					matA[i][j] = arr[iterator][j];
				matB[i] = arr[iterator][var];
				iterator++;
			}
		}

		vector<double> sol = gaussian(matA,matB); 
		sum = 0;
		for(i = 0 ; i < var ;i++)
		{
			if(sol[i] < - 100*eps )
				break;
			sum += opeq[i]*sol[i];
		}
		if(i != var)
			continue;
		if(sum > max)
		{
			max = sum ;
			finalsol = sol ;
		}
		
	}while(next_permutation(&set[0],&set[var]));

	if(max == 0)
	{
		cout << "No solution exist " << endl;
		return 0 ;
	}
	cout << "Max Optimised Value " << max << endl ;
	cout << "Solution vector " << endl;
	for(int i = 0 ; i < var ; i++ )
		cout << "x" << i+1 << "\t";
	cout << endl;
	for(int i = 0 ; i < var ; i++ )
	{
		if(finalsol[i] < 0)
			cout << 0 << "\t";
		else
			cout << finalsol[i] << "\t" ;
	}
	cout << endl ;
	return 0 ;
}