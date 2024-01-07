#include <string>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


vector<pair<long, long>> point_dir;
long min_x = 0; long max_x = 0;
long min_y = 0; long max_y = 0;


void point_making(vector<int>& alpa, vector<int>& beta)
{
    long x_top1 = (long)alpa[1] * (long)beta[2];
    long x_top2 = (long)beta[1] * (long)alpa[2];

    long bottom1 = (long)alpa[0] * (long)beta[1];
    long bottom2 = (long)beta[0] * (long)alpa[1];

    long y_top1 = (long)alpa[2] * (long)beta[0];
    long y_top2 = (long)beta[2] * (long)alpa[0];


    if ((bottom1 - bottom2) != 0)
    {
        long x_top = x_top1 - x_top2;
        long y_top = y_top1 - y_top2;
        long bottom = bottom1 - bottom2;

        if (((x_top % bottom) == 0) && ((y_top % bottom) == 0))
        {
            x_top /= bottom;
            y_top /= bottom;

            if (point_dir.empty())
            {
                min_x = x_top;
                max_x = x_top;
                min_y = y_top;
                max_y = y_top;
            }

            else
            {
                min_x = min(min_x, x_top);
                max_x = max(max_x, x_top);
                min_y = min(min_y, y_top);
                max_y = max(max_y, y_top);
            }

            point_dir.push_back({ x_top,y_top });
        }
    }
}

vector<string> solution(vector<vector<int>> line) {

    for (int i = 0; i < line.size(); ++i)
    {
        for (int j = i + 1; j < line.size(); ++j)
        {
            point_making(line[i], line[j]);
        }
    }

    string alpa = ""; alpa.append(max_x - min_x + 1, '.');
    vector<string> answer(max_y - min_y + 1, alpa);


    for (auto i = point_dir.begin(); i != point_dir.end(); ++i)
    {
        answer[max_y - (*i).second][(*i).first - min_x] = '*';
    }

    return answer;
}
