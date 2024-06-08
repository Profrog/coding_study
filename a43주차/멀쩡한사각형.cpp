#include <cmath>

long long solution(int w,int h) {
    long long answer = 1;
	double m1 = fmax(w,h), m2 = fmin(w,h);

    //1. 위 선의 함수는 y = (m2/m1)x이다. x {1~m1}을 대입하여 x에 따른 y의 리스트를 얻는다.
	for (int i = 1; i < m1; i++)
	{
		int plusdata = 1; //2. x와 x+1 사이를 한 줄이라고 할 때, 한 줄에 최소 1개 씩의 빈 블록은 존재하게 된다.
		plusdata += ((floor((m2 * i) / m1) + 1) < (m2*(i+1) / m1) ) ? 1 : 0; //3. 이전 y의 위치의 정수 단위의 내림에 1을 더한 것이 현재 y의 위치 보다 작다면 현재 줄에서 2개의 빈 블록이 존재하게 된다.
		answer += plusdata;
	}

	answer = (m1 * m2) - answer;
	return answer;
}
