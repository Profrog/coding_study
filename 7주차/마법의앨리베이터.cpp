#include <string>
#include <vector>

using namespace std;
int answer = 0;
int divide = 100000000;


int solution(int storey) {

    while (storey > 0)
    {
        int remind = storey % 10;
        storey /= 10;

        if (10 - remind  < remind)
        {
            answer += 10 - remind;
            storey += 1;
        }

        else if (remind == 5 && storey % 10 >= 5)
        {
            answer += 5;
            storey += 1;
        }

        else
            answer += remind;
    }

    return answer;
}
