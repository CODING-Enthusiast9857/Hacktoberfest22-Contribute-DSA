#hardcoded adjacency list for storing the (directed) graph

graph = {
'A' : ['B', 'C', 'D', 'E'],
'B' : ['D'],
'C' : ['D', 'E'],
'D' : ['E'],
'E' : []
}


'''
Breadth first search algorithm is a method of traversing a graph
in level order.

It also answers the question of:
finding possible paths

In this implementation, the while loop ends once all nodes are marked.
A list can be used as a queue
if we append and then pop from the front
'''
def BFS(G, startNode):
    G = graph
    queue = [] #nodes will be added here as we visit them
    markedSet = set() #mark a node as visited by adding it to a set

    queue.append(startNode)

    #search queue until empty
    while len(queue) != 0:
        node = queue.pop(0) #queue pops from beginning of structure

        #check if node is not marked yet
        if node not in markedSet:
            markedSet.add(node) #mark node
            print(node) #process node
        
        #add any adjacent nodes to queue
        for x in G[node]:
            queue.append(x)

BFS(graph,'C')
