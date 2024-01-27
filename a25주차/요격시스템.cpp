#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2) //1.개구간의 시작점이 이른 순서대로 나열(개구간의 시작점이 같으면 짧은 순서대로 나열)
{
    if (v1[0] == v2[0])
        return v1[1] < v2[1];

    else
        return  v1[0] < v2[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int line = -1;

    sort(targets.begin(), targets.end(), cmp);

    for (auto a : targets)
    {
        if (a[0] > line) 
        {
            ++answer;
            line = a[1] - 1; //2. 나열한 순서대로 탐색, 기존의 가장 뒤에 위치한 레이저가 개구간의 시작보다 앞이면 개구간의 끝 영역에 신규 레이저가 발사
        }

        else
        {
            line = (line < a[1] - 1) ? line : (a[1] - 1); //3. 기존의 가장 뒤에 위치한 레이저가 개구간의 끝보다 뒤면, 기존 레이저를 개구간의 뒤 부분으로 옮김
        }
    }

    return answer;
}
