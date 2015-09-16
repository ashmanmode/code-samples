//FB Hacker Cup : Using Redix trie
#include <bits/stdc++.h>
using namespace std;

struct node  
{
    char* key;
    int len;
    node* lnk;
    node* nxt;
    node(char* x, int n) : len(n), lnk(0), nxt(0) 
    { 
        key = new char[n]; 
        strncpy(key,x,n);       
    }
};

// dividing t node according to k key symbol 
void split(node* t, int k) 
{
    node* p = new node(t->key+k,t->len-k);
    p->lnk = t->lnk;
    t->lnk = p;
    char* a = new char[k];
    strncpy(a,t->key,k);
    delete[] t->key;
    t->key = a;
    t->len = k;
}

//returns len of longest common prefix of x and key 
int prefix(char* x, int n, char* key, int m)  
{
    for( int k=0; k<n; k++ )
        if( k==m || x[k]!=key[k] ) 
            return k;
    return n;
}

// inserting x key in t tree 
node* insert(node* t, char* x, int n=0) 
{
    if( !n ) n = strlen(x)+1;
    if( !t ) return new node(x,n);
    int k = prefix(x,n,t->key,t->len);
    if( k==0 ) t->nxt = insert(t->nxt,x,n);
    else if( k<n )
    {
        if( k<t->len ) // cut or not to cut?
            split(t,k);
        t->lnk = insert(t->lnk,x+k,n-k);
    }
    return t;
}


//finds max overlapping string in the tree 
int find(node* t, char* x, int n=0) 
{
    if( !n ) n = strlen(x)+1; 
    if( !t ) return 0;
    int k = prefix(x,n,t->key,t->len);
    if( k==0 ) return find(t->nxt,x,n); //looking for the child’s node 
    if( k==n ) return n;
    if( k==t->len ) return t->len + find(t->lnk,x+k,n-k); // let’s look for at the child’s node 
    else if( k < t->len ) return k ; 
    return 0; 
}


int main()
{
	//freopen("fb_input.txt","r",stdin);
    //freopen("fb_output.txt","w",stdout);
	int test_cases,n;
	cin >> test_cases ;
	string s ;	
	int count,match;
	for(int i = 0 ; i < test_cases ; i++ )
	{
		cin >> n >> s;
		char a[s.size()+1];
		strcpy(a,s.c_str());

		//create first node
		node t(a,strlen(a));
		count = 1 ;
		for(int j = 0 ; j < n-1; j++ )
		{
			cin >> s ;
			char a[s.size()+1];
			strcpy(a,s.c_str());
			match = find(&t,a,strlen(a));
			if(match == strlen(a))  //if no place to add an extra literal
				count += match ;
			else
				count += match +1 ;
			insert(&t,a,strlen(a));
		}
		cout << "Case #" << i+1 << ": " << count << endl ;
 	}
}
