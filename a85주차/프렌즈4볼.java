import java.util.*;

class Solution {
    int row, col;
    char[][] block_map0;
    char space0 = ' ';

    public int solution(int m, int n, String[] board) {
        row = m;
        col = n;
        block_map0 = new char[m][n];
        int totalRemoved = 0;

        for (int i = 0; i < m; i++) {
            block_map0[i] = board[i].toCharArray();
        }

    
        while (true) { //4. 이번 턴에 삭제한 블록 개수가 더 이상 없을때 까지 1~3을 반복
            boolean[][] status = new boolean[row][col];
            int removedThisTurn = 0;

            //1. 블록판을 조회하면서 2x2 모양꼴을 찾되 b와 같은 경우에 중복으로 체크되는 것을 방지하기 위해 status에 발견 상태를 기록한다.
            for (int x = 0; x < row - 1; x++) {
                for (int y = 0; y < col - 1; y++) {
                    char c = block_map0[x][y];
                    if (c == space0) continue;
                    if (block_map0[x][y + 1] == c &&
                        block_map0[x + 1][y] == c &&
                        block_map0[x + 1][y + 1] == c) {
                        status[x][y] = true;
                        status[x][y + 1] = true;
                        status[x + 1][y] = true;
                        status[x + 1][y + 1] = true;
                    }
                }
            }

            // 2. status에 기록된 발견 상태를 기반으로 현재 블록맵의 삭제 status를 반영하고 이번 턴에 삭제한 블록 개수 만큼 반환값을 올린다
            for (int x = 0; x < row; x++) {
                for (int y = 0; y < col; y++) {
                    if (status[x][y]) {
                        block_map0[x][y] = space0;
                        removedThisTurn++;
                    }
                }
            }

            if (removedThisTurn == 0) break;  
            else
            {
                totalRemoved += removedThisTurn;

                // 3. 블록맵의 전체를 열 단위로 조회하면서 space가 있는 인덱스에 더 앞의 인덱스의 데이터를 채운다.
                for (int y = 0; y < col; y++) {
                    int emptyRow = row - 1;
                    for (int x = row - 1; x >= 0; x--) {
                        if (block_map0[x][y] != space0) {
                            char temp = block_map0[x][y];
                            block_map0[x][y] = space0;
                            block_map0[emptyRow][y] = temp;
                            emptyRow--;
                        }
                    }
                }
            }
        }

        return totalRemoved;
    }
}
