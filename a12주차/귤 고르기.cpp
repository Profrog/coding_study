#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> group;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    sort(tangerine.begin(), tangerine.end());
    int remark = tangerine.back();
    group.push_back(1);
    tangerine.pop_back();

    while (tangerine.size())
    {
        if (remark == tangerine.back())
        {
            ++group.back();
        }

        else
        {
            remark = tangerine.back();
            group.push_back(1);
        }

        tangerine.pop_back();
    }

    sort(group.begin(), group.end());
    
    while (k > 0)
    {
        k -= group.back();
        group.pop_back();
        ++answer;
    }

    return answer;
}
