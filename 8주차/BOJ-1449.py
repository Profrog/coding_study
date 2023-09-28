N, L = map(int, input().split())
lick_points = list(map(int, input().split()))
lick_points.sort()

cnt = 0
last_taping_start = 0
last_taping_end = 0
for lick_point in lick_points:
    if (last_taping_start <= lick_point <= last_taping_end):
        continue
    cnt += 1
    last_taping_start = lick_point - 0.5
    last_taping_end = last_taping_start + L

print(cnt)
