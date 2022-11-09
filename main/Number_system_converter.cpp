// This is my Second assignment of IITC, so I made a program to solve it.

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


string string_divisor(string, int);
string string_remainder(string, int);
string dtob(string);
string dtoo(string);
string dtoh(string);

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
            cout<<"Decimal = "<< result;
            break;
        case 2:
            cout<<"Enter a decimal number: ";
            cin>>number;
            result = dtoo(number);
            cout<<"Decimal = "<< result;
            break;
        case 3:
            cout<<"Enter a decimal number: ";
            cin>>number;
            result = dtoh(number);
            cout<<"Decimal = "<< result;
            break;
        case 0:
            cout<<"Help";
            break;
        default:
            cout<<"Invalid Choice";
    }
    cin>>result;   
    return 0;
}





string string_divisor(string num, int base){
    string num_temp,remainder_temp,result,num_temp1;  
    int length = ceil(num.length()/(9.0-to_string(base).length())); //7535204407491801690749180
    int count = 0;
    int s = 1;
    result = "";
    remainder_temp = "";
    for (int i = 0; i < length; i++)
    {
        num_temp = "";
        for (int j = 0; j < (9.0-to_string(base).length()); j++)
        {
            if (count>=num.length())
            {
                continue;
            }
            num_temp += num[count];
            count++;
        }
        num_temp1 = remainder_temp + num_temp[0];
        if (i>0)
        {
            while(stoi(num_temp1)<base)
            {
                cout<<"num_temp1 = "<<num_temp1<<endl;
                result += "0";
                num_temp1 += num_temp[s];
                s++;
                cout<<"Count = "<<count<<"\t"<<"While Loop Infinite"<<endl;
            }
        }
        num_temp = remainder_temp + num_temp;
        if (num_temp.length()==to_string(base).length())
        {
            if(stoi(num_temp) < base){
                break;
            }
        }
        
        result = result + to_string(stoi(num_temp) / base);
        remainder_temp = "";
        if (string_remainder(num_temp,base) != "0")
        {
            remainder_temp = string_remainder(num_temp,base);
        }
    }
    return result;
}



string string_remainder(string num, int base){
    string num_temp, result;
    int length = ceil(num.length()/8.0);
    int count = 0;
    result = "0";
    for (int i = 0; i < length; i++)
    {
        num_temp = "";
        for (int j = 0; j < 8; j++)
        {
            if (count>=num.length())
            {
                continue;
            }
            num_temp += num[count];     
            count++;
        }
        for (int k = 0; k < num_temp.length(); k++)
        {
            result = to_string(stoi(result)*10);

        }
        result = to_string((stoi(result) + stoi(num_temp)) % base);
    }
    return result;
}




string dtob(string d){
    int count;
    string result;
    int a[1000];
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        cout<<string_divisor(d,2)<<"\t"<<stoi(string_remainder(d,2))<<"\t"<<(i+1)<<endl;
        a[i]=stoi(string_remainder(d,2));
        d = string_divisor(d,2);
        if (d.length()<2)
        {
            if(stoi(d) < 2){
                a[i+1]=stoi(d);
                count++;
                break;
            }
        }
    }
    for (int j = count; j > 0; j--)
    {
        result += to_string(a[j-1]);
    }
    if(result.length()%4!=0){
        for (int i = 1; i > 0; i++)
        {
            if ((result.length()+i)%4==0)
            {
                for (int k = 1; k <= i; k++)
                {
                    result = "0" + result;
                }
                break;
            }
        }
    }
    return result;
}

string dtoo(string d){
    int count;
    string result;
    int a[1000];
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        cout<<string_divisor(d,8)<<"\t"<<stoi(string_remainder(d,8))<<endl;
        a[i]=stoi(string_remainder(d,8));
        d = string_divisor(d,8);
        if (d.length()<2)
        {
            if(stoi(d) < 8){
                a[i+1]=stoi(d);
                count++;
                break;
            }
        }
        
    }
    for (int j = count; j > 0; j--)
    {
        result += to_string(a[j-1]);
    }
    if(result.length()%3!=0){
        for (int i = 1; i > 0; i++)
        {
            if ((result.length()+i)%3==0)
            {
                for (int k = 1; k <= i; k++)
                {
                    result = "0" + result;
                }
                break;
            }
        }
    }
    return result;
}


string dtoh(string d){
    int count;
    string result;
    string a[1000];
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        cout<<string_divisor(d,16)<<"\t"<<stoi(string_remainder(d,16))<<"\t"<<(i+1)<<endl;
        a[i]=string_remainder(d,16);
        if (a[i] == "10")
        {
            a[i] = "A";
        }
        else if (a[i] == "11")
        {
            a[i] = "B";
        }
        else if (a[i] == "12")
        {
            a[i] = "C";
        }
        else if (a[i] == "13")
        {
            a[i] = "D";
        }
        else if (a[i] == "14")
        {
            a[i] = "E";
        }
        else if (a[i] == "15")
        {
            a[i] = "F";
        }
        d = string_divisor(d,16);
        if (d.length()<3)
        {
            if(stoi(d) < 16){
                a[i+1]=d;
                count++;
                if (a[i+1] == "10")
                {
                    a[i+1] = "A";
                }
                else if (a[i+1] == "11")
                {
                    a[i+1] = "B";
                }
                else if (a[i+1] == "12")
                {
                    a[i+1] = "C";
                }
                else if (a[i+1] == "13")
                {
                    a[i+1] = "D";
                }
                else if (a[i+1] == "14")
                {
                    a[i+1] = "E";
                }
                else if (a[i+1] == "15")
                {
                    a[i+1] = "F";
                }
                break;
            }
        }
    }
    for (int j = count; j > 0; j--)
    {
        result += a[j-1];
    }
    return result;
}