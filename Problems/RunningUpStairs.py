# Problem link: https://csacademy.com/ieeextreme-practice/task/96c8b1313edd72abf600facb0a14dbab/
# By: Osama Khallouf

N = 22005
ans = [0 for i in range(N)]

ans[0] = 1
ans[1] = 1

for i in range(2,N):
    ans[i] = ans[i-1] + ans[i-2]

t = int(input())
for i in range(t):
    n = int(input())
    print(ans[n])
