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

int emulate0(vector<int>& alpa, int beta)
{
    for (int i = 0; i < alpa.size(); ++i)
    {
        beta = u_clead(max(alpa[i], beta), min(alpa[i], beta));
    }

    return beta;
}

int emulate1(vector<int>& alpa, int beta)
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

   
    if (max(lineup_a, lineup_b) == 1)
        return 0;

    else
        return max(lineup_a, lineup_b);
}
