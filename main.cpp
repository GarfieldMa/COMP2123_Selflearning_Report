#include <iostream>
#include "Graph.h"
#define DEBUG 0

#define NOT_CONNECTED -1

//write your Prim's Algorithm here:
Graph<double> prim(Graph<double> g, int root){
    //creating an empty graph (forest) for storing what we have added
    //the false here is for creating an undirected graph (you can refer to the Graph.h provided for implementation details)
    Graph<double> minimum_spanning_tree(false);

    //creating this int array for storing the vertex that have the cheapest connection to a certained vertex (accessed by putting the vertex's storage index (not vertex ID!) into the array index)
    int* cost_of_cheapest_connection_to = new int[g.getNumOfVertex()];
    //setting the default value of each vertex to infinity, assuming no length will be greater than this value
    for (int i = 0; i < g.getNumOfVertex(); ++i){
        cost_of_cheapest_connection_to[i] = 0x7fffffff;
    }

    //creating this int array for storing "which one does the cheapest connection to this vertex connects to?"
    int* source_of_cheapest_connection_to = new int[g.getNumOfVertex()];
    //initializing all of them to be saying "Not connected"
    for (int i = 0; i < g.getNumOfVertex(); ++i){
        source_of_cheapest_connection_to[i] = NOT_CONNECTED;
    }

    //creating a bool vector for storing whether a certain vertex has been visited in the past
    vector<bool> visited;
    visited.resize(g.getNumOfVertex(), false);

    //giving our root a smaller cost_of_cheapest_connection_to value so we could force our algorithm to begin from that point
    cost_of_cheapest_connection_to[root] = 0;

    //while the queue is not empty
    while(minimum_spanning_tree.getNumOfVertex() != g.getNumOfVertex()){
        //First step: finding the UNVISITED vertex with the lowest cost of connection to
        int cheapest_vertex_index = -1;
        int cheapest_vertex_cost = 0x7fffffff;
        for (int i = 0; i < g.getNumOfVertex(); ++i){
            if (cost_of_cheapest_connection_to[i] <= cheapest_vertex_cost && visited[i] ==  false){
                cheapest_vertex_cost = cost_of_cheapest_connection_to[i];
                cheapest_vertex_index = i;
            }
        }

        //Second: we add the found vertex to our minimum spanning tree
        minimum_spanning_tree.addVertex(g.getVertex(cheapest_vertex_index));
        if (root != cheapest_vertex_index) {
            minimum_spanning_tree.addEdge(g.getVertex(cheapest_vertex_index), g.getVertex(source_of_cheapest_connection_to[cheapest_vertex_index]), cheapest_vertex_cost);
        }

        //setting the vertex to be visited
        visited[cheapest_vertex_index] = true;

        //Third: we get the new "cost of cheapest connection to" and "source of cheapest connetion to" values
        vector<double> all_adjacencies = g.getAllAdjacentVertex(g.getVertex(cheapest_vertex_index));
#if DEBUG
        cout << "Adjacency list for " << cheapest_vertex_index << endl;
#endif
        for (vector<double>::iterator it = all_adjacencies.begin(); it != all_adjacencies.end(); it++){
#if DEBUG
            cout << *it << endl;
#endif
            if (visited[g.getStorageIndex(*it)] == false && g.getStorageIndex(*it) != cheapest_vertex_index)
            {
                int cost = g.getEdge(g.getVertex(cheapest_vertex_index), *it);
                if (cost <= cost_of_cheapest_connection_to[g.getStorageIndex(*it)])
                {
                    cost_of_cheapest_connection_to[g.getStorageIndex(*it)] = cost;
                    source_of_cheapest_connection_to[g.getStorageIndex(*it)] = cheapest_vertex_index;
                }
            }
        }
    }

    return minimum_spanning_tree;
}

int main(){
    //creating a new undirected graph containing our workspace
    //in this demonstration we will be using int vertices, which means each vertex
    Graph<double> g(false);

    //creating a bunch of vertices to be added to the graph
    //the value of each int vertex is their index in the graph
    double A = 0;
    double B = 1;
    double C = 2;
    double D = 3;

    //now add the vertices to the graph
    g.addVertex(A);
    g.addVertex(B);
    g.addVertex(C);
    g.addVertex(D);

    //Now we create some edges connecting the vertices to complete the graph
    g.addEdge(A, B, 2);
    g.addEdge(A, D, 1);
    g.addEdge(B, D, 2);
    g.addEdge(C, D, 3);

    //Now call the Prim's algorithm function we just implemented
    Graph<double> MST = prim(g, 0);
    for (int i = 0; i < MST.getNumOfVertex(); ++i)
    {
        cout << "Vertex: " << MST.getVertex(i) << endl;
        cout << "It is connected to: ";
        for (int j = 0; j < MST.getAllAdjacentVertex(MST.getVertex(i)).size(); ++j)
        {
            cout << MST.getAllAdjacentVertex(MST.getVertex(i))[j] << ' ';
        }
        cout << endl;
    }
}
