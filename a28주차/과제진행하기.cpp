#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int convert_ti(string alpa, string beta)
{
    return stoi(alpa.substr(0, 2)) * 60 + stoi(alpa.substr(3, 2)) + stoi(beta);
}


bool compare0(vector<string> alpa, vector<string> beta)
{
    return convert_ti(alpa[1], "0") <= convert_ti(beta[1], "0");
}


vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<vector<string>> wait_list;
  
    sort(plans.begin(), plans.end(), compare0);
    plans.push_back({ "end","24:00","130" });
    int current_time = 0;
   

    for (auto i = 0; i < plans.size() - 1; ++i)
    {
        int remain_time = convert_ti(plans[i][1], "0") - current_time;
        while (remain_time && wait_list.size()) //2. b.에 따라 대기 리스트의 과제를 남는 시간만큼 처리 후, 클리어 하지 못했다면 대기 리스트에 다시 넣기
        {
            int tim = stoi(wait_list.back()[2]) - remain_time;

            if (tim <= 0) 
            {
                remain_time -= stoi(wait_list.back()[2]);
                answer.push_back(wait_list.back()[0]);
                wait_list.pop_back();
            }

            {
                wait_list.back()[2] = to_string(tim);
                remain_time = 0;
            }


        }

        current_time = convert_ti(plans[i][1], "0"); //1. a. 를 위해 과제 리스트를 시간 순서대로 정렬, 현재 시간을 처리 중인 과제 완료 시간으로 정의

        int tim_2 = convert_ti(plans[i + 1][1], "0") - convert_ti(plans[i][1], "0");
        int task_2 = stoi(plans[i][2]);


        if (task_2 <= tim_2) //3. 현재 시간보다 다음 과제 처리 시작 시간이 이르다면, 최대한 처리 후, 기존 과제를 대기 리스트에 넣기
        {
            answer.push_back(plans[i][0]);
            current_time = convert_ti(plans[i][1], plans[i][2]); 
        }

        else 
        {
            wait_list.push_back(plans[i]);  
        }
    }

    while (wait_list.size()) //4.과제 리스트의 과제를 모두 처리 후, 대기 리스트의 과제가 남아 있다면 뒤에서 부터 모두 처리
    {
        answer.push_back(wait_list.back()[0]);
        wait_list.pop_back();
    }


    return answer;
}
