// This is my Second assignment of IITC, so I made a program to solve it.
#include "BigNumbersArithematic.hpp"
#include "NumberSystem.hpp"
#include "ExtraFuncs.hpp"
int main(){
    system("clear");
    ifstream in;
    ofstream out;
    string historyNum;
    Number_System num;
    string choice = "0";
    char run_again = 'y';
    cout<<"---------------Number System Converter---------------"<<endl;
    help_menu();
    while (run_again == 'y'){
        in.open("History.txt");
        if (!getline(in, historyNum)){
            historyNum = "1";
            out.open("History.txt");
            out << "0 Conversions Performed" << endl;
            in.close();
            out.close();
        }
        else{
            in.close();
            in.open("History.txt");
            in >> historyNum;
            historyNum = num.string_plus(historyNum, "1");
            in.close();
        }
        cout<<"Enter your choice: ";
        cin>>choice;
        out.open("History.txt", ios :: app);
        if(choice == "1"){
            cout<<"Enter a Decimal number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_decimal() == false){
                cout << "Entered Value is not a Decimal Number...!" << endl;
            }
            else{
                num.dtob();
                cout << "(" << num.number << ")10 = ("<< num.result << ")2" << endl;
                out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")2" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "2"){
            cout<<"Enter a Decimal Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_decimal() == false){
                cout << "Entered Value is not a Decimal Number...!" << endl;
            }
            else{
                num.dtoo();
                cout << "(" << num.number << ")10 = ("<< num.result << ")8" << endl;
                out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")8" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "3"){
            cout<<"Enter a Decimal Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_decimal() == false){
                cout << "Entered Value is not a Decimal Number...!" << endl;
            }
            else{
                num.dtoh();
                cout << "(" << num.number << ")10 = ("<< num.result << ")16" << endl;
                out << historyNum << ". (" << num.number << ")10 = ("<< num.result << ")16" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "4"){
            cout<<"Enter a Binary Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_binary() == false){
                cout << "Entered Value is not a Binary Number...!" << endl;
            }
            else{
                num.btod();
                cout << "(" << num.number << ")2 = ("<< num.result << ")10" << endl;
                out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")10" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "5"){
            cout<<"Enter a Octal Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_octal() == false){
                cout << "Entered Value is not a Octal Number...!" << endl;
            }
            else{
                num.otod();
                cout << "(" << num.number << ")8 = ("<< num.result << ")10" << endl;
                out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")10" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "6"){
            cout<<"Enter a Hexadecimal Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_hexadecimal() == false){
                cout << "Entered Value is not a Hexadecimal Number...!" << endl;
            }
            else{
                num.htod();
                cout << "(" << num.number << ")16 = ("<< num.result << ")10" << endl;
                out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")10" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "7"){
            cout<<"Enter a Binary Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_binary()== false){
                cout << "Entered Value is not a Binary Number...!" << endl;
            }
            else{
                num.btoo();
                cout << "(" << num.number << ")2 = ("<< num.result << ")8" << endl;
                out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")8" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "8"){
            cout<<"Enter a Binary Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_binary() == false){
                cout << "Entered Value is not a Binary Number...!" << endl;
            }
            else{
                num.btoh();
                cout << "(" << num.number << ")2 = ("<< num.result << ")16" << endl;
                out <<  historyNum << ". (" << num.number << ")2 = ("<< num.result << ")16" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "9"){
            cout<<"Enter a Octal Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_octal() == false){
                cout << "Entered Value is not a Octal Number...!" << endl;
            }
            else{
                num.otob();
                cout << "(" << num.number << ")8 = ("<< num.result << ")2" << endl;
                out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")2" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "10"){
            cout<<"Enter a Octal Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_octal() == false){
                cout << "Entered Value is not a Octal Number...!" << endl;
            }
            else{
                num.otoh();
                cout << "(" << num.number << ")8 = ("<< num.result << ")16" << endl;
                out <<  historyNum << ". (" << num.number << ")8 = ("<< num.result << ")16" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "11"){
            cout<<"Enter a Hexadecimal Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_hexadecimal() == false){
                cout << "Entered Value is not a Hexadecimal Number...!" << endl;
            }
            else{
                num.htoo();
                cout << "(" << num.number << ")16 = ("<< num.result << ")8" << endl;
                out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")8" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "12"){
            cout<<"Enter a Hexadecimal Number: ";
            cin>>num.number;
            num.numbercopy = num.number;
            if (num.is_hexadecimal() == false){
                cout << "Entered Value is not a Hexadecimal Number...!" << endl;
            }
            else{
                num.htob();
                cout << "(" << num.number << ")16 = ("<< num.result << ")2" << endl;
                out <<  historyNum << ". (" << num.number << ")16 = ("<< num.result << ")2" << endl;
                updateConversionsPerformed(historyNum);
            }
            out.close();
        }
        else if(choice == "13"){
            out.close();
            ifstream in2("History.txt");
            string line;
            try{
                string tempLine;
                if (!getline(in2, tempLine) || tempLine == "0 Conversions Performed"){
                    throw "File Empty";
                }
                else{
                    in2.close();
                    in2.open("History.txt");
                    cout << "\nHistory:\n";
                    do{
                        getline(in2, line);
                        cout << line << endl;
                    }while(!in2.eof());
                }
            }
            catch(const char* errorMessage)
            {
                cerr << errorMessage << endl;
            }
            in2.close();
            continue;
        }
        else if(choice =="14"){
            string hn;
            cout << "Which number of history you want to see: ";
            cin >> hn;
            out.close();
            searchInHistory(hn);
        }
        else if(choice == "15"){
            out.close();
            help_menu();
            continue;
        }
        else if(choice == "16"){
            out.close();
            break;
        }
        else{
            out.close();
            cout<<"Invalid Choice" << endl;
            cout<<"Type 15 for Help" << endl;
            continue;
        }
        cout << "Do you want to perform conversion again? (y for yes): ";
        cin >> run_again;
    }
    cout << "Thanks for using my Converter" << endl;
    return 0;
}
