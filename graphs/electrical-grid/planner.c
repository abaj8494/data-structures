// Algorithms to design electrical grids

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Place.h"
#include "PQ.h"

////////////////////////////////////////////////////////////////////////
// Your task

/**
 * Designs  a minimal cost electrical grid that will deliver electricity
 * from a power plant to all the given cities. Power lines must be built
 * between cities or between a city and a power plant.  Cost is directly
 * proportional to the total length of power lines used.
 * Assumes  that  numCities  is at least 1 (numCities is the size of the
 * cities array).
 * Stores the power lines that need to be built in the given  powerLines
 * array, and returns the number of power lines stored. Assumes that the
 * powerLines array is large enough to store all required power lines.
 */
static double distance(Place p1, Place p2);

int planGrid1(Place cities[], int numCities, Place powerPlant,
              PowerLine powerLines[]) {
    int powerPlantId = numCities;
    
    Graph g = GraphNew(numCities + 1);
    for (int i = 0; i < numCities; i++) {
        double dist = distance(cities[i], powerPlant);
        GraphInsertEdge(g, (Edge){i, powerPlantId, dist});
        for (int j = i + 1; j < numCities; j++) {
            dist = distance(cities[i], cities[j]);
            GraphInsertEdge(g, (Edge){i, j, dist});
        }
    }

    Graph mst = GraphMST(g);

    int n = 0;
    for (int i = 0; i < numCities; i++) {
        if (GraphIsAdjacent(mst, i, powerPlantId)) {
            powerLines[n++] = (PowerLine){cities[i], powerPlant};
        }
        for (int j = i + 1; j < numCities; j++) {
            if (GraphIsAdjacent(mst, i, j) != 0.0) {
                powerLines[n++] = (PowerLine){cities[i], cities[j]};
            }
        }
    }

    GraphFree(mst);
    GraphFree(g);
    return n;
}

static double distance(Place p1, Place p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

////////////////////////////////////////////////////////////////////////
// Optional task

/**
 * Designs  a minimal cost electrical grid that will deliver electricity
 * to all the given cities.  Power lines must be built between cities or
 * between a city and a power plant.  Cost is directly  proportional  to
 * the  total  length of power lines used.  Assume that each power plant
 * generates enough electricity to supply all cities, so not  all  power
 * plants need to be used.
 * Assumes  that  numCities and numPowerPlants are at least 1 (numCities
 * and numPowerPlants are the sizes of the cities and powerPlants arrays
 * respectively).
 * Stores the power lines that need to be built in the given  powerLines
 * array, and returns the number of power lines stored. Assumes that the
 * powerLines array is large enough to store all required power lines.
 */
int planGrid2(Place cities[], int numCities,
              Place powerPlants[], int numPowerPlants,
              PowerLine powerLines[]) {
    // TODO: Complete this function
    return 0;
}
