#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string twoarray(int n)
{
    string answer = "";
    int previous = 0;
    int zero_one = 0;
    int one_zero = 0;
    string bef_1 = "";
    string bef_0 = "";
    
    //1. n을 2진수로 변환한 수를 뒤에서 부터 조회하며, "01"이 포함되면 해당 01을 10으로 바꿔주고 그 뒤의 수 중 0들을 01이 있는 인덱스 뒤로 옮기면 다음 큰 수이다.
    while(n > 0)
    {
        int value = n % 2;
        if(value == 0) //0에 대하여
        { 
            if(zero_one < 1)
            {
                if(value != previous) //처음 나온 01구조
                {
                    bef_1.pop_back();
                    answer = bef_1 + bef_0;
                    answer += '0';
                    answer += '1';
                    ++zero_one;
                }
                
                else //01구조 나오기 전
                {
                    bef_0 += '0';
                }
            }
            
            else //처음에 나온 01구조 이후
            {
                answer += '0';   
            }
        }
        
        else //1에 대하여
        {
           if(zero_one < 1)
            {
                bef_1 += '1';
            }
            
            else
            {
                answer += '1';
            }
        }
        
        n /= 2;
        previous = value;
    }
 
    //2."01"이 포함되지 않은 경우는 변환수의 제일 앞에 0을 넣고, 01구조를 강제로 만들어 1.에 대한 로직을 실행한다.
    if(zero_one < 1)
    {
        bef_1.pop_back();
        answer = bef_1 + bef_0;
        answer += '0';
        answer += '1';
        ++zero_one;
    }
  
     reverse(answer.begin(), answer.end());
     return answer;
}

int solution(int n) {
    int answer = 0;
    string origin = twoarray(n);
    int more = 1;
    for(auto a = origin.rbegin(); a != origin.rend(); ++a)
    {
        answer += (*a - '0') * more;
        more *= 2;
    }
    
    return answer;
}
