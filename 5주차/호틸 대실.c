#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> booking(1,0);

int cv_time(string alpa)
{
    return 60 * stoi(alpa.substr(0, 2)) + stoi(alpa.substr(3, 2));
}

bool compare(vector<string>& alpa, vector<string>& beta)
{
    if (cv_time(alpa[0]) == cv_time(beta[0]))
        return cv_time(alpa[1]) < cv_time(beta[1]);

    else return cv_time(alpa[0]) < cv_time(beta[0]);
}

int solution(vector<vector<string>> book_time) {
    
    sort(book_time.begin(), book_time.end(), compare);

    for (int i = 0; i < book_time.size(); ++i)
    {
        for (int j = 0; j < booking.size(); ++j)
        {
            if (cv_time(book_time[i][0]) >= booking[j])
            {
                booking[j] = cv_time(book_time[i][1]) + 10;
                goto tag1;
            }
        }
      
            booking.push_back(cv_time(book_time[i][1]) + 10);
            tag1:;
    }
    
    return booking.size();
}
