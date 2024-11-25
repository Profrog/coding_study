import java.util.*;

class Solution {
    public int[][] solution(int[][] arr1, int[][] arr2) {
        
        //1.첫번째 행렬의 열 크기, 두번째 행렬의 행 크기를 가진 배열을 생성한다.
        int[][] answer = new int[arr1.length][arr2[0].length];
          
        for(int i0 = 0 ; i0 < arr1.length; ++i0)
        {
            for(int i1 = 0 ; i1 < arr1[i0].length; ++i1)
            {
                for(int j1  = 0; j1 < arr2[0].length; ++j1)
                { //2. 첫 번째 행렬의 i : 1~n번쨰 열과 두 번쨰 행렬의 j : 1~m번째 행을 곱하여 배열[i][j]에 저장해 준다.
                    answer[i0][j1] += (arr1[i0][i1] * arr2[i1][j1]);
                }
            }
        }
    
        return answer;
    }
}
