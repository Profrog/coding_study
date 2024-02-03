#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> line_list;
vector<int> mapping_list;

int fill_map(int x0, int y0, vector<vector<int>>& land)
{
    if ((x0 < 0) || (x0 >= land[0].size()))
        return 0;

    if ((y0 < 0) || (y0 >= land.size()))
        return 0;

    if (land[y0][x0] == 0)
        return 0;

    land[y0][x0] = 0;

    mapping_list.push_back(x0);
    return 1 + fill_map(x0 + 1, y0, land) + fill_map(x0, y0 + 1, land) + fill_map(x0 - 1, y0, land) + fill_map(x0, y0 - 1, land);
}


void fill_line(int x0, int y0, vector<vector<int>>& land)
{
    mapping_list = vector<int>();
    int alpa = fill_map(x0, y0, land);
    int index_1 = -1;
    sort(mapping_list.begin(), mapping_list.end());
    for (int i = 0; i < mapping_list.size(); ++i) //2.x좌표 리스트에서 석유 덩어리의 크기를 닿아 있는 x좌표에 더해준다. (중복 좌표는 배제)
    {
        if (mapping_list[i] != index_1) 
        {
            line_list[mapping_list[i]] += alpa;
            index_1 = mapping_list[i];
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    line_list = vector<int>((int)(land[0].size()), 0);


    for (int y = 0; y < land.size(); ++y)
    {
        for (int x = 0; x < land[0].size(); ++x)
        {
            if (land[y][x]) //1.x,y 좌표를 오름차순으로 탐색하면서 석유(1)이 발견되면 dfs를 통해 연결된 모든 석유를 시추하고 닿아 있는 x좌표를 추출하여 x좌표 리스트로 관리한다.
                fill_line(x, y, land);
        }
    }

    sort(line_list.begin(), line_list.end(), greater<int>()); //3.내림차순으로 정렬하여 첫 번째 값을 반환한다.
    return line_list.front();
}
