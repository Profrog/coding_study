#include <string>
#include <vector>
#include <iostream>

using namespace std;

string binaryStr(int n)
{
    string answer = "";
    while(n > 0)
    {
        int n0 = n % 2;
        if(n0 == 0)
        {
            answer = "0" + answer;
        }
        
        else
        {
            answer = "1" + answer;
        }
        
        n/= 2;
    }
    
    return answer;
}



vector<int> solution(string s) {
    
    vector<int> answer(2,0); 
    int one_count = 0;
    int zero_count = 0;
    
    do
    {
        one_count = 0;
        zero_count = 0;
        for(auto s0 : s)
        {
            if(s0 == '1') //1. 문자열에서 1의 개수, 0의 개수 카운팅
            {
                ++one_count;
            }
            
            else
            {
                ++zero_count;
                ++answer[1];
            }
        }
    
        ++answer[0];
        s =  binaryStr(one_count); //2. 1의 개수를 이진 변환한 값으로 문자열 교체
    }
    while(s != "1"); //3.교체된 문자열이 1이 아닐 때 까지 반복
    
    
    return answer;
}
