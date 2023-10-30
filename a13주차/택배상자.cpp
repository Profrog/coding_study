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

    for (int i = 1; i <= order.size(); ++i)
    {
        origin.push(i);
    }

    for (int i = 0; i < order.size(); ++i)
    {
        if (temp.empty())
            if (!make_datastack())
                return answer;


        while (temp.top() != order[i])
            if (!make_datastack())
                return answer;
                   
        temp.pop();
        ++answer;
    }

    return answer;
}
