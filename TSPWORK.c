#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int weight = infinity;
int size;
pnode graph;

int *buildArr(int size)
{

    int *arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    return arr;
}
int *copyArr(int *arr)
{
    int *copy = (int *)malloc(sizeof(int) * size);
    if (copy == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        copy[i] = arr[i];
    }
    return copy;
}

int TSP_cmd(pnode head)
{
    weight = infinity;
    graph = head;
    size = -1;
    scanf("%d", &size);
    int *arr = buildArr(size);
    int *copy = copyArr(arr);
    int temp = 0;
    for(int i =0; i<size-1;i++){
    int dist = shortsPath_cmd(graph,arr[i],arr[i+1]);
    if(dist != -1){
        temp = temp + dist;
    }
    else{
       temp = infinity;
    }
    }
    if(temp<infinity){
        weight = temp;
    }
    
    free(arr);
    free(copy);
    
    return weight;
}