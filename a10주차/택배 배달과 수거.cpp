#include <string>
#include <vector>
#include <iostream>
using namespace std;

int sendorget[2] = { 0,0 };
int vector_check(vector<int>& vector0) //1.작업(배송|수거) 하지 않아도 되는 집 고려대상에서 제거
{
    while (vector0.back() == 0)
    {
        vector0.pop_back();
    }
    return vector0.size() - 1;
}

int making_course(int cap_index, vector<int>& house, vector<int>& dummy) 
{
    int index0 = house.size() -1;
    if (&house != &dummy)
    {
       making_course(1 - cap_index, dummy, dummy); //2.멀리 떨어진 집 부터 방문, 최대 cap 크기만큼 작업(배송과 수거는 독립적으로 고려가능)
    }

    while (sendorget[cap_index] >= 0 && index0 >= 0)
    {
        sendorget[cap_index] -= house[index0];
        house[index0] = 0;

        if (sendorget[cap_index] >= 0)
        {
            if (--index0 < 0) return -1;
        }

        else
        {
            house[index0] -= sendorget[cap_index];
            break;
        }
    }

    return index0;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int sending_index = deliveries.size() - 1;
    int getting_index = pickups.size() - 1;

    while (sending_index >= 0 || getting_index >= 0) 
    {
        sending_index = vector_check(deliveries);
        getting_index = vector_check(pickups);
        if (sending_index < 0 && getting_index < 0) break; //3.모든 집이 작업 대상이 아닐 때 이동거리 합 반환

        sendorget[0] = cap;
        sendorget[1] = cap;

        if (sending_index >= getting_index) //2.멀리 떨어진 집 부터 방문, 최대 cap 크기만큼 작업(배송과 수거는 독립적으로 고려가능)
        {           
            answer += (sending_index + 1) * 2;
            making_course(0, deliveries, pickups);
        }

        else
        {
            answer += (getting_index + 1) * 2;
            making_course(1, pickups, deliveries);
        }
    }

    return answer;
}
