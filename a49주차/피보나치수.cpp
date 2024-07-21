#include <string>
#include <vector>

using namespace std;

vector<int> data0(100001, -1);

int fibo(int n)
{
    if(n <= 0) {return 0;} //1.0번째 피보나치 수는 0이고 1번째 피보나치 수는 1이다.
    if(n == 1) {return 1;}
    
    if(data0[n] < 0 ){ data0[n] = (fibo(n-1) + fibo(n-2)) % 1234567;} //2.n번째 피보나치수는 n-1, n-2번째 피보나치 수의 합으로 피보나치 수의 값이 계산될 때 마다 그 값을 저장하여 중복적인 계산을 피한다.
    return data0[n];
}


int solution(int n) {
    return fibo(n);
}
