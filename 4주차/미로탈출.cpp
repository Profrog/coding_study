#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
queue<vector<int>> list_a11;
queue<vector<int>> list_a12;

int bfs_1(vector<string>& maps, char target, queue<vector<int>>& list_a)
{
    if (!list_a.size()) return -1; 

    int list_size0 = list_a.size();

    for (int z = 0; z < list_size0; ++z)
    {
        vector<int> alpa = list_a.front();//첫 좌표가지기
        list_a.pop();

        if (alpa[0] < 0 || alpa[0] >= maps.size()) continue;
        if (alpa[1] < 0 || alpa[1] >= maps[0].size()) continue;
        if (maps[alpa[0]][alpa[1]] == 'X') continue;

        if (maps[alpa[0]][alpa[1]] == target)
        {
            return alpa[2];
        }

        maps[alpa[0]][alpa[1]] = 'X';
        list_a.push({ alpa[0] + 1, alpa[1], alpa[2] + 1 });
        list_a.push({ alpa[0] - 1, alpa[1], alpa[2] + 1 });
        list_a.push({ alpa[0] , alpa[1] + 1, alpa[2] + 1 });
        list_a.push({ alpa[0] , alpa[1] - 1, alpa[2] + 1 });
    }

    return bfs_1(maps, target,list_a);
}


int solution(vector<string> maps) {

    vector<string> maps2(maps);
    int answer0 = -1;
    int answer1 = -1;

    for (int y = 0; y < maps.size(); ++y)
    {
        for (int x = 0; x < maps[y].size(); ++x)
        {
            if (maps[y][x] == 'S')
            {
                list_a11.push({ y,x,0 });
                answer0 = bfs_1(maps, 'L', list_a11); //1.1 S에서 L로 가는 최소 시간 1.1
                if (answer0 < 0) return -1; //2.두 개의 루트 중 하나라도 에러가 나면 -1를 return
            }

            else if (maps[y][x] == 'L')
            {
                list_a12.push({ y,x,0 });
                answer1 = bfs_1(maps2, 'E', list_a12); //1.2 L에서 E로 가는 최소 시간 1.2
                if (answer1 < 0) return -1; //2.두 개의 루트 중 하나라도 에러가 나면 -1를 return
            }
        }
    }
    
    return answer0 + answer1;
}
