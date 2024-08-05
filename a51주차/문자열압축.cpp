#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int calcul_len(string s, int size)
{
    int data_len = 0;
    string s1 = s;
    string::size_type index_0 = 0;

    while (s1.length() >= size)
    {
        string find0 = s1.substr(0,size);  //2. 길이를 기준으로 반복되는 문자열을 정의한다.
        s1 = s1.substr(size);
        string::size_type pos0 = s1.find(find0);
        
        if (pos0 == 0)
        {
            int count_0 = 1;
            data_len += size;

            while (pos0 == 0) //3.원본 문자열의 복사본을 길이 만큼 잘라 반복되는 횟수 + 문자열의 길이로 치환한다.
            {
                s1 = s1.substr(size);
                pos0 = s1.find(find0);
                count_0++;
            }

            data_len += ((int)log10(count_0)+1); //4.치환할떄 log함수를 이용하여 반복되는 횟수의 문자열로 변환 길이를 고려한다.
        }

        else
        {
            data_len += size;
        }
    }

    if (s1.length() > 0) 
    {
      data_len += s1.length();
    }
    return data_len;
}


int solution(string s0){
        int small_len = s0.length();
        for (int x = 1; x <= s0.length()/2; x++)
        { //1. 반복되는 길이를 정의한다. 길이는 1~입력받은 문자열의 절반 사이즈이다.
            int cur_len = calcul_len(s0,x); 
            if (cur_len < small_len) 
            {
                small_len = cur_len;
            }
        }
    
    return small_len;
}

