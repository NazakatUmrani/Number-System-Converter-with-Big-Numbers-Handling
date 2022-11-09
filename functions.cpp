//Including Header Files -- Start
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//Including Header Files -- End


//Function Declarations -- Start
string string_divisor(string, int);
string string_remainder(string, int);
//Function Declarations -- End


//Main Function -- Start
int main(){
    string divident;
    int divisor;
    cout << "Enter a divident: " ;
    cin >> divident;
    cout << "Enter a divisor: " ;
    cin >> divisor;
    cout << "Result: " << string_divisor(divident, divisor) << endl;
}
//Main Function -- End


//Function Definations -- Start
string string_divisor(string num, int base){   //num = 8888
    string result, substrOfNum, remainder;
    for (int l = 0; l < num.length(); l++)
    {
        substrOfNum = remainder + num[l];
        result = result + to_string(stoi(substrOfNum)/base);
        if (result == "0")
        {
            result = "";
        }
        
        cout << result + to_string(stoi(substrOfNum)/base) << endl;
        remainder = to_string(stoi(substrOfNum)%base);

    }
    return result;
}


//int size = 8 for this function
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
//Function Definations -- End