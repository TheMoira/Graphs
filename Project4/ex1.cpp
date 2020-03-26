#include <iostream>
#include "utils.h"


int** randomDiGraph()
{
    int n;
    std::cout<<"Insert number of vertices: ";
    std::cin>>n;

    float p = 0;

    do{
        std::cout<<"\nInsert probability (0-1): ";
        std::cin>>p;
    }while(p<0.0 || p>1.0);

    int** adjM = makeAdjacencyMatrix(n);
    float r;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) continue;

            r = r_prob();

            if(r<p)
            {
                adjM[i][j] = 1;
            }
        }
    }

    std::list<int>* lista = DiAdjacencyToList(adjM,n);

    std::cout<<"Adjacency matrix: \n";
    printAdjacencyMatrix(adjM, n);
    std::cout<<"\nAdjacency list: \n";
    printAdjacencyList(lista, n);

    return adjM;

}