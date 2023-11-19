#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer_1 = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for (int i = 0; i < A.size(); ++i)
    {
        answer_1 += A[i] * B[i];
    }

    return answer_1;
}
