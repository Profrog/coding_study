#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;
queue<int> origin;
stack<int> temp;


void make_datastack(int alpa)
{
    while(origin.size())
    {
        if (origin.front() < alpa)
        {
            temp.push(origin.front());
            origin.pop();
        }

        else
            break;
    }
}

int solution(vector<int> order) {
    int answer = 0;

    for (int i = 1; i <= order.size(); ++i)
    {
        origin.push(i);
    }

    for (int i = 0; i < order.size(); ++i)
    {
        if (origin.size() && origin.front() == order[i])
        {
            ++answer;
            origin.pop();
            continue;
        }

        if (temp.size() && temp.top() == order[i])
        {
            ++answer;
            temp.pop();
            continue;
        }
        
  
        make_datastack(order[i]);
            //cout << order[i] << " " << temp.top();
    

        if (temp.size() && temp.top() == order[i])
        {
            ++answer;
            temp.pop();
            continue;
        }

        if (origin.size() && origin.front() == order[i])
        {
            ++answer;
            origin.pop();
            continue;
        }
 
        break;
    }

    return answer;
}
