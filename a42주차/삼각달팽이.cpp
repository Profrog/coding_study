#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> answer0;
vector<int> answer;

int indexX = 0;
int indexY = 0;
int data0 = 0;

void making_data(int size0, int mode) //3. 해당 함수에서 인덱스를 조절하여 b,c,d를 만족하도록 이차원 배열의 값을 넣어준다.
{
   
	if (mode == 0)
    {
		for (int x = 0; x < size0; x++)
		{
			answer0[indexX++][indexY] = ++data0;
		}
        
        cout << indexX;
        
        indexX--;
	    indexY++;
    }

	else if (mode == 1)
    {
		for (int x = 0; x < size0; x++)
		{
			answer0[indexX][indexY++] = ++data0;
		}

        indexX--;
        indexY--;
        indexY--;
    }

	else
    {
		for (int x = 0; x < size0; x++)
		{
			answer0[indexX--][indexY--] = ++data0;
		}

	indexX++;
	indexX++;
	indexY++;
    }
}


vector<int> solution(int n) {
	int size0 = n;

    vector<int> data(0,0);
	for (int x = 1; x <= n; x++)  //1. 삼각 달팽이를 나타낼 이차원 배열을 만들고 꼴을 만들어준다.
	{
		data.push_back(0);
		answer0.push_back(data);
	}

    int mode = 0;
	while (size0 > 0) {
		making_data(size0--, (mode++)%3); //2. e에 따라 변의 크기를 넘겨주고 b,c,d는 모드로 구별하는 함수를 만든다.
	}
	
    
    for (int x = 0; x < answer0.size(); x++) //4. 2차원 배열을 1차원 배열로 바꾸어 반환한다.
	{
		for (int y = 0; y < answer0[x].size(); y++)
		{
			answer.push_back(answer0[x][y]);
		}
	}

	return answer;
}
