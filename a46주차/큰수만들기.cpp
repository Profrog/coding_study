#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<char> num_vec;

string solution(string number, int k) {
    
    int same_count = 0;
    string answer = "";
    num_vec.assign(number.begin(), number.end());
    //1.number string을 vector<char> 형으로 변환하여 저장한다.
    
    int idx_j = 0;
    while(k < number.size())
    {
        loop1:
        for(char basis = '9'; basis >= '0'; --basis)
        {//2.각 자리수는 9~0 이므로 주어진 인덱스로 부터 number vector를 k길이 만큼 조회하면서 큰 수부터 넣어준다.주어진 인덱스는 0에서 시작하여 수를 넣어줄 때마다 해당 수가 있던 인덱스의 다음으로 갱신해 준다.
          
            for(int j = idx_j; j <= k; ++j)
            {//3.수를 넣어줄 때 마다 k를 증가시키며 k가 number size가 될 때 까지 본 과정을 반복한다.
                if(num_vec[j] == basis)
                {
                    answer.push_back(basis);
                    idx_j = j + 1;
                    if(++k >= number.size())
                    {
                        return answer;
                    }
                    
                    else
                    {
                       goto loop1;
                    }
                }
            }
        }
    }

    return answer;
}
