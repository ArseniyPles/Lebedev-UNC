import networkx as nx
import pandas as pd
import time

G = nx.Graph()

edges = [
    ("A", "B", 4),
    ("A", "C", 2),
    ("A", "D", 5),
    ("B", "C", 3),
    ("B", "D", 1),
    ("C", "D", 6),
]

G.add_weighted_edges_from(edges)

pairs = [
    ("A", "B"),
    ("B", "C"),
    ("A", "C"),
    ("A", "D"),
    ("B", "D"),
    ("C", "D"),
]

results = []

for start, end in pairs:
    start_time = time.time()

    length = nx.shortest_path_length(G, start, end, weight="weight")
    path = nx.shortest_path(G, start, end, weight="weight")

    end_time = time.time()

    results.append([
        start,
        end,
        length,
        "рисунок",
        f"{(end_time - start_time):.4f} c"
    ])

df = pd.DataFrame(results, columns=[
    "Пункт старта",
    "Пункт назначения",
    "Расстояние (км)",
    "Рисунок (результат)",
    "Время работы алгоритма"
])

print(df)