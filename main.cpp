#include <iostream>
#include <iomanip>
#include <string>
#include "Graph.h"
#include "Prim.h"    

int main(){
    //creating a new undirected graph containing our workspace
    //in this demonstration we will be using double vertices, which means each vertex contains a double variable (using double to avoid the confusion of vertex data with vertex storage index)
    Graph<double> g(false);

    //create an empty graph reference for holding the result of algorithm
    Graph<double> MST;

    string command;
    double a, b, weight;

    while (cin >> command) {
      if (command == "addVertex") {
        cin >> a;
        g.addVertex(a);
      }
      else if (command == "addEdge") {
        cin >> a >> b >> weight;
        g.addEdge(a, b, weight);
      }
      else if (command == "runPrim") {
        cin >> a; // a for the storage index of the root of MST
        MST = prim(g, a);
      }
      else
        cout << "Command error!" << endl;
    }

    //Use this loop to show the resulting MST

cout<<"***********Minimum_Spanning_Tree*************"<<endl;
    cout << setw( 8 ) << "vertices";
    	for ( int i = 0; i < MST.getNumOfVertex(); i++  ){
    		cout << setw( 8 ) << MST.getVertex( i );
    	}
    	cout << endl;
    for ( int i = 0; i < MST.getNumOfVertex(); i++  ){
		    cout << setw( 8 ) << MST.getVertex( i );
    		for ( int j = 0; j < MST.getNumOfVertex(); j++){
    			cout << setw( 8 ) << ( MST.adjacentCheck( MST.getVertex( i ), MST.getVertex( j ) ) ? '*' : ' ');
    		}
		cout << endl;
	}


    cout << "***********original graph*************" << endl;

    cout << setw( 8 ) << "vertices";
      for ( int i = 0; i < g.getNumOfVertex(); i++  ){
        cout << setw( 8 ) << g.getVertex(i);
      }
      cout << endl;
    for ( int i = 0; i < g.getNumOfVertex(); i++  ){
        cout << setw( 8 ) << g.getVertex(i);
        for ( int j = 0; j < g.getNumOfVertex(); j++){
          cout << setw( 8 ) << ( g.adjacentCheck( g.getVertex(i), g.getVertex(j) ) ? '*' : ' ');
        }
    cout << endl;
    }

}
