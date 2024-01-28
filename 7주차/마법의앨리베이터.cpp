#include <string>
#include <vector>

using namespace std;
int answer = 0;


int solution(int storey) {

    while (storey > 0) //1.주어진 수의 각 자리값 취득
    {
        int remind = storey % 10;
        storey /= 10;

        if (10 - remind < remind) //2.자리값이 4이하 일때는 +n개가 최소
        {
            answer += 10 - remind;
            storey += 1;
        }

        else if (remind == 5 && storey % 10 >= 5) //3.자리값이 6이상일 때는 10 - n꼴로 생각하여, 앞자리에 자리값 1을 추가하고 10-n꼴이 최소(6일때 n꼴을 취하면 6개가 필요, 10-n꼴이면 1 + 4 = 5이다)
        {
            answer += 5;
            storey += 1;
        }

        else //4.자리값이 5일때는 앞자리가 5이상이면 (3.)꼴을 만들어 앞자리도(3.)꼴을 취하게 하고, 5미만이면 (2.)꼴을 취하는 것이 최소 (55이면, (3.)꼴일시 5+4, (2.)꼴일시 5+5가 나옴)
            answer += remind;
    }

    return answer;
}
