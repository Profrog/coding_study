#include <string>
#include <vector>
using namespace std;

struct point_state
{
    int child_count = 0;
    int parent_count = 0;
    vector<int> child_c;
};

vector<point_state> check_link(1000001);
vector<int> point_verify(1000001, 0);

int max_point = 0;
vector<int> answer(4,0); //new_dot, dount_graph, stick_graph,eight_graph

int graph_identify(int current)
{
    ++point_verify[current];

    if (check_link[current].child_c.size() >= 2) //8자를 만든다.
    {
        return 3;
    }

    else if (check_link[current].child_c.size() == 0) //스틱을 만든다
    {
        return 2;
    }

    else if (point_verify[current] >= 2) //도넛을 만든다
    {
        return 1;
    }

    else return graph_identify(check_link[current].child_c.back());
}

vector<int> solution(vector<vector<int>> edges) {
    

    for (int i = 0; i < edges.size(); ++i) //간선 관계 개수 구하기
    {
        ++check_link[edges[i][0]].child_count;
        ++check_link[edges[i][1]].parent_count;
        check_link[edges[i][0]].child_c.push_back(edges[i][1]);
        max_point = max(max_point, max(edges[i][0], edges[i][1]));
    }

    for (int i = 1; i <= max_point; ++i) //new_dot 찾기
    {
        if (check_link[i].child_count >= 2 && check_link[i].parent_count == 0)//break를 풀었는데도 이상없음, new_dot은 제대로 찾음
        {
            answer[0] = i;
            break;
        }
    }

    for (int i = 0; i < check_link[answer[0]].child_c.size(); ++i) //그래프 판별하기
    {
        ++answer[graph_identify(check_link[answer[0]].child_c[i])];
    }

    return answer;
}
