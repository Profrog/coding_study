import java.util.*;

class Solution {
    Map<String,Map<String,ArrayList<Integer>>> data_box0; 
    
    public String[] solution(String[] files) 
    {
        data_box0 = new TreeMap<>();
        
        for(int i = 0; i < files.length; ++i)
        {   
            //1. head와 number을 분리한다.
            StringBuilder temp = new StringBuilder();
            char[] dummy = files[i].toCharArray();
            int idx = 0;
            
            while(!Character.isDigit(dummy[idx]))
            {
                temp.append(Character.toLowerCase(dummy[idx++]));
            }

            StringBuilder temp01 =  new StringBuilder();
            while(idx < dummy.length && Character.isDigit(dummy[idx]))
            {
                temp01.append(dummy[idx++]);
            }
            
            temp01.insert(0,"0".repeat(6-temp01.length()));
           
            String temp1 = temp.toString(); 
           //2. head_number 컨테이너에서 head에 따라 분류하고 그에 대한 컨테이너를 추가하거나, 저장된 컨테이너를 가져온다.
            Map<String,ArrayList<Integer>> temp1_data;
            
            if(data_box0.containsKey(temp1))
            {
                temp1_data = data_box0.get(temp1);
            }
            
            else
            {
                temp1_data = new TreeMap<>();
            }
            
            String temp2 = temp01.toString();
            ArrayList<Integer> temp2_data;
            //3. 2.에서 가져온 컨테이너를 number에 따라 분류하고 그에 대한 컨테이너를 추가하거나, 저장된 컨테이너를 가져온 후, 원본 문자열의 인덱스를 저장한다
            
            if(temp1_data.containsKey(temp2))
            {
                temp2_data = temp1_data.get(temp2);
            }
            
            else
            {
                temp2_data = new ArrayList<>();
            }
            
            temp2_data.add(i);
            temp1_data.put(temp2,temp2_data);
            data_box0.put(temp1,temp1_data);
        }
        
        String[] answer = new String[files.length];
        int idx = 0;
        
        //4.head-number 컨테이너를 조회한 후, 인덱스에 해당하는 원본 문자열을 조회하여 반환 문자열에 넣어 반환한다.
        for(Map<String,ArrayList<Integer>> alpa1 : data_box0.values())
        { 
            for(ArrayList<Integer> alpa : alpa1.values())
            {
                for(int alpa0 : alpa)
                {
                    answer[idx++] = files[alpa0];   
                }
            }
        }
        
        return answer;
    }
}
