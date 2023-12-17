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

    while (n) //0과 0사이에 있는 수들 모음
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

    for (auto i = control_list.begin(); i != control_list.end(); ++i) //소수의 개수 세기
    {
        //cout << *i << " "; 

        if (check_prime(*i))
            ++answer;
    }


    return answer;
}
