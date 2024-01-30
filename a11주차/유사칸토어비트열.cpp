#include <vector>
#include <cmath>
using namespace std;
vector<int> data_list = { 0,1,2,2,3 };

int solution(int n, long long l, long long r) {

    long long answer = pow(4, n);
    long long remind = pow(5, n - 1);
    long long multiple = pow(4, n - 1);
    int baseline = 4;

    for(--l,--r;remind > 0; l %= remind,r %= remind, multiple /= 4,remind /= 5) //2.비트열이 축소될 때 패턴 1의 가중치는 4^n만큼 감소한다.(11011 -> 1)
    {
        long long l1 = l / remind;
        long long r1 = baseline - (r / remind);

        answer -= multiple * (data_list[l1] + data_list[r1]); //1. n번째 부터 1번째로 비트열을 축소해 가면서 l보다 왼쪽의 1의 개수, r보다 오른쪽의 1의 개수를 빼준다.

        if (l1 == 2) //3. 패턴 0에는 0만 존재하므로 해당 구간으로 축소되면 예외처리를 한다(축소 영역 기준으로 2번째 인덱스)
        {
            l = 0;
        }

        if (r1 == 2)
        {
            baseline = 0;
            r = 0;
        } 
    }

    return answer;
}
