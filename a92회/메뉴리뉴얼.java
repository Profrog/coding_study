import java.util.*;

class Solution {
    
    private int[] chk_course = new int[11];
    private int[] chk_coursize = new int[11];
    
    private Map<String, Integer> combins = new HashMap<>();
    
    public String makeName(int value, char[] food)
    {
        StringBuilder ans = new StringBuilder();
        int count1 = 0;
        int[] chk_count = new int[food.length];
        
        int idx = 0;
        while(value > 0)
        {
            int remind = value % 2;
            
            if(remind > 0)
            {
                chk_count[idx] = 1;
                count1++;
            }
            
            value /= 2;
            ++idx;
        }
        
        if(chk_course[count1] > 0) //지정된 개수 이상의 조합일 경우에만 추가
        {
            for(idx = 0 ; idx < food.length; ++idx)
            {
                if(chk_count[idx] > 0)
                {
                    ans.append(food[idx]);
                }
            }
            
                    
            return ans.toString();
        }
        
        
        return null;
    }
    
    public String[] solution(String[] orders, int[] course) {
        
        //1. 손님 별 입력받은 메뉴의 구성요소를 분리하고 경우의 수를 나열
        for(int cour : course)
        { //구성 요소의 개수 정의
            chk_course[cour] = 1;
        }
        
        for(String order : orders)
        { // 손님 별 구성요소 분리
            char[] ordes = order.toCharArray();
            Arrays.sort(ordes);
            
            for(int idx = 0; idx < Math.pow(2,order.length()); ++idx)
            { // 구성 요소별 경우의 수 나열
                
                //2. 경우의 수가 코스 요리 구성 개수를 만족하는 경우 코스 요리 후보로 반환
                String s = makeName(idx, ordes);
                
                if(s != null)
                {
                    int sl = s.length();
                    
                    // 해당 코스가 몇 명의 손님에게 받았는 지 기록
                    if(combins.containsKey(s))
                    {
                        int cg = combins.get(s);
                        combins.put(s,cg + 1);
                        chk_coursize[sl] = Math.max
                            (cg + 1,chk_coursize[sl]);   
                    }

                    else
                    {
                        combins.put(s,1);
                        chk_coursize[sl] = Math.max(1,chk_coursize[sl]);
                    }
                }
            }
        }
        
        //3. 2명이상에게 주문된 코스 요리들을 배열로 묶어서 반환
        ArrayList<String> answer0 = new ArrayList<>();
        Object[] c_keys = combins.keySet().toArray();
        Arrays.sort(c_keys);
        
        for(Object c_key : c_keys)
        {
            String c_k = c_key.toString();
   
            if(combins.get(c_k) >= Math.max(2,chk_coursize[c_k.length()]))
            {
                answer0.add(c_k);
            }
        }
        

        String[] answer = answer0.toArray(new String[0]);
        return answer;
    }
}
