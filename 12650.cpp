#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N, R;
    while(cin >> N)
    {
        int store[10010] = {};
        cin >> R;
        for(int i = 0; i < R; ++i)
        {
            cin >> store[i];
        }
        sort(store, store + R);
        int j = 0, counter = 0;
        for(int k = 1; k <= N; ++k)
        {
            if(k == store[j])
            {
                ++j;
            }
            else if(k != store[j])
            {
                ++counter;
                cout << k << " ";
            }
        }
        if(counter == 0)
        {
            cout << "*";
        }
        if(j == R)
        {
            cout << endl;
        }
    }
    return 0;
}
