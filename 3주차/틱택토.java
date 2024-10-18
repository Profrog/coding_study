import java.util.*;

class Solution {
    
 
    int[] check_o_x = new int[3];
    ArrayList<Integer> win_concept = new ArrayList<>();
    int mark_count = 0;
    char o_mark = 'O';
    char x_mark = 'X';
        
    
    public int check_m(char alpa)
    {
        if (alpa == o_mark) {return 1;} //all collect 3
        else if (alpa == x_mark) {return -1;} //all collect -3
        else {return 0;}
    }
    
    public boolean count_consist(char alpa)
    {
        int check_con = check_o_x[2] - check_o_x[0];
        if (alpa == o_mark && check_con == 1) {return true;} //o_mark를 둘 차례일땐(홀수) o의 개수가 하나 더 많아야 함
        else if (alpa == x_mark && check_con == 0 ) {return true;} //x_mark를 둘 차례일땐(짝수) o와 x의 개수가 같아야함
        else {return false;}
    }
    
    public boolean win_consist()
    {
        int o_win_count = 0;
        int x_win_count = 0;

        for (int i = 0; i < win_concept.size(); ++i)
        {
            if (win_concept.get(i) == 3)
            {
                if (count_consist(o_mark) == false)
                    return false;
                ++o_win_count;
            }

            else if (win_concept.get(i) == -3)
            {
                if (count_consist(x_mark) == false)
                    return false;
                ++x_win_count;
            }

            if ((o_win_count * x_win_count) != 0)
                return false; 
        }

        return true;
    }
    
    
    public int solution(String[] board) {
	int index_each = 0;        

        int[] count = new int[6];
        for(int count0 : count)
        {
            win_concept.add(0);     
        }
    
        
        int x = 0;
        for(String brd : board)
        {
            int y = 0;
            for(char brd_0 : brd.toCharArray())
            {
                index_each  = 1 + check_m(brd_0);
                
                if(index_each != 1)
                {
                    ++check_o_x[index_each];
                    ++mark_count;

                    win_concept.set(x,win_concept.get(x) + check_m(brd_0)); //x축 방향에 대한 score 기록
                    win_concept.set(y+3,win_concept.get(y + 3) + check_m(brd_0)); //y축 방향에 대한 score 기록
                }

		++y;
            }
            ++x;
        }
        

    win_concept.add(check_m(board[0].charAt(2)) + check_m(board[1].charAt(1)) + check_m(board[2].charAt(0))); // 오른쪽 위방향에 대한 score 기록
    win_concept.add(check_m(board[0].charAt(0)) + check_m(board[1].charAt(1)) + check_m(board[2].charAt(2))); // 왼쪽 위방향에 대한 score 기록 

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
}
