import java.util.*;

class Solution {

    int x_board;
    int y_board;

    int[][] arrows = {
        {
            1,
            0
        },
        {
           -1,
            0
        },
        {
            0,
            1
        },
        {
            0,
            -1
        }
    };
    Queue < List < Integer >> bfs = new LinkedList < > ();
    int[][] board0;


    public int in_range(int score, int alpa, int beta, int arrow) {
        if ((score < alpa) || (score >= beta)) //board 사이즈 바깥으로 나갔음을 의미
            return 0;

        else if ((score == alpa) || (score == beta - 1)) //board 사이즈 경계면에 있음을 의미
        {
            if (arrow != 0)
                return 1; //로봇이 움직은 방향에서 경계면을 맞았음을 의미

            else
                return 3; //원래 있던 위치가 경계면임을 의미
        } else return 3;
    }

    public int board_check(String[] board) {
        int len_b = bfs.size();
        boolean pass0 = true;

        for (int idx = 0;
            (idx < len_b) && pass0; ++idx) {
            List < Integer > alpa = bfs.poll();


            while (true) {
                int check_in = in_range(alpa.get(0), 0, x_board, alpa.get(3)) * in_range(alpa.get(1), 0, y_board, alpa.get(4)); //경계면에 있는 지, 어떤 형태로 있는 지 점검

                if (check_in == 0) {
                    if (bfs.size() > 0) {
                        return board_check(board);
                    } else {
                        return -1;
                    }
                } else if ((check_in < 4) || (board[alpa.get(0)].charAt(alpa.get(1)) == 'D')) {
                    if (board[alpa.get(0)].charAt(alpa.get(1)) == 'G') //경계면이면서 G를 방문시 종료
                        return alpa.get(2);

                    else if (board[alpa.get(0)].charAt(alpa.get(1)) == 'D') //D이전의 INDEX가 G일시 종료
                    {
                        alpa.set(0, alpa.get(0) - alpa.get(3));
                        alpa.set(1, alpa.get(1) - alpa.get(4));
                        if (board[alpa.get(0)].charAt(alpa.get(1)) == 'G')
                            return alpa.get(2);
                    }

                    break;
                } else {
                    alpa.set(0, alpa.get(0) + alpa.get(3));
                    alpa.set(1, alpa.get(1) + alpa.get(4));
                }
            }

            if (board0[alpa.get(0)][alpa.get(1)] == 0) //현재 진행방향에서 90도에 해당하는 방향의 경로 추가
                for (int[] arrow: arrows) {
                    if (alpa.get(3) * arrow[0] + alpa.get(4) * arrow[1] != 0)
                        continue;


                    List < Integer > line = new ArrayList < > ();
                    line.add(alpa.get(0) + arrow[0]);
                    line.add(alpa.get(1) + arrow[1]);
                    line.add(alpa.get(2) + 1);
                    line.add(arrow[0]);
                    line.add(arrow[1]);

                    bfs.add(line);
                }

            board0[alpa.get(0)][alpa.get(1)] = 1;

        }
        if (bfs.size() > 0) {
            return board_check(board);
        } else {
            return -1;
        }
    }

    public int solution(String[] board) {
        x_board = board.length;
        y_board = board[0].length();
        board0 = new int[x_board][y_board];

        for (int idx = 0; idx < x_board; ++idx) {
            for (int jdx = 0; jdx < y_board; ++jdx) {
                if (board[idx].charAt(jdx) == 'R') {
                    for (int[] arrow: arrows) {
                        board0[idx][jdx] = 1;
                        List < Integer > alpa = new ArrayList < > ();
                        alpa.add(idx + arrow[0]);
                        alpa.add(jdx + arrow[1]);
                        alpa.add(1);
                        alpa.add(arrow[0]);
                        alpa.add(arrow[1]);
                        bfs.add(alpa);
                    }

                    return board_check(board);
                }
            }
        }

        int answer = 0;
        return answer;
    }
}
