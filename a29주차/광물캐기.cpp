#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int DIA_PICKER = 0;
const int IRON_PICKER = 1;
const int STONE_PICKER = 2;

vector<string> mine_map = { "stone", "iron", "diamond" };
vector<pair<int, int>> thisPicker;
vector<vector<int>> mineral_current;

bool compare0(pair<int, int>& alpa, pair<int, int>& beta)
{
	return alpa.first > beta.first;
}

int GetStressByPick(string mineral_name,int mine_index)
{
	int factor;
	for (factor = 0; factor < mine_map.size(); ++factor)
		if (mine_map[factor] == mineral_name)
		{
			++mineral_current[mine_index][factor];
			break;
		}

	return pow(5, factor);
}

int return_fatigue(int index, int picker)
{
	int answer = 0;
	picker = 2 - picker;

	for (int i = 0; i < mineral_current[index].size(); ++i)
	{
		int factor = picker >= i ? 0 : i - picker;
		answer += mineral_current[index][i] * pow(5, factor);
		
	}

	return answer;
}


int solution(vector<int> picks, vector<string> minerals) {

	int answer = 0;
	int mod_mineral = (minerals.size() % 5) > 0 ? 1 : 0;
	int iPickSum = picks[DIA_PICKER] + picks[IRON_PICKER] + picks[STONE_PICKER];

	for (int index = 0; index < minerals.size(); ++index) //1. 제공되는 광물을 5개씩 묶어 돌 곡갱이를 기준으로 그룹 피로도를 계산한다.
	{
		if (index >= iPickSum * 5) //2.b에 따라 곡갱이가 모두 소진되면 그룹화를 멈춘다. 그리고 피로도가 높은 순으로 정렬한다.
			break;

		if (index % 5 == 0)
		{
			mineral_current.push_back({ 0,0,0 });
			thisPicker.push_back(pair<int,int>(0,0));
		}

		thisPicker[(int)(index / 5)].first += GetStressByPick(minerals[index],(int)(index / 5));
		thisPicker[(int)(index / 5)].second = (int)(index / 5);
	}

	sort(thisPicker.begin(), thisPicker.end(), compare0); //2.b에 따라 곡갱이가 모두 소진되면 그룹화를 멈춘다. 그리고 피로도가 높은 순으로 정렬한다.
	
	for (auto alpa = thisPicker.begin(); alpa != thisPicker.end(); ++alpa) //3.현재 그룹에 대하여 다이아몬드 -> 철 -> 돌 곡괭이 순으로 매칭 후 계산되는 피로도의 합을 반환한다.
	{
		if (picks[DIA_PICKER] > 0)
		{
			answer += return_fatigue(alpa->second, DIA_PICKER);
			--picks[DIA_PICKER];
		}
		else if (picks[IRON_PICKER] > 0)
		{
			answer += return_fatigue(alpa->second, IRON_PICKER);
			--picks[IRON_PICKER];
		}
		else if (picks[STONE_PICKER] > 0)
		{
			answer += return_fatigue(alpa->second, STONE_PICKER);
			--picks[STONE_PICKER];
		}
		else
		{
			break;
		}
	}

	return answer;
}
