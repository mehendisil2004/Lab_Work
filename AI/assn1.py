from collections import deque

graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 5],
    3: [1],
    4: [1],
    5: [2]
}

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    print(f"BFS traversal starting from {start}: ", end="")
    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbour in graph.get(node, []):
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)
    print()

def print_graph(graph):
    print("Graph (Adjacency List):")
    for node in graph:
        print(f"{node}: {graph[node]}")

if __name__ == "__main__":
    print_graph(graph)
    bfs(graph, 0)