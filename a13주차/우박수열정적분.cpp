#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> original_data;
vector<double> space_data;

int make_squence(int alpa)
{
    int beta;

    if (alpa <= 1)
    {
        return 1;
    }

    else if (alpa % 2 == 0)
    {
        beta = alpa / 2;
    }

    else
    {
        beta = (alpa * 3) + 1;
    }

    space_data.push_back(double(original_data.back() + beta) / 2);
    original_data.push_back(beta);
    return make_squence(beta);
}

vector<double> solution(int k, vector<vector<int>> ranges) {

    original_data.push_back(k);
    make_squence(k);
    vector<double> answer;

    for (int x = 0; x < ranges.size(); ++x)
    {
        double answer0 = 0;
        int s_index = ranges[x].front();
        int e_index = space_data.size() + ranges[x].back();

        if ((s_index > e_index) || (s_index > space_data.size()) || (e_index < 0))
        {
            answer.push_back(-1);
        }

        else
        {
            for (int y = s_index; y < e_index; ++y)
            {
                answer0 += space_data[y];
            }

            answer.push_back(answer0);
        }
    }

    return answer;
}
