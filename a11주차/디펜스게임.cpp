#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> absol;

int solution(int n, int k, vector<int> enemy) {
    
    int interval = min(k, (int)enemy.size());
    int answer = interval;

    for (auto i = enemy.begin(); i != enemy.begin() + interval; ++i)
    {
        absol.push(*i);
    }

    for (auto i = enemy.begin() + interval; i != enemy.end(); ++i)
    {

        int alpa = 0;
        if (absol.top() < *i)
        {
            alpa = absol.top();
            absol.pop();
            absol.push(*i);
        }

        else
            alpa = *i;
       
        if (n - alpa >= 0)
        {
            n -= alpa;
            ++answer;
        }

        else
            break;
    }

    return answer;
}
