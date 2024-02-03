#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

vector<long> control_list;

bool check_prime(long alpa)
{
    if (alpa == 1) return false;

    for (long i = 2; i <= (long)(sqrt(alpa)); ++i)
    {
        if (alpa % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;

    long data0 = 0;
    long stair0 = 0;

    while (n) //1.k진수로 변환하면서 낮은 자리의 수부터 0 혹은 공백에 둘러싸여 있으면 소수 판별 리스트에 넣는다.
    {
        int alpa = n % k;
        n /= k;

        if (alpa == 0)
        {
            if (data0)
            {
                control_list.push_back(data0);
                data0 = 0; stair0 = 0;
            }
        }

        else
        {
            data0 += alpa * pow(10, stair0++);
        }
    }

    if (data0) //사이에 0말고 다른것이 있는 경우
    {
        control_list.push_back(data0);
        data0 = 0; stair0 = 0;
    }

    for (auto i = control_list.begin(); i != control_list.end(); ++i) //2.소수 판별 리스트의 수 중 소수인 수를 발견하면 반환값을 1씩 증가한다.
    {
        if (check_prime(*i))
            ++answer;
    }


    return answer;
}
