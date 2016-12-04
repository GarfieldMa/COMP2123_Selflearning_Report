#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>

using namespace std;

template <typename VertexType>
class Graph
{
public:
    Graph();
    Graph( bool directed );
    VertexType getVertex( int index );
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
    int getStorageIndex( const VertexType& v ) const;
    map<VertexType, int> getHashTable();
    Graph primsMinimumSpanningTree();
private:
    map<VertexType,int> HashTable; //indexing vertex
    vector<list<pair<int, int> > > adjacentList;
    int num_of_vertex;
    bool directed;
};

template <typename VertexType>
Graph<VertexType>::Graph(){
    this -> HashTable.clear();
    this -> adjacentList.clear();
    this -> num_of_vertex = 0;
    this -> directed = false;
}

template <typename VertexType>
Graph<VertexType>::Graph( bool directed ){
    this -> HashTable.clear();
    this -> adjacentList.clear();
    this -> num_of_vertex = 0;
    this -> directed = directed;
}

template <typename VertexType>
VertexType Graph<VertexType>::getVertex( int index ){
    try{
        for ( auto it = this -> HashTable.begin(); it != this -> HashTable.end(); it++ ){
            if ( it -> second == index ){
                return it -> first;
            }
        }
        throw 0;
    }
    catch(...){
        cout << "vertex " << index << " doesn't exist" << endl;
    }
    
    VertexType garbage;
    return garbage;
}

template <typename VertexType>
void Graph<VertexType>::addVertex( const VertexType v ){
    try{
        if ( this -> HashTable.count( v ) == 0 ){
            HashTable.insert( pair<VertexType, int>( v, num_of_vertex ) );
            list<pair<int,int> > l;
            adjacentList.push_back( l );
            num_of_vertex++;
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
        if ( this -> HashTable.count( v ) != 0 ){
            int index = this -> HashTable[ v ];
            this -> adjacentList.erase( this -> adjacentList.begin() + index );
            for ( auto it_vector = this -> adjacentList.begin(); it_vector != this -> adjacentList.end(); it_vector++ ){
                for ( auto it_list = it_vector -> begin(); it_list != it_vector -> end(); ){
                    if ( it_list -> first == index ){
                        it_list = it_vector -> erase( it_list );
                    }
                    else{
                        it_list++;
                    }
                }
            }
            for ( auto it = lower_bound( this -> HashTable.begin(), this -> HashTable.end(), v); it != this -> HashTable.end(); it++ ){
                it -> second--;
            }
            this -> num_of_vertex--;
            this -> HashTable.erase( v );
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
    try{
        int index_1, index_2;
        if ( HashTable.count( v1 ) != 0 ){
            index_1 = this -> HashTable.at( v1 );
        }
        else{
            throw 1;
        }
        if ( HashTable.count( v2 ) != 0 ){
            index_2 = this -> HashTable.at( v2 );
        }
        else{
            throw 2;
        }
        for ( auto it = this -> adjacentList.at( index_1 ).begin(); it != this -> adjacentList.at( index_1 ).end(); it++ ){
            if ( it -> first == index_2 ){
                return true;
            }
        }
        return false;
    }
    catch(int err_code){
        cout << "v" << err_code << " doesn't exist" << endl;
    }
    VertexType garbage;
    return garbage;
}

template <typename VertexType>
vector<VertexType> Graph<VertexType>::getAllAdjacentVertex( const VertexType& v ){
    try{
        if ( HashTable.count( v ) != 0 ){
            int index = HashTable.at( v );
            vector<VertexType> adjacent_vertex_list;
            for ( auto it = this -> adjacentList.at( index ).begin(); it != this -> adjacentList.at( index ).end(); it++ ){
                adjacent_vertex_list.push_back( getVertex(it -> first) );
            }
            return adjacent_vertex_list;
        }
        else{
            throw 0;
        }
    }
    catch(...){
        cout << "vertex doesn't exist" << endl;
    }
    vector<VertexType> garbage;
    return garbage;
}

template <typename VertexType>
void Graph<VertexType>::addEdge( const VertexType& v1, const VertexType& v2 ){
    this -> addEdge( v1, v2, 1 );
}

template <typename VertexType>
void Graph<VertexType>::addEdge( const VertexType& v1, const VertexType& v2, int weight ){
    try{
        int index_1, index_2;
        index_1 = index_2 = -1;
        if ( this -> HashTable.count( v1 ) != 0 ){
            index_1 = this -> HashTable.at( v1 );
        }
        else{
            throw 1;
        }
        if ( this -> HashTable.count( v2 ) != 0 ){
            index_2 = this -> HashTable.at( v2 );
        }
        else{
            throw 2;
        }
        if ( this -> adjacentCheck( v1, v2 ) == false ){
            this -> adjacentList.at( index_1 ).push_back( pair<int,int>(index_2, weight ) );
            if ( this -> directed == false ){
                this -> adjacentList.at( index_2 ).push_back( pair<int,int>(index_1, weight ) );
            }
        }
        else{
            return;
        }
    }
    catch(int err_code){
        cout << "v" << err_code << " doesn't exist" << endl;
    }
}

template <typename VertexType>
void Graph<VertexType>::deleteEdge( const VertexType& v1, VertexType& v2 ){
    try{
        int index_1, index_2;
        if ( this -> HashTable.count( v1 ) != 0 ){
            index_1 = this -> HashTable.at( v1 );
        }
        else{
            throw 1;
        }
        if ( this -> HashTable( v2 ) != 0 ){
            index_2 = this -> HashTable.at( v2 );
        }
        else{
            throw 2;
        }
        if ( this -> adjacentCheck( v1, v2 ) == true ){
            for ( auto it = this -> adjacentList.at( index_1 ).begin(); it != this -> adjacentList.at( index_1 ).end(); ){
                if ( it -> first == index_2 ){
                    it = this -> adjacentList.at( index_1 ).erase( it );
                }
                else{
                    it++;
                }
            }
            if ( this -> directed == false ){
                for ( auto it = this -> adjacentList.at( index_2 ).begin(); it != this -> adjacentList.at( index_2 ).end(); ){
                    if ( it -> first == index_1 ){
                        it = this -> adjacentList.at( index_2 ).erase( it );
                    }
                    else{
                        it++;
                    }
                }
            }
        }
        else{
            throw 3;
        }
        
    }
    catch( int err_code ){
        if ( err_code != 3 ){
            cout << "v" << err_code << " doesn't exist" << endl;
        }
        else{
            cout << "edge doesn't exist" << endl;
        }
        
    }
}

template <typename VertexType>
int Graph<VertexType>::getEdge( const VertexType& v1, const VertexType& v2 ) const{
    try{
        int index_1, index_2;
        if ( HashTable.count( v1 ) != 0 ){
            index_1 = this -> HashTable.at( v1 );
        }
        else{
            throw 1;
        }
        if ( HashTable.count( v2 ) != 0 ){
            index_2 = this -> HashTable.at( v2 );
        }
        else{
            throw 2;
        }
        for ( auto it = this -> adjacentList.at( index_1 ).begin(); it != this -> adjacentList.at( index_1 ).end(); it++ ){
            if ( it -> first == index_2 ){
                return it -> second;
            }
        }
        throw 3;
    }
    catch( int err_code ){
        if ( err_code == 3 ){
            cout << "Vertices are not adjacent" << endl;
        }
        else{
            cout << "v" << err_code << " doesn't exist" << endl;
        }
    }
    VertexType garbage;
    return garbage;
}


template<typename VertexType>
bool Graph<VertexType>::contain( const VertexType& v ) const{
    if ( this -> HashTable.count( v ) == 0 ){
        return false;
    }
    else{
        return true;
    }
}

template<typename VertexType>
int Graph<VertexType>::getStorageIndex( const VertexType& v ) const{
    return HashTable.find(v)->second;
}


template <typename VertexType>
int Graph<VertexType>::getNumOfVertex() const{
    return this -> num_of_vertex;
}

template <typename VertexType>
Graph<VertexType> Graph<VertexType>::primsMinimumSpanningTree(){
    //construct a new indirected graph
    Graph<VertexType> minimum_spanning_tree( false );
    
    //init the new graph with first vertex in the graph
    minimum_spanning_tree.addVertex( this -> getVertex( 0 ) );
    
    //we want to add all the vertex in original graph into the new graph
    for ( auto it_original = this -> HashTable.begin(); it_original != this -> HashTable.end(); it_original++ ){
        
        //test if we have already added all the vertex into the new graph
        if ( minimum_spanning_tree.getNumOfVertex() == this -> getNumOfVertex() ){
            break;
        }
        
        //get a vector of all the adjacent
        auto vec_adjacent_vertex = this -> getAllAdjacentVertex( it_original -> first );
        
        int min_edge = 0x7fffffff;
        VertexType* ptr_min_v = NULL;
        for( auto it_adj_v = vec_adjacent_vertex.begin(); it_adj_v != vec_adjacent_vertex.end(); it_adj_v++ ){
            
            //if *it hasn't been included in the new graph
            if ( minimum_spanning_tree.contain( *it_adj_v ) == false ){
                
                int edge = this->getEdge( it_original -> first, *it_adj_v );
                
                //see if it is smaller than the current min_edge
                if ( edge < min_edge ){
                    
                    //update
                    min_edge = edge;
                    *ptr_min_v = *it_adj_v;
                }
            }
        }
        
        //add min_v into the new graph
        if ( ptr_min_v != NULL ){
            minimum_spanning_tree.addVertex( *ptr_min_v );
            minimum_spanning_tree.addEdge( it_original->first, *ptr_min_v );
        }
    }
    
    return minimum_spanning_tree;
}

#endif
