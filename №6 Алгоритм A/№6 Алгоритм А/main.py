import heapq
import matplotlib.pyplot as plt

grid = [
[0,0,0,1,0,0,0,0,0,0],
[0,0,0,1,0,0,1,0,0,0],
[0,0,0,1,0,0,0,0,0,0],
[0,1,1,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,0],
[1,1,0,0,1,0,1,0,1,0],
[0,0,0,0,1,0,1,1,0,1],
[0,1,1,0,1,1,1,0,0,0],
[0,1,1,0,0,0,0,0,0,0],
[0,1,1,0,1,1,0,0,0,0],
]

start = (0,3)
goal = (9,9)

def heuristic(a,b):
    return abs(a[0]-b[0]) + abs(a[1]-b[1])

def a_star(grid,start,goal):
    open_set=[]
    heapq.heappush(open_set,(0,start))
    came_from={}
    g={start:0}

    while open_set:
        current=heapq.heappop(open_set)[1]

        if current==goal:
            path=[]
            while current in came_from:
                path.append(current)
                current=came_from[current]
            path.append(start)
            return path[::-1]

        x,y=current

        for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
            nx,ny=x+dx,y+dy
            if nx<0 or ny<0 or nx>=10 or ny>=10:
                continue
            if grid[ny][nx]==1:
                continue

            neigh=(nx,ny)
            new_g=g[current]+1

            if neigh not in g or new_g<g[neigh]:
                g[neigh]=new_g
                f=new_g+heuristic(neigh,goal)
                heapq.heappush(open_set,(f,neigh))
                came_from[neigh]=current
    return None

path=a_star(grid,start,goal)
print("Найденный путь:", path)
print("Длина пути:", len(path)-1)

def draw(grid,path,start,goal):
    rows=len(grid)
    cols=len(grid[0])
    plt.figure(figsize=(6,6))

    for y in range(rows):
        for x in range(cols):
            color='lightgray' if grid[y][x]==1 else 'white'
            plt.fill_between([x,x+1],y,y+1,color=color)

    if path:
        xs=[p[0]+0.5 for p in path]
        ys=[p[1]+0.5 for p in path]
        plt.plot(xs,ys,linewidth=3)

    plt.text(start[0]+0.3,start[1]+0.3,"👑",fontsize=16)
    plt.text(goal[0]+0.3,goal[1]+0.3,"❌",fontsize=16)

    plt.xlim(0,cols)
    plt.ylim(rows,0)
    plt.grid()
    plt.title("Поиск пути A*")
    plt.show()

draw(grid,path,start,goal)