#include <iostream>
using namespace std ;

class something
{
private:
	int a;
public:
	something(int a)
	{
		cout << "constructor called" << endl ;
	}
	~something()
	{
		cout << "destructor called" << endl ;
	}
};

int main()
{
	something(10);
	something a(12);
	a.~something();
	return 0;
}

