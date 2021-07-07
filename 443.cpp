#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int number;
    int humble[5842] = {};
    int position2 = 0,
        position3 = 0,
        position5 = 0,
        position7 = 0;
    humble[0] = 1;
    for (int i = 1; i < 5842; ++i)
    {
        humble[i] = min(min(2 * humble[position2], 3 * humble[position3]), min(5 * humble[position5], 7 * humble[position7]));
        if (humble[i] == 2 * humble[position2])
        {
            ++position2;
        }
        if (humble[i] == 3 * humble[position3])
        {
            ++position3;
        }
        if (humble[i] == 5 * humble[position5])
        {
            ++position5;
        }
        if (humble[i] == 7 * humble[position7])
        {
            ++position7;
        }
    }

    while(cin >> number)
    {
        if (number == 0)
        {
            break;
        }
        else if (number != 0)
        {
            if (number % 10 == 1 && number % 100 != 11)
            {
                cout << "The " << number << "st humble number is " << humble[number - 1] << "." << endl;
            }
            else if (number % 10 == 2 && number % 100 != 12)
            {
                cout << "The " << number << "nd humble number is " << humble[number - 1] << "." << endl;
            }
            else if (number % 10 == 3 && number % 100 != 13)
            {
                cout << "The " << number << "rd humble number is " << humble[number - 1] << "." << endl;
            }
            else
            {
                cout << "The " << number << "th humble number is " << humble[number - 1] << "." << endl;
            }
        }
    }
    return 0;
}
