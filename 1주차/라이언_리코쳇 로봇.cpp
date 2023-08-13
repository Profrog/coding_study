#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int x_board;
int y_board;
vector<vector<int>> arrow0 = { {1,0}, {-1,0}, {0,1}, {0,-1} }; //로봇이 움직일 수 있는 방향
vector<vector<int>> board0; //방문기록 체크용
queue<vector<int>> bfs; //경로 queue

//로봇이 경계면에 위치한지, 안쪽에 위치한 지 점검
int in_range(int score, int alpa, int beta, int arrow)  
{
    if ((score < alpa) || (score >= beta)) //board 사이즈 바깥으로 나갔음을 의미
        return 0;

    else if ((score == alpa) || (score == beta - 1)) //board 사이즈 경계면에 있음을 의미
    {
        if (arrow)
            return 1; //로봇이 움직은 방향에서 경계면을 맞았음을 의미

        else
            return 3; //원래 있던 위치가 경계면임을 의미
    }
        
    else return 3;
}

int board_check(vector<string>& board) //D나 경계면을 만났을때, 90도 방향으로 방향 전환 및 answer 증가
{
    int len_b = bfs.size();
    for (int i = 0; i < len_b; ++i)
    {
        
        vector<int> alpa = bfs.front(); //방문한 노드는 큐에서 제거
        bfs.pop();

        while (true)
        {
            int check_in = in_range(alpa[0], 0, x_board, alpa[3]) * in_range(alpa[1], 0, y_board, alpa[4]); //경계면에 있는 지, 어떤 형태로 있는 지 점검
    
            if (check_in == 0)
                goto exit;
         
            else if ((check_in < 4) || (board[alpa[0]][alpa[1]] == 'D'))
            {
                if (board[alpa[0]][alpa[1]] == 'G') //경계면이면서 G를 방문시 종료
                    return alpa[2];

                else if(board[alpa[0]][alpa[1]] == 'D') //D이전의 INDEX가 G일시 종료
                { 
                    alpa[0] -= alpa[3];
                    alpa[1] -= alpa[4];
                    if (board[alpa[0]][alpa[1]] == 'G')
                        return alpa[2];
                }

                break;
            }

            else
            {
                alpa[0] += alpa[3];
                alpa[1] += alpa[4];
            }
        }

        if (board0[alpa[0]][alpa[1]] == 0) //현재 진행방향에서 90도에 해당하는 방향의 경로 추가
            for (int k = 0; k < arrow0.size(); ++k)
            {
                if (alpa[3] * arrow0[k][0] + alpa[4] * arrow0[k][1] != 0)
                    continue;

                vector<int> line = { alpa[0] + arrow0[k][0], alpa[1] + arrow0[k][1], alpa[2] + 1, arrow0[k][0],arrow0[k][1] };
                bfs.push(line);
            }

        board0[alpa[0]][alpa[1]] = 1;
        exit:;
    }
   
    if (bfs.size())
        return board_check(board);

    else return -1;
}

int solution(vector<string> board) {

    x_board = board.size();
    y_board = board[0].size();
    board0.assign(x_board, vector<int>(y_board,0));

    for (int i = 0; i < x_board; ++i)
    {
        for (int j = 0; j < y_board; ++j)
        {
            if (board[i][j] == 'R') //R 인덱스를 찾으면 방향전환
            {
                for (int k = 0; k < arrow0.size(); ++k)
                {
                    board0[i][j] = 1;
                    vector<int> alpa = { i + arrow0[k][0], j + arrow0[k][1], 1 , arrow0[k][0], arrow0[k][1] };
                    bfs.push(alpa);
                }
                return board_check(board);
            }
        }
    }
}

vector<string> alpa = {".D.R", "...D", "..G.", "..D."};

int main(void)
{
    cout << solution(alpa) << "\n";
    return 0;
}
