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


int control_timer_1(double s0, double beta,int t_index) //2.c를 고려하여 초침과 다른 침이 만나면 반환 값을 1올린다
{
   int t =  (s0 == beta) ? 0 : (s0 > beta)? 1 : -1; 
    
    if ((int)s01 % 60 == 0)
    {
        if (t == 0)
            ++answer;

        else if (t_check[t_index] < 0)
            ++answer;
    }

    else if (t == 1 && t_check[t_index] < 0)
        ++answer;
    
    return t;
}

void control_timer()
{
    int t0 = control_timer_1(s01, m01, 0);
    int t1 = control_timer_1(s01, h01, 1);

    (m01 == h01)? --answer: 0;

    if (s01 != 60) //3.1.에서 비교를 위해 1초전의 위치값은 저장한다.
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
    future_time = 3600 * h2 + 60 * m2 + s2; //1.시간으로 1초로 기준으로 변환한뒤 그 사이에서 분침, 시침의 위치도 a를 고려하여 1초 단위로 변환한다

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
