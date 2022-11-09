//int size = 8 for this program


#include <iostream>
#include <string>
#include <cmath>
using namespace std;
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