#include <string>
#include <vector>
#include <iostream>

using namespace std;

int topping_lcount[10001] = { 0 };
int topping_rcount[10001] = { 0 };

int solution(vector<int> topping) {
    int answer = 0;
    
    int topping_left = 0;
    int topping_right = 0;

    for (auto x = topping.begin(); x != topping.end(); ++x) //1. 모든 토핑을 right 그룹에 분배한다
    {
        if (topping_rcount[*x] == 0)
        {
            ++topping_right;
        }

        ++topping_rcount[*x];
    }

    for (auto x = topping.begin(); x != topping.end(); ++x) //2.토핑을 하나 씩 left 그룹에 분배해보면서 left 그룹에 분배한 토핑의 개수와 right 그룹에 분배한 토핑의 개수를 비교한다.
    {
     
        if (topping_lcount[*x] <= 0)
        {
            ++topping_left;
        }

        ++topping_lcount[*x];


        if (topping_rcount[*x] <= 1)
        {
            --topping_right;
        }

        --topping_rcount[*x];

        if (topping_left == topping_right ) //3. 토핑의 개수가 같아 졌을 때, 반환값을 증가시킨다.
        {
            ++answer;
        }
    }

    return answer;
}
