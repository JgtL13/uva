#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool verify (int pearlDiameter[1000], int pearlNumber)
{
    int store[1000] = {};
    int i = 0;
    if (pearlNumber % 2 == 0)
    {
        return false;
    }
    else if (pearlNumber == 1)
    {
        return true;
    }
    else if (pearlNumber % 2 != 0)
    {
        sort(pearlDiameter, pearlDiameter+pearlNumber);
        for (int x = 0; x < pearlNumber; x += 2, ++i)
        {
            store[i] = pearlDiameter[x];
        }
        for (int y = pearlNumber - 2; y > 0; y -= 2, ++i)
        {
            store[i] = pearlDiameter[y];
        }
        for (int z = 0; z < pearlNumber; ++z)
        {
            pearlDiameter[z] = store[z];
        }
        for (int a = 0, b = pearlNumber - 1; b > a; ++a, --b)
        {
            if (pearlDiameter[a] == pearlDiameter[b])
            {
                continue;
            }
            else if (pearlDiameter[a] != pearlDiameter[b])
            {
                return false;
                break;
            }
        }
    }
}

int main()
{
    int check, input, pearlNumber;
    bool valid = true;
    while(cin >> check)
    {
        int pearlDiameter[1000] = {};
        if (check == 0)
        {
            break;
        }
        else if (check != 0)
        {
            int i = 1;
            pearlDiameter[0] = check;
            while(cin >> input)
            {
                if (input != 0)
                {
                    pearlDiameter[i] = input;
                    ++i;
                }
                else if (input == 0)
                {
                    pearlNumber = i;
                    valid = verify(pearlDiameter, pearlNumber);
                    if(valid)
                    {
                        for (int z = 0; z < pearlNumber; ++z)
                        {
                            if (z == pearlNumber - 1)
                            {
                                cout << pearlDiameter[z] << endl;
                            }
                            else
                            {
                                cout << pearlDiameter[z] << " ";
                            }
                        }
                    }
                    else if(!valid)
                    {
                        cout << "NO" << endl;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
