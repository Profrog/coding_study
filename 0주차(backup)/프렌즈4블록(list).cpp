#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

vector<list<char>> map0;
int row = 0;
int col = 0;

void viewer()
{
    cout << endl;
    
    for(int y = col-1 ; y >= 0; --y)
    {
        for(auto x = map0[y].rbegin() ; x != map0[y].rend() ; ++x) //row check
        {
            cout << *x;       
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
    
    auto lt = map0[y].begin();
    auto rt = map0[y1].begin();
    advance(lt,x);
    advance(rt,x);
    
    auto ld = lt;
    auto rd = rt;
    advance(lt,x_vec);
    advance(rt,x_vec);
    
    
    if(compareMark(*lt,mark) && compareMark(*rt,mark) && compareMark(*ld,mark) && compareMark(*rd,mark))
    {
        if(*lt < 90)
            *lt += 30;
        
        if(*rt < 90)
            *rt += 30;
        
        if(*ld < 90)
            *ld += 30;
        
        if(*rd < 90)
            *rd += 30;
    
        return true;
    }
        
    return false;
}

int findDeleteBlock(int y, int x,int volume,char mark)
{
    if(isDeleteblock(y+1,x,1,1,mark))
    {
       volume += findDeleteBlock(y+1,x,2,mark);
    }
    
    if(isDeleteblock(y+1,x+1,1,1,mark))
    {
       volume += findDeleteBlock(y+1,x+1,3,mark);
    }
    
    if(isDeleteblock(y,x+1,1,1,mark))
    {
       volume += findDeleteBlock(y,x+1,2,mark);
    }
    
    //map0[y][x] = mark + 30;
    //map0[y][x-1] = mark + 30;
    //map0[y-1][x] = mark + 30;
    //map0[y-1][x-1] = mark + 30;
    //cout << y << "#" << x << " "<< volume << endl;
    return volume;
}


int mapControl()
{
    int answer = 0;

    for(int y = 0 ; y < col-1; ++y)
    {
         //row check 
        
        auto lt = map0[y].begin();
        for(int x = 0 ; x < row-1; ++x,++lt)
        {
            char map_mark = *lt;
            
            if(map_mark == '#')
            {
                continue;
            }
            
            else if(map_mark > 90)
            {
                continue;
            }
            
            else if(isDeleteblock(y,x,1,1,map_mark))
            {
                int data = findDeleteBlock(y,x,4,map_mark);
                //cout << data << " ";
            }            
        }
        
        //cout << endl;
    }
    
    //viewer();
    
    for(int y = 0 ; y < col;++y)
    {
        for(auto x = map0[y].begin() ; x != map0[y].end();)
        {
            if(*x > 90)
            {
                x = map0[y].erase(x);
                map0[y].push_back('#');
                ++answer; 
            }
            
            else
            {
                ++x;
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
        list<char> alpa;
        for(int y = row-1 ; y >= 0 ; --y)
        {
            alpa.push_back(board[y][x]);
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
