import java.util.*;

class Solution {
    
    public String[] msg0 = {"님이 들어왔습니다.","님이 나갔습니다."};
    public Map<String, String> db0;
    public ArrayList<String> output0;
    
    public void enterId(String id, String name)
    { //2. Enter일 경우, 임시 db에 id별 이름을 넣고 로그에 id와 들어옴 이벤트를 추가한다.
        db0.put(id,name);
        output0.add(id + "_0");
    }
    
    public void changeId(String id, String name)
    { //3. Chagne일 경우, 임시 db의 id별 이름을 수정한다.
        db0.put(id,name);
    }
    
    public void leaveId(String id)
    { //4. Leave일 경우, 로그에 id와 나감 이벤트를 추가한다.
        output0.add(id + "_1");
    }
    
    public void splitRecord(String[] record)
    { //1.record를 파싱하여 Enter, Change, Leave에 따라 액션을 분리한다.
        for(String reco : record)
        {
            String[] recos = reco.split(" ");
         
            if(recos[0].equals("Enter"))
            {
                enterId(recos[1],recos[2]);
            }
            
            else if(recos[0].equals("Change"))
            {
                changeId(recos[1],recos[2]);
            }
            
            else if(recos[0].equals("Leave"))
            {
               leaveId(recos[1]);
            }
        }
    }
    
    public String[] solution(String[] record) {
        ArrayList<String> answer;
        answer = new ArrayList<>();
        output0 = new ArrayList<>();
        db0 = new HashMap<>();
        
        splitRecord(record); 
        
        for(String output: output0)
        {
            String[] out1 = output.split("_");
            String data = db0.get(out1[0]) + msg0[Integer.parseInt(out1[1])];
            answer.add(data);
        }
        
        return answer.toArray(new String[0]);
    }
}
