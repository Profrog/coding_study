#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> data_group;

int solution(vector<int> cards) {

    for (int i = 0; i < cards.size(); ++i) //3.모든 그룹이 정의될 때 까지 반복, d에 따라 최종값을 반환한다.
    {
        int answer = 0;
        int linked = cards[i] - 1;

        while (linked > -1 && cards[linked] > 0) //1. 첫 번의 상자 부터 카드를 확인하며 카드의 값이 0이 아닌 경우 그룹합계에 더하며 확인한 카드는 0으로 치환한다.
        {
            int next_index = cards[linked]-1;
            cards[linked] = 0;
            linked = next_index;
            ++answer;
        }
 
        data_group.push_back(answer); //2.c에 따라서 하나의 그룹의 정의되면 그룹 리스트에 그룹 합계를 추가한다.
    }

    sort(data_group.begin(), data_group.end(), greater<int>());
    return data_group[0] * data_group[1];
}
