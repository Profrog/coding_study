#include <string>
#include <vector>
using namespace std;

int MAX_COUNT0 = 8;
int emo_list_size = 0;
vector<int> emo_discount(MAX_COUNT0, 0);

int Setemo_discountAdd()
{
    if (emo_discount[emo_list_size] > 0)
    {
        return 0;
    }

    for (int i = 0; i < MAX_COUNT0; ++i) //1.이모티콘의 길이가 7이하인 걸 고려하여 고정된 길이의 할인율 리스트 db를 구현
    {
        if (emo_discount[i] < 5)
        {
            ++emo_discount[i];
            return 1;
        }
        else
        {
            ++emo_discount[i] = 0;
        }
    }

    return 1;
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0);

    do
    {
        int iPlus = 0;
        int iCoin = 0;
        emo_list_size = (int)emoticons.size();

        for (int i = 0; i < users.size(); ++i) //2.최대 경우의 수가(5^7)정도로 크지 않으므로 완전 탐색으로 c를 만족하는 데이터 탐색
        {
            int iCoin0 = 0;
            for (int j = 0; j < MAX_COUNT0; ++j)
            {
                if (emo_discount[j] * 10 >= users[i][0])
                {
                    iCoin0 += emoticons[j] * (1 - (emo_discount[j] * (float)(0.1)));
                }
            }

            if (iCoin0 >= users[i][1])
            {
                iPlus++;
                iCoin0 = 0;
            }
            iCoin += iCoin0;
        }

        if ((iPlus > answer[0]) || ((iPlus == answer[0]) && (iCoin > answer[1])))
        {
            answer[0] = iPlus;
            answer[1] = iCoin;
        }

    } while (Setemo_discountAdd() > 0);

    return answer;
}
