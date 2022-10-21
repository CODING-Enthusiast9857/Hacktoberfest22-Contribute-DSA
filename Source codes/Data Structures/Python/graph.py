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
        
