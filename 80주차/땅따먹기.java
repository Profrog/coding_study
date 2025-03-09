import java.util.*;

class Solution {
    
    int getBestData(int[] land, int row)
    { //1번째 행과 0~3번째의 열에 위치한 데이터는 자신의 열이 아닌 0번째 행의 데이터 중 가장 큰 값을 누적 받는다.
        if(row == 0){return Math.max(land[1],Math.max(land[2],land[3]));}
        else if(row == 1){return Math.max(land[0],Math.max(land[2],land[3]));}
        else if(row == 2){return Math.max(land[0],Math.max(land[1],land[3]));}
        else {return Math.max(land[0],Math.max(land[1],land[2]));} //3일때
    }
    
    int solution(int[][] land) {
        int answer = 0;

        for(int i = 1; i < land.length; ++i)
        { //2.1번째 행부터 테이블의 마지막 행까지 반복한다.
            for(int j = 0; j < 4; ++j)
            {
                land[i][j] += getBestData(land[i-1],j);
                answer = Math.max(answer,land[i][j]); //3.누적값 중 가장 큰 값을 반환한다.
            }
        }
    
        return answer;
    }
}
