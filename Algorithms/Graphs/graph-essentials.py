# Graph Algorithms in Python

# Import necessary libraries
from collections import defaultdict, deque
import heapq

# Define the Graph class using adjacency list representation
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def __str__(self):
        return '\n'.join([f'{key}: {value}' for key, value in self.graph.items()])

# Breadth-First Search (BFS)
def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    while queue:
        vertex = queue.popleft()
        print(vertex, end=' ')
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# Depth-First Search (DFS)
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end=' ')
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

# Dijkstra's Algorithm
def dijkstra(graph, start):
    queue = []
    heapq.heappush(queue, (0, start))
    distances = {node: float('infinity') for node in graph}
    distances[start] = 0

    while queue:
        current_distance, current_node = heapq.heappop(queue)

        if current_distance > distances[current_node]:
            continue

        for neighbor in graph[current_node]:
            distance = current_distance + graph[current_node][neighbor]

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))

    return distances

# Topological Sort
def topological_sort_util(graph, v, visited, stack):
    visited.add(v)
    for neighbor in graph[v]:
        if neighbor not in visited:
            topological_sort_util(graph, neighbor, visited, stack)
    stack.insert(0, v)

def topological_sort(graph):
    visited = set()
    stack = []

    for vertex in graph:
        if vertex not in visited:
            topological_sort_util(graph, vertex, visited, stack)

    return stack

# Example usage of the Graph class and algorithms
if __name__ == "__main__":
    # Create a graph and add edges
    g = Graph()
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 2)
    g.add_edge(2, 0)
    g.add_edge(2, 3)
    g.add_edge(3, 3)

    print("Graph:")
    print(g)

    print("\nBFS starting from vertex 2:")
    bfs(g.graph, 2)

    print("\nDFS starting from vertex 2:")
    dfs(g.graph, 2)

    # Example usage of Dijkstra's algorithm
    weighted_graph = {
        'A': {'B': 1, 'C': 4},
        'B': {'A': 1, 'C': 2, 'D': 5},
        'C': {'A': 4, 'B': 2, 'D': 1},
        'D': {'B': 5, 'C': 1}
    }

    print("\nDijkstra's shortest paths from vertex 'A':")
    print(dijkstra(weighted_graph, 'A'))

    # Example usage of Topological Sort
    dag = Graph()
    dag.add_edge(5, 2)
    dag.add_edge(5, 0)
    dag.add_edge(4, 0)
    dag.add_edge(4, 1)
    dag.add_edge(2, 3)
    dag.add_edge(3, 1)

    print("\nTopological sort of the DAG:")
    print(topological_sort(dag.graph))
