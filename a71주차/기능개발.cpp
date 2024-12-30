import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        if(speeds.length == 0)
        {
            return new int[0];
        }
        
        int[] days = new int[speeds.length];
        
        for(int idx = 0; idx < speeds.length ; idx++)
        { //1.작업 완료에 필요한 일수를 저장하는 컨테이너 생성
            int task = 100 - progresses[idx];
            int share = task / speeds[idx];
            int remind = (task % speeds[idx] > 0)? 1 : 0;
            days[idx] = share + remind;
        }
        
        
        ArrayList<Integer> datacont = new ArrayList<>();
        int data = days[0];
        int cont = 0;
        
        for(int dat : days)
        {
            if(dat <= data)
            { //2.현재작업 일수가 이전작업 일수 보다 작은 경우에는 기능개수 저장 값 증가
                cont++;
            }
            
            else
            { //3.현재작업 일수가 이전작업 일수 보다 큰 경우에는 배포기능 수 저장 컨테이너에 1값 추가
                datacont.add(cont);
                data = dat;
                cont = 1;
            }
        }
        
        datacont.add(cont);
        int[] answer = new int[datacont.size()];
        
        int idx = 0;
        for(int data0 : datacont)
        {
            answer[idx] = data0;
            ++idx;
        }
        
        //4.배포기능 수 저장 컨테이너 반환
        return answer;
    }
}
