/* -*- c++ -*- */

#include <iostream>
#include <chrono>
#include <thread> // Y se requiere -lpthread en el Makefile

using namespace std;

short int segundos2Milis(const float s)
{
	short int ms;
	
	if (s * 1000 > numeric_limits<short int>::max())
	{
		ms = numeric_limits<short int>::max();
	}
	else
	{
		ms = s * 1000;
	}
	return ms;
}

void dime(const string & texto)
{
	short int s = segundos2Milis(1.0f);
	
	for (int i = 0; i < 5; ++i)
	{
		cout<<texto<<endl;
		this_thread::sleep_for(chrono::milliseconds(segundos2Milis(1.0f)));
	}
}

int main()
{
	thread t1 (dime, "Hola" );
	this_thread::sleep_for(chrono::milliseconds(segundos2Milis(0.5f)));
	thread t2 (dime, "Mundo");
	
	t1.join();
	t2.join();
		
	cout<<"Adiós"<<endl;
	
	return EXIT_SUCCESS;
}

