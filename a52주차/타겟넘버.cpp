#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    vector<int> list_a(1, target); //1. 타겟 값을 관리 리스트에 넣는다.
    
    int idx_s = 0;
    int idx_e = 1;
    int answer = 0;
    int nl = numbers.size();

    for (int x = 0; x < nl; ++x)
    {
        int idx_s0 = list_a.size();        
        for (int y = idx_s; y < idx_e; ++y)
        {
            //2. numbers 원소의 값을 하나씩 관리 리스트 값에서 빼거나 더하고 다시 관리 리스트에 저장한다.
            int minus = list_a[y] - numbers[x];
            int plus = list_a[y] + numbers[x];
            list_a.push_back(minus);
            list_a.push_back(plus);
            
            if (x == nl - 1) //3. 최종 원소를 반영했을 때 0이 되는 개수를 반환한다.
            {
                (minus == 0) ? ++answer : 0;
                (plus == 0) ? ++answer : 0;
            }             
        }

        idx_s = idx_s0;
        idx_e = list_a.size();
    }
    
    return answer;
}

