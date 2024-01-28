#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {

    vector<int> answer(numbers.size(), -1);
    vector<int> target(1, 0); //1. 첫번째 원소를 갱신 예약리스트에 등록한다.

    int count = 0;
    for (int i = 1; i < numbers.size(); ++i)
    {
        while (target.size() && (numbers[i] > numbers[target.back()])) //2. 리스트를 두번째 원소부터 탐색하며, 큰수를 발견하면 갱신 예약 리스트의 값을 뒤에서 확인하여 제거한다.(갱신 예약 리스트는 로직 특성 상 내림차순으로 정렬되어 있다.)
        {                                                              //3. 갱신 예약 리스트가 내림차순인 이유는 어떤 수보다 뒤의 있는 수가 더 컷다면(오름차순이었다면) 큰수발견으로 판정되어 갱신예약리스트에서 제거되었을 것
            answer[target.back()] = numbers[i];
            target.pop_back();
        }

        target.push_back(i);
    }

    return answer;
}
