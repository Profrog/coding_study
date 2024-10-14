#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(n > 0) 
    {
        while(n % 2 == 0) //1.이동 요구 거리가 짝수인 동안 2로 나눠준다.
        {
            n /= 2;
        }
        
        --n; //2.홀수 일때는 1을 빼서 짝수로 만들어준다. 에너지 사용값은 1올려준다.
        ++ans;
    }
    
    return ans; //3.에너지 사용값을 반환한다.
}
