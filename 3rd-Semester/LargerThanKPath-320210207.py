# Yousef Ibrahim Gomaa Mahmoud
# ID: 320210207

# Sheet 8 - Question 5

# Using Graph data structure.
class Graph:
    def __init__(self, Vertex):
        self.vertex = Vertex
        self.list = [[] for i in range(Vertex)]
   
    # Start point is at node 0
    def checkPath(self, K):
        Path = [False]*self.vertex
        Path[0] = 1
        source = 0
        return self.foundPath(source, K, Path)
       
    def foundPath(self, source, K, Path):
        i = 0
        while i != len(self.list[source]):
            adjVertex = self.list[source][i][0] # Adjacent Vertex
            weight = self.list[source][i][1] # Edge Weight
            i += 1 # Iterator
      
            # Skip edge if a cycle was detected.
            if (Path[adjVertex] == True):
                continue
       
            # Found path to a node whose total path weight is larger than K
            if (weight >= K):
                return True
       
            # Add current vertex to path if its not found yet 
            # OR if no more vertices are left to visit.
            Path[adjVertex] = True
            
            if (self.foundPath(adjVertex, K-weight, Path)): # Recursion
                return True
       
            Path[adjVertex] = False # Backtrack Step
       
        return False

############## MAIN PROGRAM ##############

N = 9 # Number of Vertices
graph = Graph(N) # Construct a N vertex graph.
   
# Add edge twice to each two connected vertices.
graph.list[0].append([1, 4])
graph.list[1].append([0, 4])

graph.list[0].append([7, 8])
graph.list[7].append([0, 8])

graph.list[1].append([2, 8])
graph.list[2].append([1, 8])

graph.list[1].append([7, 11])
graph.list[7].append([1, 11])

graph.list[2].append([3, 7])
graph.list[3].append([2, 7])

graph.list[2].append([8, 2])
graph.list[8].append([2, 2])

graph.list[2].append([5, 4])
graph.list[5].append([2, 4])

graph.list[3].append([4, 9])
graph.list[4].append([3, 9])

graph.list[3].append([5, 14])
graph.list[5].append([3, 14])

graph.list[4].append([5, 10])
graph.list[5].append([4, 10])

graph.list[5].append([6, 2])
graph.list[6].append([5, 2])

graph.list[6].append([7, 1])
graph.list[7].append([6, 1])

graph.list[6].append([8, 6])
graph.list[8].append([6, 6])

graph.list[8].append([7, 7])
graph.list[7].append([8, 7])

# Try K = 20, 30 and 60
Klist = [20,30,60]
for K in Klist:
    if graph.checkPath(K):
        print(f"at K = {K}, a path has been found to be larger than K.")
    else:
        print(f"at K = {K}, a path has NOT been found to be larger than K.")