# GRASP_assignment

**Explanation of code--**

  -Took number of nodes and edges as input and stored in the adjacency list.
  -PMC function will decide presence of perfect matching cut
    if nodes are odd in number , pmc can't exist

  The working of the function is based on recursion , I am pairing a node with all others , and calling recursive function for all other except these two.
  If, for any two node , recursive function return true then function return true; else false.


  **ChatGpt Explaination -**


  The given code appears to be an implementation of a function to check whether a Perfect Matching Cut (PMC) exists in a graph. Here's how the code works:

The code starts with including the necessary header file bits/stdc++.h and some standard libraries.

The int keyword is redefined as long long int using a #define directive.

The function PMC is defined, which takes the number of matched nodes (matched_nodes), the total number of nodes (n), a vector of visited nodes (visited), and an adjacency list representation of the graph (adj).

The function checks if the number of nodes is odd (n%2!=0). If it is odd, it means that an even number of nodes is required for a PMC, so the function returns false.

If all nodes have been visited (matched_nodes==n), it means that a PMC has been found, so the function returns true.

The function selects an unvisited node (ind) to start pairing.

The selected node is marked as visited (visited[ind] = 1).

The function then iterates over the adjacent nodes of the selected node (adj[ind]). If an adjacent node is unvisited (visited[x]==0), it marks the adjacent node as visited, recursively calls the PMC function with matched_nodes+2 (as two more nodes are matched), and checks if a PMC can be found from this point. If a PMC is found (tempPMC is true), the function returns true. Otherwise, it marks the adjacent node as unvisited (visited[x] = 0) and continues with the next adjacent node.

If no PMC is found after checking all possible adjacent nodes, the function returns false.

The main function reads the number of nodes and the number of edges from the user.

It then reads the edges one by one and stores them in a vector of pairs (edges).

An adjacency list adj is created using the edges information. Each node is connected to its adjacent nodes.

A vector visited is initialized with 0 for all nodes.

The PMC function is called with initial values of matched_nodes=0, n=nodes, visited, and adj.

Finally, based on the returned value of check_PMC, it outputs whether a Perfect Matching Cut exists in the given graph or not.

It's worth noting that the code assumes that the input graph is undirected and connected. If the graph is not connected, this code will not work correctly.
