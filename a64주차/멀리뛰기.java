import java.util.*;

class Solution {
    public long solution(int n) {
        
        long[] box = new long[n+2];
        long divide0 = 1234567;
        box[1] = 1;
        box[2] = 2;
        
        for(int idx = 3; idx <= n; ++idx)
        { //1.n번째 칸에 도달할 수 있는 경우의 수는 n-1번째에서 1칸을 뛰거나, n-2번째에서 2칸을 뛰는 경우의 수로 f(n) = f(n-1) + f(n-2)가 된다.
            box[idx] = (box[idx-1] + box[idx-2]) % divide0;   //2.질의의 조건에 따라 overflow가 나지 않기 위해서 값을 산출할때 마다 1234567로 나눠준다. 
        }

        return box[n] % divide0;
    }
}
