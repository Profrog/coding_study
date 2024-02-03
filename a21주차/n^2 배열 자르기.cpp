#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; ++i)
    {
        int y_alpa = (i / n); 
        int x_alpa = (i % n); //2.1차원 배열로 만들 시 index는 (x,y) -> (n*y + x) 가 된다. 이를 역으로 생각하여 해당 위치 값을 역추측하여 반환값에 더해준다.
        answer.push_back(max(y_alpa, x_alpa) + 1); //1.2차원 배열에서 (x,y)중 최댓값 + 1이 해당 위치의 값이 된다.
    }

    return answer;
}
