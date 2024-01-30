#include <string>
#include <vector>
using namespace std;

vector<long long>lineup;

long long solution(int k_, int d_) {

    long long k = k_;
    long long d = d_;
    long long answer = 0;

    for (long long i = 0; (k * i) <= d; ++i) //1. x가 0일 때 d이하인 모든 bk에 대한 리스트를 정리한다.
    {
        lineup.push_back((long long)(k * i * k * i));
    }

    for (long long i = 0; (k * i) <= d; ++i)
    {
        while ((long long)(k * i * k * i) + lineup.back() > (long long)(d * d)) //2. x를 1씩 늘려가며 피타고라스 정리를 활용한 x,y좌표를 이용한 빗변의 길이가 d를 넘는 bk 값을 모두 제거한다.
        {
            lineup.pop_back();
        }

        answer += lineup.size(); //3.  가능한 좌표의 수를 모두 취합하여 반환한다.
    }

    return answer;
}
