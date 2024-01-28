#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> answer;


int dfs_1(vector<string>& maps, int y, int x) //2.dfs 로직 내에서 상하좌우가 붙어있는 영역이 있으면 현재 영역에 더하고 경계면으로 치환
{
    int answer = 0;

    if (y < 0 || y >= maps.size())
        return 0;

    if (x < 0 || x >= maps[y].size())
        return 0;

    if (maps[y][x] == 'X')
        return 0;

    answer += (maps[y][x]- '0');
    maps[y][x] = 'X';

    answer += dfs_1(maps, y + 1, x);
    answer += dfs_1(maps, y - 1, x);
    answer += dfs_1(maps, y, x + 1);
    answer += dfs_1(maps, y, x - 1);

    return answer;
}

vector<int> solution(vector<string> maps) {

    for (int y = 0; y < maps.size(); ++y)
        for (int x = 0; x < maps[y].size(); ++x) //1.영역을 검사하여, 경계면(X)가 아니면 dfs 실행
            if (maps[y][x] != 'X')
                answer.push_back(dfs_1(maps, y, x));

    if (answer.empty()) //3.영역의 종류가 1개 이상이면 오름차순으로 정렬하여 반환하고, 아니면 -1을 가진 리스트 반환
        answer.push_back(-1);

    else
        sort(answer.begin(), answer.end());

    return answer;
}
