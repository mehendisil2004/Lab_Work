def is_valid(state):
    m_left, c_left, boat = state
    m_right, c_right = 3 - m_left, 3 - c_left

    if m_left < 0 or c_left < 0 or m_right < 0 or c_right < 0:
        return False

    if (m_left > 0 and m_left < c_left) or (m_right > 0 and m_right < c_right):
        return False

    return True

def get_successors(state):
    m, c, boat = state
    moves = [(1,0), (2,0), (0,1), (0,2), (1,1)]
    successors = []

    for dm, dc in moves:
        if boat == 1:  
            new_state = (m - dm, c - dc, 0)
        else:          
            new_state = (m + dm, c + dc, 1)

        if is_valid(new_state):
            successors.append(new_state)

    return successors

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

if __name__ == "__main__":
    start = (3, 3, 1)  
    goal = (0, 0, 0)   

    solution = dfs(start, goal)

    if solution:
        print("Solution found using DFS:\n")
        for step in solution:
            print(step)
    else:
        print("No solution found.")
