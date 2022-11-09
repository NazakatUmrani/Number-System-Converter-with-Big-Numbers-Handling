#include <iostream>
#include <string>
using namespace std;
    

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