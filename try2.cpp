#include <bits/stdc++.h>
using namespace std;

struct food
{
    int p;
    int c;
    int f;
};

ifstream in("cooking_the_books_example_input.txt");
ofstream out("fbhackercup1.txt");
vector<food> a ; 

bool isSol(int n,int p,int c,int f)
{
    if( p == 0 && c == 0 && f == 0 )
        return true;
    if( n == 0 && (p != 0 || c != 0 || f != 0) )
        return false;

    if(a[n-1].p > p || a[n-1].c > c || a[n-1].f > f)
        return isSol(n-1,p,c,f);
    return isSol(n-1,p,c,f) || isSol(n-1,p-a[n-1].p,c-a[n-1].c,f-a[n-1].f);
}

int main()
{
    int t ; 
    in >> t ;
    int P,C,F,n,r;
    for(int i = 0 ; i < t ; i++ )
    {
        in >> P >> C >> F ;
        in >> n;
        for(int j = 0 ; j < n ; j++ )
        {
            food temp;
            in >> temp.p >> temp.c >> temp.f ;
            a.push_back(temp);
        }
        if(isSol(n,P,C,F))
            out << "Case #" << i+1 << ": yes" << endl;
        else
            out << "Case #" << i+1 << ": no" << endl;
        a.clear();
    }
}