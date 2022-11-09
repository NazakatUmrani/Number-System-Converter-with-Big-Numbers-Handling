#include <iostream>
#include <string>
using namespace std;
    
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