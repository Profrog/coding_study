#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
const int size0 = 3;
vector<int> check_o_x(3,0);
vector<int> win_concept(6, 0);
int mark_count = 0;
char o_mark = 'O';
char x_mark = 'X';

int check_m(char alpa)
{
    if (alpa == o_mark) return 1; //all collect 3
    else if (alpa == x_mark) return -1; //all collect -3
    return 0;
}

bool count_consist(char alpa)
{
    int check_con = check_o_x[2] - check_o_x[0];
    //cout << alpa << " " << check_con;
    if (alpa == o_mark && check_con == 1) return true; //o_mark를 둘 차례일땐(홀수) o의 개수가 하나 더 많아야 함
    else if (alpa == x_mark && check_con == 0 ) return true; //x_mark를 둘 차례일땐(짝수) o와 x의 개수가 같아야함
    return false;
}

bool win_consist()
{
    int o_win_count = 0;
    int x_win_count = 0;

    for (int i = 0; i < win_concept.size(); ++i)
    {
        if (win_concept[i] == 3)
        {
            if (count_consist(o_mark) == false)
                return false;
            ++o_win_count;
        }

        else if (win_concept[i] == -3)
        {
            if (count_consist(x_mark) == false)
                return false;
            ++x_win_count;
        }

        if (o_win_count * x_win_count)
            return false; 
    }

    return true;
}


int solution(vector<string> board) {
    int index_exch = 0;

    for (int y = 0; y < size0; ++y)
    {
        for (int x = 0; x < size0; ++x)
        {
            index_exch = 1 + check_m(board[y][x]); // o->2, x -> 0

            if (index_exch == 1) continue;
            
            else
            {
                ++check_o_x[index_exch];
                ++mark_count;

                win_concept[x] += check_m(board[y][x]); //x축 방향에 대한 score 기록
                win_concept[y + 3] += check_m(board[y][x]); //y축 방향에 대한 score 기록
            }
        }
    }

    win_concept.push_back(check_m(board[0][2]) + check_m(board[1][1]) + check_m(board[2][0])); // 오른쪽 위방향에 대한 score 기록
    win_concept.push_back(check_m(board[0][0]) + check_m(board[1][1]) + check_m(board[2][2])); // 왼쪽 위방향에 대한 score 기록 

    if (mark_count > 0)
    {
        char alpa = ((mark_count % 2) == 0)? x_mark : o_mark;
        if (count_consist(alpa) == false) //전체 개수에 대한 무결성
            return 0;

        if (win_consist() == false)
            return 0; 
    }

    return 1;
}
