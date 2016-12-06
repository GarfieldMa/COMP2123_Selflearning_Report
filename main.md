---

title: Solving the Minimum-Spanning-Tree Problem with Prim’s Algorithm
subtitle: COMP2123 Group-Based Self-Learning Report

author: MA Rutian, MAO Wenxu, YAO Qingning

---

# Solving the Minimum-Spanning-Tree Problem with Prim’s Algorithm
## Objectives
Today there’s gonna be something exciting to learn and at the end of day, you shall be able to:

- Understand what is the *Minimum-Spanning-Tree Problem*

- Know what is *Prim’s Algorithm* and how to implement it
- Understand how Prim’s Algorthim could be used to solve the minimum-spanning-tree problem

## Motivations
*”So what is a minimum-spanning-tree problem anyways?”*
Great question! In simple words, it is about finding a set of shortest possible edges of a *connected*, *edge-weighted* and *undirected* graph that connects all the vertices together without cycles. OK that’s quite a lot of information and really not simple I admit, but if you take a closer look it’s actually pretty simple and logical:

### First thing: we are going to study the problem in this kind of graph …

> Connected
>
> Edge-Weighted
> 
> Undirected

##### What does these words mean ?


#### 1. "Connected"
Recall from what you have learnt in COMP2121😀, a connected graph is a graph in which you can find a path between **any** two vertices. 

##### Examples
<img src="https://vvvfo.github.io/COMP2123_report_resources/connected_graph.png" width="35%" style="float :left">
<img src="https://vvvfo.github.io/COMP2123_report_resources/not_connected_graph.png" width="33%" style = "float : right">
**On the left**
is an example of connected graph since you can find a path  between any two vertices.


-------


**On the right** is **not** a connected graph as *3* is not connected to other parts of the graph. For instance, there is no path between *3* and *2*.
 <br /> <br /> <br /> <br /> <br /> 

####  2. "Edge-Weighted"
Recall from what you have learnt in COMP2121😀, edge-weighted means that there is a numerical value for the weight of each edge.

####  3. "Undirected"
Recall from what you have learnt in COMP2121😀, all edges in the graph indicate a two-way relationship which means they can be travesed in two directions. 

## Great! Now you know what context we are in, let's move on to see what we are looking for ---- a Minimum-Spanning-Tree!
### What is a tree?
Recall from what you have learnt in COMP2121😀, tree is a connected graph with no circle.


### What is a Spanning-Tree in a graph?
We call a tree a Spanning-Tree of graph g if and only if the tree spans (in other words includes) all the vertices in that graph.

### What is a Minimum-Spanning-Tree in a graph?
<img src="https://vvvfo.github.io/COMP2123_report_resources/mst_1.png" width="30%" style="float :left">

A Minimum-Spanning-Tree is a spanning tree with ***minimum*** total weight among all spanning tree. **This is what we are looking for!😃**
<br /><br /><br /><br />


And that’s it!
*”But how do we find that though?”*
Great question again, then here comes our main guest today - **Prim’s Algorithm**!

## What is Prim’s Algorithm About?
##### In simple words, Prim's Algorithm can help us find the Minimum-Spanning-Tree we mentioned above.


#### The algorithm may be described in following steps:



1. Initialize a tree with an arbitrary node in the graph

2. Find a node not yet in the tree that can be connected to existing tree with the minimum weight edge and add it to the tree.
3. Repeat step 2 until all the nodes are in the tree

<img src="https://vvvfo.github.io/COMP2123_report_resources/d1.png" width="20%"> --> <img src="https://vvvfo.github.io/COMP2123_report_resources/d2.png" width="19.8%"> --> <img src="https://vvvfo.github.io/COMP2123_report_resources/d3.png" width="20%" > --> <img src="https://vvvfo.github.io/COMP2123_report_resources/d4.png" width="19.4%">--> <img src="https://vvvfo.github.io/COMP2123_report_resources/d5.png" width="20%"> -->  <img src="https://vvvfo.github.io/COMP2123_report_resources/d6.png" width="19.8%" > --> <img src="https://vvvfo.github.io/COMP2123_report_resources/d7.png" width="19.9%" > --> <img src="https://vvvfo.github.io/COMP2123_report_resources/d8.png" width="19.9%" >




### Your Trusty Data Structure - Graph
How can we do this in C++? First we need to have  a data structure for modeling a *graph*. As this is not the main focus of today’s self learning, we have provided a `Graph.h` file which contains a basic implementation of the a Graph data structure! *It uses `template` in implementation for the purpose of a more generic usage, which could make some function calling a little bit different from things you already know.* 

For today, we will use vertices of type `double` and weight of type `int` and you only need to know our `Graph.h` contains methods that you could make use of in following way when implementing our algorithm:

#### `Graph<double>(false)` 

Construct a **undirected graph object** with vertices of type `double`.

#### `double getVertex(int index)`

Return the **vertex** corresponds to a index.

#### `int getIndex(double vertex)`

Return the **index** corresponds to a vertex.

#### `int getNumOfVertex()`

Return the **number** of vertices.

#### `void addVertex(double vertex)`

Add a **vertex** to the graph.

#### `void addEdge(double v1, double v2, int w)`

Add an **edge** connecting `v1` to `v2` with weight `w`.

#### `int getEdge(double v1, double v2)`

Return the **weight** of edge connecting `v1` to `v2`.
 
#### `vector<double> getAllAdjacentVertex(double vertex)`

Return a vector of all the vertices adjacent to a vertex.

#### `bool contain(vertex)`

Return whether a graph contains a vertex.

### You are good to go!🙂
 
And now you are equipped with our weapon and shield, we can finally go on our conquest to find our *Minimum-Spanning-Tree*!

## Let’s Do It!🤗
- First, you need to open a file Prim.cpp
		
		gedit Prim.cpp

- We need input and output, an provided implementation of graph and string for type specification in later stage, so please add following statements in `Prim.cpp`
		
		#include <iostream>
		#include <string>
		#include "Graph"
	
### Let's implement this algorithm!🤗
- First, let's include the skeleton!
```
Graph<double> prim(Graph<double> g, int root){
		//All your code in this section find their way here😊
}		
```
The return type should be a graph with double as vertices, same as the original graph. 

Two arguments here are the graph we want to find our Minimum-Spanning Tree in and the arbitrary root we asign to start with.

- Now, let's create an empty graph `minimum_spanning_tree ` for storing what we have added.
     
     	Graph<double> minimum_spanning_tree(false);

**Note:** the false here is for creating an undirected graph (you can refer to the Graph.h provided for implementation details)
    
    
####   Here come three important arrays
1. We need an array (with size of number of vertices) to store each index's **cheapest connection** (the connection that uses lowest weighted edge possible) to the existing tree. 

	*The `i-th` entry in this array stores the lowest cost vertex `i` can be connected to the existing tree.*
	
	Think 😆 What value should they be initialized to when all of them are not in the tree?🤔
	
	Yes, they should be initialized to the largest `int` possible to indicate we have not been there yet.
	
	Now, let's include them to our code.
	
		int* cost_of_cheapest_connection_to = new int[g.getNumOfVertex()];
   
    	for (int i = 0; i < g.getNumOfVertex(); ++i){
        	cost_of_cheapest_connection_to[i] = 0x7fffffff;
    	}
		
    	
2. We also need an array to record which vertex this cheapest connection connect to to keep track of edges we want to add to the tree. 

	The `i-th` entry of this array will store an `int`
	indicating the **index of the vertex** of `i-th` vertex's cheapest connection target.
	 
	Think 😆 How could we denote that we have not explored a vertex in terms of index?🤔

	Correct! Let's use -1 (or basically any negative integer) to represent it.

	Now let's implement this.
	
		int* source_of_cheapest_connection_to = new int[g.getNumOfVertex()];
    
    	for (int i = 0; i < g.getNumOfVertex(); ++i){
       	 source_of_cheapest_connection_to[i] = NOT_CONNECTED;
    	}


3. Finally, we need one more array to record whether this node is already in the tree. 

	A vector of `bool` can do the job right ?🐒 And what should their initial value be when no node is in the tree ? 🙈
	
	True! The answer should be false 😬
	
	Cool, let's include our idea into the code!
	
		vector<bool> visited;
    	visited.resize(g.getNumOfVertex(), false);
    	
    	
    	
####  The iteration should begin!
Now, we could start the iteration to build the tree!

A while loop would be a good choice in this case 😀.

 	while(minimum_spanning_tree.getNumOfVertex() != g.getNumOfVertex()){ 
 	
 	//All the code in the iteration go to here
 	
 	}
	
Can you tell why the condition we set termination condition as `minimum_spanning_tree.getNumOfVertex() != g.getNumOfVertex()` ? 🤔😜

Yeah, I know you can recall that the iteration should not stop until all nodes are added😊

Now, we what we need to do in the iteration can be divided into 3 steps 😃

##### Step 1 in iteration:  finding the UNVISITED vertex with the lowest cost of connection to
We could use two `int` to record the cheapest cost and the corresponding index respectively.😀

Now we can add the following code to iterate through the array `cost_of_cheapest_connection_to` to find the cheapest connection.

	int cheapest_vertex_index = -1;
	int cheapest_vertex_cost = 0x7fffffff;
	for (int i = 0; i < g.getNumOfVertex(); ++i){
        
        //a comparison and resulting action need to be added
        
    }
    
In side the for loop, what comparison we need to make?🤔

Recall that we need to find the cheapest yet unvisited vertex, so that's the two criteria in the comparison.💡


	if (cost_of_cheapest_connection_to[i] <= cheapest_vertex_cost && visited[i] ==  false){
        cheapest_vertex_cost = cost_of_cheapest_connection_to[i];
        cheapest_vertex_index = i;
    }
  
  
 After finding that vertex, Guess what comes next?😜
 
 Bingo!
 
####  Step 2 in iteration: add the found vertex to our minimum spanning tree and set it to visited.

Now its the time to scroll back to where funcitons in Graph.h is introduced cause we need to use it now. Take your time~ I will be waiting here😊

It's simple to do this, isn't it? Guess you are ready to add the following to your code.😀

	minimum_spanning_tree.addVertex(g.getVertex(cheapest_vertex_index));
    if (root != cheapest_vertex_index) {
        minimum_spanning_tree.addEdge(g.getVertex(cheapest_vertex_index), g.getVertex(source_of_cheapest_connection_to[cheapest_vertex_index]), cheapest_vertex_cost);
    }
 
 **Note : we have to perform a checking before adding an edge because the first node we add to the tree does not have anything to connect to.**
 
 Then, what left in this step is just to set the corresponding entry in the visited vector to be true.
 		
 	visited[cheapest_vertex_index] = true;
 
 
 **Hang on, bro! You are almost there!💪🏽**
 
 
####  Step 3: Update `cost_of_cheapest_connection_to` and `source_of_cheapest_connection_to` after a new vertex is added to the tree

This step is a little bit more complicated, but I believe we can make it together🙂

In this step, basically what we need to do is to update two arrays. Recall that `cost_of_cheapest_connection_to` stores the cheapest cost to connect to the tree and `source_of_cheapest_connection_to` stores the corresponding vertex to connect to. 

Then, after we add a vertex to the tree, some of these values might change as the newly added vertex could provide a **cheaper** connection (or make it possible for some vertex to connection).

How do we update these values you might ask. Great question ! Let's find out together!😀

As vertices that could be affected are those **connected to the newly added vertex**, we can examine them one by one and update if necessary.

##### Let's give it a try!
- First, we can get all the adjacent vertices using method from Graph.h

		vector<double> all_adjacencies = g.getAllAdjacentVertex(g.getVertex(cheapest_vertex_index));

This gives a vector of all vertices adjacent to the newly added one.

- Second, let's iterate through these vertices to see if update is necessary.
	
		for (vector<double>::iterator it = all_adjacencies.begin(); it != all_adjacencies.end(); it++){
		
		//code for checking and updating need to be added
		
		}

 - ① Remember only vertices that haven't been visited before should be checked 

 
 			if (visited[g.getIndex(*it)] == false && g.getIndex(*it) != cheapest_vertex_index){
 			
 			//code in following step should be added here
 			
 			}
 			
 	- ② If the vertex satisfies condition above, we can move on to check if it **does** have a cheaper connection and update the two arrays if it's really the case.

		-  Get the weight of edge connecting this vertex and the newly added one.		
	 		
	 		
	 			int cost = g.getEdge(g.getVertex(cheapest_vertex_index), *it);
		
 		- If `cost` is less than its original cheapest cost, update two corresponding values in the arrays.
 		
	            if (cost <= cost_of_cheapest_connection_to[g.getIndex(*it)]){
	                cost_of_cheapest_connection_to[g.getIndex(*it)] = cost;
	                source_of_cheapest_connection_to[g.getIndex(*it)] = cheapest_vertex_index;
	            }

Wow, a lot happen in this step right? Don't worry, let's check if you got everything correct. Here are the code in **Step 3** should look like🙂
	
	  vector<double> all_adjacencies = g.getAllAdjacentVertex(g.getVertex(cheapest_vertex_index));
      for (vector<double>::iterator it = all_adjacencies.begin(); it != all_adjacencies.end(); it++){

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
        
#####  Congratulation ! That's all the stuff we need to put into the big while loop😃
We can return `minimum_spanning_tree` after the while loop and the implementation is done!

Buuuuuut, 😌 one more thing to consider......How could we determine the first node to be added to be `root` as we promised in the declaration? This is a tricky question🤔

Think about the how we choose the vertex to add in the first step in while loop. Do you find something?😊

Cool, the answer is to set value corresponds to `root` in `cost_of_cheapest_connection_to` to be 0. Then in the first iteration of while loop, it will be recognized as the cheapest connection and be added to the tree!

What you need to do is simply to add 
	
	 cost_of_cheapest_connection_to[root] = 0;
	
before while loop.

##### Great! Congratulation! You have finished implement this algorithm! 
Can't wait to try if it works? We provide the.....for you in......	
	