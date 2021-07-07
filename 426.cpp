#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
using namespace std;

class History
{
private:
    string date;
    int check_number;
    double dollar;
    bool star;
public:
    History(string,int,double);
    void print_history();
    void set_star(bool Star);
    int get_check_number();
};

History::History(string Date, int Check_Number, double Dollar)
{
    date = Date;
    check_number = Check_Number;
    dollar = Dollar;
}

void History::print_history(){
    if(star)
        cout<<setw(4)<<check_number<<"* "<<setw(9)<<fixed<<setprecision(2)<<dollar<<" "<<date;
    else
        cout<<setw(4)<<check_number<<"  "<<setw(9)<<fixed<<setprecision(2)<<dollar<<" "<<date;
}

void History::set_star(bool Star)
{
    star = Star;
}

int History::get_check_number()
{
    return check_number;
}

int main()
{
    int lines;
    char test;
    bool Star;
    int N, temp, Check_Number;
    double Dollar;
    string Date, input;
    vector<History> store;
    vector<int> cn;
    cin >> N;
    getchar();
    getchar();
    while (N--)
    {
        cn.clear();
        store.clear();
        Star = false;
        lines = 0;
        while(getline(cin, input))
        {
            if(input == "")
            {
                break;
            }
            else
            {
                stringstream ss;
                ss.str(input);
                ss >> Date >> Check_Number >> Dollar;
                History htr(Date, Check_Number, Dollar);
                store.push_back(htr);
                temp = htr.get_check_number();
                cn.push_back(temp);
            }
        }

        for (int i1 = 0; i1 < store.size() - 1; ++i1)
        {
            for (int i2 = 0; i2 < store.size() - 1 - i1; ++i2)
            {
                if (store[i2].get_check_number() > store[i2 + 1].get_check_number())
                {
                    swap(store[i2], store[i2 + 1]);
                }
            }
        }
        for (int i = 0; i < store.size(); ++i)
        {
            if (i == 0)
            {
                Star = false;
            }
            else if (store[i].get_check_number() != store[i - 1].get_check_number() + 1)
            {
                Star = true;
            }
            else if (store[i].get_check_number() == store[i - 1].get_check_number() + 1)
            {
                Star = false;
            }
            store[i].set_star(Star);
        }

        if(store.size() == 1)
        {
            store[0].print_history();
            cout << endl;
        }

        else if (store.size() == 2)
        {
            store[0].print_history();
            cout << "   ";
            store[1].print_history();
            cout << endl;
        }
        else if (store.size() == 3)
        {
            store[0].print_history();
            cout << "   ";
            store[1].print_history();
            cout << "   ";
            store[2].print_history();
            cout << endl;
        }
        else if (store.size() == 4)
        {
            store[0].print_history();
            cout << "   ";
            store[2].print_history();
            cout << endl;
            store[1].print_history();
            cout << "   ";
            store[3].print_history();
            cout << endl;
        }
        else
        {
            lines = store.size() / 3;
            if (store.size() % 3 != 0)
            {
                lines++;
            }
            for (int k = 0; k < lines; ++k)
            {
                for (int m = k; m < store.size(); m += lines)
                {
                    if(m != k)
                    {
                        cout << "   ";
                    }
                    store[m].print_history();
                }
                cout << endl;
            }
        }

        if(N != 0)
        {
            cout << endl;
        }
    }
    return 0;
}
