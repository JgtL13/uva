#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

bool isvowel(char c[1000])
{
    if(c[0] == 'A' || c[0] == 'E' || c[0] == 'I' || c[0] == 'O' || c[0] == 'U' || c[0] == 'a' || c[0] == 'e' || c[0] == 'i' || c[0] == 'o' || c[0] == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char store[1000] = {};
    char c;
    int i = 0;
    while(cin.get(c))
    {
        if(isalpha(c))
        {
            store[i] = c;
            ++i;
        }
        else
        {
            if(i > 0)
            {
                if(isvowel(store))
                {
                    for(int j = 0; j < i; ++j)
                    {
                        cout << store[j];
                    }
                    cout << "ay";
                    i = 0;
                }
                else
                {
                    for(int k = 1; k < i; ++k)
                    {
                        cout << store[k];
                    }
                    cout << store[0] << "ay";
                    i = 0;
                }
            }
            cout << c;
        }
    }
    return 0;
}
