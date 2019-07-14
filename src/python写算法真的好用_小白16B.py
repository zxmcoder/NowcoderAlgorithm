# https://ac.nowcoder.com/acm/contest/949/B
n,m=map(int,input().split(' '))
for _ in range(m):
    x,y=map(int,input().split(' '))
    print(3*(2**y-2**(x-1))+2*(x-y)-2)