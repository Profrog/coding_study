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

    for (auto x = topping.begin(); x != topping.end(); ++x)
    {
        if (topping_rcount[*x] == 0)
        {
            ++topping_right;
        }

        ++topping_rcount[*x];
    }

    for (auto x = topping.begin(); x != topping.end(); ++x)
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

        if (topping_left == topping_right)
        {
            ++answer;
        }
    }

    return answer;
}
