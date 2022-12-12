// This is my Second assignment of IITC, so I made a program to solve it.

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include "functions.cpp"
using namespace std;

int main(){
    system("clear");
    string number,result;
    int choice = 0;
    char run_again = 'y';
    cout<<"--------Number System Converter--------"<<endl;
    help_menu();
    while (run_again == 'y'){
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter a Decimal number: ";
                cin>>number;
                if (is_decimal(number) == false){
                    cout << "Entered Value is not a Decimal Number...!" << endl;
                    break;
                }
                result = dtob(number);
                cout << "(" << number << ")10 = ("<< result << ")2" << endl;
                break;
            case 2:
                cout<<"Enter a Decimal Number: ";
                cin>>number;
                if (is_decimal(number) == false){
                    cout << "Entered Value is not a Decimal Number...!" << endl;
                    break;
                }
                result = dtoo(number);
                cout << "(" << number << ")10 = ("<< result << ")8" << endl;
                break;
            case 3:
                cout<<"Enter a Decimal Number: ";
                cin>>number;
                if (is_decimal(number) == false){
                    cout << "Entered Value is not a Decimal Number...!" << endl;
                    break;
                }
                result = dtoh(number);
                cout << "(" << number << ")10 = ("<< result << ")16" << endl;
                break;
            case 4:
                cout<<"Enter a Binary Number: ";
                cin>>number;
                if (is_binary(number) == false){
                    cout << "Entered Value is not a Binary Number...!" << endl;
                    break;
                }
                result = btod(number);
                cout << "(" << number << ")2 = ("<< result << ")10" << endl;
                break;
            case 5:
                cout<<"Enter a Octal Number: ";
                cin>>number;
                if (is_octal(number) == false){
                    cout << "Entered Value is not a Octal Number...!" << endl;
                    break;
                }
                result = otod(number);
                cout << "(" << number << ")8 = ("<< result << ")10" << endl;
                break;
            case 6:
                cout<<"Enter a Hexadecimal Number: ";
                cin>>number;
                if (is_hexadecimal(number) == false){
                    cout << "Entered Value is not a Hexadecimal Number...!" << endl;
                    break;
                }
                result = htod(number);
                cout << "(" << number << ")16 = ("<< result << ")10" << endl;
                break;
            case 7:
                cout<<"Enter a Binary Number: ";
                cin>>number;
                if (is_binary(number) == false){
                    cout << "Entered Value is not a Binary Number...!" << endl;
                    break;
                }
                result = btoo(number);
                cout << "(" << number << ")2 = ("<< result << ")8" << endl;
                break;
            case 8:
                cout<<"Enter a Binary Number: ";
                cin>>number;
                if (is_binary(number) == false){
                    cout << "Entered Value is not a Binary Number...!" << endl;
                    break;
                }
                result = btoh(number);
                cout << "(" << number << ")2 = ("<< result << ")16" << endl;
                break;
            case 9:
                cout<<"Enter a Octal Number: ";
                cin>>number;
                if (is_octal(number) == false){
                    cout << "Entered Value is not a Octal Number...!" << endl;
                    break;
                }
                result = otob(number);
                cout << "(" << number << ")8 = ("<< result << ")2" << endl;
                break;
            case 10:
                cout<<"Enter a Octal Number: ";
                cin>>number;
                if (is_octal(number) == false){
                    cout << "Entered Value is not a Octal Number...!" << endl;
                    break;
                }
                result = otoh(number);
                cout << "(" << number << ")8 = ("<< result << ")16" << endl;
                break;
            case 11:
                cout<<"Enter a Hexadecimal Number: ";
                cin>>number;
                if (is_hexadecimal(number) == false){
                    cout << "Entered Value is not a Hexadecimal Number...!" << endl;
                    break;
                }
                result = htoo(number);
                cout << "(" << number << ")16 = ("<< result << ")8" << endl;
                break;
            case 12:
                cout<<"Enter a Hexadecimal Number: ";
                cin>>number;
                if (is_octal(number) == false){
                    cout << "Entered Value is not a Hexadecimal Number...!" << endl;
                    break;
                }
                result = htob(number);
                cout << "(" << number << ")16 = ("<< result << ")2" << endl;
                break;
            case 0:
                system("clear");
                help_menu();
                continue;
            default:
                cout<<"Invalid Choice" << endl;
        }
        cout << "Do you want to perform conversion again? (y or n): ";
        cin >> run_again;
    }
    return 0;
}
