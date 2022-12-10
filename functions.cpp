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

string string_divisor(string, string);
string string_remainder(string, string);
string string_plus(string, string);
string string_minus(string, string);
string string_multiplication(string, string);
string string_power(string, string);
string string_max(string, string);
string string_trimmer(string);
//Function Declarations -- Start

//Function Definations -- Start

//Big Numbers Arithmetic Functions -- Start
string string_plus(string str1, string str2){
    int length, zeroscount, str1len, str2len;
    string result, carry, str1reverse, str2reverse;
    if (str1 == "0" || str2 == "0")
    {
        if (str1 == "0")
        {
            result = str2;
        }
        else if (str2 == "0")
        {
            result = str1;
        }
    }
    else{
        str1len = str1.length();
        str2len = str2.length();
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
    }
    return result;
}

string string_multiplication(string number, string multiplier){
    string result;
    if (number == "0" || multiplier == "0")
    {
        result = "0";
    }
    else if (number == "1" || multiplier == "1")
    {
        if (number == "1")
        {
            result = multiplier;
        }
        else if (multiplier == "1")
        {
            result = number;
        }
    }
    else{
        string ans = "0";
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
        result = ans;
    }
    return result;
}

string string_power(string number, string power){
    string i = "1", result = number;
    if (power == "0")
    {
        result = "1";
    }    
    else{
        while (i != power && string_max(power,"0") == power)
        {
            result = string_multiplication(result,number);
            i = string_plus(i, "1");
        }
    }
    return string_trimmer(result);
}

string string_minus(string str1, string str2){
    string count = "0";
    str1 = string_trimmer(str1);
    str2 = string_trimmer(str2);
    if (str1 == str2)
    {
        return "0";
    }
    else if (str1 == "0" || str2 == "0")
    {
        if (str1 == "0")
        {
            count = str2;
        }
        else if (str2 == "0")
        {
            count = str1;
        }
    }
    else if (string_max(str1,str2) == str1){
        for(int s=1; s>0; s++){
            count = string_plus(count, "1");
            str2 = string_plus(str2, "1");
            if (str2 == str1)
            {
                break;
            }
        }
    }
    return count;
}

string string_max(string str1, string str2){
    string test, max;
    str1 = string_trimmer(str1);
    str2 = string_trimmer(str2);
    if (str1.size() > str2.size()){
        max = str1;
    }
    else if (str2.size() > str1.size()){
        max = str2;
    }
    else if (str2 == str1){
        max = str1;
    }
    else if (str1.size() == str2.size()){
        string tempstr1, tempstr2;
        for (int i = 0; i < str1.size(); i++){
            tempstr1 = str1[i];
            tempstr2 = str2[i];
            if (stoi(tempstr1) > stoi(tempstr2)){
                max = str1;
                break;
            }
            else if (stoi(tempstr1) < stoi(tempstr2)){
                max = str2;
                break;
            }
        }
    }
    return max;
}

string string_divisor(string divident, string divisor){
    string divident_slice, temp_quotient, remainder, quotient;
    if (divident == "0")
    {
        return "0";
    }
    else if (divisor == "0")
    {
        return "Error";
    }
    else if (divident == divisor)
    {
        return "1";
    }
    else if (string_max(divident,divisor) == divisor)
    {
        return "0";
    }
    else{
        for(int j = 0; j < divident.size(); j++){
            divident_slice = remainder + divident_slice + divident[j];
            remainder = "";
            divident_slice = string_trimmer(divident_slice);
            if (string_max(divident_slice, divisor) == divident_slice){
                temp_quotient = "0";
                for(int k = 1; k > 0; k++){
                    if(string_max(string_multiplication(divisor,to_string(k)), divident_slice) == string_multiplication(divisor,to_string(k)) && string_multiplication(divisor,to_string(k)) != divident_slice){
                        quotient += temp_quotient;
                        remainder = string_minus(divident_slice, string_multiplication(divisor,to_string(k-1)));
                        divident_slice = "";
                        break;
                    }
                    temp_quotient = to_string(k);
                }
            }
            else{
                quotient += "0";
            }
        }
    }
    return string_trimmer(quotient);
}

string string_remainder(string divident, string divisor){
    string quotient = string_divisor(divident,divisor);
    string product = string_multiplication(quotient,divisor);
    string remainder = string_minus(divident, product);
    return remainder;
}

string string_trimmer(string str){
    string result_str = "", is_zero;
    if (str[0] != '0')
    {
        return str;
    }
    else{
        for (int i = 0; i < str.size(); i++){
            is_zero = str[i];
            if (is_zero == "0")
            {
                continue;
            }
            else{
                result_str = str.substr(i,str.size());
                break;
            }
        }
        if (result_str == "")
        {
            result_str = "0";
        }
    }
    return result_str;
}

//Big Numbers Arithmetic Functions -- End

string dtob(string d){
    int count;
    string result;
    string a = "";
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        a += string_remainder(d,"2");
        d = string_divisor(d,"2");
        if (d.length()<2)
        {
            if(string_max(d, "2") == "2" && d != "2"){
                a += d;
                count++;
                break;
            }
        }
    }
    reverse(a.begin(), a.end());
    result = a;
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
    string result, temp;
    string a = "";
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        temp = string_remainder(d,"16");
        if (temp == "10")
        {
            a += "A";
        }
        else if (temp == "11")
        {
            a += "B";
        }
        else if (temp == "12")
        {
            a += "C";
        }
        else if (temp == "13")
        {
            a += "D";
        }
        else if (temp == "14")
        {
            a += "E";
        }
        else if (temp == "15")
        {
            a += "F";
        }
        else
        {
            a += temp;
        }
        d = string_divisor(d,"16");
        if (d.length()<3)
        {
            if(stoi(d) < 16){
                count++;
                temp = d;
                if (temp == "10")
                {
                    a += "A";
                }
                else if (temp == "11")
                {
                    a += "B";
                }
                else if (temp == "12")
                {
                    a += "C";
                }
                else if (temp == "13")
                {
                    a += "D";
                }
                else if (temp == "14")
                {
                    a += "E";
                }
                else if (temp == "15")
                {
                    a += "F";
                }
                else{
                    a += d;
                }
                break;
            }
        }
    }
    reverse(a.begin(),a.end());
    result = a;
    return string_trimmer(result);
}

string dtoo(string d){
    int count;
    string result;
    string a = "";
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        a += string_remainder(d,"8");
        d = string_divisor(d,"8");
        if (d.length()<2)
        {
            if(string_max(d,"8") == "8" && d != "8"){
                a += d;
                count++;
                break;
            }
        }
    }
    reverse(a.begin(),a.end());
    result = a;
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
    string temp, result = "0", power;
    int length;
    d = string_trimmer(d);
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
    string temp, result = "0", power;
    int length;
    d = string_trimmer(d);
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
    string temp, result = "0", power;
    int length;
    d = string_trimmer(d);
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