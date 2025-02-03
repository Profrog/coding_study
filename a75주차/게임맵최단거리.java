import java.util.*;

class Solution {    
    private int[][] map0;
    private int[][] chkmap;
    
    private int answer = 1;
    private Queue<int[]> poslist;
    private boolean chkarrive = false;
    
    private boolean chkMap(int x, int y)
    {
        //2.맵을 벗어나거나 장해물이 있는 인덱스, 이미 방문하였던 경로는 무시한다.
        int max_x = map0.length -1;
        int max_y = map0[0].length -1;
        if(x < 0 || y < 0){return false;} //맵 벗어남(1)
        if(x > max_x || y > max_y){return false;} //맵 벗어남(2)
        if(chkmap[x][y] > 0) {return false;} //새로운 길인 경우만 탐색하려구
        if(map0[x][y] == 0){return false;} //벽처리
        else if(x == max_x && y == max_y){chkarrive = true; return true;} //도착지
        else return true; //갈 수 있는 길
    }
    
    private int controlMap()
    { 
        int lens = poslist.size();
        
        for(int idx = 0 ; idx < lens; idx++)
        {
            int[] pos = poslist.poll();
            int x = pos[0];
            int y = pos[1];
            
            //.1,현재 인덱스를 기준으로 상하좌우 중 갈 수 있는 경로를 확인한다.
            for(int a = 1; a >= -1; --a)
            {
                for(int b = 1; b >= -1; --b)
                {
                    if((a+b == 1) || (a+b == -1)) //대각선으로는 못 가
                    {
                        if(chkMap(x+a,y+b))
                        {
                            chkmap[x+a][y+b] = answer + 1;
                            poslist.add(new int[]{x+a,y+b});             
                        }
                    }    
                }
            }
        }
            
        
        if(poslist.size() > 0)
        {
            //3.bfs로 탐색하면서, 가장 먼저 도착 지점을 밟았을 때, 통과 루트 반환 개수를 반환한다.
            ++answer;
            if(chkarrive) {return 0;}
            else return controlMap();  
        }
        
        else return 1;
    }
    
    
    public int solution(int[][] maps) {
        map0 = maps;
        chkmap = new int[maps.length][maps[0].length];
        poslist = new LinkedList<>();
        
        chkmap[0][0] = 0;
        poslist.add(new int[]{0,0}); 
        controlMap();
        
        //System.out.println(chkarrive);
        if(chkarrive == false) {return -1;}
        else return answer;
    }
}
