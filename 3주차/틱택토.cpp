#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
const int size0 = 3;

int check_b(char alpa)
{
    if (alpa == 'O') return 1;
    else if (alpa == 'X') return -1;
    else return 0;
}

int solution(vector<string> board) {
    int answer = 0;
    
    int _num = 0;
    int x_num[4] = { 0 };
    int y_num[4] = { 0 };
    int check_x_o[2] = {0};
  
    for (int y = 0; y < size0; ++y)
    {
        for (int x = 0; x < size0; ++x)
        {
            int cur = check_b(board[y][x]);
            int cur_in = 3 * y + x;

            y_num[cur_in / 3] += cur;
            x_num[cur_in % 3] += cur;
            _num += cur;
        }
    }
    
    x_num[3] = check_b(board[0][2]) + check_b(board[1][1]) + check_b(board[2][0]);
    y_num[3] = check_b(board[0][0]) + check_b(board[1][1]) + check_b(board[2][2]);
    
    if (_num < 0 || _num > 1) return 0; 
    check_x_o[_num] = 1;

    for (int i = 0; i <= size0; ++i) //가로세로에 대하여
    {       
        if(abs(x_num[i])/3)
        {  
            if(check_x_o[(x_num[i]/3 + 1)/2] == 0) return 0;
        }

        if(abs(y_num[i])/3)
        {
            if(check_x_o[(y_num[i]/3 + 1)/2] == 0) return 0;
        }
    }
    return 1;
}



