#include <string>
#include <vector>
using namespace std;

vector<long long>lineup;

long long solution(int k_, int d_) {

    long long k = k_;
    long long d = d_;
    long long answer = 0;

    for (long long i = 0; (k*i) <= d; ++i)
    {
        lineup.push_back((long long)(k*i * k*i));
    }

    for (long long i = 0; (k * i) <= d; ++i)
    {
        while ((long long)(k * i * k * i) + lineup.back() > (long long)(d*d))
        {
            lineup.pop_back();
        }

        answer += lineup.size();
    }

    return answer;
}
