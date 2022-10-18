#hardcoded adjacency list for storing the (Directed) graph

graph = {
'A' : ['B', 'C', 'D', 'E'],
'B' : ['D'],
'C' : ['D', 'E'],
'D' : ['E'],
'E' : []
}


'''
Depth first search algorithm is a method of traversing a graph.

It also answers the question of:
what portions of the graph are reachable from a given node?

In this implementation, the while loop ends once all nodes are marked.
A list can be used as a stack
if we add and remove from the end of the structure.
'''
def DFS(G, startNode):
    G = graph
    stack = [] #nodes will be added here as we visit them
    markedSet = set() #mark a node as visited by adding it to a set

    stack.append(startNode)

    #search stack until empty
    while len(stack) != 0:
        node = stack.pop()

        #check if node is not marked yet
        if(node not in markedSet):
            markedSet.add(node) #mark node
            print(node) #process node
        
        #add any unmarked adjacent nodes to stack
        for x in G[node]:
            stack.append(x)
            
DFS(graph,'B')            
