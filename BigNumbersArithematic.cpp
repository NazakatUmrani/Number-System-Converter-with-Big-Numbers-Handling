#include "BigNumbersArithematic.hpp"
string BigNumbersArithematic :: string_plus(string str1, string str2){
    int length, zeroscount, str1len, str2len;
    string result, carry;
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

string BigNumbersArithematic :: string_multiplication(string number, string multiplier){
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
        string ans;
        ans = "0";
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

string BigNumbersArithematic :: string_power(string number, string power){
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

string BigNumbersArithematic :: string_minus(string str1, string str2){
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

string BigNumbersArithematic :: string_max(string str1, string str2){
    string max;
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

string BigNumbersArithematic :: string_divisor(string divident, string divisor){
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

string BigNumbersArithematic ::  string_remainder(string divident, string divisor){
    string quotient = string_divisor(divident,divisor);
    string product = string_multiplication(quotient,divisor);
    string remainder = string_minus(divident, product);
    return remainder;
}

string BigNumbersArithematic :: string_trimmer(string str){
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