#include <string>
#include <vector>
#include <queue>
using namespace std;


queue<int> liner;
vector<int> check(1000001, 1);

int solution_1(int x,int n, int level)
{
    if (liner.empty())
    {
        return -1;
    }

    int alpa = liner.size();
    for(int i = 0; i < alpa; ++i)
    {
        int elem = liner.front();
        liner.pop();

        if (elem == x)
        {
            return level;
        }

        if (elem < 1)
            continue;

        if (elem % 2 == 0 && check[elem / 2])
        {
            check[elem / 2] = 0;
            liner.push(elem / 2);
        }

        if (elem % 3 == 0 && check[elem / 3])
        {
            check[elem / 3] = 0;
            liner.push(elem / 3);
        }

        if (elem - n > 0 && check[elem-n])
        {
            check[elem - n] = 0;
            liner.push(elem - n);
        }
    }

    return solution_1(x, n, level + 1);
}


int solution(int x, int y, int n) {
    int answer = 0;

    liner.push(y);
    return solution_1(x,n,0);
}
