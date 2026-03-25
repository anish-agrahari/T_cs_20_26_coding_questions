class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w


# DSU (Disjoint Set)
def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]


def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)
    if a != b:
        parent[a] = b


def kruskal(n, edges, skip_index):
    parent = [i for i in range(n + 1)]
    weight = 0
    count = 0

    for i in range(len(edges)):
        if i == skip_index:
            continue

        u, v, w = edges[i].u, edges[i].v, edges[i].w

        if find(parent, u) != find(parent, v):
            union(parent, u, v)
            weight += w
            count += 1

    if count == n - 1:
        return weight
    return float('inf')


# Main
n, m = map(int, input().split())

edges = []
for _ in range(m):
    u, v, w = map(int, input().split())
    edges.append(Edge(u, v, w))

# Sort edges by weight
edges.sort(key=lambda e: e.w)

# Step 1: MST
mst = kruskal(n, edges, -1)

# Step 2: Second MST
second_mst = float('inf')

for i in range(m):
    val = kruskal(n, edges, i)
    if mst < val < second_mst:
        second_mst = val

print(mst, second_mst)