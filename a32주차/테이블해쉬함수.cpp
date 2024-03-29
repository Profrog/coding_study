#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int col0;
vector<int> hash_list;

bool sort_algo(vector<int>& alpa, vector<int>& beta) //1. a. 에 따라 datalist를 정렬한다.
{
    if (beta[col0] > alpa[col0])
        return true;

    else if ((beta[col0] == alpa[col0]) && beta.front() < alpa.front())
        return true;

    else
        return false;
}


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    col0 = col - 1;

    sort(data.begin(), data.end(), sort_algo);

    for (int i = row_begin - 1; i <= row_end - 1; ++i) //2. row_begin <= n <= row_end에 대하여 s_n의 리스트를 구한다.
    {
        answer = 0;

        for (auto j = data[i].begin(); j != data[i].end(); ++j)
        {
            answer += (*j) % (i + 1);
        }

        hash_list.push_back(answer); 
    }

    while (hash_list.size() > 1) //3. s_n들 값을 중첩적으로 xor한 값을 반환한다.
    {
        int hash_alpa = hash_list.back();
        hash_list.pop_back();

        hash_list.back() ^= hash_alpa;
    }

    return hash_list.back();
}
