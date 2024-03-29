# Problem desciription

Suppose you are given a undirected graph specified as a list of edges. In this challenge problem, we'll use a simplified disjoint sets data structure to count how many "connected components" the graph has, and whether each one contains a cycle or not.

First, some background information: In an undirected graph, two vertices have connectivity if there is any path leading from one to the other using any number of edges. So, a lone vertex by itself, with no edges, is not "connected" to the other parts of the graph. A "connected component" is any subset of the graph vertices where all the vertices have paths to each other, and where that set is maximal, meaning that no reachable vertices are left out of the set. A connected component contains a "cycle" if there are two (or more) distinct paths connecting any two vertices--that means there is a closed loop somewhere.

Example: An edge label like "(0,1)" means an edge between vertex 0 and vertex 1. Suppose we have vertices numbered 0 through 8, and we have these edges:

(0,1), (1,2), (0,2), (3,4), (5,6), (6,7), (7,8)

Try drawing it on a sheet of paper. The three connected components are these sets of vertices:

{0, 1, 2}, {3, 4}, {5, 6, 7, 8}

You'll see the connected components are like islands of vertices. Here, {0, 1, 2} contains a cycle, and the other two connected components do not contain cycles. Also, notice that for a set to be a connected component, it must be maximal, meaning no vertices can be left out--and so {0, 1} is not called a connected component, because the 2 is also reachable there. (Maximal does not mean "maximum". A single, lone vertex is a connected component by itself, because the subset containing only that one vertex is maximal, considering what can be reached from it. So, the sizes of the other connected components elsewhere do not matter.)

In graph theory, it's common to say "n" for the number of vertices and "m" for the number of edges in some graph. For this problem, we'll say we have some undirected graph of some n vertices, which are arbitrarily labeled with indices from 0 through n-1. (This is reasonable because we could otherwise relabel the vertices using a hash table for lookups. Also, we won't assume that subsequent numbers are connected by edges, although that may happen in our unit tests.) Then, we'll initialize a collection of disjoint sets as n singletons (single element sets), one for each vertex; we have a DisjointSets class to represent this collection.

To create sets representing connected components, we can iterate over the graph edges: For each edge (A,B) connecting vertex A to vertex B, we can union the sets that A and B belong to, so the disjoint sets data structure now indicates now that A and B belong to the same set. Our member function for the union operation is called "dsunion" to avoid conflicting with the C++ keyword "union".

At the end of the process of calling dsunion() on every pair of vertices in the edge list, the number of disjoint sets should correspond to the number of connected components in the graph.

The disjoint sets data structure can also detect cycles. As the edges are being processed, if the edge currently being processed connects vertex A and vertex B, and both vertex A and vertex B are already in the same disjoint set, then the edge connecting vertex A and vertex B completes a cycle.

In the source code provided below, you should modify the definition of DisjointSets::dsunion (under TASK 1) and the definition of DisjointSets::count_comps (under TASK 2) according to the hints in the code comments. We'll detect cycles during the union procedure and we can count the number of components after all union operations are completed.

The starter code main() also contains an example graph with expected output. When you're ready to submit, we'll run your code through some randomized unit tests for grading.