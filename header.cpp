#include <cstdlib>
#include <iostream>
#include "header.h"

Display :: Display(){}
Display :: Display(bool b[4]){
    binToDisplay(b, this);
}

void Display :: print(){
    if(line[0]) cout << " * * * * "; else cout << " \t ";
    cout << endl;
    if(line[1]){
        if(line[2]){for(int i=0;i<4;i++)cout<<"*\t*"<<endl;}
        else{for(int i=0;i<4;i++)cout<<"*\t "<<endl;}
    }
    else{
        if(line[2]){for(int i=0;i<4;i++)cout<<" \t*"<<endl;}
        else{for(int i=0;i<4;i++)cout<<" \t "<<endl;}
    }
    if(line[3]) cout << " * * * * "; else cout << " \t ";
    cout << endl;
    if(line[4]){
        if(line[5]){for(int i=0;i<4;i++)cout<<"*\t*"<<endl;}
        else{for(int i=0;i<4;i++)cout<<"*\t "<<endl;}
    }
    else{
        if(line[5]){for(int i=0;i<4;i++)cout<<" \t*"<<endl;}
        else{for(int i=0;i<4;i++)cout<<" \t "<<endl;}
    }
    if(line[6]) cout << " * * * * "; else cout << " \t ";
    cout << endl<<endl;
}

int input(){
    int val;
    do{
        cout << "insert a value (0-9):" << endl;
        cin >> val;
    }while(val>9 || val<0);
    //cout << val << endl;
    return val;
}

void decToBin(int val, bool b[4]){
    for(int i = 3; i >= 0; i--){
        b[i] = val%2;
        val /= 2;
    }
    //for(int i = 0; i < 4; i++)cout << b[i] << endl;
}

void binToDisplay(bool b[4], Display *d){
    bool A, B, C, D;
    A = b[0];
    B = b[1];
    C = b[2];
    D = b[3];

    d->line[0]= A | C | (B & D) | (!C & !B & !D);
    d->line[1]= A | (B & !C) | (!C & !D) | (B & !D);
    d->line[2]= A | (C & D) | (!C & !D) | (!A & !B);
    d->line[3]= A | (B & !C) | (C & !D) | (C & !B);
    d->line[4]= (!D & !B) | (C & !D);
    d->line[5]= A | B | !C | D;
    d->line[6]= A | (!A & !B & !D) | (C & !D) | (B & !C & D) | (!A & !B & C);
}
