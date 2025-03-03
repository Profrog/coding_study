import java.util.*;

class Solution {
    
    PriorityQueue<Integer> scov0;
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        scov0 = new PriorityQueue<>();
        
        for(int scov : scoville)
        {//1. 모든 스코빌 지수 데이터를 최소힙에 넣는다.
            scov0.add(scov);
        }

        while(scov0.size() > 0)
        { //3.최소힙의 최솟값이 k이상이거나 더 이상 값을 poll할 수 없을 때 까지 반복한다.
           int data1 = scov0.poll();
           if(data1 >= K) {return answer;}
           else if(scov0.size() == 0){return -1;}  
           else
           { //2.최소값과 그 다음 값을 poll하여, 섞기를 진행하고 최소힙에 넣어준다 
            int data2 = scov0.poll();
            scov0.add(data1 + data2*2);
            ++answer;
           }
        }
        
        return answer;
    }
}
