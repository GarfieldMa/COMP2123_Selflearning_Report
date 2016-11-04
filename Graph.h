#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>
#include <vector>

using namespace std;

template <typename VertexType>
class Graph
{
public:
	Graph();
	void addVertex( const VertexType& v );
	void deleteVertex( const VertexType& v );
	bool adjacentCheck( const VertexType& v1, const VertexType& v2 ) const;
	vector<VertexType> getAllAdjacentVertex( const VertexType& v ) const;
	void addEdge( const VertexType& v1, const VertexType& v2 );
	void deleteEdge( const VertexType& v1, VertexType& v2 );
private:
	map<VertexType,int> HashTable; //indexing vertex
	vector<list<int> > adjacentList;
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
void Graph<VertexType>::addVertex( const VertexType& v ){
	if ( this -> HashTable.count( v ) == 0 ){
		HashTable[ v ] = num_of_vertex;
		list<int> l;
		adjacentList.push_back( l );
		num_of_vertex++;
	}
}

template <typename VertexType>
void Graph<VertexType>::deleteVertex( const VertexType& v ){
	if ( this -> HashTable.count( v ) != 0 ){
		int index = this -> HashTable[ v ];
		this -> adjacentList.erase( this -> adjacentList.begin() + index );
		for ( vector<list<int> >::iterator it_vector = this -> adjacentList.begin(); it_vector != this -> adjacentList.end(); it_vector++ ){
			for ( list<int>::iterator it_list = it_vector -> begin(); it_list != it_vector -> end(); ){
				if ( (*it_list) == index ){
					it_list = it_vector -> erase( it_list );
				}
				else{
					it_list++;
				}
			}
		}
	}
}

template <typename VertexType>
bool Graph<VertexType>::adjacentCheck( const VertexType& v1, const VertexType& v2 ) const{
	int index_1, index_2;
	index_1 = -1;
	index_2 = -1;
	if ( HashTable.count( v1 ) != 0 ){
		index_1 = this -> HashTable.at( v1 );
	}
	if ( HashTable.count( v2 ) != 0 ){
		index_2 = this -> HashTable.at( v2 );
	}
	if ( index_1 != -1 && index_2 != -1 ){
		for ( list<int>::const_iterator it = this -> adjacentList[ index_1 ].begin(); it != this -> adjacentList[ index_1 ].end(); it++ ){
			if ( (*it) == index_2 ){
				return true;
			}
		}
		return false;
	}
	else{
		return false;
	}
}

template <typename VertexType>
vector<VertexType> Graph<VertexType>::getAllAdjacentVertex( const VertexType& v ) const{
	vector<VertexType> adjVertex;
	if ( HashTable.count( v ) != 0 ){
		int index = HashTable.at( v );
		vector<int> adj_index;
		for ( list<int>::const_iterator it = this -> adjacentList[ index ].begin(); it != this -> adjacentList[ index ].end(); it++ ){
			adj_index.push_back( *it );
		}
		for ( typename map<VertexType, int>::const_iterator it = this -> HashTable.begin(); it != this -> HashTable.end(); it++ ){
			if ( it -> second == index ){
				adjVertex.push_back( it -> first );
			}
		}
		return adjVertex;
	}
	else{
		return adjVertex;
	}
}

template <typename VertexType>
void Graph<VertexType>::addEdge( const VertexType& v1, const VertexType& v2 ){
	int index_1, index_2;
	index_1 = index_2 = -1; 
	if ( this -> HashTable.count( v1 ) != 0 ){
		index_1 = this -> HashTable.at( v1 );
	}
	if ( this -> HashTable.count( v2 ) != 0 ){
		index_2 = this -> HashTable.at( v2 );
	}
	if ( index_1 != -1 && index_2 != -1 ){
		if ( this -> adjacentCheck( v1, v2 ) == false ){
			this -> adjacentList[ index_1 ].push_back( index_2 );
			if ( this -> directed == false ){
				this -> adjacentList[ index_2 ].push_back( index_1 );
			}
		}
		else{
			return;
		}
	}
	else{
		return;
	}
}

template <typename VertexType>
void Graph<VertexType>::deleteEdge( const VertexType& v1, VertexType& v2 ){
	int index_1, index_2;
	index_1 = index_2 = -1; 
	if ( this -> HashTable.count( v1 ) != 0 ){
		index_1 = this -> HashTable[ v1 ];
	}
	if ( this -> HashTable( v2 ) != 0 ){
		index_2 = this -> HashTable[ v2 ];
	}
	if ( index_1 != -1 && index_2 != -1 ){
		if ( this -> adjacentCheck( v1, v2 ) == true ){
			for ( list<int>::iterator it = this -> adjacentList[ index_1 ].begin(); it != this -> adjacentList[ index_1 ].end(); ){
				if ( (*it) == index_2 ){
					it = this -> adjacentList[ index_1 ].erase( it );
				}
				else{
					it++;
				}
			}
			if ( this -> directed == false ){
				for ( list<int>::iterator it = this -> adjacentList[ index_2 ].begin(); it != this -> adjacentList[ index_2 ].end(); ){
					if ( (*it) == index_1 ){
						it = this -> adjacentList[ index_2 ].erase( it );
					}
					else{
						it++;
					}
				}
			}
		}
		else{
			return;
		}
	}
	else{
		return;
	}
}
#endif