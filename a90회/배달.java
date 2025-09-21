import java.util.*;

class Solution {
    
    int[][] graph;
    
    public int solution(int N, int[][] road, int K) {
        
        graph = new int[N+1][N+1]; //1.마을 간 시간을 담는 2차원 배열에, 데이터 채우기
       
        for (int[] r : road) {
            
            if(graph[r[0]][r[1]] == 0 || graph[r[0]][r[1]] > r[2])
            {
                graph[r[0]][r[1]] = r[2];
                graph[r[1]][r[0]] = r[2];
            }
        }
        
        int[] dist = new int[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE); //2.1번 마을에서 마을 간 시간을 담는 1차원 배열을 아주 큰 값으로 채우기
        dist[1] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[1]-b[1]);
        pq.add(new int[]{1,0});
        
        while (!pq.isEmpty()) {
            //3. 우선 순위 큐에 {마을 명, 마을 간 루트길이} = {1,0}값을 넣고 우선순위 큐에서 돌리면서 최소 마을 간 루트길이에 대해 반복적으로 로직 적용하여 각 마을 간 최소 루트길이 구함
            int[] cur = pq.poll();
            int node = cur[0];
            int cost = cur[1];
            
            if (cost > dist[node]) continue;
            
            
            for(int nextNode = 0; nextNode < N+1; ++nextNode)
            {
                if(graph[node][nextNode] > 0)
                {
                    int nextCost = cost + graph[node][nextNode];
                    
                    if (nextCost < dist[nextNode]) {
                        dist[nextNode] = nextCost;
                        pq.add(new int[]{nextNode, nextCost});
                    }
                    
                }
            }
        }
        
        int answer = 0;
        for (int d : dist) { //4. K 시간 내의 마을 간 루트길이 반환
            if (d <= K) answer++;
        }
        
        return answer;
    }
}
