#include <cstdlib>
#include <iostream> 
using namespace std;

typedef struct Display{
	bool line[7];
	Display();
	Display(bool b[4]);
	void print();
}Display;

int input();
void decToBin(int val, bool b[4]);
void binToDisplay(bool b[4], Display *d);
