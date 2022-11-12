// This is my Second assignment of IITC, so I made a program to solve it.

#include <iostream>
#include <cmath>
#include <string>
#include "functions.cpp"
using namespace std;

int main(){
    string number,result;
    int choice;
    cout<<"----Number System Converter----"<<endl;
    cout<<"0 --for help"<<endl;
    cout<<"1 --for decimal to binary"<<endl;
    cout<<"2 --for decimal to octal"<<endl;
    cout<<"3 --for decimal to hexadecimal"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;    

    switch(choice){
        case 1:
            cout<<"Enter a decimal number: ";
            cin>>number;
            result = dtob(number);
            cout<<"Decimal = "<< result << endl;
            break;
        case 2:
            cout<<"Enter a decimal number: ";
            cin>>number;
            result = dtoo(number);
            cout<<"Decimal = "<< result << endl;
            break;
        case 3:
            cout<<"Enter a decimal number: ";
            cin>>number;
            result = dtoh(number);
            cout<<"Decimal = "<< result << endl;
            break;
        case 0:
            cout<<"Help";
            break;
        default:
            cout<<"Invalid Choice";
    } 
    return 0;
}