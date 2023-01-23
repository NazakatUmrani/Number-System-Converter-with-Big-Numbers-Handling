#include "ExtraFuncs.hpp"
void help_menu(){
    cout<<"----------------------Help Menu----------------------"<<endl;
    cout<<" 1   --   for Decimal          to        Binary"<<endl;
    cout<<" 2   --   for Decimal          to        Octal"<<endl;
    cout<<" 3   --   for Decimal          to        Hexadecimal"<<endl;
    cout<<" 4   --   for Binary           to        Decimal"<<endl;
    cout<<" 5   --   for Octal            to        Decimal"<<endl;
    cout<<" 6   --   for Hexadecimal      to        Decimal"<<endl;
    cout<<" 7   --   for Binary           to        Octal"<<endl;
    cout<<" 8   --   for Binary           to        Hexadecimal"<<endl;
    cout<<" 9   --   for Octal            to        Binary"<<endl;
    cout<<"10   --   for Octal            to        Hexadecimal"<<endl;
    cout<<"11   --   for Hexadecimal      to        Octal"<<endl;
    cout<<"12   --   for Hexadecimal      to        Binary"<<endl;
    cout<<"13   --   for displaying conversions history"<<endl;
    cout<<"14   --   for searching previous history"<<endl;
    cout<<"15   --   for this Help Menu"<<endl;
    cout<<"16   --   to quit this program"<<endl;
}

void updateConversionsPerformed(string n){
    ifstream in;
    ofstream out;
    string line, num;
    BigNumbersArithematic obj;
    in.open("History.txt");
    out.open("TempHistory.txt");
    while (getline(in, line)){
        out << line << endl;
    }
    in.close();
    out.close();
    num = n;
    line = num + " Conversions Performed";
    in.open("TempHistory.txt");
    out.open("History.txt");
    getline(in, num);
    out << line << endl;
    while(getline(in, line)){
        out << line << endl;
    }
    in.close();
    out.close();
    try{
        int x = remove("TempHistory.txt");
        if (x != 0){
            throw "TempHistory File Not Deleted";
        }
    }
    catch(const char* e)
    {
        cerr << e << endl;
    }
}
void searchInHistory(string &n){
    ifstream in3("History.txt");
    string line3;
    n += ".";
    while(in3 >> line3){
        if(line3 == n){
            cout << "\nData Found" << endl;
            cout << line3 << " ";
            in3 >> line3;
            cout << line3 << " ";
            in3 >> line3;
            cout << line3 << " ";
            in3 >> line3;
            cout << line3 << endl << endl;
            line3 = "NULL";
            break;
        }
    }
    if (line3 != "NULL"){
        cout << "\nData does not exist\n" << endl;
    }
    in3.close();
}