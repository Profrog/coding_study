#include <string>
#include <vector>
using namespace std;
string solution(string s) {
    string answer = "";
    int sl = s.length();
    
    int idx = -1;
    while(idx < sl)
    {
       while(s[++idx] == ' '){answer += ' ';} //1.공백문자가 아닐 때 까지 문자열을 탐색 및 글자 저장
       if(idx < sl){answer += toupper(s[idx++]);} //2.공백문자 다음 첫글자를 대문자로 치환하여 저장
       while(idx < sl && s[idx] != ' '){answer += tolower(s[idx++]);} //3. 다음 공백문자가 나타날 때 까지 글자를 소문자로 치환하여 저장
       answer += ' ';
    }
    answer.pop_back();
    return answer;
}
