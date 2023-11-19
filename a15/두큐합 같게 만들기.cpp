a#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

long long sum_0;
int fq_size;
int bq_size;

int make_queue(vector<int>& queue01)
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

int solution(vector<int> queue1, vector<int> queue2) {

    vector<int> queue01;
    vector<int> answer;
    sum_0 = 0;
    fq_size = queue1.size();
    bq_size = queue2.size();

    queue01 = vector<int>();
    for (auto i = queue1.begin(); i != queue1.end(); ++i)
    {
        queue01.push_back(*i);
        sum_0 += *i;
    }

    for (auto i = queue2.begin(); i != queue2.end(); ++i)
    {
        queue01.push_back(*i);
        sum_0 += *i;
    }

    answer.push_back(make_queue(queue01));
    //01

    queue01 = vector<int>();
    sum_0 = 0;
    fq_size = queue2.size();
    bq_size = queue1.size();

    for (auto i = queue2.begin(); i != queue2.end(); ++i)
    {
        queue01.push_back(*i);
        sum_0 += *i;
    }

    for (auto i = queue1.begin(); i != queue1.end(); ++i)
    {
        queue01.push_back(*i);
        sum_0 += *i;
    }

    answer.push_back(make_queue(queue01));
    //02

    sort(answer.begin(), answer.end());
    for (auto i = answer.begin(); i != answer.end(); ++i)
    {
        if (*i > -1)
            return *i;

    }

    return -1;
}
