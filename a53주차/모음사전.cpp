#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

map <char, int> book; 
int solution(string word) {
    int answer = 0; 
    book['A'] = 0; //1.가중치는 a=0, e=1, i=2, o=3, u=4로 구성된다.
    book['E'] = 1;
    book['I'] = 2;
    book['O'] = 3;
    book['U'] = 4;
    
    int more = 0;
    for(int idx = 4; idx >= 0; --idx)
    {
        more += pow(5, 4 - idx); //2.가중치는 자리수에 대해 5의 제곱수 형태로 늘어난다.
        
        if(idx < word.size())
        {
            int data = book.find(word[idx])->second;
            answer += (more * data) + 1; //3.자식으로 취급 했을 때의 없은 경우의 수를 1 더해서 계산한다.
        }
    }
    
    return answer;
}
