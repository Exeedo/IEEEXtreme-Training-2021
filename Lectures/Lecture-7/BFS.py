N = 20
visited = [False]*N
dist = [0]*N
adj = [[] for i in range(N)]

def BFS(source):
	queue = []
	idx = 0
	queue.append(source)
	visited[source] = True
	
	while idx < len(queue): # This is the same as while(!q.empty())
		v = queue[idx]
		idx += 1
		for w in adj[v]:
			if visited[w]:
				continue
			queue.append(w)
			visited[w]=True
			dist[w] = dist[v] + 1

with open("BFS_input.txt", 'r') as in_file:
	line_number=0
	n,e = 0,0
	for line in in_file:
		if line_number == 0:
			n,m=[int(x) for x in line.split()]
		else:
			a,b=[int(x) for x in line.split()]
			adj[a].append(b)
			adj[b].append(a)
		line_number += 1

s = 1
BFS(s)

for i in range(1,n+1):
	print(f"Distance between source (1) and {i} = {dist[i]}")

'''
[1, 2, 5, 3, 4, 6]
                   ^

'''