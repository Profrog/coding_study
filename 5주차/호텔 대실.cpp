#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> booking(1, 0);

int cv_time(string alpa) //1.시간을 분 단위로 바꾸어 데이터의 인덱스로 삼음
{
    return 60 * stoi(alpa.substr(0, 2)) + stoi(alpa.substr(3, 2));
}

bool compare(vector<string>& alpa, vector<string>& beta) //2. 사용자 리스트를 시작시간이 빠른 순으로, 시작시간이 같으면 일찍 끝나는 순으로 정렬
{
    if (cv_time(alpa[0]) == cv_time(beta[0]))
        return cv_time(alpa[1]) < cv_time(beta[1]);

    else return cv_time(alpa[0]) < cv_time(beta[0]);
}

int solution(vector<vector<string>> book_time) {

    sort(book_time.begin(), book_time.end(), compare);

    for (int i = 0; i < book_time.size(); ++i) //3.객실 리스트에는 마지막 사용시간 + 10분을 저장하며 새로운 사용자에 대하여 기존 객실이 커버할 수 없으면 새로운 객실을 객실리스트에 추가
    {
        for (int j = 0; j < booking.size(); ++j)
        {
            if (cv_time(book_time[i][0]) >= booking[j])
            {
                booking[j] = cv_time(book_time[i][1]) + 10;
                goto tag1;
            }
        }

        booking.push_back(cv_time(book_time[i][1]) + 10);
    tag1:;
    }

    return booking.size();
}
