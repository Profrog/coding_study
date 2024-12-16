import java.util.*;


class Solution {
    
    public int solution(String[][] clothes) {
        //1.의상의 종류를 map 컨테이너로 관리하며, 종류 별 의상 갯수 값을 저장한다.
        Map<String,Integer> closet = new HashMap<>();
        
        for(String[] cloth : clothes)
        {
            //2.입지 않는 경우의 수를 고려하여 의상 갯수 값은 +1로 관리한다.
            if(closet.containsKey(cloth[1]))
            {
                closet.put(cloth[1],closet.get(cloth[1]) + 1);
            }
            
            else
            {
                closet.put(cloth[1],1);
            }
        }
        
        int answer = 1;
        for(String key : closet.keySet())
        {
            answer = answer * (closet.get(key) + 1);
        }
        
        //3,b) 따라 전부 잆지 않은 경우의 수를 고려하여 1 빼준다.
        return answer-1;
    }
}
