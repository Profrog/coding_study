#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dayz = 10;
queue<string> backet;

int check_match(vector<string>& want, string cur_item)
{
    for (int i = 0; i < want.size() ; ++i)
    {
        if (want[i] == cur_item)
            return i;
    }

    return -1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int backet_score = 0;

    for (int i = 0; i < dayz; ++i) //최초 10개로 데이터 셋 만들기
    {
        backet.push(discount[i]);
        int alpa = check_match(want, discount[i]);
        if (alpa > -1)
        {
            --number[alpa];
            if (number[alpa] == 0)
                ++backet_score;
        }

        if (backet_score == want.size())
            ++answer;
    }


    for (int i = dayz; i < discount.size(); ++i)
    {
        string beta = backet.front();
        backet.pop();
        int alpa = check_match(want, beta);
        if (alpa > -1)
        {
            ++number[alpa];
            if (number[alpa] == 1)
            { 
                --backet_score;
            }
        }

        backet.push(discount[i]);
        alpa = check_match(want, discount[i]);
        if (alpa > -1)
        {
            --number[alpa];
            if (number[alpa] == 0)
                ++backet_score;
        }

        if (backet_score == want.size())
        {
            ++answer;
        }
    }

    return answer;
}
