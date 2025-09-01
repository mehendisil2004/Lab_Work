def get_input_and_write_file():
    print("Enter puzzle size N (e.g., 3 for 8-puzzle or 4 for 15-puzzle):")
    N = int(input())

    lines = [str(N)]

    print(f"\nEnter the {N}x{N} START state (use 0 for blank):")
    for i in range(N):
        row = input(f"Start Row {i+1}: ").strip()
        lines.append(row)

    print(f"\nEnter the {N}x{N} GOAL state (use 0 for blank):")
    for i in range(N):
        row = input(f"Goal Row {i+1}: ").strip()
        lines.append("") if i == 0 else None
        lines.append(row)

    with open("input.txt", "w") as f:
        f.write("\n".join(lines))

    print("\nInput written to input.txt\n")

get_input_and_write_file()


import sys
import copy

DIRECTIONS = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def read_input(filename):
    with open(filename, 'r') as f:
        lines = [line.strip() for line in f if line.strip()]

    N = int(lines[0])
    start = [list(map(int, lines[i].split())) for i in range(1, 1+N)]
    goal = [list(map(int, lines[i].split())) for i in range(1+N, 1+2*N)]
    return N, start, goal

def write_output(path, filename="output.txt"):
    with open(filename, 'w') as f:
        for step, state in enumerate(path):
            f.write(f"Step {step}:\n")
            for row in state:
                f.write(" ".join(map(str, row)) + "\n")
            f.write("\n")

def find_zero(state):
    for i in range(len(state)):
        for j in range(len(state[i])):
            if state[i][j] == 0:
                return i, j
    return -1, -1

def is_goal(state, goal):
    return state == goal

def serialize(state):
    return tuple(tuple(row) for row in state)

def get_neighbors(state, N):
    x, y = find_zero(state)
    neighbors = []
    for dx, dy in DIRECTIONS:
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < N:
            new_state = copy.deepcopy(state)
            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
            neighbors.append(new_state)
    return neighbors

def dfs(start, goal, N, max_depth=10000):
    stack = [(start, [start])]
    visited = set()
    visited.add(serialize(start))

    while stack:
        current, path = stack.pop()

        if is_goal(current, goal):
            return path

        if len(path) > max_depth:
            continue

        for neighbor in get_neighbors(current, N):
            key = serialize(neighbor)
            if key not in visited:
                visited.add(key)
                stack.append((neighbor, path + [neighbor]))

    return None

def display_state(state):
    for row in state:
        print(" ".join(map(str, row)))
    print()

def main():
    input_file = "input.txt"
    output_file = "output.txt"
    N, start, goal = read_input(input_file)

    print("\nInitial State:")
    display_state(start)
    print("Goal State:")
    display_state(goal)
    print("Solving using DFS...\n")

    solution = dfs(start, goal, N)

    if solution:
        print(f"Solution found in {len(solution)-1} moves.\n")
        for i, state in enumerate(solution):
            print(f"Step {i}:")
            display_state(state)
        write_output(solution, output_file)
        print("Solution written to 'output.txt'")
    else:
        print("No solution found.")
        with open(output_file, "w") as f:
            f.write("No solution found.\n")

main()
