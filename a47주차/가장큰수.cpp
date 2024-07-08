#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b)
{
 return a+b > b+a;
}

string solution(vector<int> numbers) {
 vector<string> data0;
 string answer = "";

 for(auto x = numbers.begin() ; x != numbers.end() ; x++) 
 {//1.앞자리 수가 클수록 큰 수 이므로 정수 리스트의 원소를 string으로 바꾸어 리스트에 저장한다.
  data0.push_back(to_string(*x));
 }

 //2. 해당 string 리스트를 사전식 내림차순으로 정렬하고 앞에서 부터 순서대로 붙여 수를 만든다.
 sort(data0.begin(), data0.end(),compare);
 for(auto x = data0.begin() ; x != data0.end() ; x++)
  answer += *x;

 //3.만든 수의 앞자리가 0일때는 0을 반환하고, 나머지 경우에는 만든 수를 반환해 준다.   
 if(answer.front() == '0')
   return "0";
    
 return answer;
}
