#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

vector<int> memory(10000001, 0);
list<int> shift;
int answer = 0;

void make_shift(vector<int>& elements, int index)
{
    int size_shift = shift.size();

    for (int i = 0; i < size_shift; ++i)
    {
        auto alpa = shift.front();
        shift.pop_front();

        int beta = alpa + elements[(i + index) % elements.size()];

        if (!memory[beta]) //2.부분 수열의 길이의 합이 기존에 저장 되었던 경우는 합의 가짓수에서 제외한다.
        {
            memory[beta] = 1;
            ++answer;
        }

        shift.push_back(beta);
    }
}


int solution(vector<int> elements) {

    shift.assign(elements.size(), 0);

    for (int i = 0; i < elements.size(); ++i) //1. 부분 수열의 길이(1~n)에 따라 수열의 시작포인트를 한칸씩 shift하면서 합을 구한다
    {
        make_shift(elements, i);
    }

    return answer;
}
