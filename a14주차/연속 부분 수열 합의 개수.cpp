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

        if (!memory[beta])
        {
            memory[beta] = 1;
            ++answer;
        }

        shift.push_back(beta);
    }
}


int solution(vector<int> elements) {

    shift.assign(elements.size(), 0);

    for (int i = 0; i < elements.size(); ++i)
    {
        make_shift(elements, i);
    }

    return answer;
}
