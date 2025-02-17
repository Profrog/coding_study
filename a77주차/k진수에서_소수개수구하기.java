import java.util.*;

class Solution {
       
    char[] value = {'0','1','2','3','4','5','6','7','8','9', 'A','B','C','D','E','F'};

    String make_string(int n, int length)
    { //1.참여자 전체가 말할 수(0 ~ t*m)을 진수 변환 후 각 자리를 붙여 string으로 만든다.
        StringBuilder answer = new StringBuilder("0");
        int num = 0; 
        while(answer.length() <= length)
        {
            int num0 = ++num;

            String part_answer = "";
            while(num0 > 0)
            {
                part_answer = value[num0 % n] + part_answer;
                num0 /= n;  
            }

            answer.append(part_answer);
        }

        return answer.toString();
    }
    
    
    public String solution(int n, int t, int m, int p) {
        StringBuilder answer = new StringBuilder();
        String all_case = make_string(n, t*m);
    
        for(int idx = 0; idx < t; ++idx)
        { //2.p번째 문자를 substring에 붙인 뒤 반환한다.
            answer.append(all_case.charAt(idx*m + p -1));
        }

        return answer.toString();
    }
}
