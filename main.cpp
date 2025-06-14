#include <cstdlib>
#include<iostream>
#include "header.h"
using namespace std;

int main(int argc, char *argv[]){
    bool b[4];
    decToBin(input(),b);
    Display d(b);
    d.print();
}
