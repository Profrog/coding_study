#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = skill_trees.size();
    
    map<char, int> skill_dep;
        
    for(int idx = 0 ; idx < skill.length(); ++idx) //1.map 컨테이너를 사용하여 의존성 대상 스킬 명과 a.에 따른 의존성 값을 가진 컨테이너를 만듬
    {
        skill_dep.insert({skill[idx], idx});
    }
        
    
	for (auto cur_tr = skill_trees.begin() ; cur_tr != skill_trees.end(); ++cur_tr)
	{
        int dep_calcul = -1; //2.각 스킬트리에서 의존성 계산에 대하여 초기값 혹은 대상이 아닌 의존성 값은 -1로 정의함
		for (auto idx = (*cur_tr).begin(); idx != (*cur_tr).end() ; ++idx)
		{
			int cur_dep = -1;
            auto cur_idx = skill_dep.find((*idx));
            
            if(cur_idx != skill_dep.end())
            {
                cur_dep = cur_idx -> second; 
        
                if(dep_calcul == cur_dep - 1) //3.의존성이 확인되면 map 컨테이너에서 의존성 값을 찾고 그 값이 이전에 저장한 값보다 1큰지 확인함
                {
                    dep_calcul = cur_dep;
                }
                
                else
                {
                    --answer; //4.의존성이 위배되면 c.에 따라 반환 트리 개수 값에서 제외
                    break;
                }
            
            }
            
		}
	}

	return answer;
}
