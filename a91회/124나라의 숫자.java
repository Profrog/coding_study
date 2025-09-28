import java.util.*;

class Solution {
    
    StringBuilder answer0;

    public char return124(int n)
    { //2.  0 -> 1 =, 1- >2, 2 -> 4에 맞게 값을 변형시켜 Stringbuilder에 저장
        if(n == 0) return '1';
        else if(n == 1) return '2';
        else return '4';
    }
    
    public String solution(int n) {
        answer0 = new StringBuilder();
        
        while(n > 0)
        { //1. 3진법으로 변환 하듯이 몫이 0이 될 때 가지, 3으로 나누어줌
            n -= 1;
            int n1 = n % 3;
            n = n / 3 ;
            answer0.append(return124(n1));
        }
        
        //3. Stringbuilder의 값을 reverse 시켜 반환
        String answer = answer0.reverse().toString();
        return answer;
    }
}
