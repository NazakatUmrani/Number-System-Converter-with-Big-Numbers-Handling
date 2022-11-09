#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string string_divisor(string, int);
string string_remainder(string, int);

int main(){
    int base = 2;
    string num,result;
    cin>>num;
    result = string_divisor(num,base);
    cout<<result;
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
        num_temp = remainder_temp + num_temp;
        if (i>0)
        {
            while(stoi(num_temp1)<2)
            {
                cout<<"num_temp1 = "<<num_temp1<<endl;
                result += "0";
                num_temp1 += num_temp[s];
                s++;
                cout<<"Count = "<<count<<"\t"<<"While Loop Infinite"<<endl;
            }
        }
        if (num_temp.length()==1)
        {
            cout<<num_temp.length()<<"\t"<<num_temp<<endl;
            if(stoi(num_temp) < 2){
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