#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> answer_case;
vector<int> answer(11, 0);
vector<double> answer_priority;
int appch = 0;
int lion = 0;
int differ = 0;
int n0;
double alpa = 0;

int calcul_level(int n, vector<int>& info, int mode)
{
    int answer0 = 0;
    int answer1 = 0;
    int index = 10;
    double precision_0 = 0.1;
    alpa = 0;

    while (index >= 0)
    {
        answer0 += ((n % 2) > 0 ? info[index] + 1 : 0);
        answer1 += ((n % 2) > 0 ? 10 - index : 0);
        alpa += ((n % 2) > 0 ? info[index] + 1 : 0) * precision_0;
        precision_0 *= 0.1;

        if (mode)
        {
            answer[index] = ((n % 2) > 0 ? info[index] + 1 : 0);
        }

        n /= 2;
        --index;
    }

    alpa += (n0 - answer0) * 0.1;

    if (mode)
    {
        answer.back() += (n0 - answer0);
    }

    if (mode < 0)
        return answer1;

    else
        return answer0;
}


vector<int> solution(int n, vector<int> info) {

    n0 = n;
    double target = 0;


    for (int i = 0; i < info.size(); ++i)
    {
        appch += ((info[i] > 0) ? 1 : 0) * pow(2, 10 - i);
    }

    for (int i = 0; i < pow(2, 11); ++i)
    {
        if (calcul_level(i, info, 0) <= n)
        {
            answer_case.push_back(i);
            answer_priority.push_back(alpa);
        }
    }

    for (int i = 0; i < answer_case.size(); ++i)
    {
        int cur_appch = appch & (~answer_case[i]);
        int new_differ = calcul_level(answer_case[i], info, -1) - calcul_level(cur_appch, info, -1);

        if (new_differ >= differ)
        {
            if ((new_differ == differ) && (answer_priority[i] <= target))
                continue;

            lion = answer_case[i];
            differ = new_differ;
            target = answer_priority[i];
        }
    }

    calcul_level(lion, info, 1);

    if (differ == 0)
        return { -1 };
    else
        return answer;
}
