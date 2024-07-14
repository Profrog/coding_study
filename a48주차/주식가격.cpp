#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {	
	
    int size_prices = prices.size();
    vector<int> answer(size_prices, 0);

	for (int i = 0; i < size_prices; i++)
	{
		for (int j = i + 1; j < size_prices; j++)
		{
			answer[i]++;
			if (prices[j] < prices[i])
				break;
		}
	}

	return answer;
}
