#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> answer;

int con_num(char a)
{
    return a - '0';
}

int solution_1(vector<string>& maps, int y , int x)
{
    int answer = 0;

    if(y < 0 || y >= maps.size())
     return 0;

    if(x < 0 || x >= maps[y].size())
     return 0;

    if(maps[y][x] == 'X')
        return 0;
    
    answer += con_num(maps[y][x]);
    maps[y][x] = 'X';
    
    answer += solution_1(maps,y+1,x);
    answer += solution_1(maps,y-1,x);
    answer += solution_1(maps,y,x+1);
    answer += solution_1(maps,y,x-1);

    return answer;
}

vector<int> solution(vector<string> maps) {

    for(int y = 0 ; y < maps.size() ; ++y)
        for(int x = 0 ; x < maps[y].size() ; ++x)
            if(maps[y][x] != 'X')
               answer.push_back(solution_1(maps, y, x));  

    if(answer.empty())
     answer.push_back(-1);

    else
     sort(answer.begin(), answer.end()); 

    return answer;
}
