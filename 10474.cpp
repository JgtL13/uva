#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    bool notFound = false;
    int cases = 0;
    int N, Q, counter;
    int store[10000] = {}, querie[10000] = {};
    while(true)
    {
        counter = 0;
        ++cases;
        cin >> N >> Q;
        if(N == 0 && Q == 0)
        {
            break;
        }
        else
        {
            for(int i = 0; i < N; ++i)
            {
                cin >> store[i];
            }
            for(int i = 0; i < Q; ++i)
            {
                cin >> querie[i];
            }
            sort(store, store + N);
            cout << "CASE# " << cases << ":" << endl;
            for(int i = 0; i < Q; ++i)
            {
                notFound = true;
                counter = 0;
                for(int j = 0; j < N; ++j)
                {
                    ++counter;
                    if(querie[i] == store[j])
                    {
                        cout << querie[i] << " found at " << counter << endl;
                        notFound = false;
                        break;
                    }
                }
                if(counter == N && notFound)
                {
                    cout << querie[i] << " not found" << endl;
                }
            }
        }
    }
    return 0;
}
