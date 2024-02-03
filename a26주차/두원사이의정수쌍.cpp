#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long mile(long long r,long long x,int mode)
{
    if (r <= x)
        return 0;
    
    else
    {
        double y = sqrt(r*r - x*x); 
        return (y == (int)y)? (int)y : (int)(y+mode); //3.x(0~r2) 사이의 y좌표 중 원 안에 있고 정수 좌표 인 것들을 구해 개수의 차를 구한다.
    }
}


long long solution(int r1, int r2) {
    long long answer = 0;

    for(int i = 0; i <= r2; ++i)
    {
        answer += ( mile(r2,i,0) - mile(r1,i,1) + 1); //2.두 원 사이의 정수쌍 중 작은 원에 닿아있는 것은 사분면 당 1개다.
    }
    
    return 4*answer -4*(r2-r1+1) ; //1.좌표의 개수는 대칭적이므로 1사분면에 대해서 구한뒤 4를 곱하여 반환한다.
}
    


