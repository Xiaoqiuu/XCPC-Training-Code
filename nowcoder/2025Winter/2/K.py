from sys import stdin
from collections import deque
n,m=map(int,stdin.readline().split())
grid=[stdin.readline().strip() for _ in range(n)]
visited=[[False]*m for _ in range(n)]
dirs=[(-1,0),(1,0),(0,-1),(0,1)]
min_k=float('inf')
for i in range(n):
    for j in range(m):
        if grid[i][j]=='1' and not visited[i][j]:
            q=deque()
            q.append((i,j))
            visited[i][j]=True
            adj=set()
            while q:
                x,y=q.popleft()
                for dx,dy in dirs:
                    nx,ny=x+dx,y+dy
                    if 0<=nx<n and 0<=ny<m:
                        if grid[nx][ny]=='0':
                            adj.add((nx,ny))
                        elif grid[nx][ny]=='1' and not visited[nx][ny]:
                            visited[nx][ny]=True
                            q.append((nx,ny))
            min_k=min(min_k,len(adj))
print(min_k)
