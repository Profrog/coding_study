import java.util.*;

class Solution {
    
    public boolean chkPrime(String val)
    {
        if(val.equals("")) {return false;}
        long alpa = Long.valueOf(val);
        if (alpa == 1) return false;

        for (long i = 2; i <= (long)(Math.sqrt(alpa)); ++i)
        {
            if (alpa % i == 0)
            {
                return false;
            }
        }

        return true; 
    }
    
    public String makeInt(int n,int k)
    {
        long answer = 0;
        long unit = 1;

        while (n > 0)
        {
            long alpa = n % k;  
            n /= k;
            
            answer += (alpa * unit); 
            unit *= 10;
        }
       
       
       return Long.toString(answer);
    }
    

    public int solution(int n, int k) { 
        int answer = 0;
      
        String n1 = makeInt(n,k); //1.수를 k진수 변환하고 string으로 변형
        
        String[] n11 = n1.split("0"); //2.0사이의 수들을 추출 후, 소수인지 검사
        for(String n110 : n11)
        {
            if(chkPrime(n110)) //3.소수일 경우, 반환값 증가
            {
                ++answer;
            }
        }
        
        return answer;
    }
}
