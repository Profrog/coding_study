#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> data_group;

int solution(vector<int> cards) {

    for (int i = 0; i < cards.size(); ++i)
    {
        int answer = 0;
        int linked = cards[i] - 1;

        while (linked > -1 && cards[linked] > 0)
        {
            int next_index = cards[linked]-1;
            cards[linked] = 0;
            linked = next_index;
            ++answer;
        }
 
        data_group.push_back(answer);
    }

    sort(data_group.begin(), data_group.end(), greater<int>());
    return data_group[0] * data_group[1];
}
