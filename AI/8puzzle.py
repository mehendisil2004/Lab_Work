import copy

DIRECTIONS = [(-1,0),(1,0),(0,-1),(0,1)]

def find_zero(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0: return i,j

def serialize(state):
    return tuple(tuple(r) for r in state)

def is_goal(state, goal):
    return state == goal

def get_neighbors(state):
    x,y = find_zero(state)
    neighbors=[]
    for dx,dy in DIRECTIONS:
        nx,ny=x+dx,y+dy
        if 0<=nx<3 and 0<=ny<3:
            new=copy.deepcopy(state)
            new[x][y],new[nx][ny]=new[nx][ny],new[x][y]
            neighbors.append(new)
    return neighbors

def dfs(start, goal, limit=50):
    stack=[(start,[start])]
    visited=set([serialize(start)])
    while stack:
        state,path=stack.pop()
        if is_goal(state,goal): return path
        if len(path)>limit: continue
        for nb in get_neighbors(state):
            s=serialize(nb)
            if s not in visited:
                visited.add(s)
                stack.append((nb,path+[nb]))
    return None

start=[[1,2,3],[4,0,6],[7,5,8]]
goal=[[1,2,3],[4,5,6],[7,8,0]]

solution=dfs(start,goal)
if solution:
    for step,s in enumerate(solution):
        print(f"Step {step}:")
        for r in s: print(r)
        print()
else:
    print("No solution found.")
