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

#### 1. Connected: 
Recall from what you have learnt in COMP2120😀, a connected graph is a graph in which you can find a path between **any** two vertices. 

##### connected exapmle:
<img src="resources/connected_graph.png" width="300" style="float : left"> 
This is an example of connected graph since you can find a path  between any two vertices.


 <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br />
##### not connected example:

<img src="resources/not_connected_graph.png" width="35%" style = "float : left">
This is **not** a connected graph as *3* is not connected to other parts of the graph. For instance, there is no path between *3* and *2*.
 <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br />

####  2. Edge-Weighted: 
Recall from what you have learnt in COMP2120😀, edge-weghted means that there is a numerical value for the weight of each edge.

####  3. Undirected: 
Recall from what you have learnt in COMP2120😀, all edges in the graph indicate a two-way relationship which means they can be travesed in two directions. 

## Great! Now you know what context we are in, let's move on to see what we are looking for ---- a Minimum-Spanning-Tree!
### What is a tree in a graph?
Recall from what you have learnt in COMP2120😀, tree is a connected graph with no circle.


### What is a Spanning-Tree?
We call a tree a Spanning-Tree of graph g if and only if the tree spans (in other words includes) all the vertices in that graph.

### What is a Minimum-Spanning-Tree?
A Minimum-Spanning-Tree is a spanning tree with ***minimum*** total weight among all spanning tree. **This is what we are looking for!😃**



And that’s it!
*”But how do we find that though?”*
Great question again, then here comes our main guest today - **Prim’s Algorithm**!

## What is Prim’s Algorithm About?
In simple words, … 

… a pseudo code of this algorithm would be like this:
```
/* insert ADAPTED pseudocode here */
```

### Your Trusty Data Structure - Graph
But how can we do this in C++? First we need to have  a data structure for modeling a *graph*. A graph is …, and as this is not the main focus of today’s self learning, we have provided a `Graph.h` file which contains a basic implementation of the a Graph data structure! In this implementation we used *adjacency list* to model a graph, to find out more about it, you can visit [XXXXXX](LINK_TO_BE_CHANGED!!!). For today, you only need to know our `Graph.h` contains the following methods that you could make use of when implementing our algorithm:

- `addVertex()` which adds XXXX
- `and some other stuff`
- …
 
And now you are equipped with our weapon and shield, we can finally go on our conquest to find our *Minimum-Spanning-Tree*!

## Let’s Do It!
First we gonna grab ‘em by the p*ssy by declaring … to be continued.

