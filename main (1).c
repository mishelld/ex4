#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
int value = infinity;
int len;
pnode graph;


void newGraph(pnode *node){
    deleteGraph(node);
    int len = 0;
    char c = 'B';
    scanf("%d", &len);
    scanf("%c", &c);
    for (int i = 0; i <= len-1 ; i++){
        scanf("%c", &c);
        addNode(node);
    }
}


pnode getNode(pnode *node, int id_num){
    pnode ind = *node;
    while (ind != NULL){
        if (ind->node_num == id_num){
            return ind;
        }
        ind = ind->next;
    }
    return NULL;
}


void addNode(pnode *node){
    int id_num = -1;
    scanf("%d", &id_num);
    pnode source = getNode(node, id_num);
    if (source == NULL){
        source = (pnode)malloc(sizeof(node));
        if (source == NULL){
            return;
        }
        source->node_num = id_num;
        source->next = *node;
        source->edges = NULL;
        *node = source;
    }
    else{
        pedge ind = source->edges;
        while (ind != NULL){
            pedge other = ind->next;
            free(ind);
            ind = other;
        }
        source->edges = NULL;
    }
    pedge *edge = &(source->edges);
    int destination = -1;
    int flag = scanf("%d", &destination);
    while (flag != 0 && flag != EOF){
        pnode dest = getNode(node, destination);
        int value = -1;
        scanf("%d", &value);
        if (dest == NULL){
            dest = (pnode)malloc(sizeof(node));
            if (dest == NULL){
                return;
            }
            dest->node_num = destination;
            dest->edges = NULL;
            dest->next = *node;
            *node = dest;
        }
        *edge = (pedge)malloc(sizeof(edge));
        if ((*edge) == NULL){
            return;
        }
        (*edge)->endpoint = dest;
        (*edge)->weight = value;
        (*edge)->next = NULL;
        edge = &((*edge)->next);
        flag = scanf("%d", &destination);
    }
}



void print(pnode node){
    pnode ind_node = node;
    while (ind_node  != NULL){
        printf("Node %d: ", ind_node ->node_num);
        pedge ind_edge = ind_node ->edges;
        while (ind_edge != NULL){
            printf("dest %d: weight %d, ", ind_edge->endpoint->node_num, ind_edge->weight);
            ind_edge = ind_edge->next;
        }
        printf("\n");
        ind_node  = ind_node ->next;
    }
}



void deleteGraph(pnode *node){
    pnode ind_node = *node;
    while (ind_node != NULL){
        pedge ind_edge = ind_node->edges;
        while (ind_edge != NULL){
            pedge other = ind_edge;
            ind_edge = ind_edge->next;
            free(other);
        }
        pnode other = ind_node;
        ind_node = ind_node->next;
        free(other);
    }
    *node = NULL;
}



void deleteNode(pnode *node){
    int flag = -1;
    scanf("%d", &flag);
    pnode ind_node = *node;
    pnode befor = NULL;
    while (ind_node != NULL){
        if (ind_node->next != NULL && ind_node->next->node_num == flag){
            befor = ind_node;
        }
        if (ind_node->edges != NULL && ind_node->edges->endpoint->node_num == flag){
            pedge other = ind_node->edges;
            ind_node->edges = ind_node->edges->next;
            free(other);
            ind_node = ind_node->next;
            continue;
        }
        pedge ind_edge = ind_node->edges;
        if (ind_edge != NULL){
            while (ind_edge->next != NULL){
                if (ind_edge->next->endpoint->node_num == flag){
                    pedge temp = ind_edge->next;
                    ind_edge->next = temp->next;
                    free(temp);
                }
                else{
                    ind_edge = ind_edge->next;
                }
            }
        }
        ind_node = ind_node->next;
    }
    if (befor != NULL){
        pnode delete = befor->next;
        pedge ind_edge = delete->edges;
        while (ind_edge != NULL){
            pedge other = ind_edge;
            ind_edge = ind_edge->next;
            free(other);
        }
        befor->next = delete->next;
        free(delete);
    }
}



void permutations(int from, int *arr){
    if (from == len - 1){
        int other_w = 0;
        for (int i = 0; i < len - 1; i++){
            int distance = findShortsPath(graph, arr[i], arr[i + 1]);
            if (distance == -1){
                other_w = infinity;
                return;
            }
            other_w += distance;
        }
        if (other_w < value){
            value= other_w;
        }
        return;
    }
    for (int i = 0; i < len; ++i){
        int *other = (int *)malloc(sizeof(int) * len);
        if (other == NULL){
            other =  NULL;
        }
        for (int i = 0; i < len; i++){
            other[i] = arr[i];
        }
        int tentative = other[from];
        other[from] = other[i];
        other[i] = tentative;
        permutations(from + 1, other);
        free(other);
    }
}



int TSP(pnode node){
    value = infinity;
    graph = node;
    len = -1;
    scanf("%d", &len);
    int *arr = (int *)malloc(sizeof(int) * len);
    if (arr == NULL){
        arr = NULL;
    }
    for (int i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
     int *other = (int *)malloc(sizeof(int) * len);
    if (other == NULL){
        other =  NULL;
    }
    for (int i = 0; i < len; i++){
        other[i] = arr[i];
    }
    permutations(0, other);
    free(arr);
    free(other);
    if(value<infinity){
    return value;
    }
    return -1;
}



int findShortsPath(pnode node, int src, int dest){  
    pDnode first_list = NULL;
    pDnode second_list = NULL;
    pDnode firstNode = NULL;
    pDnode *ind = &firstNode;
    while (node != NULL){
        (*ind) = (pDnode)malloc(sizeof(Dnode));
        if ((*ind) == NULL){
            (*ind) =  NULL;
        }
        (*ind)->node = node;
        if (node->node_num == src){
            (*ind)->prev = (*ind);
            (*ind)->value = 0;
        }
        else{
            (*ind)->prev = NULL;
            (*ind)->value = infinity;
        }
        (*ind)->visited = 0;
        (*ind)->next = NULL;
        ind = &((*ind)->next);
        node = node->next;
    }
    first_list =  firstNode;
    second_list = firstNode;
    pDnode flag = NULL;
    pDnode toReturn = NULL;
    while (first_list != NULL){ 
        if (!first_list->visited && first_list->value < infinity && (toReturn == NULL || toReturn->value < first_list->value)){
            toReturn = first_list;
        }
        first_list = first_list->next;
    }
    if (toReturn != NULL){
        toReturn->visited = 1;
    }
    flag =  toReturn;
    while (flag != NULL){
        pedge ind_edge = flag->node->edges;
        while (ind_edge != NULL){
           pDnode flag2= NULL;
           first_list = second_list;
           int dist = ind_edge->endpoint->node_num;
           while (first_list != NULL){
           if (first_list->node->node_num == dist){
            flag2 = first_list;
              }
             first_list = first_list->next;
          }
            int dist2 = flag->value + ind_edge->weight;
            if (flag2->value > dist2){
                flag2->value = dist2;
                flag2->prev = flag;
            }
            ind_edge = ind_edge->next;
        }
        first_list = second_list;
        pDnode check = NULL;
        while (first_list != NULL){ 
            if (!first_list->visited && first_list->value < infinity && (check == NULL || check->value < first_list->value)){
                check = first_list;
            }
            first_list = first_list->next;
        }
        if (check != NULL){
            check->visited = 1;
        }
        flag =  check;
    }
    pDnode check2 = NULL;
    while (second_list != NULL){
        if (second_list->node->node_num == dest){
            check2 = second_list;
        }
        second_list = second_list->next;
    }
    int distance = check2->value;
    if(distance == infinity){
        distance= -1;
    }
    while (first_list != NULL){
        pDnode other = first_list;
        first_list = first_list->next;
        free(other);
    }
    while (second_list != NULL){
        pDnode other1 = second_list;
        second_list = second_list->next;
        free(other1);
    }
    return distance;
}



int main(){
    pnode other = NULL;
    pnode *node = &other;
    char c = '\0';
    while (scanf("%c", &c) != EOF){
        if (c == 'A'){
            newGraph(node);
        }
        else if (c == 'B'){
            addNode(node);
        }
        else if (c == 'D'){
            deleteNode(node);
        }
        else if (c == 'S'){
            int source = -1, dest = -1;
            scanf("%d %d", &source, &dest);
            int distance = findShortsPath(*node,source, dest);
            printf("Dijsktra shortest path: %d \n",distance);
        }
        else if (c == 'T') {
            int value = TSP(*node);
            printf("TSP shortest path: %d \n", value);
        }
    }
    deleteGraph(node);
    return 0;
}