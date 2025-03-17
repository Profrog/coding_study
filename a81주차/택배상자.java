import java.util.*;

class Solution {
    
    LinkedList<Integer> origin0;
    Stack<Integer> temp0;
    
    boolean makeDatastack()
    { //4.order의 모든 원소를 맞췄거나, 더이상 메인 벨트에서 원소를 꺼낼 수 없을 때 원소 맞춘 개수 반환
        if (origin0.size() > 0)
        {
            temp0.push(origin0.pollFirst());
            return true;
        }

        return false;
    }
    
    public int solution(int[] order) {
        
        int answer = 0;
        origin0 = new LinkedList<>();
        temp0 = new Stack<>();
        
        int ol = order.length;
        for(int i = 1; i <= ol; ++i)
        {//1.queue(메인 벨트)에 1~n까지의 원소 삽입
            origin0.add(i);
        }
        
        for (int i = 0; i < ol; ++i)
        {
            if (temp0.empty())
            { //2.stack(보조벨트)가 비어있으면 메인벨트에서 원소 하나 빼서 보조벨트에 넣기
                if (!makeDatastack()){return answer;}
            }

            while (temp0.peek() != order[i])
            { //3.보조벨트에서 꺼낸 원소가 order의 원소와 같을 때 까지 반복
                if (!makeDatastack()){return answer;}
            }
                   
            temp0.pop();
            ++answer;
        }

        return answer;
    }
    
}
