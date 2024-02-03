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
    int case_control = 0;
    int get_score = 0;
    int index = 10;
    double precision_0 = 0.1;
    alpa = 0;

    while (index >= 0)
    {
        case_control += ((n % 2) > 0 ? info[index] + 1 : 0);
        get_score += ((n % 2) > 0 ? 10 - index : 0);
        alpa += ((n % 2) > 0 ? info[index] + 1 : 0) * precision_0;
        precision_0 *= 0.1;

        if (mode == 1)
        {
            answer[index] = ((n % 2) > 0 ? info[index] + 1 : 0);
        }

        n /= 2;
        --index;
    }

    alpa += (n0 - case_control) * 0.1;

    if (mode == 1)
    {
        answer.back() += (n0 - case_control);
    }

    if (mode == -1)
        return get_score;

    else
        return case_control;
}


vector<int> solution(int n, vector<int> info) {

    n0 = n;
    double target = 0;


    for (int i = 0; i < info.size(); ++i)
    {
        appch += ((info[i] > 0) ? 1 : 0) * pow(2, 10 - i);
    }

    for (int i = 0; i < pow(2, 11); ++i) //1.라이언이 해당 데이터를 취득하는 경우의 수(a에 따라)를 10자리의 2진법 수로 표현한다.
    {
        if (calcul_level(i, info, 0) <= n) //2.취득 경우의 수가 라이언이 가진 화살 이하라면 실현 가능한 경우의 수로 관리한다. 높은 점수의 화살일 수록 우선순위를 둔다.(최소한의 화살로 이기고 남은 화살을 가장 낮은 화살에 넣는 것이 좋다.)
        {
            answer_case.push_back(i);
            answer_priority.push_back(alpa);
        }
    }

    for (int i = 0; i < answer_case.size(); ++i)
    {
        int cur_appch = appch & (~answer_case[i]);
        int new_differ = calcul_level(answer_case[i], info, -1) - calcul_level(cur_appch, info, -1);

        if (new_differ >= differ) //3.실현 가능한 경우의 수 중 룰에 따라 어피치를 이기는 경우의 수 중 우선 순위가 높은 경우의 수를 반환용으로 저장한다.
        {
            if ((new_differ == differ) && (answer_priority[i] <= target))
                continue;

            lion = answer_case[i];
            differ = new_differ;
            target = answer_priority[i];
        }
    }

    calcul_level(lion, info, 1);

    if (differ == 0) //4.어떤 경우의 수에서도 이길 수 없을 시 [-1]을 반환한다.
        return { -1 };
    else
        return answer;
}
