import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        int last_idx_truck = truck_weights.length;
        int idx = 0;
        int cur_weight = 0;
        
        Queue<Integer> cur_queue = new LinkedList<>();
        for (int i = 0; i < bridge_length; i++) {
            //1.다리에 해당하는 큐 컨테이너를 만들고 0 값으로 채워 넣음
            cur_queue.add(0);
        }
        
        while(idx < last_idx_truck)
        {
            ++answer;
            cur_weight -= cur_queue.poll();
            
            //2.모든 트럭을 처리할 때까지 다리에 트럭을 얹을 수 있다면 트럭을 얹음
            if (cur_weight + truck_weights[idx] <= weight) {
                cur_queue.add(truck_weights[idx]);
                cur_weight += truck_weights[idx];
                idx++;
            }
            
            //3.그럴 수 없다면 0값을 추가하여 트럭값이 큐에서 빠지기를 기다림
            else 
            {
                cur_queue.add(0);
            }
        }
            
        return answer + bridge_length;
    }
}
