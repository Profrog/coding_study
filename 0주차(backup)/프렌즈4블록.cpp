#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> map0;
vector<pair<int,int>> del_trg;

int row = 0;
int col = 0;
const int mark_chk = 32;
const int max_mark = 95;
const char space0 = ' ';

void viewer()
{
    cout << endl;
    
    for(int y = 0 ; y <= col-1 ; ++y)
    {
        for(int x = 0 ; x <= row-1 ; ++x) //row check
        {
            cout << map0[y][x];       
        }
        
        cout << endl;
    }
    
    cout << endl;
}

bool compareMark(char input, char mark)
{
    if(input == mark) return true;
    else if(input == (mark+mark_chk)) return true;
    else if((input+mark_chk) == mark) return true;
    else return false;
}


bool isDeleteblock(int y, int x, int y_vec, int x_vec, char mark)
{
    int x1 = x + x_vec; 
    int y1 = y + y_vec;
    
    if(y1 >= col || y1 < 0 || x1 >= row || x1 < 0)
    {
        return false;
    }

    if(compareMark(map0[y][x1],mark) && compareMark(map0[y1][x],mark) && compareMark(map0[y1][x1],mark))
    {
        if(map0[y][x] < max_mark)
        {
            map0[y][x] += mark_chk;
        }
        
        if(map0[y][x1] < max_mark)
        {
            map0[y][x1] += mark_chk;
        }
           
        if(map0[y1][x] < max_mark)
        {
            map0[y1][x] += mark_chk;
        }
        
        if(map0[y1][x1] < max_mark)
        {
            map0[y1][x1] += mark_chk;
        }
         
        return true;
    }
        
   else return false;
}


int mapControl()
{
    int answer = 0;
    for(int y = 0 ; y < col-1; ++y)
    {
        for(int x = 0 ; x < row -1 ;++x)
        { 
            if(map0[y][x] == space0) break;
            else isDeleteblock(y,x,1,1,map0[y][x]);           
        }
    }
    
     for(int y = 0 ; y <= col-1; ++y)
    {
 
        for(int x = row-1 ; x >= 0 ;--x)
        {
           if(map0[y][x] > max_mark && map0[y][x] != space0)
           {
                map0[y][x] = space0;
                ++answer;
                int cur_idx = x;
                int new_idx = x+1;                
                while(map0[y][new_idx] != space0 && (new_idx < row))
                {
                    swap(map0[y][cur_idx],map0[y][new_idx]);
                    cur_idx = new_idx;
                    ++new_idx;
                } 
           }
        }   
    }

    return answer;
}

int solution(int m, int n, vector<string> board) {
    
    int answer = 0;
    row = m;
    col = n;
    for(int x = 0 ; x <= col-1; ++x)
    {
        string alpa = "";
        for(int y = row-1; y >= 0 ; --y)
        {
            alpa += board[y][x];
        }    
        map0.push_back(alpa);
    }
    
    int data = 0;
    do{       
        data = mapControl();
        answer += data;
        
    }while(data > 0);

    return answer;
}
