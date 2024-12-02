import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        int lidx = citations.length-1;
        
        //1.인용논문 배열은 내림차순으로 정렬한다.
        Arrays.sort(citations); 
        for(int idx = lidx; idx >=0 ; --idx)
        {
            //2.큰 인용수부터 인용수와 인용수 부터 큰 논문 수를 비교하여 작은 값으로 가능한 인용수로 정의한다.
            int n_ans = Math.min(citations[idx],lidx-idx+1);
            //3.가능한 인용수중 가장 큰 것을 반환한다.
            answer = Math.max(answer,n_ans);
        }
        
        return answer;
    
    }
}
