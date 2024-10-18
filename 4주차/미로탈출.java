import java.util.*;

class Solution {
    Queue<int[]> list_a11 = new LinkedList<>();
    Queue<int[]> list_a12 = new LinkedList<>();
    
    public int bfs_1(String[] maps, char target, Queue<int[]> list_a)
    {
        if (list_a.size() <= 0) {return -1;}
        int list_size0 = list_a.size();

        for (int z = 0; z < list_size0; ++z)
        {
            int[] alpa = list_a.poll();//첫 좌표가지기

            if (alpa[0] < 0 || alpa[0] >= maps.length) {continue;}
            if (alpa[1] < 0 || alpa[1] >= maps[0].length()) {continue;}
            if (maps[alpa[0]].charAt(alpa[1]) == 'X') {continue;}

            if (maps[alpa[0]].charAt(alpa[1]) == target)
            {
                return alpa[2];
            }
            
            
            StringBuilder sb = new StringBuilder(maps[alpa[0]]);
            sb.setCharAt(alpa[1],'X');
            maps[alpa[0]] = sb.toString();
            
            list_a.add(new int[]{alpa[0] + 1, alpa[1], alpa[2] + 1 });
            list_a.add(new int[]{alpa[0] - 1, alpa[1], alpa[2] + 1 });
            list_a.add(new int[]{alpa[0] , alpa[1] + 1, alpa[2] + 1 });
            list_a.add(new int[]{alpa[0] , alpa[1] - 1, alpa[2] + 1 });
        }

        return bfs_1(maps, target,list_a);
    }
    
    public int solution(String[] maps) {
        
        String[] maps2 = Arrays.copyOf(maps, maps.length);
        int answer0 = -1;
        int answer1 = -1;
        
        int y = 0;
        for(String map : maps)
        {
            int x = 0;
            for(char alpa : map.toCharArray())
            {
                int[] data = {y,x,0}; 
                
                if(alpa == 'S')
                {
                    list_a11.add(data);
                    answer0 = bfs_1(maps, 'L', list_a11); //1.1 S에서 L로 가는 최소 시간 1.1
                    if (answer0 < 0) {return -1;} //2.두 개의 루트 중 하나라도 에러가 나면 -1를 return
                }                
                
                else if(alpa == 'L')
                {
                    list_a12.add(data);   
                    answer1 = bfs_1(maps2, 'E', list_a12); //1.2 L에서 E로 가는 최소 시간 1.2
                    if (answer1 < 0) {return -1;} //2.두 개의 루트 중 하나라도 에러가 나면 -1를 return
                }
                ++x;
            }       
            
            ++y;
        }
    
        return answer0 + answer1;
    }
}
