import java.util.*;
import java.util.Collection.*;
import java.util.stream.*;

class Solution {
    public int[] solution(String s) {
        
        int[] chk = new int[100001];
        s = s.substring(1, s.length() -2); 
        
        String[] slide = s.split("},"); //1.String 형태의 튜플을 배열 집합 형태로 분리한다.
        Arrays.sort(slide, new Comparator<String>()
                    {
                        @Override
                        public int compare(String a, String b)
                        {
                            if(a.length() > b.length()) return 1;
                            else return -1;
                        }
                    }
                   ); //2.집합을 길이가 짧은 순으로 정렬한다.
        
        
        ArrayList<Integer> datalist = new ArrayList<>();
        int idx2 = 0;
        
        for(String sli : slide)
        {
            //System.out.println(sli);
            sli = sli.substring(1);
            String[] sl = sli.split(",");
            
            for(String s0 : sl)
            {
                int idx = Integer.valueOf(s0);
                if(chk[idx] > -1) //3.튜플의 원소는 중복되지 않으므로, 해당 원소가 이전 작은 집합에 포함되지 않은 원소일 경우, 원본 튜플에 원소를 추가한다.
                {
                    datalist.add(idx);
                    chk[idx] = -1;
                }
            }
        }
        
 
        int[] answer = datalist.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}
