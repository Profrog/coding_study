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

    while (tangerine.size()) //1. 크기에 따라 귤 그룹을 만든다.
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
    
    while (k > 0) //2. 귤 개수가 많은 그룹부터 k개 그룹에 배정하면서, 배정된 귤 개수의 총합이 k보다 커질때 까지 반복한다.
    {
        k -= group.back();
        group.pop_back();
        ++answer;
    }

    return answer;
}
