// Implementation of the undirected weighted graph ADT

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"
#include "Queue.h"

// graph representation (adjacency matrix)
typedef struct GraphRep {
	int nV;      // #vertices
	int nE;      // #edges
	int **edges; // matrix of weights (0 == no edge)
} GraphRep;

static int validVertex(Graph g, Vertex v);

////////////////////////////////////////////////////////////////////////

Graph GraphNew(int nV)
{
	assert(nV > 0);

	Graph new = malloc(sizeof(*new));
	assert(new != NULL);
	new->nV = nV;
	new->nE = 0;

	new->edges = calloc(nV, sizeof(int *));
	assert(new->edges != NULL);
	for (int v = 0; v < nV; v++) {
		new->edges[v] = calloc(nV, sizeof(int));
		assert(new->edges[v] != 0);
	}

	return new;
}

void GraphFree(Graph g)
{
	assert(g != NULL);
	for (int v = 0; v < g->nV; v++)
		free(g->edges[v]);
	free(g->edges);
	free(g);
}

////////////////////////////////////////////////////////////////////////

void GraphInsertEdge(Graph g, Vertex v, Vertex w, int weight)
{
	assert(g != NULL && validVertex(g, v) && validVertex(g, w));

	if (g->edges[v][w] != 0 && g->edges[w][v] != 0)
		return; // an edge already exists; do nothing.

	g->edges[v][w] = weight;
	g->edges[w][v] = weight;
	g->nE++;
}

void GraphRemoveEdge(Graph g, Vertex v, Vertex w)
{
	assert(g != NULL && validVertex(g, v) && validVertex(g, w));
	if (g->edges[v][w] == 0 && g->edges[w][v] == 0)
		return; // the edge doesn't exist; do nothing.

	g->edges[v][w] = 0;
	g->edges[w][v] = 0;
	g->nE--;
}

////////////////////////////////////////////////////////////////////////

/**
 * Finds  the  shortest path (in terms of the number of hops) from `src`
 * to `dest` such that no edge on the path has weight larger than `max`.
 * Stores  the  path  in the given `path` array including both `src` and
 * `dest` and returns the number of vertices stored in the  path  array.
 * Returns 0 if there is no such path.
 */

static int *findPathBfs(Graph g, Vertex src, Vertex dest, int max) {
	int *pred = calloc(g->nV, sizeof(int));
	assert(pred != NULL);
	for (Vertex v = 0; v < g->nV; v++) {
		pred[v] = -1;
	}
	pred[src] = src;
	
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	
	bool found = false;
	while (!found && !QueueIsEmpty(q)) {
		Vertex v = QueueDequeue(q);
		
		for (Vertex w = 0; w < g->nV; w++) {
			if (g->edges[v][w] <= max && pred[w] == -1) {
				pred[w] = v;
				if (w == dest) {
					found = true;
					break;
				}
				QueueEnqueue(q, w);
			}
		}
	}
	
	QueueFree(q);
	return pred;
}


// starting bfs from src
int findPath(Graph g, Vertex src, Vertex dest, int max, int *path) {
	assert(g != NULL);
	
	int *pred = findPathBfs(g, src, dest, max);
	
	if (pred[dest] == -1) {
		free(pred);
		return 0;
	}
	
	// fill path array in reverse
	int pathLength = 0;
	Vertex curr = dest;
	while (curr != src) {
		path[pathLength++] = curr;
		curr = pred[curr];
	}
	path[pathLength++] = src;
	
	// reverse path array
	for (int i = 0, j = pathLength - 1; i < j; i++, j--) {
		Vertex tmp = path[i];
		path[i] = path[j];
		path[j] = tmp;
	}
	
	free(pred);
	return pathLength;
}


// starting bfs from dest
int findPath(Graph g, Vertex src, Vertex dest, int max, int *path) {
	assert(g != NULL);
	
	int *pred = findPathBfs(g, dest, src, max);
	
	if (pred[src] == -1) {
		free(pred);
		return 0;
	}
	
	int pathLength = 0;
	Vertex curr = src;
	while (curr != dest) {
		path[pathLength++] = curr;
		curr = pred[curr];
	}
	path[pathLength++] = dest;
	
	free(pred);
	return pathLength;
}

////////////////////////////////////////////////////////////////////////

void GraphShow(Graph g, char **names)
{
	assert(g != NULL);
	printf("#vertices=%d, #edges=%d\n\n", g->nV, g->nE);
	int v, w;
	for (v = 0; v < g->nV; v++) {
		printf("%d %s\n", v, names[v]);
		for (w = 0; w < g->nV; w++) {
			if (g->edges[v][w]) {
				printf("\t%s (%d)\n", names[w], g->edges[v][w]);
			}
		}
		printf("\n");
	}
}

////////////////////////////////////////////////////////////////////////
// Helper Functions

static int validVertex(Graph g, Vertex v)
{
	return (g != NULL && v >= 0 && v < g->nV);
}

