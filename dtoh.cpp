#include <iostream>
#include <string>
using namespace std;




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
                a[i+1]=stoi(d);
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