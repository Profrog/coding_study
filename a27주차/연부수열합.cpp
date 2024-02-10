#include <string>
#include <vector>

using namespace std;
vector<int> answer(2, 0);
vector<int> search_data(2,0);

void priority_consult(vector<int>& new0) //4.b에 따라 길이가 짧고, 시작 인덱스가 작은 수열을 반환 수열로 등록한다.
{
    int collection0[2][2] = {{answer[0],answer[1]}, {new0[0], new0[1]}};

    if ((new0[1] - new0[0]) == (answer[1] - answer[0]))
    {
        int more_index = (new0[0] < answer[0]) ? 1 : 0;
        answer[0] = collection0[more_index][0];
        answer[1] = collection0[more_index][1];
    }

    else
    {
        int more_index = ((new0[1] - new0[0]) < (answer[1] - answer[0])) ? 1 : 0;
        answer[0] = collection0[more_index][0];
        answer[1] = collection0[more_index][1];
    }
}

int making_seq(vector<int>& sequence, vector<int>& search, int data_index,int k) 
{
    int reverse_index = 1 - data_index;
    int weight0 = (data_index == 0) ? (+1) : (-1);

    if (search_data[data_index] < k) //1.부분 수열을 만들 때, 현재 부분 수열의 합이 k보다 작으면 확장하고, 작으면 축소한다.
    {
        search[reverse_index] += weight0;
        search_data[data_index] += sequence[search[reverse_index]];
    }

    else if (search_data[data_index] > k)
    {
        search_data[data_index] -= sequence[search[data_index]];
        search[data_index] += weight0;
    }

    if (search_data[data_index] == k)
    {
        priority_consult(search);

        search[reverse_index] += weight0;
        search_data[data_index] += sequence[search[reverse_index]];
    }

    return search[reverse_index];
}


vector<int> solution(vector<int> sequence, int k) {

    int slast_index = sequence.size() - 1;
    answer = {0, slast_index  + 1};
    search_data = { sequence[0], sequence[slast_index] };
    
    vector<int> front_search = { 0,0 };
    vector<int> back_search = { slast_index, slast_index };
    int safe_boundary = 0;

    while (front_search[0] < back_search[0])
    {
        safe_boundary = making_seq(sequence,front_search, 0, k); //2. 원본수열의 앞에서 부터 만드는 부분 수열은 끝 인덱스를 늘려 확장하고, 뒤에서 부터 만드는 부분 수열은 시작 인덱스를 줄여 확장한다.

        if (safe_boundary < 0 || safe_boundary > slast_index)
            break;

        safe_boundary = making_seq(sequence,back_search, 1, k); //3. 원본수열의 앞에서 부터 만드는 부분 수열은 시작 인덱스를 늘려 축소하고, 뒤에서 부터 만드는 부분 수열은 끝 인덱스를 늘여 축소한다.

        if (safe_boundary < 0 || safe_boundary > slast_index)
            break;
    }

    return answer;
}
