#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int check_data(int k, vector<vector<int>>& dungeons, vector<int>& alpa)
{
    int answer1 = 0;

    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (k < dungeons[alpa[i]][0] || k < dungeons[alpa[i]][1])
            return answer1;

        k -= dungeons[alpa[i]][1];
        ++answer1;       
    }
    return answer1;
}


int solution(int k, vector<vector<int>> dungeons) {

    int answer = 0;
    vector<int> alpa;

    for (int i = 0; i < dungeons.size(); ++i)
        alpa.push_back(i);

    do
    {
        answer = max(answer, check_data(k, dungeons, alpa));
    } while (next_permutation(alpa.begin(), alpa.end()));

    return answer;
}
