import java.util.*;

class Solution {
    
    private int[] chk = new int[10];
    private int maxy = 0;
    
    public int nextMaxy(int loc)
    {
        for(int idx = loc; idx >= 0; idx--) 
        {
            if(chk[idx] > 0){return idx;}        
        }
    
        return -1;
    }
    
    
    public int solution(int[] priorities, int location) {
        
        Queue<Integer> prior = new LinkedList<>();
        int idx = 0;
        for(int pri : priorities)
        {
            maxy = Math.max(maxy, pri);
            chk[pri]++; //1.우선 순위 별 프로세스 개수 컨테이너에 저장
            
            if(idx == location) {prior.add(-pri);} //2.특정 프로세스의 상태 저장을 위해 음수 형태로 저장
            else {prior.add(pri);}
        
            ++idx;
        }
        
        
        idx = 0;
        int answer = 0;
        while(true)
        {
            int data = prior.peek();
        
            if(Math.abs(data) == maxy)
            {
                ++answer;
                if(data < 0){return answer;} //4.특정 프로세스 실행 시 몇 번째인지 반환
                
                chk[data]--;
                maxy = nextMaxy(data); //3.프로세스 개수 컨테이너를 활용하여 현재 가장 높은 우선순위 취득
                prior.poll();
            }
            
            else
            {
                prior.add(prior.poll()); 
            }
        }
    }
}
