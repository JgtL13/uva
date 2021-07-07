#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int answer[5] = {56, 96, 36, 76, 16};
    int tests;
    cin >> tests;
    while(tests--)
    {
        char input[2000] = {};
        cin >> input;
        int length = strlen(input);
        if(length == 1 && input[0] == '0')
        {
            cout << "1" << endl;
            continue;
        }
        else if(length == 1 && input[0] == '1')
        {
            cout << "66" << endl;
            continue;
        }
        else
        {
            int lastDigit = input[length - 1] - '0';
            cout << answer[(lastDigit + 3) % 5 ] << endl;
            continue;
        }
    }
    return 0;
}
