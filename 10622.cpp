#include <iostream>
#include <cmath>
using namespace std;

int gcd(int m, int n)
{
    if(n == 0)
    {
        return m;
    }
    else
    {
        return gcd(n, m % n);
    }
}

int main()
{
    bool negative = false;
    long long number, counter, answer;
    int power[10000] = {};
    while(true)
    {
        cin >> number;
        if(number == 0)
        {
            break;
        }
        else if(number < 0)
        {
            number = -number;
            negative = true;
        }
        else if(number > 0)
        {
            negative = false;
        }
        int j = 0;
        for(unsigned int i = 2; i <= 65536; ++i)
        {
            counter = 0;
            while(number % i == 0)
            {
                number /= i;
                ++counter;
            }
            if(counter != 0)
            {
                power[j] = counter;
                ++j;
            }
            if(number == 1)
            {
                break;
            }
        }
        if(number == 1)
        {
            answer = power[0];
            for(int k = 1; k < j; ++k)
            {
                answer = gcd(answer, power[k]);
            }
            if(negative)
            {
                while(answer % 2 == 0)
                {
                    answer /= 2;
                }
            }
            cout << answer << endl;
        }
        else if(number != 1)
        {
            cout << "1" << endl;
        }
    }
    return 0;
}
