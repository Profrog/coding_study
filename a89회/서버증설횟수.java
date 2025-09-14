import java.util.*;
class Solution {
    private int answer0 = 0;
    private int[] time_table0;
    private int time_size0 = 24; 

    public int chkServer(int server_cnt, int cur_user, int server)
    { 
        
        if(cur_user < (server_cnt + 1)* server){return 0;}
        
        else
        {
            int need_server = (int)(Math.floor(cur_user/server));
            return need_server - server_cnt;
        }
    }
    
    public int solution(int[] players, int m, int k) {
        //1. 시간 별 서버 개수를 관리하는 배열을 하나 생성
        time_table0 = new int[time_size0]; 
        
        for(int i = 0; i < time_size0; ++i)
        {
            //2. 현재 관리 중 서버 개수가 사용자 수에 비해 부족한 경우 그 필요 개수를 계산하는 로직 구성
            int need_server = chkServer(time_table0[i],players[i],m);
            
            if(need_server > 0) 
            { //3. 필요 개수만큼 반환용 서버 증설 개수의 총합에 넣고, [현재 시간, 현재 시간+K] 만큼 서버 관리 배열의 값을 필요 개수만큼 증가
                for(int j = i; j < (i + k) && j < time_size0; ++j)
                {
                    time_table0[j] += need_server;
                }
                answer0 += need_server;    
            }
        }
        
        return answer0;
    }
}
