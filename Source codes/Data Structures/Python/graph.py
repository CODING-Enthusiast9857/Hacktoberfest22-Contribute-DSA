# Implementation of graph data structure in python

class Graph:
    def __init__(self):
        self.nodes = {}

    def add_node(self, node):
        self.nodes[node] = []

    def add_edge(self, node1, node2):
        self.nodes[node1].append(node2)
        self.nodes[node2].append(node1)
    
    def print_graph(self):
        for node in self.nodes:
            print(node, ":", self.nodes[node])

    def delete_node(self, node):
        for n in self.nodes[node]:
            self.nodes[n].remove(node)
        self.nodes.pop(node)
    
    def delete_edge(self, node1, node2):
        self.nodes[node1].remove(node2)
        self.nodes[node2].remove(node1)
    
    def search(self, node):
        return node in self.nodes
    
    def search_edge(self, node1, node2):
        try:
            return node2 in self.nodes[node1]
        except KeyError:
            return False
        
g = Graph()
g.add_node(10)
g.add_node(20)
g.add_node(30)
g.add_node(40)
g.add_node(50)
g.add_edge(10, 20)
g.add_edge(20, 30)
g.add_edge(20, 40)
g.add_edge(30, 40)
g.add_edge(30, 50)
g.add_edge(40, 50)
g.print_graph()
g.delete_edge(20, 30)
g.print_graph()
g.delete_node(30)
g.print_graph()
print(g.search(30))
print(g.search_edge(20, 30))
