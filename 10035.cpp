#include <iostream>
#include <fstream>
using namespace std;

int digits(long long number)
{
    int digit = 1;
    while(number / 10 != 0)
    {
        number /= 10;
        digit++;
    }
    return digit;
}

int main()
{
    long long a, b;
    int largest;
    while(true)
    {
        cin >> a >> b;
        if(a == 0 && b == 0)
        {
            break;
        }
        else
        {
            int digitA = digits(a);
            int digitB = digits(b);
            if(digitA >= digitB)
            {
                largest = digitA;
            }
            else if(digitB > digitA)
            {
                largest = digitB;
            }
            int counter = 0;
            int more = 0;
            for(int i = 0; i < largest; ++i)
            {
                more = a % 10 + b % 10 + more;
                more /= 10;
                a /= 10;
                b /= 10;
                if(more > 0)
                {
                    counter++;
                }
            }
            if(counter == 0)
            {
                cout << "No carry operation." << endl;
            }
            else if(counter > 0)
            {
                if(counter == 1)
                {
                    cout << counter << " carry operation." << endl;
                }
                else if(counter > 1)
                {
                    cout << counter << " carry operations." << endl;
                }
            }
        }
    }
    return 0;
}
