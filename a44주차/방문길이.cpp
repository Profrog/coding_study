#include <string>
#include <map>
using namespace std;


const int NUM_mArrow = 4;
const int MIN_INDEX = 0;
const int MAX_INDEX = 11;


map<char, int> dir_dic;
int mMap[11][11][4];
int mCurIndex[2];
int mArrow[4][2]; /*0:U ,1:D ,2:R ,3:L */
char mArrow_list[4];
int mAnswer;


bool OverDir(int* alpa)
{
    bool return0 = true;

    if ((MIN_INDEX <= alpa[0]) && (alpa[0] < MAX_INDEX))
    {
        if ((MIN_INDEX <= alpa[1]) && (alpa[1] < MAX_INDEX))
        {
            return0 = false;
        }
    }

    return return0;
}


int CheckIndex(int alpa)
{
    switch(alpa)
    {
        case 0 :
            return 1;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 2;
    }
}


bool MovingMap(int Idx)
{
    bool return0 = false;
    int beta[2] = { mCurIndex[0] + mArrow[Idx][0], mCurIndex[1] + mArrow[Idx][1] };

    if (OverDir(beta)) //3.c에 따라 맵을 넘어설 경우 새로운 길의 업데이트를 취소한다.
    {
        --mAnswer;
    }

    else
    {
        if ((mMap[mCurIndex[0]][mCurIndex[1]][Idx] > 0) && (mMap[beta[0]][beta[1]][CheckIndex(Idx)] > 0))
        { //4.d에 따라 맵 데이터상으로 지나간 길일 경우 새로운 길의 업데이트를 취소한다
            --mAnswer;
        }

        ++mMap[mCurIndex[0]][mCurIndex[1]][Idx];
        ++mMap[beta[0]][beta[1]][CheckIndex(Idx)];
        mCurIndex[0] = beta[0];
        mCurIndex[1] = beta[1];
        return0 = true;
    }
    
    return return0;
}

int solution(string dirs) {

    mCurIndex[0] = 5; //1.a에 따라 맵과 움직임을 정의한다.
    mCurIndex[1] = 5;

    mArrow[0][0] = 0;
    mArrow[0][1] = 1;
    mArrow[1][0] = 0;
    mArrow[1][1] = -1;

    mArrow[2][0] = 1;
    mArrow[2][1] = 0;
    mArrow[3][0] = -1;
    mArrow[3][1] = 0;
    
    dir_dic.insert(pair<char,int>('U',0));
    dir_dic.insert(pair<char,int>('D',1));
    dir_dic.insert(pair<char,int>('R',2));
    dir_dic.insert(pair<char,int>('L',3));
    
    mAnswer = (int)(dirs.length());
    for (auto alpa = dirs.begin(); alpa != dirs.end(); ++alpa)
    {
        int dir_idx = dir_dic.find(*alpa)->second;
        MovingMap(dir_idx); //2.주어진 dir에 따라 현재 움직임을 업데이트 하고 맵 데이터에 반영한다.
    }

    return mAnswer;
}

