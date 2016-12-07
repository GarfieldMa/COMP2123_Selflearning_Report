#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <vector>

#define MAX 0X7ffffff


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

#endif
