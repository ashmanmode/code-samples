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
		size  = strlen(str);
		s = new char[size+1];
		strcpy(s,str);
	}
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
