#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main () {
    string divident,result = "";
    int base,temp,count=0;
    cout<<"Enter divident: ";
    cin>>divident;
    cout<<"Enter divisor: ";
    cin>>base;
    int b_size = to_string(base).length();
    int array[divident.size()/b_size];
    for (int i = 0; i < divident.size(); i++)
    {   
        array[i]=0;
        temp = 0;
        for (int j = 0; j < b_size; j++)
        {
            array[i] = divident[count];
            count++;
            temp = (temp*10) + (array[i]-48);
        }
        array[i] = temp;
    }
    count = 0;
    temp = 0;
    for (int k = 0; k <= ceil(divident.length()/float(base)); k++)
    {
        result += to_string(array[k]/base);
        if (count == 0)
        {
            if (array[k]/base != 0)
            {
                count = 1;
            }
            if (count == 0)
            {
                result = "";
            }            
        }
        if (array[k]%base != 0)
        {
            temp = array[k]%base;
            array[k+1] = (temp * pow(10,b_size))+array[k+1];
        }
    }
    cout<<"Final result = "<<result<<endl;
    
    return 0;
}