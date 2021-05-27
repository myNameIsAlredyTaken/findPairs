#pragma once
#include <iostream>

#define SIZE 10

class Graph
{
public:
	Graph();

	void addVertex(int num);
	void addEdge(int v1, int v2);

	void findPairs();
private:
	void findInnerPairs(int current, bool visited[]);
	void findInnerPairsSteps(int current, bool visited[], int& steps, int start);
	
	bool edgeExists(int v1, int v2);
	bool vertexExists(int v1);

	int matrix[SIZE][SIZE];

	int vertexes[SIZE];
	int vertexCount;
};

