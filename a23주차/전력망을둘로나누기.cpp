#include <string>
#include <vector>
#include <cmath>

using namespace std;
vector<vector<int>> line_data(101, vector<int>(0,0));
vector<int> value_data(101, 1);
int alpa; 
int beta0;

int dfs_maker(int gamma)
{
    if (value_data[gamma] == -1)
        return 0;
 
    value_data[gamma] = -1;

    int answer = 1;
    for (int i = 0; i <  line_data[gamma].size(); ++i)
    {
        if (line_data[gamma][i] != alpa && line_data[gamma][i] != beta0)
        {
            answer += dfs_maker(line_data[gamma][i]);
        }
    }

    return answer;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000;

    for (int i = 0; i < wires.size(); ++i)
    {
        line_data[wires[i][0]].push_back(wires[i][1]);
        line_data[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); ++i)
    {
        value_data = vector<int>(101, 0);
        alpa = wires[i][0]; beta0 = wires[i][1];
        answer = min(answer, abs(dfs_maker(alpa) - dfs_maker(beta0)));
    }

    return answer;
}
