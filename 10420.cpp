#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    string c[2000] = {};
    int counter[2000] = {};
    string input, country, discard;
    int tests;
    cin >> tests;
    getchar();
    int i = 0;
    while(tests--)
    {
        bool exist = false;
        cin >> country;
        getline(cin, discard);
        for(int j = 0; j < i; ++j)
        {
            if(country == c[j])
            {
                counter[j]++;
                exist = true;
            }
        }
        if(!exist)
        {
            c[i] = country;
            counter[i] = 1;
            ++i;
        }
    }
    for(int a = 0; a < i; ++a)
    {
        for(int b = 0; b < i - 1; ++b)
        {
            if(c[b] > c[b + 1])
            {
                swap(c[b], c[b + 1]);
                swap(counter[b], counter[b + 1]);
            }
        }
    }
    for(int k = 0; k < i; ++k)
    {
        cout << c[k] << " " << counter[k] << endl;
    }
    return 0;
}
