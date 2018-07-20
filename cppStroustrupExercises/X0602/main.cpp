/* -*- c++ -*- */

#include <iostream>
#include <chrono>
#include <thread> // Y se requiere -lpthread en el Makefile

using namespace std;

class Di {
public:
	Di(const string & texto) :
		texto_{texto}
	{
		cout<<"Constructor que recibe "<<texto<<endl;
	}
	
	void operator()()
	{
		for (int i = 0; i < 1000; ++i)
		{
			cout<<texto_<<endl;
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
	}
private:
	const string & texto_;
};

int main()
{
	thread t1 { Di{"Hola" } };
	thread t2 { Di{"Mundo"} };
	
	this_thread::sleep_for(chrono::milliseconds(5000));
	return EXIT_SUCCESS;
}
