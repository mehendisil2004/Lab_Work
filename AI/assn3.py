from collections import deque

def water_jug_solution_paths(capacity_x, capacity_y, target, output_file):
    visited = set()
    queue = deque()
    start_state = (0, 0)

    queue.append((start_state, [start_state]))
    visited.add(start_state)

    search_space = []
    solution_paths = []

    while queue:
        (x, y), path = queue.popleft()

        if x == target or y == target:
            solution_paths.append(path)

        next_states = [
            (capacity_x, y),
            (x, capacity_y),
            (0, y),
            (x, 0),
            (x - min(x, capacity_y - y), y + min(x, capacity_y - y)),
            (x + min(y, capacity_x - x), y - min(y, capacity_x - x))
        ]

        for state in next_states:
            if state not in visited:
                visited.add(state)
                queue.append((state, path + [state]))
                search_space.append(((x, y), state))

    with open(output_file, "w") as f:
        f.write("Search Space Transitions:\n")
        for frm, to in search_space:
            f.write(f"{frm}  →  {to}\n")

        f.write("\nSolution to Target:\n")
        for idx, sol_path in enumerate(solution_paths, 1):
            f.write(f"\nSolution {idx}:\n")
            for step in sol_path:
                f.write(f"Jug 1: {step[0]}l, Jug 2: {step[1]}l\n")


if __name__ == "__main__":
    cap_x = int(input("Enter capacity of Jug 1: "))
    cap_y = int(input("Enter capacity of Jug 2: "))
    target_amount = int(input("Enter target measurement: "))
    output_filename = "jug_output.txt"

    water_jug_solution_paths(cap_x, cap_y, target_amount, output_filename)
    print(f"\nResults saved to {output_filename}")
