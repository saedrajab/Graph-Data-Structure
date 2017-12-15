// DisreteMathProjectGraph.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
struct MatrixNode
{
	int distance;
	MatrixNode *next;

};
static string ch = "ABCDEFGHIK";
int Letter = 65;
int sum = 0;

struct Matrix
{
	MatrixNode *head;
};


struct Graph
{
	int Vertices;
	Matrix* array;
};


MatrixNode * newMatrixNode(int dest)
{
	MatrixNode *newNode = new MatrixNode;
	newNode->distance = dest;
	newNode->next = NULL;
	return newNode;
}

Graph * createG(int vertices)
{
	Graph* graph = new Graph;
	graph->Vertices = vertices;
	graph->array = new Matrix[vertices];

	for (int i = 0; i < vertices; i++)
		graph->array[i].head = NULL;

	return graph;

}


void addEdge(Graph *graph, int source, int destination)
{

	MatrixNode *newNode = newMatrixNode(destination);
	newNode->next = graph->array[source].head;
	graph->array[destination].head = newNode;

}

void printGraph(Graph *graph)
{
	int nodesLetter = 65;
	for (int i = 0; i < graph->Vertices; i++)
	{
		MatrixNode * current = graph->array[i].head;


		cout << "\nAdjacency Matrix of edge " << (char)(nodesLetter) << "\n head ";
		++nodesLetter;
		while (current)
		{
			for (unsigned i = 0; i < ch.length(); ++i)
			{
				cout << "-> " << ch.at(current->distance);
				i = 11;
			}
			//printf("->%d", current->distance);
			current = current->next;
		}

		cout << "\n";

	}

}

void countOcc(Graph *graph, int index)
{
	int c = 0;

	MatrixNode * current = graph->array[index].head;
	for (int i = 0; i < graph->Vertices; i++)
	{

		while (current)
		{
			if (current->distance = index)
				c++;
			current = current->next;
		}

	}
	sum += c;
	cout << "The count of each edge with deg(" << char(Letter) << ") is: " << c << endl;
	++Letter;

}




int main()
{

	int edges = 10;
	Graph *graph = createG(edges);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 0, 9);
	addEdge(graph, 0, 8);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 8);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 5, 6);
	addEdge(graph, 5, 3);
	addEdge(graph, 6, 2);
	addEdge(graph, 6, 7);
	addEdge(graph, 7, 6);
	addEdge(graph, 8, 0);
	addEdge(graph, 9, 6);
	addEdge(graph, 8, 1);
	addEdge(graph, 8, 0);
	addEdge(graph, 9, 1);



	printGraph(graph);
	cout << endl << endl;

	for (int i = 0; i < graph->Vertices; i++)
		countOcc(graph, i);
	cout << endl;
	cout << "The sum of edges is: " << sum << endl;


	system("pause");
	return 0;

}
