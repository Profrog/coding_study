#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int u_clead(int alpa, int beta)
{
    if (alpa % beta == 0)
        return beta;

    else
        return u_clead(max(beta, alpa % beta), min(beta, alpa % beta));
}

int emulate0(vector<int>& alpa, int beta) //1.유클리드 호제법을 사용하여 arrayA, arrayB의 최대 공약수를 구한다.
{
    for (int i = 0; i < alpa.size(); ++i)
    {
        beta = u_clead(max(alpa[i], beta), min(alpa[i], beta));
    }

    return beta;
}

int emulate1(vector<int>& alpa, int beta) //2. 각각의 최대 공약수가 다른 배열과의 서로소인지를 확인
{
    for (int i = 0; i < alpa.size(); ++i)
    {
        if (alpa[i] % beta == 0)
            return 1;
    }

    return beta;
}

int solution(vector<int> arrayA, vector<int> arrayB) {

    int lineup_a = emulate0(arrayA, arrayA[0]); //a그룹 최대공약수
    int lineup_b = emulate0(arrayB, arrayB[0]); //b그룹 최대공약수

    lineup_a = emulate1(arrayB, lineup_a);
    lineup_b = emulate1(arrayA, lineup_b);

   
    if (max(lineup_a, lineup_b) == 1) //3.최대공약수 둘 다 서로소가 아니라면 0을 반환, 아니라면 큰 수를 반환한다.
        return 0;

    else
        return max(lineup_a, lineup_b);
}
