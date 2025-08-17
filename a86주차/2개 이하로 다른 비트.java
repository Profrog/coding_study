import java.util.*;

class Solution {
    
    public long getAnswer(long input1)
    {
        long mask = 1;
        long result = 0;
        
        if((input1 & 1) == 0) {return input1 + 1;} //1. input 정수가 짝수일 경우 1을 더하여 바로 반환
        
        while ((input1 & mask) != 0) {  
            //2.비트 마스킹을 통하여 0이 나올 때 까지 인덱스를 1의 자리부터 큰 자리수 방향으로 탐색
            mask <<= 1;  
            if(mask > input1) {break;}
        }
        
        if(mask > input1)
        { 
          //3.마스크가 input 정수보다 커질 경우 1,11 경우에 대한 값을 처리하여 반환  
          return (mask) | (input1 >> 1);
        }
        
        else
        {
            //4. 작을 경우 해당 인덱스의 0을 1로 바꾼 후, 그 이하 자릿수 중 1을 가진것을 0으로 바꾸어 반환
            result = (input1 | mask);
            long mask2 = (mask >> 1);
            while ((result & mask2) == 0 && mask2 > 0) {  
                mask2 >>= 1;  // 1이 나올 때까지 왼쪽으로 이동
            }  

            if(mask2 > 0)
            {
                result &= (~mask2);
            }
        }
    
        return result;
    }
    
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];
        
        for(int i = 0; i < numbers.length; ++i)
        {
            answer[i] = getAnswer(numbers[i]);    
        }
        
        return answer;
    }
}
