import java.util.*;
class Solution {
    
    Map<String,Integer> datamap0;
    int weight0 = 1;
    public int[] solution(String msg) {
        Stack<Integer> answer1 = new Stack();
        
        datamap0 = new HashMap<>();
        for(char a = 'A'; a <= 'Z'; ++a,++weight0)
        { //1.A~Z까지 map 컨테이너에 저장한다(A:1 ~Z:26)
            String alpa = Character.toString(a);
            datamap0.put(alpa,weight0);
        }
        
        StringBuilder data = new StringBuilder();
        answer1.push(0);
        
        for(char a : msg.toCharArray())
        {
            data.append(a);
            String data1 = data.toString();
 
            if(datamap0.containsKey(data1))
            { //2.입력받은 문자열의 부분 문자열을 map에서 찾을 수 있는 경우, 정답 반환용 stack의 마지막 값을 교체한다.
                answer1.pop();
                answer1.push(datamap0.get(data1));
            }
            
            else
            { //3.찾을 수 없는 경우에는 부분 문자열을 map에 추가하고, 부분 문자열의 마지막 문자부터 다시 2.를 진행한다.
                datamap0.put(data1,weight0++);
                data = new StringBuilder();
                data.append(a);
                answer1.push(datamap0.get(Character.toString(a)));
            }
        }
        
        int[] answer = new int[answer1.size()];
        int idx = 0;
        for(int ans : answer1)
        {
            answer[idx++] = ans;
        }
        
        return answer;
    }
}
