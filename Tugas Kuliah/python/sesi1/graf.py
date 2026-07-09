import networkx as nx
import matplotlib.pyplot as plt

# Membuat graf kosong
G = nx.Graph()

# Menambahkan simpul (nodes)
G.add_node(1)
G.add_node(2)
G.add_node(3)

# Menambahkan sisi (edges)
G.add_edge(1, 2)
G.add_edge(2, 3)
G.add_edge(1, 3)

# Menggambar graf
pos = nx.spring_layout(G)  # Mengatur posisi simpul
nx.draw(G, pos, with_labels=True, node_color='lightblue', node_size=700, font_size=16, font_color='black', font_weight='bold')
plt.title("Graf Sederhana")
plt.show()
