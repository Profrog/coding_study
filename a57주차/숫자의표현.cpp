#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> number;


int solution(int n) {
    int answer = 0;
    int s_idx = 0; //1.누적값 시작 인덱스와 끝 인덱스를 정의한다.
    int e_idx = 0;
    int value = 0;
    
    for(int data = 0; data <= n; data++)
    {//2. 0~n사이의 정수를 가진 배열을 만든다.(0을 포함하는 이유는 계산 시작 전 초기 상태 반영)
        number.push_back(data);
    }
    
    while(true)
    {
        if(value == n) //3.누적값이 매개변수 값과 같으면 방법의 수를 1 늘리고, 시작 인덱스를 1 증가한다.
        {
            if(s_idx > 0)
            {
                ++answer;
            }
            
            value -= s_idx++;
        }
        
        else if(value < n)
        {//4.누적값이 매개변수 값보다 작으면 끝 인덱스를 증가하고, 해당 인덱스에 대응하는 배열 값을 누적값에 추가한다.
            if(++e_idx >= number.size())
            {//6.끝 인덱스가 배열 사이즈를 넘어가면 현재 까지 계산된 방법의 수를 반환한다.
              return answer;
            }
            
            else
            {
                value += number[e_idx];
            }
        }
        
        else 
        {//5.누적값이 매개변수 값보다 크면 시작 인덱스를 증가하고, 이전 인덱스에 대응하는 배열 값을 누적값에서 뺀다.
            if(s_idx + 1 > e_idx)
            {
               return answer;  
            }
            
            else
            {
                value -= number[s_idx++];
            }
        }
    
    }
    
    return answer;
}
