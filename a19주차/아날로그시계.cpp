#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cur_time = 0;
int future_time = 0;
int answer = 0;
int t_check[2] = {0};

double s01;
double m01;
double h01;

int timer_check(double alpa, double beta, int mode)
{
    if (alpa == beta)
        return 0;

    return (alpa > beta)? 1 : -1;
}

void control_timer_1(int t,int t_index)
{
    if ((int)s01 % 60 == 0)
    {
        if (t == 0)
            ++answer;

        else if (t_check[t_index] < 0)
            ++answer;
    }

    else if (t == 1 && t_check[t_index] < 0)
        ++answer;
}

void control_timer()
{
    int t0 = timer_check(s01, m01, 0); //초침이 분침을 넘겼는지
    int t1 = timer_check(s01, h01, 1); //초침이 시침을 넘겼는지
  
    control_timer_1(t0, 0);
    control_timer_1(t1, 1);

    (m01 == h01)? --answer: 0;

    if (s01 != 60)
    {
        t_check[0] = t0;
        t_check[1] = t1;
    }

    else if (s01 == m01)
    {
        t_check[0] = t0;
        t_check[1] = t1;
    }

    else
    {
        t_check[0] = -1;
        t_check[1] = -1;
    }
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {

    answer = 0;
    cur_time = 3600 * h1 + 60 * m1 + s1;
    future_time = 3600 * h2 + 60 * m2 + s2;

    for (int i = cur_time; i <= future_time; ++i, ++s1)
    {
        h1 %= 12;
        s01 = s1;
        m01 = m1 + ((double)(s1) / 60);
        h01 = (h1 + ((double)m1 / 60) + ((double)s1 / 3600)) * 5;

        control_timer();

        (s1 >= 60) ? ++m1 : 0;
        (m1 >= 60) ? ++h1 : 0;

        s1 %= 60;
        m1 %= 60;
    }

    return answer;
}
