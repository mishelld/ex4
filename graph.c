#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/*int weight = infinity;
int size;
pnode graph;


void build_graph_cmd(pnode *head)
{
    deleteGraph_cmd(head);
    int size = 0;
    scanf("%d", &size);
    char n = 'B';
    scanf("%c", &n);
    for (int i = 0; i < size; ++i)
    {
        scanf("%c", &n);
        insert_node_cmd(head);
    }
}

pnode getNode(pnode *head, int id)
{
    pnode index = *head;
    while (index != NULL)
    {
        if (index->node_num == id)
        {
            return index;
        }
        index = index->next;
    }
    return NULL;
}

void insert_node_cmd(pnode *head)
{
    int id = -1;
    scanf("%d", &id);
    pnode src = getNode(head, id);

    if (src == NULL)
    {
        src = (pnode)malloc(sizeof(node));
        if (src == NULL)
        {
            return;
        }
        src->node_num = id;
        src->next = *head;
        src->edges = NULL;
        *head = src;
    }
    else
    {
        pedge index = src->edges;
        while (index != NULL)
        {
            pedge temp = index->next;
            free(index);
            index = temp;
        }
        src->edges = NULL;
    }
    pedge *lastEdge = &(src->edges);
    int dest = -1;
    int isDone = scanf("%d", &dest);
    while (isDone != 0 && isDone != EOF)
    {
        pnode destNode = getNode(head, dest);
        if (destNode == NULL)
        {
            destNode = (pnode)malloc(sizeof(node));
            if (destNode == NULL)
            {
                return;
            }
            destNode->node_num = dest;
            destNode->edges = NULL;
            destNode->next = *head;
            *head = destNode;
        }
        int weight = -1;
        scanf("%d", &weight);

        *lastEdge = (pedge)malloc(sizeof(edge));
        if ((*lastEdge) == NULL)
        {
            return;
        }
        (*lastEdge)->endpoint = destNode;
        (*lastEdge)->weight = weight;
        (*lastEdge)->next = NULL;
        lastEdge = &((*lastEdge)->next);
        isDone = scanf("%d", &dest);
    }
}
void printGraph_cmd(pnode head)
{
    pnode nodeIndex = head;
    while (nodeIndex != NULL)
    {
        printf("Node %d: ", nodeIndex->node_num);
        pedge edgeIndex = nodeIndex->edges;
        while (edgeIndex != NULL)
        {
            printf("dest %d: weight %d, ", edgeIndex->endpoint->node_num, edgeIndex->weight);
            edgeIndex = edgeIndex->next;
        }
        printf("\n");
        nodeIndex = nodeIndex->next;
    }
}
void deleteGraph_cmd(pnode *head)
{
    pnode nodeIndex = *head;
    while (nodeIndex != NULL)
    {
        pedge edgeIndex = nodeIndex->edges;
        while (edgeIndex != NULL)
        {
            pedge temp = edgeIndex;
            edgeIndex = edgeIndex->next;
            free(temp);
        }
        pnode temp = nodeIndex;
        nodeIndex = nodeIndex->next;
        free(temp);
    }
    *head = NULL;
}
void delete_node_cmd(pnode *head)
{
    int key = -1;
    scanf("%d", &key);
    pnode nodeIndex = *head;
    pnode prevAns = NULL;
    while (nodeIndex != NULL)
    {
        if (nodeIndex->next != NULL && nodeIndex->next->node_num == key)
        {
            prevAns = nodeIndex;
        }
        if (nodeIndex->edges != NULL && nodeIndex->edges->endpoint->node_num == key)
        {
            pedge temp = nodeIndex->edges;
            nodeIndex->edges = nodeIndex->edges->next;
            free(temp);
            nodeIndex = nodeIndex->next;
            continue;
        }
        pedge edgeIndex = nodeIndex->edges;
        if (edgeIndex != NULL)
        {
            while (edgeIndex->next != NULL)
            {
                if (edgeIndex->next->endpoint->node_num == key)
                {
                    pedge temp = edgeIndex->next;
                    edgeIndex->next = temp->next;
                    free(temp);
                }
                else
                {
                    edgeIndex = edgeIndex->next;
                }
            }
        }
        nodeIndex = nodeIndex->next;
    }
    if (prevAns != NULL)
    {
        pnode remove = prevAns->next;
        pedge edgeIndex = remove->edges;
        while (edgeIndex != NULL)
        {
            pedge temp = edgeIndex;
            edgeIndex = edgeIndex->next;
            free(temp);
        }
        prevAns->next = remove->next;
        free(remove);
    }
}


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
int shortsPath_cmd(pnode head, int src, int dest)
{  
 pDnode list = NULL;
  pDnode list1 = NULL;
//
pDnode head1 = NULL;
    pDnode *index = &head1;
    while (head != NULL)
    {
        (*index) = (pDnode)malloc(sizeof(Dnode));
        if ((*index) == NULL)
        {
            (*index) =  NULL;
        }
        (*index)->node = head;
        if (head->node_num == src)
        {
            (*index)->prev = (*index);
            (*index)->value = 0;
        }
        else
        {
            (*index)->prev = NULL;
            (*index)->value = infinity;
        }
        (*index)->visited = 0;
        (*index)->next = NULL;
        index = &((*index)->next);
        head = head->next;
    }
    list =  head1;
    list1 = head1;
    pDnode u = NULL;
    //
    pDnode ans = NULL;
    while (list != NULL)
    { 
        //if head not visited , and the heads value is smaller then inifiny 
        if (!list->visited && list->value < infinity && (ans == NULL || ans->value < list->value))
        {
            ans = list;
        }
        list = list->next;
    }
    if (ans != NULL)
    {
        ans->visited = 1;
    }
    u =  ans;
    //
    while (u != NULL)
    {
        pedge edgeIndex = u->node->edges;
        while (edgeIndex != NULL)
        {
           pDnode v= NULL;
           list = list1;
           int d = edgeIndex->endpoint->node_num;
           while (list != NULL)
           {
           if (list->node->node_num == d)
             {
            v = list;
              }
             list = list->next;
          }
  
            int newDist = u->value + edgeIndex->weight;
            if (v->value > newDist)
            {
                v->value = newDist;
                v->prev = u;
            }
            edgeIndex = edgeIndex->next;
        }
    list = list1;
    pDnode an = NULL;
    while (list != NULL)
    { 
        //if head not visited , and the heads value is smaller then inifiny 
        if (!list->visited && list->value < infinity && (an == NULL || an->value < list->value))
        {
            an = list;
        }
        list = list->next;
    }
    if (an != NULL)
    {
        an->visited = 1;
    }
    u =  an;
    

    }
    pDnode l = NULL;
    while (list1 != NULL)
    {
        if (list1->node->node_num == dest)
        {
            l = list1;
        }
        list1 = list1->next;
    }
    
    int dis = l->value;
    //
    if(dis == infinity){
        dis= -1;
    }
     while (list != NULL)
    {
        pDnode temp = list;
        list = list->next;
        free(temp);
    }
     while (list1 != NULL)
    {
        pDnode temp = list1;
        list1 = list1->next;
        free(temp);
    }
    return dis;
    
}*/

