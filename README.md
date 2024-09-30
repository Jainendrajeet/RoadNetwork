Graph Algorithms: Dijkstra and Prim's Algorithm
Project Overview
This project implements Dijkstra's Algorithm for finding the shortest path from a source node to all other nodes and Prim's Algorithm for finding the Minimum Spanning Tree (MST) of a graph. Both algorithms are designed for graphs represented by an adjacency matrix and use a priority queue (min-heap) for efficient graph traversal.

Key Algorithms:
Dijkstra's Algorithm: Finds the shortest path from the source to all other nodes in a weighted graph.
Prim's Algorithm: Finds the minimum spanning tree (MST) for a graph, ensuring that the sum of the weights of the edges in the tree is minimized.
Features
Dijkstra's Algorithm:
Computes the shortest distance from a source node to all other nodes.
Handles weighted graphs with non-negative edge weights.
Prim's Algorithm:
Computes the Minimum Spanning Tree (MST) of a connected graph.
Handles weighted undirected graphs.
File Structure
The project consists of the following source files:

main.cpp — Contains the implementation of both Dijkstra’s and Prim’s algorithms along with graph representation and input/output functions.
Code Explanation
1. Graph Representation
The graph is represented using an adjacency matrix graph[n][n], where graph[i][j] represents the weight of the edge between node i and node j. If graph[i][j] is 0, it indicates no direct edge between those nodes.

2. Dijkstra’s Algorithm
Dijkstra's algorithm finds the shortest path from a source node to all other nodes in a graph. It uses a priority queue (min-heap) to explore the node with the smallest known distance.

Key steps:

Initialization:
Set the source node distance to 0, and all other node distances to infinity (INT_MAX).
Insert the source node into the priority queue.
Exploration:
Extract the node with the minimum distance from the queue.
Update the distances of its adjacent nodes if a shorter path is found.
Termination:
The algorithm terminates when the priority queue is empty, meaning all nodes have been processed.
3. Prim's Algorithm
Prim’s algorithm finds a Minimum Spanning Tree (MST) of a connected graph. It starts from an arbitrary node and expands the MST by adding the minimum-weight edge that connects the MST to a new node.

Key steps:

Initialization:
Set the distance to the starting node to 0, and all others to infinity (INT_MAX).
Insert the starting node into the priority queue.
Building MST:
At each step, extract the node with the minimum distance from the queue.
Add the corresponding edge to the MST.
Update the distances of its adjacent nodes if a lower-weight edge is found.
Termination:
The algorithm terminates when all nodes have been added to the MST.
