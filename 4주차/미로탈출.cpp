#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int startX;
int startY;
queue<vector<int>> list_a;


int solution_1(vector<string>& maps, char target)
{
    if (!list_a.size()) return -1;

    int list_size0 = list_a.size();

    for (int z = 0; z < list_size0; ++z)
    {
        vector<int> alpa = list_a.front();
        list_a.pop();

        if (alpa[0] < 0 || alpa[0] >= maps.size()) continue;
        if (alpa[1] < 0 || alpa[1] >= maps[0].size()) continue;
        if (maps[alpa[0]][alpa[1]] == 'X') continue;
        

        if (maps[alpa[0]][alpa[1]] == target)
        {
            startY = alpa[0];
            startX = alpa[1];
            list_a = queue<vector<int>>();
            return alpa[2];
        }

        maps[alpa[0]][alpa[1]] = 'X';
        list_a.push({ alpa[0] + 1, alpa[1], alpa[2]+1});
        list_a.push({ alpa[0] - 1, alpa[1], alpa[2]+1});

        list_a.push({ alpa[0] , alpa[1] + 1, alpa[2]+1});
        list_a.push({ alpa[0] , alpa[1] - 1, alpa[2]+1});
    }

    return solution_1(maps, target);
}


int solution(vector<string> maps) {

    vector<string> maps2 (maps);

    for (int y = 0; y < maps.size(); ++y)
    {
        for (int x = 0; x < maps[y].size(); ++x)
        {
            if (maps[y][x] == 'S')
            {
                list_a.push({ y,x,0});
                int answer0 = solution_1(maps, 'L'); //레버 찾기
                if (answer0 < 0) return -1;
           
                list_a.push({startY,startX,0});
                int answer1 = solution_1(maps2, 'E'); //탈출구 찾기
                if (answer1 < 0) return -1;
                                                            
                return answer0 + answer1;
            }
        }
    }
}
