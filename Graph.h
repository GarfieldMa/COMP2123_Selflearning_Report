#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#define MAX 0X7ffffff
#define DEBUG 0
#define NOT_CONNECTED -1


using namespace std;

template <typename VertexType>
class Graph
{
public:
    Graph();
    Graph( bool directed );
    VertexType getVertex( int index ) const;
    int getIndex( const VertexType& v ) const;
    void addVertex( const VertexType v );
    void deleteVertex( const VertexType& v );
    bool adjacentCheck( const VertexType& v1, const VertexType& v2 ) const;
    bool contain( const VertexType& v ) const;
    vector<VertexType> getAllAdjacentVertex( const VertexType& v );
    int getNumOfVertex() const;
    void addEdge( const VertexType& v1, const VertexType& v2, int weight );
    void addEdge( const VertexType& v1, const VertexType& v2 );
    void deleteEdge( const VertexType& v1, VertexType& v2 );
    int getEdge( const VertexType& v1, const VertexType& v2 ) const;
    Graph<VertexType> prim(Graph<VertexType> g, int root);
    template <typename T> friend ostream& operator << ( ostream& , const Graph<T>& );

private:
    vector<VertexType> vertices; //indexing vertex
    vector<vector<int> > adjMatrix;
    int num_of_vertex;
    bool directed;
};

template <typename VertexType>
Graph<VertexType>::Graph(){
    this -> vertices.clear();
    this -> adjMatrix.clear();
    this -> num_of_vertex = 0;
    this -> directed = false;
}

template <typename VertexType>
Graph<VertexType>::Graph( bool directed ){
    this -> vertices.clear();
    this -> adjMatrix.clear();
    this -> num_of_vertex = 0;
    this -> directed = directed;
}

template <typename VertexType>
VertexType Graph<VertexType>::getVertex( int index ) const{
    return this -> vertices.at( index );
}


template <typename VertexType>
int Graph<VertexType>::getIndex( const VertexType& v ) const{
    int index = -1;
    for ( int i = 0; i < this -> vertices.size(); i++ ){
        if ( this -> vertices.at( i ) == v ){
            index = i;
            break;
        }
    }
    return index;
}



template <typename VertexType>
void Graph<VertexType>::addVertex( const VertexType v ){
    try{

    	//check duplicate
        auto it_v = this -> vertices.end();
        for ( auto it = this -> vertices.begin(); it != this -> vertices.end(); it++ ){
            if ( *it == v ){
                it_v = it;
                break;
            }
        }

        //if no dupicate
        if ( it_v == this -> vertices.end() ){
            this -> vertices.push_back( v );
            num_of_vertex++;

            for ( auto it = this -> adjMatrix.begin(); it != this -> adjMatrix.end(); it++ ){
                it -> push_back( MAX );
            }

            vector<int> vec_adj( num_of_vertex, MAX );
            this -> adjMatrix.push_back( vec_adj );
        }
        else{
            throw 0;
        }
    }
    catch(...){
        cout << "vertex already exists" << endl;
    }
}

template <typename VertexType>
void Graph<VertexType>::deleteVertex( const VertexType& v ){
    try{
        int index = -1;
        for ( int i = 0; i < this -> vertices.size(); i++ ){
            if ( this -> vertices.at( i ) == v ){
                index = i;
                break;
            }
        }
        if ( index != -1 ){
            this -> vertices.erase( this -> vertices.begin() + index );
            for ( auto it_i = this -> adjMatrix.begin(); it_i != this -> adjMatrix.end(); it_i++ ){
                it_i -> erase( it_i -> begin() + index );
            }
            this -> adjMatrix.erase( this -> adjMatrix.begin() + index );
            num_of_vertex--;
        }
        else{
            throw 0;
        }

    }
    catch(...){
        cout << "vertex doesn't exist" << endl;
    }

}

template <typename VertexType>
bool Graph<VertexType>::adjacentCheck( const VertexType& v1, const VertexType& v2 ) const{
    int index_1 = this -> getIndex( v1 );
    int index_2 = this -> getIndex( v2 );
    if ( index_1 != -1 && index_2 != -1 ){
        return this -> adjMatrix.at( index_1 ).at( index_2 ) != MAX;
    }
    else{
        return false;
    }
}

template <typename VertexType>
vector<VertexType> Graph<VertexType>::getAllAdjacentVertex( const VertexType& v ){
    vector<VertexType> vec;
    int index = this -> getIndex( v );
    if ( index != -1 ){
        for ( int i = 0; i < this -> adjMatrix.at( index ).size(); i++ ){
            if ( this -> adjMatrix.at( index ).at( i ) != MAX ){
                vec.push_back( this -> getVertex( i ) );
            }
        }
    }
    return vec;
}

template <typename VertexType>
void Graph<VertexType>::addEdge( const VertexType& v1, const VertexType& v2 ){
    this -> addEdge( v1, v2, 1 );
}

template <typename VertexType>
void Graph<VertexType>::addEdge( const VertexType& v1, const VertexType& v2, int weight ){
    try{
        int index_1 = this -> getIndex( v1 );
        int index_2 = this -> getIndex( v2 );
        if ( index_1 != -1 && index_2 != -1 ){
            this -> adjMatrix.at( index_1 ).at( index_2 ) = weight;
            if ( this -> directed == false ){
                this -> adjMatrix.at( index_2 ).at( index_1 ) = weight;
            }
        }
        else{
            throw 0;
        }
    }
    catch(...){
        cout << "vertex doesn't exist" << endl;
    }
}

template <typename VertexType>
void Graph<VertexType>::deleteEdge( const VertexType& v1, VertexType& v2 ){
    try{
        int index_1 = this -> getIndex( v1 );
        int index_2 = this -> getIndex( v2 );
        if ( index_1 != -1 && index_2 != -1 ){
            this -> adjMatrix.at( index_1 ).at( index_2 ) = MAX;
        }
        else{
            throw 0;
        }
    }
    catch(...){
        cout << "vertex doesn't exist" << endl;
    }
}

template <typename VertexType>
int Graph<VertexType>::getEdge( const VertexType& v1, const VertexType& v2 ) const{
    try{
        int index_1 = this -> getIndex( v1 );
        int index_2 = this -> getIndex( v2 );
        if ( index_1 != -1 && index_2 != -1 ){
            return this -> adjMatrix.at( index_1 ).at( index_2 );
        }
        else{
            throw 0;
        }
    }
    catch(...){
        cout << "vertex doesn't exist" << endl;
        return MAX;
    }
}


template<typename VertexType>
bool Graph<VertexType>::contain( const VertexType& v ) const{
    return this -> getIndex( v ) != -1;
}

template <typename VertexType>
int Graph<VertexType>::getNumOfVertex() const{
    return this -> num_of_vertex;
}

template <typename VertexType>
Graph<VertexType> prim(Graph<VertexType> g, int root){
    //creating an empty graph (forest) for storing what we have added
    //the false here is for creating an undirected graph (you can refer to the Graph.h provided for implementation details)
    Graph<VertexType> minimum_spanning_tree(false);

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
        vector<VertexType> all_adjacencies = g.getAllAdjacentVertex(g.getVertex(cheapest_vertex_index));
#if DEBUG
        cout << "Adjacency list for " << cheapest_vertex_index << endl;
#endif
        for (typename vector<VertexType>::iterator it = all_adjacencies.begin(); it != all_adjacencies.end(); it++){
#if DEBUG
            cout << *it << endl;
#endif
            if (visited[g.getIndex(*it)] == false && g.getIndex(*it) != cheapest_vertex_index)
            {
                int cost = g.getEdge(g.getVertex(cheapest_vertex_index), *it);
                if (cost <= cost_of_cheapest_connection_to[g.getIndex(*it)])
                {
                    cost_of_cheapest_connection_to[g.getIndex(*it)] = cost;
                    source_of_cheapest_connection_to[g.getIndex(*it)] = cheapest_vertex_index;
                }
            }
        }
    }

    return minimum_spanning_tree;
}

template <typename T>
ostream& operator << ( ostream& cout, const Graph<T>& g ){
	cout << setw( 8 ) << "vertices";
	vector<T> vec_tmp = g.vertices;
	sort( vec_tmp.begin(), vec_tmp.end() );
	for ( int i = 0; i < g.getNumOfVertex(); i++  ){
    		cout << setw( 8 ) << vec_tmp.at( i );
    }
    cout << endl;

    int sum_edge = 0;
    for ( int i = 0; i < g.getNumOfVertex(); i++  ){
		    cout << setw( 8 ) << vec_tmp.at( i );
    		for ( int j = 0; j < g.getNumOfVertex(); j++){
    			if ( g.adjacentCheck( vec_tmp.at( i ), vec_tmp.at( j ) ) ){
    				cout << setw( 8 ) << '*';
    				sum_edge += g.getEdge( vec_tmp.at( i ), vec_tmp.at( j ) );
    			}
    			else{
    				cout << setw( 8 ) << ' ';
    			}
    		}
		cout << endl;
	}
	cout << "Sum of edges' weight: " << sum_edge << endl;
	return cout;
}

#endif
