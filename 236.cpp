#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool verify (int answerStore[99999], int answer, int s)
{
    for (int z = 0; z < s; ++z)
    {
        if (answerStore[z] == answer)
        {
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    string sAnswer;
    long long temp;
    int answerStore[99999] = {};
    int store[99999] = {};
    char input, tempChar;
    int tempInt;
    while(true)
    {
        int i = 0, answer, a = 0, s = 0, chainLength = 0;
        bool unValid = false;
        while(cin.get(input))
        {
            if (input == '\n')
            {
                break;
            }
            else
            {
                store[i] = input - '0';
                ++i;
            }
        }
        if (store[0] == 0 && i == 1)
        {
            return 0;
        }
        cout << "Original number was ";
        for (int r = 0; r < i; ++r)
        {
            cout << store[r];
        }
        cout << endl;
        while(true)
        {
            int first = 0, second = 0;
            sort(store, store + i);
            for (int j = i - 1; j >= 0; --j)
            {
                temp = store[j];
                for (int k = j; k > 0; --k)
                {
                    temp *= 10;
                }
                first += temp;
            }
            for (int m = 0; m < i; ++m)
            {
                temp = store[m];
                for (int n = m + 1; n < i; ++n)
                {
                    temp *= 10;
                }
                second += temp;
            }
            answer = first - second;
            chainLength++;
            cout << first << " - " << second << " = " << answer << endl;
            unValid = verify(answerStore, answer, s);
            if(unValid)
            {
                break;
            }
            answerStore[s] = answer;
            s++;
            store[99999] = {};
            i = 0;
            while(true)
            {
                store[i] = (answer % 10);
                ++i;
                if(answer - 10 < 0)
                {
                    break;
                }
                else
                {
                    answer /= 10;
                }
            }
        }
        cout << "Chain length " << chainLength << endl << endl;
    }
}
