#include <iostream>
using namespace std;

int main()
{
    int number, i;
    int counter = 0;
    while(true)
    {
        ++counter;
        int sum;
        int noCounter = 0;
        cin >> number;
        if (number == 0)
        {
            break;
        }
        else if (number == 1)
        {
            cout << "Case " << counter << ": 1" << endl;
            continue;
        }
        else
        {
            for (i = number - 1; i > 0; --i)
            {
                sum = 0;
                for (int j = i; j > 0; --j)
                {
                    if (i % j == 0)
                    {
                        sum += j;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (sum == number)
                {
                    cout << "Case " << counter << ": " << i << endl;
                    break;
                }
                else
                {
                    noCounter++;
                }
            }
            if (noCounter == number - 1)
            {
                cout << "Case " << counter << ": -1" << endl;
            }
        }
    }
    return 0;
}
