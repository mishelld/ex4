#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
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



//


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
    
}

/* pnode s = NULL;
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
*/