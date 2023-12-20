from collections import defaultdict
from heapq import heappop, heappush

def dijkstra(n, u, v, graph, t):
    dist = [float('inf') for _ in range(n + 1)]
    dist[u] = 0
    hq = [(0, u)]
    print("start")

    while hq:
        w, node = heappop(hq)

        for nw, next_node in graph[node]:
            if dist[next_node] > w + nw:
                dist[next_node] = w + nw
                heappush(hq, (w + nw, next_node))
                # print("node: ", node, "next_node: ", next_node, "nw: ", nw)
    if t:
        print("u: ", u, "v: ", v, "dist: \n", dist)
        return dist[v]
    else:
        return dist

def solution(n, s, a, b, fares):
    answer = 0
    graph = defaultdict(list)
    
    for v1, v2, dist in fares:
        graph[v1].append([dist, v2])
        graph[v2].append([dist, v1])
    
    c1 = dijkstra(n, s, a, graph, True) + dijkstra(n, a, b, graph, True) # s -> a -> b
    c2 = dijkstra(n, s, b, graph, True) + dijkstra(n, b, a,graph, True) # s -> b -> a
    c3 = dijkstra(n, s, b, graph, False)
    c3 = c3[a] + c3[b]
    print(c1, c2, c3)
    return min(c1, c2, c3)

print(solution(	6, 4, 6, 2, [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))