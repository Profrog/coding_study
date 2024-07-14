#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {	
	
    int size_prices = prices.size();
    vector<int> answer(size_prices, 0);

	for (int i = 0; i < size_prices; i++)
	{//1.prices의 전체 인덱스를 조회한다.
		for (int j = i + 1; j < size_prices; j++)
		{
			answer[i]++;
			if (prices[j] < prices[i])
			{//2.조회한 타겟 인덱스보다 큰 인덱스 들을 조회하며 더 작은 price를 발견하거나 리스트의 끝 값을 조회하기 전까지 시간값을 올리고 다음 타겟 인덱스를 조회 하기전 반환 리스트에 시간값을 저장한다.
				break;
			}
		}
	}

	return answer;
}
