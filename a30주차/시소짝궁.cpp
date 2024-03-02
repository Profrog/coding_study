#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> weight_list(4001, 0);

long long check_weight(int alpa) //2.기록 시에 토크가 중복이면 무게쌍이 나오므로 반환값에 더해준다.(2개 중복 : 1, 3개 중복 : 1+2)
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

    for (int i = 1; i < weights.size(); ++i) //1.무게 리스트를 탐색하며 토크를 기록한다.
    {
        if (weights[i - 1] == weights[i]) //4.무게가 같은 경우는 거리(2,3,4)일 때 3번의 무게쌍으로 기록되므로 1번의 무게쌍으로 기록되도록 예외처리를 해준다.
        {
            ++same;
            answer -= 2 * same;
        }

        else
        {
            same = 0;
        }

        answer += check_weight(weights[i] * 2) + check_weight(weights[i] * 3) + check_weight(weights[i] * 4); //3. 2에 따라 반환값은 축적되며, 경우의 수가 반영된다.
    }

    return answer;
}
