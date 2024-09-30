#include <iostream>
#include<string>
#include<stack>
using namespace std;


int solution(string s)
{
    stack<int> s0;
    int answer = 0;

    if (s.length() == 0) 
        return 0;

    else //1.문자열의 가장 앞의 글자를 stack에 집어 넣는다.
     s0.push(s[0]);

    for (int x = 1; x < s.length(); x++)
    {
        if(s0.empty()) s0.push(s[x]);

        else if(s[x] == s0.top()) //2. 다음의 넣을 글자가 stack 가장 최근에 저장된 값과 일치하면 그 값을 stack에서 제거한다.
            s0.pop();

        else //3. 일치하지 않을 경우에는 해당 글자를 stack에 집어 넣는다.
            s0.push(s[x]);
    }

    if (s0.size() > 0) //4.stack이 비었을 때는 1, 비지 않았을 때는 0을 반환한다.
        return 0;

    else return 1;
}
