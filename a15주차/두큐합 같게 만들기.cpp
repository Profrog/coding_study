#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

long long sum_0;
int fq_size;
int bq_size;

int solve_queue(vector<int>& queue01) //2. 앞의 queue과 뒤의 queue의 합의 절반이 될 때까지 앞의 queue에서 뒤의 queue로 원소 하나씩 옮긴다.
{
    int answer = 0;

    if (sum_0 % 2) return -1;
    else sum_0 /= 2;

    int start_i = 0;
    int end_i = 0;
    long long current_v = queue01.front();

    while ((start_i <= end_i) && (end_i < queue01.size()))
    {
        if (sum_0 == current_v) {

            int alpa0 = (end_i - fq_size + 1);

            if (alpa0 >= 0)
                return start_i + alpa0;

            else
            {
                return 2 * start_i + 1 + fq_size;
            }
        }

        else if (sum_0 < current_v)
        {
            current_v -= queue01[start_i++];
        }

        else
        {
            current_v += queue01[++end_i];
        }
    }

    return -1;
}

vector<int> make_queue(vector<int>& queue_a, vector<int>& queue_b) //1. a에 대하여 queue1에서 먼저 추출하는 경우와 queue2에서 먼저 추출하는 두 가지 경우를 생각한다.
{
   vector<int> queue01;
    
    for (auto i = queue_a.begin(); i != queue_a.end(); ++i)
    {
        queue01.push_back(*i);
        sum_0 += *i;
    }

    for (auto i = queue_b.begin(); i != queue_b.end(); ++i)
    {
        queue01.push_back(*i);
        sum_0 += *i;
    }

    return queue01;
}


int solution(vector<int> queue1, vector<int> queue2) {

    vector<int> queue01;
    vector<int> answer;
   
    sum_0 = 0;
    fq_size = queue1.size();
    bq_size = queue2.size();
    queue01 = make_queue(queue1, queue2);
    answer.push_back(solve_queue(queue01));
    //01

    sum_0 = 0;
    fq_size = queue2.size();
    bq_size = queue1.size();
    queue01 = make_queue(queue2, queue1);
    answer.push_back(solve_queue(queue01));
    //02
    
    sort(answer.begin(), answer.end());
    for (auto i = answer.begin(); i != answer.end(); ++i) //3.2.에서 실패했으면 -1 그 외에는 추출 최소 횟수를 반환한다.
    {
        if (*i > -1)
            return *i;

    }

    return -1;
}
