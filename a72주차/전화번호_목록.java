import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        
        Map<String, Integer> book = new HashMap<>();
        
        Arrays.sort(phone_book, new Comparator<String>() 
                    { //1.문자열 길이가 짧은 순으로 정렬
                        @Override
                        public int compare(String alpa, String beta)
                        {
                            if(alpa.length() > beta.length()) {return 1;}
                            else if(alpa.length() < beta.length()) {return -1;}
                            return 0;
                        }
                        
                    }
                );
        
        for(String phone : phone_book)
        {
            //System.out.println(phone);
            for(int idx = 1; idx < phone.length(); ++idx)
            {
                String data = phone.substring(0,idx);
                
                //3.원소의 이름의 일부가 map 컨테이너에서 발견되면 false, 그런 경우가 없으면 true 반환
                if(book.containsKey(data)){return false;}
                
            }
            
            book.put(phone,1); //2.전화번호 리스트를 조회하며, 원소의 이름을 map 컨테이너에 저장
        }
        
    
        return true;
    }
}
