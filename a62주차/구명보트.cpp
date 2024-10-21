#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    
    int answer = 0;
    int start = 0;
    int end = people.size() - 1; 
    sort(people.begin(), people.end(), greater<int>()); //1.사람의 몸무게를 큰 순으로 정렬한다.

    while (start <= end) {
       if (people[start] + people[end] <= limit) //2.최대 몸무게 사람을 태우고 제일 작은 사람을 태울 수 있으면 태운다.
            {
                end--;
            }

            start++; //3.태우지 못한다면, 몸무게가 큰 사람만 태운다.
            answer++;
    }

    return answer;
}



