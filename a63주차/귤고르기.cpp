#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> group;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    group.push_back(1);
    
    sort(tangerine.begin(), tangerine.end()); //1. 귤 집합을 정렬한다. 귤의 종류 별 개수를 컨테이너에 저장한다.
    int remark = tangerine.back();
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

    sort(group.begin(), group.end()); //2. 컨테이너를 정렬한다. 개수가 많은 귤 부터 k를 채워나가며, 종류가 다른 귤일 때 반환값을 1 올린다.
    while (k > 0)
    {
        k -= group.back();
        group.pop_back();
        ++answer;
    }

    return answer;
}
