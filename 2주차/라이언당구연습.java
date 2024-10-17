import java.util.*;

class Solution {
    
    int x_m;
    int y_n;
    int ax;
    int ay;
    
    public int calcul(int bx, int by)
    {
        int[] answer0 = new int[4];
        int answer00 = 10000000;
        
        answer0[0] = (int)Math.pow(bx + ax,2) + (int)Math.pow(by - ay,2);
        answer0[1] = (int)Math.pow(bx - (2*x_m -ax),2) + (int)Math.pow(by - ay,2);
        answer0[2] = (int)Math.pow(bx - ax,2) + (int)Math.pow(by + ay,2);
        answer0[3] = (int)Math.pow(bx - ax,2) + (int)Math.pow(by - (2 * y_n - ay),2);
        
        if(ay == by)
        {
            if(ax > bx)
            {
                answer0[0] = answer00;
            }
            
            else
            {
                answer0[1] = answer00;
            }
        }
        
        if(ax == bx)
        {
            if(ay > by)
            {
                answer0[2] = answer00;
            }
            
            else
            {
                answer0[3] = answer00;
            }
        }
        
        return Math.min(Math.min(answer0[0], answer0[1]) ,Math.min(answer0[2], answer0[3]));
    }
    
    public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
        x_m = m;
        y_n = n;
        ax = startX;
        ay = startY;
        
        int[] answer = new int[balls.length];
        int idx = 0;
    
        for(int[] ball : balls)
        {
            answer[idx] = calcul(ball[0],ball[1]);  
            ++idx;
        }

        return answer;
    }
}
