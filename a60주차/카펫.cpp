#include <string>
#include <vector>

using namespace std;
vector<int> answer;
int b_l;

int X = 0;
int Y = 0;


void findSize(int brown0, int yellow0)
{
    int w_l = (brown0 + 4) / 2; //1.갈색 카펫의 블록 수는 (카펫 가로 길이 + 카펫 세로 길이) * 2 - 4이다.
    int max_l = w_l/2; //2.따라서 c.에 따라 카펫 최대 세로 길이는 (갈색 카펫 + 4)/4 이다.
    
    for (int y = 1; y <= max_l; y++)
    {
        int x = w_l - y;

        if (x * y == brown0 + yellow0) //3.1 ~ 카펫 최대 세로길이를 완전 탐색으로 탐색하며, 세로 * 가로 값이 갈색 블록 + 노란색 블록인 값을 찾아서 반환한다.
        {
            answer.push_back(x);
            answer.push_back(y);
            break;
        }
    }
}


vector<int> solution(int brown, int yellow) {

    findSize(brown, yellow);
    return answer;
}

