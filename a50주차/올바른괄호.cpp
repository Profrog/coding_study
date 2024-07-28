#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    int data = 0;
    int idx = -1;
    while(++idx < s.size() && data >= 0) //1.여는 괄호의 값은 1, 닫는 괄호의 값은 -1로 생각햐면 a.에 따라 룰을 지키는 1~n번째의 괄호 값의 합은 0이상이어야 한다.
    {
        if(s[idx] == '(')
        {
            data += 1;   
        }
        
        else
        {
            data -= 1;
        }   
    }
    
    if(data == 0) //2.최종 괄호 값의 합이 0인지를 확인해 룰 만족을 검사한다.
    {
        answer = true;
    }
    
    return answer;
}
