import networkx as nx
import matplotlib.pyplot as plt
import osmnx as ox

G = nx.Graph()

G.add_nodes_from(["A", "B", "C", "D"])

edges = [
    ("A", "B", 4),
    ("A", "C", 2),
    ("A", "D", 5),
    ("B", "C", 3),
    ("B", "D", 1),
    ("C", "D", 6),
]

G.add_weighted_edges_from(edges)

pos = {
    "A": (0, 1),
    "B": (2, 1),
    "C": (1, 2),
    "D": (1, 0)
}

plt.figure(figsize=(6,6))
nx.draw(
    G, pos,
    with_labels=True,
    node_size=2000,
    font_size=14
)

labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

plt.title("Граф дорог")
plt.show()