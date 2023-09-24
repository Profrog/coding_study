#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {

    vector<int> answer(numbers.size(), -1);
    vector<int> exam(1, numbers[0]);
    vector<int> exam_index(1, 0);

    int count = 0;
    for (int i = 1; i < numbers.size(); ++i)
    {
        while (!exam.empty() && numbers[i] > exam.back())
        {
            answer[exam_index.back()] = numbers[i];

            exam.pop_back();
            exam_index.pop_back();
        }

        exam.push_back(numbers[i]);
        exam_index.push_back(i);
    }

    return answer;
}
