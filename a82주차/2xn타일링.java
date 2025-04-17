import java.util.*;

class Solution {
    
    final int dnf = 1000000007;
    int[] datamap0 = new int[60001];
    
    public int solution(int n) {
        
        datamap0[1] = 1; //1.가로가 1일 때는 1가지의 경우의 수가, 가로가 2일때는 2가지의 경우의 수가 있음
        datamap0[2] = 2;
        
        int answer = 0;
        
       for(int i = 3; i <= n; ++i)
       { //2.가로가 3일 때 부터 n일때 까지, b에 따라 f(n) = f(n-1) + f(n-2)임을 활용하여 동적으로 경우의 수 계산
           datamap0[i] = (datamap0[i-1] + datamap0[i-2])%dnf;
       }
    
       return datamap0[n];
    }
}
