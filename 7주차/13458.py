n = int(input())
alpa = list(map(int, input().split()))
beta = list(map(int, input().split()))
answer = n

for ind in alpa:
    ind -= beta[0]

    if (ind > 0):
        answer += int((ind / beta[1])) + (1 if (ind % beta[1]) > 0 else 0)

print(answer)
