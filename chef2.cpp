#include <iostream>
#include <cstdlib>

using namespace std;

class node
{
public:
   int data;
   node* next;
   node* prev;
};

class list
{
private:
   node* a;
   node* first;
   int size ;
public:
   list(int n)
   {
      a = NULL;
      size = n-1;
   };
   void enque(int element)
   {
      node* temp = new node();
      temp->data = element ;
      temp->next = NULL ;
      if( a == NULL)  //first node
      {
         temp->prev = NULL ;
         a = temp ;
         first = temp ;
      }
      else if(size == 0)  //last node
      {
         temp->prev = a ;
         temp->next = first ;
         a->next = temp ;
         first->prev = temp ;
         a = first ;
      }
      else
      {
         temp->prev = a ;
         a->next = temp ;
         a = temp ;
      }
      size -- ;
   }
   void rotate_c(int d)
   {
      for(int i = 0 ; i < d ;i ++)
         a = a->next ;
   }
   void rotate_a(int d)
   {
      for(int i = 0 ; i < d ;i ++)
         a = a->prev ;
   }
   void display(int d)
   {
      node* temp  = a; 
      for(int i = 0 ; i < d ; i ++ )
         temp = temp->next;
      cout << temp->data << endl ;
   }
   
};


int main()
{
   int n,m,num ;
   cin >> n >> m ;
   list lst(n);
   for(int i = 0 ; i < n ; i++)
   {
      cin >> num ;
      lst.enque(num);
   }
   char control;
   int d;
   for(int i =0 ; i < m ; i++ )
   {
      cin >> control >> d ;
      if ( 'C' == control )
         lst.rotate_c(d);
      else if('A' == control)
         lst.rotate_a(d);
      else
         lst.display(d-1);
   }
   return 0 ;
}