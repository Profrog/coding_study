#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> map0;
int row = 0;
int col = 0;

void viewer()
{
    cout << endl;
    
    for(int y = col-1 ; y >= 0; --y)
    {
        for(int x = row-1 ; x >=0 ; --x) //row check
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
    else if(input == (mark+30)) return true;
    return false;
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
        return true;
    }
        
    return false;
}

int findDeleteBlock(int y, int x,int volume,char mark)
{
    if(isDeleteblock(y-1,x,-1,-1,mark))
    {
       volume += findDeleteBlock(y-1,x,2,mark);
    }
    
    if(isDeleteblock(y-1,x-1,-1,-1,mark))
    {
       volume += findDeleteBlock(y-1,x-1,3,mark);
    }
    
    if(isDeleteblock(y,x-1,-1,-1,mark))
    {
       volume += findDeleteBlock(y,x-1,2,mark);
    }
    
    map0[y][x] = mark + 30;
    map0[y][x-1] = mark + 30;
    map0[y-1][x] = mark + 30;
    map0[y-1][x-1] = mark + 30;
    //cout << y << "#" << x << " "<< volume << endl;
    return volume;
}


int mapControl()
{
    int answer = 0;

    
    for(int x = row-1 ; x >= 0; --x)
    {
        for(int y = col-1 ; y >=0; --y) //row check
        {
    
            if(map0[y][x] == '#')
            {
                continue;
            }
            
            else if(map0[y][x] > 90)
            {
                continue;
            }
            
            else if(isDeleteblock(y,x,-1,-1,map0[y][x]))
            {
                int data = findDeleteBlock(y,x,4,map0[y][x]);
                //cout << data << " ";
            }            
        }
        
        //cout << endl;
    }
    
    for(int y = 0 ; y < col;++y)
    {
        for(auto elec = map0[y].begin(); elec != map0[y].end();)
        {
            if(*elec > 90)
            {
                elec = map0[y].erase(elec);
                map0[y].push_back('#');
                ++answer; 
            }
            
            else
            {
                ++elec;
            }
        }
    }
    
    //viewer();
    //cout << answer << " " << endl;
    return answer;
}

int solution(int m, int n, vector<string> board) {
    
    int answer = 0;
    row = m;
    col = n;
    for(int x = col-1 ; x >= 0; --x)
    {
        string alpa = "";
        for(int y = row-1 ; y >= 0 ; --y)
        {
            alpa += board[y][x];
        }    
        map0.push_back(alpa);
    }
    
    //viewer();
    
    int data = 0;
    do{       
        data = mapControl();
        answer += data;
        cout << endl;
        
    }while(data > 0);

    return answer;
}




