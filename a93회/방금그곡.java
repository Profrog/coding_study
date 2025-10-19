import java.util.*;

class Solution {
    
    public String convey(String alpa)
    {
        //패턴 변형기 : 주어진 패턴에서 C#, B# 등은 관리가 힘드므로 소문자로 변형해서 저장함
        StringBuilder answer = new StringBuilder();    
        for(char a : alpa.toCharArray())
        {
            if(a == '#')
            {
                int idx = answe#r.length() -1;
                answer.setCharAt(idx,  Character.toLowerCase(answer.charAt(idx)));
            }
            
            else
            {
                answer.append(a);
            }
        }
        
        return answer.toString();
    }
    
    public int intTime(String hour, String minute)
    {
        return Integer.valueOf(hour)*60 + Integer.valueOf(minute);
    }
    
    public String solution(String m, String[] musicinfos) {
        String answer = "(None)";
        int musiclen = 0;
       
        m = convey(m);
        CharSequence m1 = m.subSequence(0,m.length());
        
        for(String musicinfo : musicinfos)
        {
            String[] music = musicinfo.split(",");
            
            String[] time0 = music[0].split(":");
            String[] time1 = music[1].split(":");
            int interval = intTime(time1[0],time1[1]) - intTime(time0[0],time0[1]);
            
            StringBuilder value = new StringBuilder();
            
            music[3] = convey(music[3]);
            for(int idx = 0; idx < interval; ++idx)
            { //musicinfo를 파싱하여 재생 시간을 고려하여 곡당 전체 패턴을 구함
                int idx1 = idx % music[3].length();
                value.append(music[3].charAt(idx1));
            }
            
           
            if(value.toString().contains(m1))
            { //곡의 전체 패턴에서 m이 발견되면 반환값의 후보가 되며, 여러 후보가 생길때는 조건에 따라 우선이 높은 후보를 반환
                if(musiclen < interval)
                {
                    answer = music[2];
                    musiclen = interval;
                }
            }
        }
        
        return answer;
    }
}
