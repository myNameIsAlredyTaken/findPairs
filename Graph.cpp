#include "Graph.h"

Graph::Graph() {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = 0;
	vertexCount = 0;
}

void Graph::addVertex(int num) {
	vertexes[vertexCount++] = num;
}

void Graph::addEdge(int v1, int v2) {
	if (vertexExists(v1) && vertexExists(v2)) {
		matrix[v1][v2] = 1;
		matrix[v2][v1] = 1;
	}
}

bool Graph::edgeExists(int v1, int v2) {
	return matrix[v1][v2] > 0;
}

bool Graph::vertexExists(int v) {
	for (int i = 0; i < vertexCount; i++)
		if (vertexes[i] == v)
			return true;
	return false;
}

void Graph::findPairs() {
	bool visited[SIZE];
	for (int i = 0; i < vertexCount; i++) {
		for (int j = 0; j < SIZE; j++)
			visited[j] = false;
		findInnerPairs(i, visited);
		std::cout << std::endl;
	}
}

void Graph::findInnerPairs(int current_, bool visited[]) {
	visited[current_] = true;
	int start = current_;
	int current, steps;
	for (int i = 0; i < vertexCount; i++) {
		current = current_;
		steps = 0;
		if (edgeExists(current, i) && !visited[i]) {
			std::cout << "V" << start << ", V" << i << std::endl;
			current = i;
			findInnerPairsSteps(current, visited, ++steps, start);
		}
	}
}

void Graph::findInnerPairsSteps(int current, bool visited[], int& steps, int start) {
	visited[current] = true;
	for (int i = 0; i < vertexCount; i++) {
		if (steps < 3) {
			if (edgeExists(current, i) && !visited[i]) {
				std::cout << "V" << start << ", V" << i << std::endl;
				findInnerPairsSteps(i, visited, ++steps, start);
			}
		}
		else { 
			steps--;
			break; 
		}
	}
	steps--;
}