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

    for (int i = 0; i < wires.size(); ++i) //1.주어진 간선 정보로 트리(그래프)를 만든다.
    {
        line_data[wires[i][0]].push_back(wires[i][1]);
        line_data[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); ++i)
    {
        value_data = vector<int>(101, 0);
        alpa = wires[i][0]; beta0 = wires[i][1]; 
        answer = min(answer, abs(dfs_maker(alpa) - dfs_maker(beta0))); //2.간선을 하나씩 끊어서 dfs로 분리된 트리의 depth를 확인하고 a,b 트리의 연결된 노드 개수 차가 가장 작은 것을 반환한다.
    }

    return answer;
}
