#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; ++i)
    {
        int y_alpa = (i / n);
        int x_alpa = (i % n);
        answer.push_back(max(y_alpa, x_alpa) + 1);
    }

    return answer;
}
