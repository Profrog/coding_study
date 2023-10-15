#include <vector>
#include <cmath>
using namespace std;
vector<int> data_list = { 0,1,2,2,3 };


int solution(int n, long long l, long long r) {
    
    long long answer = pow(4, n);
    long long remind = pow(5, n - 1);
    long long multiple = pow(4, n - 1);
    int baseline = 4;

    --l;
    --r;
    while (remind)
    {
        long long l1 = l / remind;
        long long r1 = baseline - (r/ remind);

        answer -= multiple * (data_list[l1] + data_list[r1]);

        if (l1 == 2)
        {
            l = 0;
        }

        if (r1 == 2)
        {
            baseline = 0;
            r = 0;
        }

        l %= remind;
        r %= remind;
        multiple /= 4;
        remind /= 5;
    }

    return answer;
}
