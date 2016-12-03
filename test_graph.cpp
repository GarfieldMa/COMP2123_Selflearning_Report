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
	while ( cin >> input0 && input0 != -1 ){
		g.addVertex( input0 );
		v.push_back( input0 );
	}
	int input1;

	//test addEdge
	while ( cin >> input0 >> input1 && input0 != -1 && input1 != -1 ){
		g.addEdge( input0, input1 );
	}
	cout << setw( 8 ) << "vertex";
	for ( vector<int>::iterator it = v.begin(); it != v.end(); it++ ){
		cout << setw( 8 ) << *it; 
	}
	cout << endl;

	//test adjacentCheck
	for ( vector<int>::iterator it = v.begin(); it != v.end(); it++ ){
		cout << setw( 8 ) << *it;
		for ( vector<int>::iterator it1 = v.begin(); it1 != v.end(); it1++ ){
			cout << setw( 8 ) << ( g.adjacentCheck( *it, *it1 ) ? '*' : ' ');
		}
		cout << endl;
	}
	return 0;
}