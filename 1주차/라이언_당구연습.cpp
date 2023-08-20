#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int x_m;
int y_n;
int ax; //startx
int ay; //starty
//mode =1&x0, =2%x_n, =3&y0, =4&y_n

int calcul(int bx, int by) //접점 좌표를 얻음
{
    int answer0[4];
    int answer00 = 100000000;

    answer0[0] = (int)pow(bx - (-ax), 2) + (int)pow(by - ay, 2); //x0 대칭
    answer0[1] = (int)pow(bx - (2 * x_m - ax), 2) + (int)pow(by - ay, 2); //xm 대칭
    answer0[2] = (int)pow(bx - ax, 2) + (int)pow(by - (-ay), 2);  //y0 대칭
    answer0[3] = (int)pow(bx - ax, 2) + (int)pow(by - (2 * y_n - ay), 2); //yn 대칭

    if (ay == by) 
    {
        if (ax > bx)
            answer0[0] = answer00;

        else
            answer0[1] = answer00;
    }

    if (ax == bx)
    {
        if (ay > by)
            answer0[2] = answer00;

        else
            answer0[3] = answer00;
    }

    //cout << answer0[0] << " " << answer0[1] << " " << answer0[2] << " " << answer0[3] << "\n";
    return min(min(answer0[0], answer0[1]) ,min(answer0[2], answer0[3]));
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    x_m = m; //rk
    y_n = n;
    ax = startX;
    ay = startY;

    for (int i = 0; i < balls.size(); ++i)
    {
        answer.push_back(calcul(balls[i][0], balls[i][1]));
    }

    return answer;
}
