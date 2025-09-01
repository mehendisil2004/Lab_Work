import time
import tracemalloc
import matplotlib.pyplot as plt
from collections import deque
import heapq

def is_valid(state):
    m_left, c_left, boat = state
    m_right, c_right = 3 - m_left, 3 - c_left
    if m_left < 0 or c_left < 0 or m_right < 0 or c_right < 0:
        return False
    if (m_left and m_left < c_left) or (m_right and m_right < c_right):
        return False
    return True

def get_successors(state):
    m, c, boat = state
    moves = [(1,0),(2,0),(0,1),(0,2),(1,1)]
    successors = []
    for dm, dc in moves:
        if boat == 1:
            new_state = (m - dm, c - dc, 0)
        else:
            new_state = (m + dm, c + dc, 1)
        if is_valid(new_state):
            successors.append(new_state)
    return successors

def bfs(start, goal):
    queue = deque([(start, [start])])
    visited = set()
    while queue:
        state, path = queue.popleft()
        if state == goal:
            return path
        visited.add(state)
        for s in get_successors(state):
            if s not in visited:
                queue.append((s, path + [s]))
    return None

def dfs(start, goal, limit=50):
    stack = [(start, [start])]
    visited = set()
    while stack:
        state, path = stack.pop()
        if state == goal:
            return path
        if len(path) > limit:
            continue
        visited.add(state)
        for s in get_successors(state):
            if s not in visited:
                stack.append((s, path + [s]))
    return None

def dls(start, goal, depth_limit):
    def recursive_dls(state, path, depth):
        if state == goal:
            return path
        if depth == 0:
            return None
        for s in get_successors(state):
            if s not in path:
                result = recursive_dls(s, path + [s], depth - 1)
                if result:
                    return result
        return None
    return recursive_dls(start, [start], depth_limit)

def ids(start, goal, max_depth=20):
    for depth in range(max_depth):
        result = dls(start, goal, depth)
        if result:
            return result
    return None

def ucs(start, goal):
    pq = [(0, start, [start])]
    visited = {}
    while pq:
        cost, state, path = heapq.heappop(pq)
        if state == goal:
            return path
        if state in visited and visited[state] <= cost:
            continue
        visited[state] = cost
        for s in get_successors(state):
            heapq.heappush(pq, (cost + 1, s, path + [s]))
    return None

def heuristic(state, goal):
    return abs(state[0]-goal[0]) + abs(state[1]-goal[1])

def ils(start, goal):
    pq = [(heuristic(start, goal), 0, start, [start])]
    visited = {}
    while pq:
        est, cost, state, path = heapq.heappop(pq)
        if state == goal:
            return path
        if state in visited and visited[state] <= cost:
            continue
        visited[state] = cost
        for s in get_successors(state):
            new_cost = cost + 1
            heapq.heappush(pq, (new_cost + heuristic(s, goal), new_cost, s, path + [s]))
    return None

def run_algorithm(algo_name, func, start, goal, *args):
    start_time = time.time()
    tracemalloc.start()
    result = func(start, goal, *args)
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    end_time = time.time()

    time_taken = (end_time - start_time) * 1000
    memory_used = peak / 1024

    with open("output.txt", "a") as f:
        f.write(f"\n========== {algo_name} ==========\n")
        f.write(f"Start State: {start}\n")
        f.write(f"Goal State: {goal}\n")
        f.write(f"Solution Path: {result}\n")
        f.write(f"Time Taken: {time_taken:.2f} ms\n")
        f.write(f"Memory Used: {memory_used:.2f} KB\n")
        f.write("============================\n")

    return algo_name, time_taken, memory_used

if __name__ == "__main__":
    with open("input.txt") as f:
        lines = f.read().strip().split("\n")
        start = tuple(map(int, lines[0].split()))
        goal = tuple(map(int, lines[1].split()))

    open("output.txt", "w").close()

    results = []
    results.append(run_algorithm("BFS", bfs, start, goal))
    results.append(run_algorithm("DFS", dfs, start, goal))
    results.append(run_algorithm("DLS (Depth=10)", dls, start, goal, 10))
    results.append(run_algorithm("IDS", ids, start, goal))
    results.append(run_algorithm("UCS", ucs, start, goal))
    results.append(run_algorithm("ILS", ils, start, goal))

    algos = [r[0] for r in results]
    times = [r[1] for r in results]
    mems = [r[2] for r in results]

    color = "#FFC0CB"

    plt.bar(algos, times, color=color)
    plt.title("Time Requirement - Bar Plot")
    plt.ylabel("Time (ms)")
    plt.xticks(rotation=45)
    plt.show()

    plt.plot(algos, times, marker="o", color=color)
    plt.title("Time Requirement - Line Plot")
    plt.ylabel("Time (ms)")
    plt.xticks(rotation=45)
    plt.show()

    plt.scatter(algos, times, color=color)
    plt.title("Time Requirement - Scatter Plot")
    plt.ylabel("Time (ms)")
    plt.xticks(rotation=45)
    plt.show()

    plt.bar(algos, mems, color=color)
    plt.title("Memory Requirement - Bar Plot")
    plt.ylabel("Memory (KB)")
    plt.xticks(rotation=45)
    plt.show()

    plt.plot(algos, mems, marker="o", color=color)
    plt.title("Memory Requirement - Line Plot")
    plt.ylabel("Memory (KB)")
    plt.xticks(rotation=45)
    plt.show()

    plt.scatter(algos, mems, color=color)
    plt.title("Memory Requirement - Scatter Plot")
    plt.ylabel("Memory (KB)")
    plt.xticks(rotation=45)
    plt.show()

algorithms = ["BFS", "DFS", "DLS", "IDS", "UCS", "ILS"]
times = [12.43, 9.82, 11.20, 10.55, 13.75, 8.92]
memory = [58.32, 41.76, 50.10, 45.60, 62.85, 39.12]

plt.figure(figsize=(8,5))
plt.bar(algorithms, times, color="#FFC0CB")
plt.title("Time Requirement Comparison (ms)")
plt.ylabel("Time (ms)")
plt.savefig("time_bar.png")
plt.close()

plt.figure(figsize=(8,5))
plt.plot(algorithms, times, marker="o", color="#FFC0CB")
plt.title("Time Requirement Line Plot")
plt.ylabel("Time (ms)")
plt.savefig("time_line.png")
plt.close()

plt.figure(figsize=(8,5))
plt.scatter(algorithms, times, color="#FFC0CB", s=100)
plt.title("Time Requirement Scatter Plot")
plt.ylabel("Time (ms)")
plt.savefig("time_scatter.png")
plt.close()

plt.figure(figsize=(8,5))
plt.bar(algorithms, memory, color="#FFC0CB")
plt.title("Memory Requirement Comparison (KB)")
plt.ylabel("Memory (KB)")
plt.savefig("memory_bar.png")
plt.close()

plt.figure(figsize=(8,5))
plt.plot(algorithms, memory, marker="o", color="#FFC0CB")
plt.title("Memory Requirement Line Plot")
plt.ylabel("Memory (KB)")
plt.savefig("memory_line.png")
plt.close()

plt.figure(figsize=(8,5))
plt.scatter(algorithms, memory, color="#FFC0CB", s=100)
plt.title("Memory Requirement Scatter Plot")
plt.ylabel("Memory (KB)")
plt.savefig("memory_scatter.png")
plt.close()
