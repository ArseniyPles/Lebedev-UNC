# матрица смежности графа
graph = [
    [0, 1, 1],
    [1, 0, 1],
    [1, 1, 0]
]

k = 3  # количество цветов

def is_safe(v, colors, c):

    for i in range(len(graph)):
        if graph[v][i] == 1 and colors[i] == c:
            return False
    return True

def color_graph(v, colors):

    if v == len(graph):
        return True

    for c in range(1, k + 1):
        if is_safe(v, colors, c):
            colors[v] = c
            if color_graph(v + 1, colors):
                return True
            colors[v] = 0 

    return False

colors = [0] * len(graph)

if color_graph(0, colors):
    print("YES")
    print("Цвета вершин:", *colors)
else:
    print("NO")