#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    
    vector<int> data0;
    stringstream s0(s);
    string stringBuffer;
    
    while (getline(s0, stringBuffer, ' ')){ //1.문자열을 공백 기준으로 파싱
        data0.push_back(stoi(stringBuffer)); //2.파싱된 문자열을 정수로 바꾸어 배열에 저장
    }
 
    string answer = "";
                        
    answer = to_string(*min_element(data0.begin(),data0.end())) + " " + to_string(*max_element(data0.begin(),data0.end())); //3.배열의 값 중 최댓값과 최솟값을 찾아 b. 형태에 맞게 반환                                        
    return answer;
}
