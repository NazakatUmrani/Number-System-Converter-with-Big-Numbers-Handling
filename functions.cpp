//Including Header Files -- Start
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
//Including Header Files -- End

//Function Declarations -- Start
string dtob(string d);
string dtoh(string d);
string dtoo(string d);
string btod(string d);
string otod(string d);
string htod(string d);
string btoo(string d);
string btoh(string d);
string otob(string d);
string otoh(string d);
string htob(string d);
string htoo(string d);

string string_divisor(string, int);
string string_remainder(string, int);
string string_multiplication(string, string);
string string_power(string, string);
string string_plus(string, string);
string string_minus(string, string);
//Function Declarations -- Start

//Function Definations -- Start

//Big Numbers Arithmetic Functions -- Start
string string_divisor(string num, int base){
    string quotient, substrOfNum, remainder;
    for (int l = 0; l < num.length(); l++)
    {
        substrOfNum = remainder + num[l];
        quotient = quotient + to_string(stoi(substrOfNum)/base);
        if (quotient == "0")
        {
            quotient = "";
        }
        remainder = to_string(stoi(substrOfNum)%base);
    }
    return quotient;
}

string string_remainder(string num, int base){
    string quotient, substrOfNum, remainder;
    for (int k = 0; k < num.length(); k++)
    {
        substrOfNum = remainder + num[k];
        quotient = quotient + to_string(stoi(substrOfNum)/base);
        if (quotient == "0")
        {
            quotient = "";
        }
        remainder = to_string(stoi(substrOfNum)%base);
    }
    return remainder;
}

string string_plus(string str1, string str2){
    int length, zeroscount, str1len, str2len;
    str1len = str1.length();
    str2len = str2.length();
    string result, carry, str1reverse, str2reverse;
    if (str2len < str1len)
    {
        length = str1len;
        zeroscount = (length-str2len);
        for (int w = 0; w < zeroscount; w++)
        {
            str2 = "0" + str2;
        }
    }
    else if (str1len < str2len)
    {
        length = str2len;
        zeroscount = (length-str1len);
        for (int o = 0; o < zeroscount; o++)
        {
            str1 = "0" + str1;
        }
    }
    else
    {
        length = str1.length();
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());   
    carry = "0";
    for (int o = 0; o < length; o++)
    {
        string temp1, temp2, result_temp;
        temp1 = str1[o];
        temp2 = str2[o];
        result_temp = to_string(stoi(carry) + stoi(temp1) + stoi(temp2));
        if (result_temp.length() > 1)
        {
            carry = result_temp[0];
            result += result_temp[1];
        }
        else
        {
            carry = "0";
            result += result_temp;
        }
        if (o==(length-1) && carry != "" && carry != "0")
        {
            result += carry;
        }
    }    
    reverse(result.begin(), result.end());
    return result;
}

string string_multiplication(string number, string multiplier){
    if (number == "0" || multiplier == "0")
    {
        return "0";
    }
    else{
        string ans = "0", result;
        int carry;
        reverse(number.begin(), number.end());
        reverse(multiplier.begin(),multiplier.end());
        for (int j = 0; j < multiplier.size(); j++)
        {   
            result = "";
            carry = 0;
            for (int i = 0; i < number.size(); i++)
            {
                string tempnumber, tempmultiplier, tempans;
                tempnumber = number[i];
                tempmultiplier = multiplier[j];
                tempans = to_string(carry + (stoi(tempnumber) * stoi(tempmultiplier)));
                if (tempans.size() > 1)
                {
                    string strtoint;
                    strtoint = tempans[0];
                    carry = stoi(strtoint);
                    result += tempans[1];
                }
                else
                {
                    result += tempans[0];
                    carry = 0;
                }
                if (i == (number.size()-1) && carry != 0)
                {
                    result += to_string(carry);
                }
            }
            reverse(result.begin(), result.end());
            for (int k = 0; k < j; k++)
            {
                result += "0";
            }
            ans = string_plus(ans, result);
        }
        return ans;
    }
}

string string_power(string number, string power){
    string i = "1", result = number;
    while (i != power && stoi(power) > 0)
    {
        result = string_multiplication(result,number);
        i = string_plus(i, "1");
    }
    if (power == "0")
    {
        return "1";
    }
    return result;
}

string string_minus(string str1, string str2){
    int length, zeroscount, str1len, str2len;
    str1len = str1.length();
    str2len = str2.length();
    string result, str1reverse, str2reverse;
    if (str2len < str1len)
    {
        length = str1len;
        zeroscount = (length-str2len);
        for (int w = 0; w < zeroscount; w++)
        {
            str2 = "0" + str2;
        }
    }
    else if (str1len < str2len)
    {
        length = str2len;
        zeroscount = (length-str1len);
        for (int o = 0; o < zeroscount; o++)
        {
            str1 = "0" + str1;
        }
    }
    else
    {
        length = str1.length();
    }
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int o = 0; o < length; o++)
    {
        string temp1, temp2, result_temp;
        temp1 = str1[o];
        temp2 = str2[o];
        int temp1int, temp2int;
        temp1int = stoi(temp1);
        temp2int = stoi(temp2);
        if (temp1int < temp2int)
        {
            string temp_carry;
            temp_carry = str1[o+1];
            temp1 = '1' + temp1;
            temp_carry = to_string(stoi(temp_carry) - 1);
            str1[o+1] = temp_carry[0];
        }
        
        result_temp = to_string(stoi(temp1) - stoi(temp2));
        result += result_temp;
    }
    reverse(result.begin(), result.end());
    return result;
}

//Big Numbers Arithmetic Functions -- End
string dtob(string d){
    int count;
    string result;
    int a[1000];
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        //cout<<string_divisor(d,2)<<"\t"<<stoi(string_remainder(d,2))<<"\t"<<(i+1)<<endl;
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

string btod(string d){
    string temp, result = "", power;
    int length;
    length = d.size();
    for (int s = 0; s < length; s++)
    {
        temp = d[s];
        power = to_string(length - (s+1));
        result = string_plus(result, (string_multiplication(temp, string_power("2",power))));
    }
    return result;
}
    
string otod(string d){
    string temp, result = "", power;
    int length;
    length = d.size();
    for (int s = 0; s < length; s++)
    {
        temp = d[s];
        power = to_string(length - (s+1));
        result = string_plus(result, (string_multiplication(temp, string_power("8",power))));
    }
    return result;
}

string htod(string d){
    string temp, result = "", power;
    int length;
    length = d.size();
    for (int s = 0; s < length; s++)
    {
        if (d[s] == 'A' || d[s] == 'a' || d[s] == 'B' || d[s] == 'b' || d[s] == 'C' || d[s] == 'c' || d[s] == 'D' || d[s] == 'd' || d[s] == 'E' || d[s] == 'e' || d[s] == 'F' || d[s] == 'f')
        {
            if (d[s] == 'A' || d[s] == 'a')
            {
                temp = "10";
            }
            else if (d[s] == 'B' || d[s] == 'b')
            {
                temp = "11";
            }
            else if (d[s] == 'C' || d[s] == 'c')
            {
                temp = "12";
            }
            else if (d[s] == 'D' || d[s] == 'd')
            {
                temp = "13";
            }
            else if (d[s] == 'E' || d[s] == 'e')
            {
                temp = "14";
            }
            else if (d[s] == 'F' || d[s] == 'f')
            {
                temp = "15";
            }
        }
        else
        {
            temp = d[s];
        }
        power = to_string(length - (s+1));
        result = string_plus(result, (string_multiplication(temp, string_power("16",power))));
    }
    return result;
}

string btoo(string d){
    return dtoo(btod(d));
}

string btoh(string d){
    return dtoh(btod(d));
}

string otob(string d){
    return dtob(otod(d));
}

string otoh(string d){
    return dtoh(otod(d));
}

string htob(string d){
    return dtob(htod(d));
}

string htoo(string d){
    return dtoo(htod(d));
}
//Function Definations -- End