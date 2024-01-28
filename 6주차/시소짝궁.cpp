#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> weight_list(4001, 0);

long long check_weight(int alpa)
{
    if (alpa < weight_list.size())
    {
        return weight_list[alpa]++;
    }
}

long long solution(vector<int> weights) {
    long long answer = 0;
  
    sort(weights.begin(), weights.end());
    answer += check_weight(weights[0] * 2) + check_weight(weights[0] * 3) + check_weight(weights[0] * 4);
    long long same = 0;

    for (int i = 1; i < weights.size(); ++i)
    {
        if (weights[i-1] == weights[i])
        {
            ++same;
            answer -= 2 * same;
        }

        else
        {
            same = 0;
        }

        answer += check_weight(weights[i] * 2) + check_weight(weights[i] * 3) + check_weight(weights[i] * 4);
    }

    return answer;
}
