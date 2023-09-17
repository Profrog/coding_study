
from collections import deque

top = []
top.append(deque(list(map(int,list(input())))))
top.append(deque(list(map(int,list(input())))))
top.append(deque(list(map(int,list(input())))))
top.append(deque(list(map(int,list(input())))))


def right_hand(index):
    top[index].appendleft(top[index].pop())


def left_hand(index):
    top[index].append(top[index].popleft())


def moving_top(start, arrow, step):

    #print(start)
    if(step <= 0 and start-1 >=0 and top[start-1][2] != top[start][6]):
        moving_top(start-1, -1 * arrow,-1)

    if (step >= 0 and start + 1 < 4 and top[start][2] != top[start+1][6]):
        moving_top(start+1, -1 * arrow,1)

    if(arrow == 1):
        return right_hand(start)

    else:
        return left_hand(start)

n = int(input())

for i in range(0,n):
  a,b = map(int, input().split())
  moving_top(a-1,b,0)

answer = 0
for i in range(0,4):
 answer += top[i][0]*pow(2,i)

print(answer)
