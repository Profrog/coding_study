#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;
queue<int> origin;
stack<int> temp;

bool make_datastack()
{
    if (origin.size())
    {
        temp.push(origin.front());
        origin.pop();
        return true;
    }

    return false;
}

int solution(vector<int> order) {
    int answer = 0;

    for (int i = 1; i <= order.size(); ++i) //1. c를 만족하는 넣어야 하는 순서(1,2,3,,,n)를 가진 큐로 모범 벨트 구현
    {
        origin.push(i);
    }

    for (int i = 0; i < order.size(); ++i)
    {
        if (temp.empty()) //2. 보조 벨트가 비어있으면 모범 벨트의 요소를 하나 넣고, 모범&임시 벨트의 요소 중에 메인 벨트의 요소와 일치하는 지 확인
            if (!make_datastack())
                return answer;


        while (temp.top() != order[i]) // 3. 어느 쪽도 일치 하지 않으면 현재 실어진 택배 개수 반환, 일치하면 이어서 메인 벨트 탐색
            if (!make_datastack())
                return answer;
                   
        temp.pop();
        ++answer;
    }

    return answer;
}
