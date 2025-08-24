import java.util.*;

class Solution {
    
    private int[][] arr0;
    private int[] answer;
    private int box_size = 1;
    private int arr_size;
    
   public void adjustCnt(int x_pos, int y_pos, int box_sized)
   {
      int lt = arr0[x_pos][y_pos];
      int rt = arr0[x_pos + box_sized][y_pos];
      int ld = arr0[x_pos][y_pos + box_sized];
      int rd = arr0[x_pos + box_sized][y_pos + box_sized];
      
      if((lt == rt) && (lt == ld) && (lt == rd) && lt >= 0)
      { //3. 2 ~ 2^n(2^n <= 박스 크기)로 단위를 늘려가며 조회하면서 압축가능한 값을 발견하면 반환 배열의 값을 -3함
          answer[lt] -= 3;   
      }
       
      else
      {
          arr0[x_pos][y_pos] = -1;
      } 
   }
        
    public int[] solution(int[][] arr) {
        
        arr0 = arr;
        answer = new int[2];
        arr_size = arr.length;
       
        for(int idx = 0; idx < 12; ++idx)
        {
            if(box_size > arr_size){break;}
            
            for(int x_pos = 0; x_pos < arr_size; x_pos += box_size)
            { //1.박스의 사이즈/2 만큼이 다음 박스와 현재 박스의 시작점(0,0)의 인덱스 차이와 같음
                for(int y_pos = 0; y_pos < arr_size; y_pos += box_size)
                {
                    if(box_size == 1){++answer[arr[x_pos][y_pos]];} //2. 1*1 일때, 1의 개수와 0의 개수를 반환 배열에 저장
                    else
                    {
                        adjustCnt(x_pos,y_pos,box_size/2); 
                    }
                }
            }
            
            box_size *= 2;
        }
        
        return answer;
    }
}
