#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> clear0;

int solution(int n, int k, vector<int> enemy) {

    int interval = min(k, (int)enemy.size()); 
    int answer = interval;

    for (auto i = enemy.begin(); i != enemy.begin() + interval; ++i) //1. 무적권 수 만큼 적 리스트 원소값 우선순위 큐에 저장
    {
        clear0.push(*i);
    }

    for (auto i = enemy.begin() + interval; i != enemy.end(); ++i)
    {

        int alpa = 0;
        if (clear0.top() < *i) //2. 남은 적 리스트 원소값을 차례대로 처리하며, 우선순위 큐의 가장 큰 값보다 큰 값을 발견하면 해당 값을 무적권 우선순위 큐에 넣고, 기존에 저장되어 있던 값을 아군 병사로 해결함
        {
            alpa = clear0.top();
            clear0.pop();
            clear0.push(*i);
        }

        else
          alpa = *i;
        
        if ((n -= alpa) < 0) //3. b에 따라 아군 병사가 동나면 현재 처리하고 있던 인덱스 값 반환
          break;

        ++answer;
    }

    return answer;
}
