#include <iostream>
#include <cstring> 

using namespace std;

class String
{
private:
	char *s;
	int size;
public:
	//constructor
	String(const char *str)
	{
		cout << "constructor Execute" << endl;
		size  = strlen(str);
		s = new char[size+1];
		strcpy(s,str);
	}
	//destructor
	/*The default destructor works fine unless we have dynamically allocated 
	memory or pointer in class. When a class contains a pointer to memory allocated
	in class, we should write a destructor to release memory before the class instance 
	is destroyed. This must be done to avoid memory leak.*/
	~String()
	{
		delete [] s;
		cout << "Destructor was executed" << endl ;
	}
	// copy constructor
	String(const String &str)
	{
		size = str.size;
		s = new char[size+1];
		strcpy(s,str.s);
	}
	void Change(const char *str)
	{
		delete [] s;
		size = strlen(str);
		s = new char[size+1];
		strcpy(s,str);
	}
	void print()
	{
		cout << s << endl;
	}
};

int main()
{
	String asd("ashish manmode");
	String zxc = asd ;

	asd.print();
	zxc.print();

	zxc.Change("ramesh pandey");

	asd.print();
	zxc.print();

	return 0 ; 
}
