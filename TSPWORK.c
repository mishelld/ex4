#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int weight = infinity;
int size;
pnode graph;


void permutations(int start, int *arr)
{
    if (start == size - 1)
    {
        int tempWeight = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int dis = shortsPath_cmd(graph, arr[i], arr[i + 1]);
        if (dis == -1)
        {
            tempWeight = infinity;
            return;
        }
        tempWeight += dis;
    }
    if (tempWeight < weight)
    {
        weight = tempWeight;
    }
        return;
    }
    for (int i = 0; i < size; ++i)
    {
     int *copy1 = (int *)malloc(sizeof(int) * size);
    if (copy1 == NULL)
    {
        copy1 =  NULL;
    }
    for (int i = 0; i < size; i++)
    {
        copy1[i] = arr[i];
    }
       // swap(&copy[start], &copy[i]);
        int temp = copy1[start];
        copy1[start] = copy1[i];
        copy1[i] = temp;

        permutations(start + 1, copy1);
        free(copy1);
    }
}
int TSP_cmd(pnode head)
{
    weight = infinity;
    graph = head;
    size = -1;
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    if (arr == NULL)
    {
        arr = NULL;
    }
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
     int *copy = (int *)malloc(sizeof(int) * size);
    if (copy == NULL)
    {
        copy =  NULL;
    }
    for (int i = 0; i < size; i++)
    {
        copy[i] = arr[i];
    }
    
    permutations(0, copy);
    free(arr);
    free(copy);
    if(weight<infinity){
   return weight;
    }
    return -1;
}