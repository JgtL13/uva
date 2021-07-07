#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

class ITSA
{
private:
    int contestant;
    int answerContestant;
    int problemNumber;
    int time;
    int correct;
    int totalTime;
    char result;
public:
    ITSA (int, int, int, char);
    int get_contestant();
    int get_problemNumber();
    int get_time();
    char get_result();
};

ITSA::ITSA(int c, int p, int t, char r)
{
    contestant = c;
    problemNumber = p;
    time = t;
    result = r;
}

int ITSA::get_contestant()
{
    return contestant;
}

int ITSA::get_problemNumber()
{
    return problemNumber;
}

int ITSA::get_time()
{
    return time;
}

char ITSA::get_result()
{
    return result;
}
class answer
{
private:
    int answerContestant;
    int answerCorrect;
    int answerTime;
public:
    answer(int, int, int);
    int get_answerContestant();
    int get_answerCorrect();
    int get_answerTime();
};

answer::answer(int acon, int acor, int atime)
{
    answerContestant = acon;
    answerCorrect = acor;
    answerTime = atime;
}

int answer::get_answerContestant()
{
    return answerContestant;
}

int answer::get_answerCorrect()
{
    return answerCorrect;
}

int answer::get_answerTime()
{
    return answerTime;
}

int main()
{
    stringstream ss;
    vector<ITSA> store;
    vector<answer> answerStore;
    int cases;
    int c, p, t;
    char r, ch;
    string input;
    cin >> cases;
    getchar();
    getchar();
    while(cases--)
    {
        answerStore.clear();
        store.clear();
        while(true)
        {
            getline(cin, input);
            if(input[0] == '\0')
            {
                break;
            }
            ss << input;
            ss >> c >> p >> t >> r;
            ITSA itsa(c, p, t, r);
            store.push_back(itsa);
        }
        for(int i = 0; i < store.size(); ++i)
        {
            for (int j = 0; j < store.size() - 1; ++j)
            {
                if(store[j].get_contestant() > store[j + 1].get_contestant())
                {
                    swap(store[j], store[j + 1]);
                }
                else if(store[j].get_contestant() == store[j + 1].get_contestant())
                {
                    if(store[j].get_problemNumber() > store[j + 1].get_problemNumber())
                    {
                        swap(store[j], store[j + 1]);
                    }
                    else if(store[j].get_problemNumber() == store[j + 1].get_problemNumber())
                    {
                        if(store[j].get_time() > store[j + 1].get_time())
                        {
                            swap(store[j], store[j + 1]);
                        }
                                else if(store[j].get_time() == store[j + 1].get_time())
                        {
                            if(store[j].get_result() - '0' < store[j + 1].get_result() - '0')
                            {
                                swap(store[j], store[j + 1]);
                            }
                        }
                    }
                }
            }
        }
        int time = 0;
        int correct = 0;
        int I = 0;
        bool repeat = false;
        for (unsigned int k = 0; k < store.size(); ++k)
        {
            if(store[k].get_contestant() == store[k + 1].get_contestant())
            {
                if(store[k].get_result() == 'C' && repeat == false)
                {
                    time += I * 20 + store[k].get_time();
                    correct++;
                }
                if(store[k].get_result() == 'I')
                {
                    I++;
                }
                if(store[k].get_problemNumber() == store[k + 1].get_problemNumber())
                {
                    if(store[k].get_result() == 'C')
                    {
                        repeat = true;
                    }
                }
                else if (store[k].get_problemNumber() != store[k + 1].get_problemNumber())
                {
                    I = 0;
                    repeat = false;
                }
            }
            else if(store[k].get_contestant() != store[k + 1].get_contestant())
            {
                if(store[k].get_result() == 'C' && repeat == false)
                {
                    time += I * 20 + store[k].get_time();
                    correct++;
                }
                answer ans(store[k].get_contestant(), correct, time);
                answerStore.push_back(ans);
                correct = 0;
                time = 0;
                I = 0;
                repeat = false;
            }
        }
        for(int i = 0; i < answerStore.size(); ++i)
        {
            for (int j = 0; j < answerStore.size() - 1; ++j)
            {
                if(answerStore[j].get_answerCorrect() < answerStore[j + 1].get_answerCorrect())
                {
                    swap(answerStore[j], answerStore[j + 1]);
                }
                else if(answerStore[j].get_answerCorrect() == answerStore[j + 1].get_answerCorrect())
                {
                    if(answerStore[j].get_answerTime() > answerStore[j + 1].get_answerTime())
                    {
                        swap(answerStore[j], answerStore[j + 1]);
                    }
                    else if(answerStore[j].get_answerTime() == answerStore[j + 1].get_answerTime())
                    {
                        if(answerStore[j].get_answerContestant() > answerStore[j + 1].get_answerContestant())
                        {
                            swap(answerStore[j], answerStore[j + 1]);
                        }
                    }
                }
            }
        }
        for (unsigned int z = 0; z < answerStore.size(); ++z)
        {
            cout << answerStore[z].get_answerContestant() << " " << answerStore[z].get_answerCorrect() << " " << answerStore[z].get_answerTime() << endl;
        }
        if(cases != 0)
        {
            cout << endl;
        }
    }
    return 0;
}
