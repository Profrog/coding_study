n = int(input())
alpa = []
answer = 0

for i in range(0,n):
    time0,value0 = map(int, (input().split()))
    if(i + time0 <= n):
      for j in alpa:
        if(j[0] <= i):
            alpa.append([i + time0, j[1] + value0])

      alpa.append([i + time0, value0])
      #print(alpa)


for i in alpa:
    answer = max(answer, i[1])

print(answer)
