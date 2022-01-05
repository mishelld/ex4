#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


pDnode buildDijkstra_NodeList(pnode start, int src)
{
    pDnode head = NULL;
    pDnode *index = &head;
    while (start != NULL)
    {
        (*index) = (pDnode)malloc(sizeof(Dnode));
        if ((*index) == NULL)
        {
            return NULL;
        }
        (*index)->node = start;
        if (start->node_num == src)
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
        start = start->next;
    }
    return head;
}
void deleteList(pDnode list) {
    while (list != NULL)
    {
        pDnode temp = list;
        list = list->next;
        free(temp);
    }
}

pDnode minInList(pDnode list)
{
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
    return ans;
}
int shortsPath_cmd(pnode head, int src, int dest)
{  /* pnode s = NULL;
    pnode index = head;
    while (index != NULL)
    {
        if (index->node_num == src)
        {
            s = index;
        }
        index = index->next;
    }
   
    while(list!=NULL){
        pedge ed = list->edges;
        while(ed!=NULL){
            if(ed->weight< ed->endpoint->value  && !ed->endpoint->visited){
                ed->endpoint->value = ed->weight;
        }
         ed=ed->next;
    }
    list= list->next;

}
pnode h = head;
while(h!=NULL){
    if(list->node_num==dest){
        return list->value;
    }
    list = list->next;
}
return -1;

}*/
 pDnode list = buildDijkstra_NodeList(head, src);
 pDnode list1 = buildDijkstra_NodeList(head, src);
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
        //
        u = minInList(list1);
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
    deleteList(list);
    return dis;
    
}
