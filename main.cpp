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
    cout<<"0  -- for help"<<endl;
    cout<<"1  -- for Decimal     to  Binary"<<endl;
    cout<<"2  -- for Decimal     to  Octal"<<endl;
    cout<<"3  -- for Decimal     to  Hexadecimal"<<endl;
    cout<<"4  -- for Binary      to  Decimal"<<endl;
    cout<<"5  -- for Octal       to  Decimal"<<endl;
    cout<<"6  -- for Hexadecimal to  Decimal"<<endl;
    cout<<"7  -- for Binary      to  Octal"<<endl;
    cout<<"8  -- for Binary      to  Hexadecimal"<<endl;
    cout<<"9  -- for Octal       to  Binary"<<endl;
    cout<<"10 -- for Octal       to  Hexadecimal"<<endl;
    cout<<"11 -- for Hexadecimal to  Octal"<<endl;
    cout<<"12 -- for Hexadecimal to  Binary"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;    

    switch(choice){
        case 1:
            cout<<"Enter a Decimal number: ";
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
        case 6:
            cout<<"Enter a Hexadecimal Number: ";
            cin>>number;
            result = htod(number);
            cout << "(" << number << ")16 = ("<< result << ")10" << endl;
            break;
        case 7:
            cout<<"Enter a Binary Number: ";
            cin>>number;
            result = btoo(number);
            cout << "(" << number << ")2 = ("<< result << ")8" << endl;
            break;
        case 8:
            cout<<"Enter a Binary Number: ";
            cin>>number;
            result = btoh(number);
            cout << "(" << number << ")2 = ("<< result << ")16" << endl;
            break;
        case 9:
            cout<<"Enter a Octal Number: ";
            cin>>number;
            result = otob(number);
            cout << "(" << number << ")8 = ("<< result << ")2" << endl;
            break;
        case 10:
            cout<<"Enter a Octal Number: ";
            cin>>number;
            result = otoh(number);
            cout << "(" << number << ")8 = ("<< result << ")16" << endl;
            break;
        case 11:
            cout<<"Enter a Hexadecimal Number: ";
            cin>>number;
            result = htoo(number);
            cout << "(" << number << ")16 = ("<< result << ")8" << endl;
            break;
        case 12:
            cout<<"Enter a Hexadecimal Number: ";
            cin>>number;
            result = htob(number);
            cout << "(" << number << ")16 = ("<< result << ")2" << endl;
            break;
        case 0:
            cout<<"Help";
            break;
        default:
            cout<<"Invalid Choice";
    } 
    return 0;
}