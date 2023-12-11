#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cur_time = 0;
int future_time = 0;
int answer = 0;
int t_check[2];

double s01;
double m01;
double h01;
int i;


int timer_check(double alpa, double beta, int mode)
{
    if (alpa > beta)
        return 1;

    else if (alpa < beta)
        return -1;


    else return 0;
}

void control_timer()
{
    int t1 = timer_check(s01, m01, 0); //초침이 분침을 넘겼는지
    int t2 = timer_check(s01, h01, 1); //초침이 시침을 넘겼는지
    int answer0 = answer;

    if ((int)s01%60 == 0)
    {
        if (t1 == 0)
            ++answer;

        else if (t_check[0] < 0)
            ++answer;
    }

    else if (t1 == 1 && t_check[0] < 0)
        ++answer;

    if (answer > answer0)
        cout << h01 << " " << m01 << " " << s01 << " " << answer << "@\n";

    answer0 = answer;


    if ((int)s01 % 60 == 0)
    {
        if (t2 == 0)
            ++answer;

        else if (t_check[1] < 0)
            ++answer;
    }

    else if (t2 == 1 && t_check[1] < 0)
        ++answer;

    if (answer > answer0)
        cout << h01 << " " << m01 << " " << s01 << " " << answer << "#\n";


    if (m01 == h01)
        --answer;

    if (s01 != 60)
    {
        t_check[0] = t1;
        t_check[1] = t2;
    }

    else if (s01 == m01)
    {
        t_check[0] = t1;
        t_check[1] = t2;
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
    t_check[0] = 0; t_check[1] = 0;

    //if (m1 == 0 && s1 == 0)
       // ++answer;

    for (i = cur_time; i <= future_time; ++i, ++s1)
    {
        h1 %= 12;
        s01 = s1;
        m01 = m1 + ((double)(s1) / 60);
        h01 = (h1 + ((double)m1 / 60) + ((double)s1 / 3600)) * 5;

        control_timer();
        bool check_0 = false;

        if (s1 >= 60)
        {
            ++m1;
        }

        if (m1 >= 60)
        {
            ++h1;
        }
        s1 %= 60;
        m1 %= 60;
        h1 %= 12;
    }

    return answer;
}
