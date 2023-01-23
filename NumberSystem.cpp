#include "NumberSystem.hpp"
void Number_System :: dtob (){
    int count;
    string a;
    a = "";
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        a += string_remainder(numbercopy,"2");
        numbercopy = string_divisor(numbercopy,"2");
        if (numbercopy.length()<2)
        {
            if(string_max(numbercopy, "2") == "2" && numbercopy != "2"){
                a += numbercopy;
                count++;
                break;
            }
        }
    }
    reverse(a.begin(), a.end());
    result = string_trimmer(a);
    numbercopy = result;
}

void  Number_System :: dtoh (){
    int count;
    string temp;
    string a = "";
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        temp = string_remainder(numbercopy,"16");
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
        numbercopy = string_divisor(numbercopy,"16");
        if (numbercopy.length()<3)
        {
            if(stoi(numbercopy) < 16){
                count++;
                temp = numbercopy;
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
                    a += numbercopy;
                }
                break;
            }
        }
    }
    reverse(a.begin(),a.end());
    result = string_trimmer(a);
    numbercopy = result;
}

void  Number_System :: dtoo (){
    int count;
    string a;
    a = "";
    count=0;
    for (int i = 0; i >= 0; i++)
    {
        count++;
        a += string_remainder(numbercopy,"8");
        numbercopy = string_divisor(numbercopy,"8");
        if (numbercopy.length()<2)
        {
            if(string_max(numbercopy,"8") == "8" && numbercopy != "8"){
                a += numbercopy;
                count++;
                break;
            }
        }
    }
    reverse(a.begin(),a.end());
    result = string_trimmer(a);
    numbercopy = result;
}

void  Number_System :: btod (){
    string temp, power;
    int length;
    result = "0";
    numbercopy = string_trimmer(numbercopy);
    length = numbercopy.size();
    for (int s = 0; s < length; s++)
    {
        temp = numbercopy[s];
        power = to_string(length - (s+1));
        result = string_plus(result, (string_multiplication(temp, string_power("2",power))));
    }
    numbercopy = result;
}

void  Number_System :: otod (){
    string temp, power;
    int length;
    result = "0";
    numbercopy = string_trimmer(numbercopy);
    length = numbercopy.size();
    for (int s = 0; s < length; s++)
    {
        temp = numbercopy[s];
        power = to_string(length - (s+1));
        result = string_plus(result, (string_multiplication(temp, string_power("8",power))));
    }
    numbercopy = result;
}

void  Number_System :: htod (){
    string temp, power;
    int length;
    result = "0";
    numbercopy = string_trimmer(numbercopy);
    length = numbercopy.size();
    for (int s = 0; s < length; s++)
    {
        if (numbercopy[s] == 'A' || numbercopy[s] == 'a' || numbercopy[s] == 'B' || numbercopy[s] == 'b' || numbercopy[s] == 'C' || numbercopy[s] == 'c' || numbercopy[s] == 'D' || numbercopy[s] == 'd' || numbercopy[s] == 'E' || numbercopy[s] == 'e' || numbercopy[s] == 'F' || numbercopy[s] == 'f')
        {
            if (numbercopy[s] == 'A' || numbercopy[s] == 'a')
            {
                temp = "10";
            }
            else if (numbercopy[s] == 'B' || numbercopy[s] == 'b')
            {
                temp = "11";
            }
            else if (numbercopy[s] == 'C' || numbercopy[s] == 'c')
            {
                temp = "12";
            }
            else if (numbercopy[s] == 'D' || numbercopy[s] == 'd')
            {
                temp = "13";
            }
            else if (numbercopy[s] == 'E' || numbercopy[s] == 'e')
            {
                temp = "14";
            }
            else if (numbercopy[s] == 'F' || numbercopy[s] == 'f')
            {
                temp = "15";
            }
        }
        else
        {
            temp = numbercopy[s];
        }
        power = to_string(length - (s+1));
        result = string_plus(result, (string_multiplication(temp, string_power("16",power))));
    }
    numbercopy = result;
}

void  Number_System :: btoo (){
    btod();
    dtoo();
}

void  Number_System :: btoh (){
    btod();
    dtoh();
}

void  Number_System :: otob (){
    otod();
    dtob();
}

void  Number_System :: otoh (){
    otod();
    dtoh();
}

void  Number_System :: htob (){
    htod();
    dtob();
}

void  Number_System :: htoo (){
    htod();
    dtoo();
}

bool Number_System :: is_decimal(){
    bool tf = true;
    string numbercopy = number;
    for (int i = 0; i < numbercopy.size(); i++)
    {
        if (numbercopy[i] == '0' || numbercopy[i] == '1' || numbercopy[i] == '2' || numbercopy[i] == '3' || numbercopy[i] == '4' || numbercopy[i] == '5' || numbercopy[i] == '6' || numbercopy[i] == '7' || numbercopy[i] == '8' || numbercopy[i] == '9')
        {
            continue;
        }
        tf = false;
        break;
    }
    return tf;
}

bool Number_System :: is_binary(){
    bool tf = true;
    string numbercopy = number;
    for (int i = 0; i < numbercopy.size(); i++)
    {
    if (numbercopy[i] == '0' || numbercopy[i] == '1')
        {
            continue;
        }
        tf = false;
        break;
    }
    return tf;
}

bool Number_System :: is_octal(){
    bool tf = true;
    string numbercopy = number;
    for (int i = 0; i < numbercopy.size(); i++)
    {
    if (numbercopy[i] == '0' || numbercopy[i] == '1' || numbercopy[i] == '2' || numbercopy[i] == '3' || numbercopy[i] == '4' || numbercopy[i] == '5' || numbercopy[i] == '6' || numbercopy[i] == '7')
        {
            continue;
        }
        tf = false;
        break;
    }
    return tf;
}

bool Number_System :: is_hexadecimal(){
    bool tf = true;
    string numbercopy = number;
    for (int i = 0; i < numbercopy.size(); i++)
    {
    if (numbercopy[i] == '0' || numbercopy[i] == '1' || numbercopy[i] == '2' || numbercopy[i] == '3' || numbercopy[i] == '4' || numbercopy[i] == '5' || numbercopy[i] == '6' || numbercopy[i] == '7' || numbercopy[i] == '8' || numbercopy[i] == '9' || numbercopy[i] == 'A' || numbercopy[i] == 'a' || numbercopy[i] == 'B' || numbercopy[i] == 'b' || numbercopy[i] == 'C' || numbercopy[i] == 'c' || numbercopy[i] == 'D' || numbercopy[i] == 'd' || numbercopy[i] == 'E' || numbercopy[i] == 'e' ||  numbercopy[i] == 'F' || numbercopy[i] == 'f')
        {
            continue;
        }
        tf = false;
        break;
    }
    return tf;
}