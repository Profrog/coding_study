#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

vector<int> car_link(10000,-1);
vector<int> car_cost(10000.0);
int last_time = (23 * 60) + 59;

vector<int> split_data(string& alpa)
{
    vector<string> return_a;
    istringstream beta(alpa);
    string buffer;

    while (getline(beta, buffer, ' '))
    {
        return_a.push_back(buffer);
    }

    vector<int> return_b(3,0);
    
    return_b[0] = stoi(return_a[0].substr(0, 2)) * 60 + stoi(return_a[0].substr(3, 2));
    return_b[1] = stoi(return_a[1]);
    return_b[2] = return_a[2] == "IN" ? 0 : 1;

    return return_b;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    for (int i = 0; i < records.size(); ++i)
    {
        vector<int> data_l = split_data(records[i]);

        if (data_l[2] == 0)
        {
            car_link[data_l[1]] = data_l[0];
        }

        else
        {
            car_cost[data_l[1]] += data_l[0] - car_link[data_l[1]];
            car_link[data_l[1]] = -1;
        }
    }

    for (int i = 0; i < car_cost.size(); ++i)
    {
        if (car_cost[i] || car_link[i] > -1)
        {
            if (car_link[i] > -1)
                car_cost[i] += (last_time - car_link[i]);

           answer.push_back((car_cost[i] > fees[0]) ? fees[1] + ceil((double)(car_cost[i] - fees[0]) / fees[2]) * fees[3] : fees[1]);

        }

    }

    return answer;
}
