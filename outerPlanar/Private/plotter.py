import subprocess
import networkx as nx
import matplotlib.pyplot as plt

n = input("Enter N ")
print(n)
fw = open("Gen.in", "w")
fw.write(n)
fw.close()
subprocess.call(["Gen.exe"])
fh = open("Gen.ou")
G = nx.Graph()
count = 0
for line in fh:
    str = line.split()
    if count == 0:
        n = int(str[0])
        print(n)
        G.add_node(range(n))
    elif count == 1:
        count += 1
        continue
    else:
        print(str[0], str[1])
        G.add_edge(int(str[0]), int(str[1]))
    count += 1

nx.draw_networkx(G, with_labels=True)
plt.show()
