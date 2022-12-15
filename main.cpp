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
    string choice = "0";
    char run_again = 'y';
    cout<<"--------Number System Converter--------"<<endl;
    help_menu();
    while (run_again == 'y'){
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == "1"){
            cout<<"Enter a Decimal number: ";
            cin>>number;
            if (is_decimal(number) == false){
                cout << "Entered Value is not a Decimal Number...!" << endl;
            }
            else{
                result = dtob(number);
                cout << "(" << number << ")10 = ("<< result << ")2" << endl;
            }
        }
        else if(choice == "2"){
            cout<<"Enter a Decimal Number: ";
            cin>>number;
            if (is_decimal(number) == false){
                cout << "Entered Value is not a Decimal Number...!" << endl;
            }
            else{
                result = dtoo(number);
                cout << "(" << number << ")10 = ("<< result << ")8" << endl;
            }
        }
        else if(choice == "3"){
            cout<<"Enter a Decimal Number: ";
            cin>>number;
            if (is_decimal(number) == false){
                cout << "Entered Value is not a Decimal Number...!" << endl;
            }
            else{
                result = dtoh(number);
                cout << "(" << number << ")10 = ("<< result << ")16" << endl;
            }
        }
        else if(choice == "4"){
            cout<<"Enter a Binary Number: ";
            cin>>number;
            if (is_binary(number) == false){
                cout << "Entered Value is not a Binary Number...!" << endl;
            }
            else{
                result = btod(number);
                cout << "(" << number << ")2 = ("<< result << ")10" << endl;
            }
        }
        else if(choice == "5"){
            cout<<"Enter a Octal Number: ";
            cin>>number;
            if (is_octal(number) == false){
                cout << "Entered Value is not a Octal Number...!" << endl;
            }
            else{
                result = otod(number);
                cout << "(" << number << ")8 = ("<< result << ")10" << endl;
            }
        }
        else if(choice == "6"){
            cout<<"Enter a Hexadecimal Number: ";
            cin>>number;
            if (is_hexadecimal(number) == false){
                cout << "Entered Value is not a Hexadecimal Number...!" << endl;
            }
            else{
                result = htod(number);
                cout << "(" << number << ")16 = ("<< result << ")10" << endl;
            }
        }
        else if(choice == "7"){
            cout<<"Enter a Binary Number: ";
            cin>>number;
            if (is_binary(number) == false){
                cout << "Entered Value is not a Binary Number...!" << endl;
            }
            else{
                result = btoo(number);
                cout << "(" << number << ")2 = ("<< result << ")8" << endl;
            }
        }
        else if(choice == "8"){
            cout<<"Enter a Binary Number: ";
            cin>>number;
            if (is_binary(number) == false){
                cout << "Entered Value is not a Binary Number...!" << endl;
            }
            else{
                result = btoh(number);
                cout << "(" << number << ")2 = ("<< result << ")16" << endl;
            }
        }
        else if(choice == "9"){
            cout<<"Enter a Octal Number: ";
            cin>>number;
            if (is_octal(number) == false){
                cout << "Entered Value is not a Octal Number...!" << endl;
            }
            else{
                result = otob(number);
                cout << "(" << number << ")8 = ("<< result << ")2" << endl;
            }
        }
        else if(choice == "10"){
            cout<<"Enter a Octal Number: ";
            cin>>number;
            if (is_octal(number) == false){
                cout << "Entered Value is not a Octal Number...!" << endl;
            }
            else{
                result = otoh(number);
                cout << "(" << number << ")8 = ("<< result << ")16" << endl;
            }
        }
        else if(choice == "11"){
            cout<<"Enter a Hexadecimal Number: ";
            cin>>number;
            if (is_hexadecimal(number) == false){
                cout << "Entered Value is not a Hexadecimal Number...!" << endl;
            }
            else{
                result = htoo(number);
                cout << "(" << number << ")16 = ("<< result << ")8" << endl;
            }
        }
        else if(choice == "12"){
            cout<<"Enter a Hexadecimal Number: ";
            cin>>number;
            if (is_hexadecimal(number) == false){
                cout << "Entered Value is not a Hexadecimal Number...!" << endl;
            }
            else{
                result = htob(number);
                cout << "(" << number << ")16 = ("<< result << ")2" << endl;
            }
        }
        else if(choice == "0"){
            system("clear");
            help_menu();
            continue;
        }
        else{
            cout<<"Invalid Choice" << endl;
            continue;
        }
        cout << "Do you want to perform conversion again? (y for yes): ";
        cin >> run_again;
    }
    return 0;
}
