#include <string>
#include <vector>
#include <queue>
using namespace std;

int y0;
queue<int> liner; //1.x의 변형값을 가진 원소를 저장하는 리스트
vector<int> check(10000001, 1);


bool check_consistency(int elem) //2.bfs를 통해 변형값이 y랑 일치하는 지 검사하며 변형값의 변형값을 리스트에 갱신
{
    if (elem <= y0 && check[elem])
    {
        check[elem] = 0;
        liner.push(elem);
        return true;
    }

    return false;
}

int bfs_1(int x, int n, int level)
{
    if (liner.empty())
    {
        return -1;
    }

    int alpa = liner.size();
    for (int i = 0; i < alpa; ++i)
    {
        int elem = liner.front();
        liner.pop();

        if (elem == y0) //3.y랑 변형값이 일치하면 현재 bfs의 depth를 반환
        {
            return level;
        }
        check_consistency(elem * 2);
        check_consistency(elem * 3);
        check_consistency(elem + n);
    }

    return bfs_1(x, n, level + 1);
}


int solution(int x, int y, int n) {
    
    y0 = y;
    liner.push(x);
    return bfs_1(x, n, 0);
}
