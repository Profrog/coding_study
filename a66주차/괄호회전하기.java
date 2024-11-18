import java.util.*;

class Solution {
    
    public int calcul(String s)
    {
        Map<Character, Integer> sign_ = new HashMap<>();         
        Stack<Character> q = new Stack<>();
        sign_.put('(',0);
        sign_.put('{',0);
        sign_.put('[',0);
        
        for(char alpa : s.toCharArray())
        {
            if(alpa == '(' || alpa == '[' || alpa == '{') 
            {//1.여는 괄호( '(', '{', '[')가 나왔을 때, 카운팅 값을 증가한다.
                q.push(alpa);
                sign_.put(alpa,sign_.get(alpa)+1);
            }
            
            else
            {
                char trg = '@';
                if(alpa == ')') {trg = '(';}
                else if(alpa == '}') {trg = '{';}
                else if(alpa == ']') {trg = '[';}
                int v = sign_.get(trg);
                sign_.put(trg, v-1); 
                //2. 닫는 괄호(')', '}', ']')가 나왔을 때, 카운팅 값을 감소한다.
                
                if(sign_.get(trg) < 0 || q.peek() != trg)
                {//3. 닫는 괄호(')', '}', ']')가 나왔을 때, 여는 괄호가 카운팅 되지 않았다면 0을 반환한다.
                    return 0;
                }

                q.pop();
            }
        }
        
        if(sign_.get('(') == 0 && sign_.get('{') == 0 && sign_.get('[') == 0)
        {
            return 1;
        }
        
        return 0;
    }
    
    public int solution(String s) {
        
        int answer = 0;
        
        StringBuilder s0 = new StringBuilder(s);
        int caseo = s.length();

        for(int cas = 0 ; cas < caseo; ++cas)
        {
            //4.모든 괄호 패턴에 대하여 올바른 괄호를 판단하여 그 개수의 합을 반환한다.
            answer += calcul(s0.toString());
            s0.append(s0.charAt(0));
            s0.deleteCharAt(0);
        }

        return answer;
    }
}
