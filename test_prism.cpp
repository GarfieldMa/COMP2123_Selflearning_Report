#include <iostream>
#include <iomanip>
#include <vector>
#include "Graph.h"

using namespace std;

int main(){
	Graph<int> g;
	vector<int> v;
	int input0;

	//test addVertex
	g.addVertex( 1 );
	g.addVertex( 2 );
	g.addVertex( 3 );
	g.addVertex( 4 );
	g.addVertex( 5 );
	g.addVertex( 6 );
	g.addVertex( 7 );

	g.addEdge( 1, 2, 2 );
	g.addEdge( 1, 4, 1 );
	g.addEdge( 1, 3, 4 );
	g.addEdge( 2, 4, 3 );
	g.addEdge( 2, 5, 10 );
	g.addEdge( 3, 4, 2 );
	g.addEdge( 3, 6, 5 );
	g.addEdge( 4, 5, 7 );
	g.addEdge( 4, 6, 8 );
	g.addEdge( 4, 7, 4 );
	g.addEdge( 5, 7, 6 );
	g.addEdge( 6, 7, 1 );

	cout << setw( 8 ) << "vertex";
	for( int i = 1; i < 8; i++ ){
		cout << setw( 8 ) << i;
	}
	cout << endl;

	for ( int i = 1; i < 8; i++ ){
		cout << setw( 8 ) << i;
		for( int j = 1; j < 8; j++ ){
			// cout << setw( 8 ) << g.getEdge( i, j );
			if ( g.adjacentCheck( i, j ) == true){
				cout << setw( 8 ) << g.getEdge( i ,j );
			}
			else{
				cout << setw( 8 ) << ' ';
			}
			// cout << setw( 8 ) << ( g.adjacentCheck( i, j ) ? g.getEdge( i, j ) : (char)' ');
		}
		cout << endl;
	}

	Graph<int> mini_tree = g.primsMinimumSpanningTree();
	cout << "********Prim's Minimum Spanning Tree********" << endl;
	cout << setw( 8 ) << "vertex";
	for( int i = 1; i < 8; i++ ){
		cout << setw( 8 ) << i;
	}
	cout << endl;

	for ( int i = 1; i < 8; i++ ){
		cout << setw( 8 ) << i;
		for( int j = 1; j < 8; j++ ){
			// cout << setw( 8 ) << g.getEdge( i, j );
			if ( mini_tree.adjacentCheck( i, j ) == true){
				cout << setw( 8 ) << mini_tree.getEdge( i ,j );
			}
			else{
				cout << setw( 8 ) << ' ';
			}
			// cout << setw( 8 ) << ( g.adjacentCheck( i, j ) ? g.getEdge( i, j ) : (char)' ');
		}
		cout << endl;
	}
	return 0;
}