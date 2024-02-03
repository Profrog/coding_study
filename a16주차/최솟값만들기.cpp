#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer_1 = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>()); //1.A리스트를 최솟값 순으로 정렬, B리스트를 최댓값 순으로 정렬하여 각 원소를 곱하여 반환한다.

    for (int i = 0; i < A.size(); ++i)
    {
        answer_1 += A[i] * B[i];
    }

    return answer_1;
}
