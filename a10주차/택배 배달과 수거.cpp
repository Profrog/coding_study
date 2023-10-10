#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    long long truck = cap;
   
    for(int i = 1 ; i < n ; ++i)
    {
        while (deliveries.back() > 0)
        {
            answer += deliveries.size();
            deliveries.back() -= cap;
            pickups.back() -= cap;
        }

        while (pickups.back() > 0)
        {
            answer += pickups.size();
            deliveries.back() -= cap;
            pickups.back() -= cap;
        }

        deliveries[deliveries.size() - 2] += deliveries.back();
        deliveries.pop_back();
        
        pickups[pickups.size() - 2] += pickups.back();
        pickups.pop_back();
    }

    while (deliveries.back() > 0)
    {
        answer += deliveries.size();
        deliveries.back() -= cap;
        pickups.back() -= cap;
    }

    while (pickups.back() > 0)
    {
        answer += pickups.size();
        deliveries.back() -= cap;
        pickups.back() -= cap;
    }

    return answer*2;
}
