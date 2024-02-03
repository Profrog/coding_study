#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> original_data;
vector<double> space_data;

int collatz_graph(int alpa) //1.collaz 추측에 의거한 점 간 사이의 영역을 시작점을 index로 갖는 리스트 형태로 저장한다.
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
    return collatz_graph(beta);
}

vector<double> solution(int k, vector<vector<int>> ranges) {

    original_data.push_back(k);
    collatz_graph(k);
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

        else //3. a > b + n - 1일 시 -1을 return 한다.
        {
            for (int y = s_index; y < e_index; ++y) //2.[a,b]구간의 영역의 합을 b에 의거하여 넓이의 합으로 구한다.
            {
                answer0 += space_data[y];
            }

            answer.push_back(answer0);
        }
    }

    return answer;
}
