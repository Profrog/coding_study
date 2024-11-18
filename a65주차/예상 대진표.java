import java.util.*;

class Solution
{
    public int solution(int n, int a, int b)
    {
        int answer = (int)(Math.log(n)/Math.log(2)); //1. n을 밑이 2인 진수에 넣어서 나온 값이 최대 압축(토너먼트 진행) 횟수(초기값)
        int b1 = Math.max(a,b);
        int a1 = Math.min(a,b);
        int s_idx = 1;
        int e_idx = n;
        
        while(s_idx != e_idx) //2.이분탐색으로 탐색하면서 그룹의 반 크기 안에 두 인덱스가 모이게 되면 한 차수 적은 압축 횟수에 두 인덱스가 만날 수 있다.
        {
            int mid = (s_idx + e_idx) / 2;
            if(a1 > mid) {s_idx = mid;} //3.그룹의 반 크기안에 인덱스가 모일 때, 왼쪽 그룸에서 만나면 끝 인덱스 값을 인덱스 중간값으로 넣어준다.
            else if(b1 <= mid){e_idx = mid;} //4.3.의 상황에서 오른쪽 그룹에서 만나면시작 인젝스 값을 중간값으로 넣어준다.
            else {return answer;}
            --answer;
        }
        
        return answer;
    }
}
