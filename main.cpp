// This is my Second assignment of IITC, so I made a program to solve it.

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include "functions.cpp"
using namespace std;

int main(){
    string number,result;
    int choice;
    cout<<"----Number System Converter----"<<endl;
    cout<<"0 -- for help"<<endl;
    cout<<"1 -- for Decimal to Binary"<<endl;
    cout<<"2 -- for Decimal to Octal"<<endl;
    cout<<"3 -- for Decimal to Hexadecimal"<<endl;
    cout<<"4 -- for Binary to Decimal"<<endl;
    cout<<"4 -- for Octal to Decimal"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;    

    switch(choice){
        case 1:
            cout<<"Enter a decimal number: ";
            cin>>number;
            result = dtob(number);
            cout << "(" << number << ")10 = ("<< result << ")2" << endl;
            break;
        case 2:
            cout<<"Enter a Decimal Number: ";
            cin>>number;
            result = dtoo(number);
            cout << "(" << number << ")10 = ("<< result << ")8" << endl;
            break;
        case 3:
            cout<<"Enter a Decimal Number: ";
            cin>>number;
            result = dtoh(number);
            cout << "(" << number << ")10 = ("<< result << ")16" << endl;
            break;
        case 4:
            cout<<"Enter a Binary Number: ";
            cin>>number;
            result = btod(number);
            cout << "(" << number << ")2 = ("<< result << ")10" << endl;
            break;
        case 5:
            cout<<"Enter a Octal Number: ";
            cin>>number;
            result = otod(number);
            cout << "(" << number << ")8 = ("<< result << ")10" << endl;
            break;
        case 0:
            cout<<"Help";
            break;
        default:
            cout<<"Invalid Choice";
    } 
    return 0;
}