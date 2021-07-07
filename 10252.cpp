#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string first, second;
    while(getline(cin, first))
    {
        getline(cin, second);
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        int j = 0, k = 0, n = 0;
        char answer[1010] = {};
        for(int i = 0; i < first.size(); ++i)
        {
            for(int j = n; j < second.size(); ++j)
            {
                if(first[i] == second[j])
                {
                    answer[k] = first[i];
                    ++k;
                    n = j + 1;
                    break;
                }
            }
        }
        sort(answer, answer + k);
        for(int a = 0; a < k; ++a)
        {
            cout << answer[a];
        }
        cout << endl;
    }
    return 0;
}
