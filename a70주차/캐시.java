import java.util.*;

class Solution {
    
    LinkedList<String> cache = new LinkedList<>();
    
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        for(String city : cities)
        {
            city = city.toLowerCase(); //1. d)에 따라 도시 이름을 소문자 기준으로 변형한다.
            
            if(cache.size() < cacheSize) 
            {//2.0부터 캐시 크기만큼, 캐시에 도시를 추가하고(시간 5), 중복되는 경우(시간 1)를 처리한다.
                boolean chk = true;
                
                for(String cache_data : cache)
                {
                    if(cache_data.equals(city))
                    {
                        cache.addLast(cache_data);
                        cache.remove(cache_data);
                        answer += 1;
                        chk = false;
                        break;
                    }
                }
                
                if(chk)
                {
                    cache.addLast(city);
                    answer += 5;
                }
            }
            
            else
            { //3.캐시 크기부터 도시 리스트 크기 만큼, 캐시에 도시를 반영하고(시간 5), 중복되는 경우(시간 1)를 처리한다.
                boolean chk = true;
                
                for(String cache_data : cache)
                {
                    if(cache_data.equals(city))
                    {
                        cache.addLast(cache_data);
                        cache.remove(cache_data);
                        answer += 1;
                        chk = false;
                        break;
                    }
                }
                
                if(chk)
                {
                    cache.addLast(city);
                    cache.removeFirst();
                    answer += 5;
                }
            }
            
            //System.out.println(city + " " + answer);
        }
        
        return answer;
    }
}
