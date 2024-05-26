#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int check_data(int k, vector<vector<int>>& dungeons, vector<int>& sequence)
{
    int answer1 = 0;

    for (int i = 0; i < dungeons.size(); ++i)
    {
        if (k < dungeons[sequence[i]][0])
        {
            return answer1;
        }

        k -= dungeons[sequence[i]][1];
        ++answer1;
    }

    return answer1;
}


int solution(int k, vector<vector<int>> dungeons) {

    int answer = 0;

    vector<int> sequence;

    for (int i = 0; i < dungeons.size(); ++i) //1.배열의 인덱스를 수열의 순서로 인식하기 위해 배열의 인덱스를 저장한 리스트 생성
    {
        sequence.push_back(i);
    }

    do
    {
        answer = max(answer, check_data(k, dungeons, sequence)); //3.최대 탐험 던전 수 반환
        
        //2.순열로 던전 탐험 경우의 수를 만들고 각각의 경우의 수에서 탐험 던전의 수 반환
    } while (next_permutation(sequence.begin(), sequence.end()));

    return answer;
}
