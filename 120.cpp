#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool isDone(int array[100], int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        if(array[i] <= array[i + 1])
        {
            continue;
        }
        else
        {
            return false;
            break;
        }
    }
    return true;
}

int findLargest(int array[100], int size)
{
    int largest = array[0];
    for(int i = 0; i < size - 1; ++i)
    {
        if(array[i + 1] > largest)
        {
            largest = array[i + 1];
        }
        else
        {
            continue;
        }
    }
    return largest;

}

int findLargestPosition(int array[100], int size, int number)
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i] == number)
        {
            return i;
            break;
        }
        else
        {
            continue;
        }
    }

}

int main()
{
    char input;
    int temp;
    int tens = 0;
    int s = 0;
    int store[100] = {};
    while(cin.get(input))
    {
        if(input == '\n')
        {
            store[s] = temp;
            ++s;
            tens = 0;
            int n = s;
            int counter = 1;
            for(int i = 0; i < s; ++i)
            {
                cout << store[i] << " ";
            }
            cout << endl;
            while(!isDone(store, n))
            {
                int largest = findLargest(store, n);
                int pos = findLargestPosition(store, n, largest);
                //cout << pos << " " << s << " " << counter << "!" << endl;
                if(pos == s - counter)
                {
                    //cout << "." << endl;
                    --n;
                    ++counter;
                }
                else if(pos == 0)
                {
                    cout << counter << " ";
                    for(int i = 0; i < n / 2; ++i)
                    {
                        swap(store[i], store[n - 1 - i]);
                    }
                    --n;
                    ++counter;
                }
                else
                {
                    cout << s - pos << " ";
                    for(int i = 0; i <= pos / 2; ++i)
                    {
                        swap(store[i], store[pos - i]);
                    }
                }
            }
            cout << 0 << endl;
            s = 0;
        }
        else if(input == ' ')
        {
            store[s] = temp;
            ++s;
            tens = 0;
            continue;
        }
        else
        {
            if(tens != 0)
            {
                temp = temp * 10 + (input - 48);
            }
            else
            {
                ++tens;
                temp = input - 48;
            }
        }
    }
    return 0;
}
