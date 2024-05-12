#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dayz = 10;
queue<string> backet;

int check_match(vector<string>& want, string cur_item) //1. want와 number은 인덱스를 사용하여 매치 및 관리
{
    for (int i = 0; i < want.size() ; ++i)
    {
        if (want[i] == cur_item)
            return i;
    }

    return -2;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int backet_score = 0;

    for (int i = 0; i < dayz; ++i) //2. 최초 10개로 discount 관리용 큐 만들기, want의 number를 얼마나 만족하는 지 체크섬으로 관리함
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


    for (int i = dayz; i < discount.size(); ++i) //3. 관리하던 큐에서 앞의 것(오래된 데이터)부터 삭제하고 새로운 데이터를 들이며 want와 number을 만족하는 지 체크
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
