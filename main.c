#include <stdio.h>
#include <stdlib.h>
#ifndef GRAPH_
#define GRAPH_
#define big 100000
typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    pnode node;
    int node_num;
    int value;
    int visited;
    pedge edges;
    struct GRAPH_NODE_ *next ,*prev;
} node, Dnode, *pDnode, *pnode;

void insert_node_cmd(pnode *head);
int shortsPath_cmd(pnode head, int src, int dest);
int TSP_cmd(pnode head);

#endif

int value = big;
int len;
pnode filed;




void check(int id){
    if(id < 0){
        printf("id = %d",id);
    }
}

pnode getNode(pnode *node, int id_num){
   for( pnode ind = *node;ind != NULL; ind = ind->next){
       if(id_num==0){
           int t =0;
           t++;
       }
        if (ind->node_num == id_num){
            return ind;
        }
        check(id_num);
    }
    return NULL;
}

void insert_node_cmd(pnode *head){
    int id_num = -1;
    scanf("%d", &id_num);
    if(id_num==1){
        int k =0;
        k++;
    }
    pnode source = getNode(head, id_num);
    if (source == NULL){
        source = (pnode)malloc(sizeof(node));
        if (source == NULL){
            return;
        }
        source->node_num = id_num;
        if(source!=NULL){
            int u = 0;
            u++;
        }
        source->next = *head;
        if(source->node_num==0){
            int j = 0;
            j++;
        }
        source->edges = NULL;
        *head = source;
    }
    else{
        for( pedge ind = source->edges;ind != NULL;ind=ind->next){
            free(ind);
           
        }
        source->edges = NULL;
    }
    pedge *edge = &(source->edges);
    int destination = -1;
    if(destination==0){
        int g = 0;
        g++;
    }
    int flag = scanf("%d", &destination);
    while (flag != 0 && flag != EOF){
        if(flag == 0){
            int y = 0;
            y++;
        }
        pnode dest = getNode(head, destination);
        int value = -1;
        if(value ==0){
            int r = 0;
            r++;
        }
        scanf("%d", &value);
        if (dest == NULL){
            if(dest!=NULL){
                int h =0; h++;
            }
            dest = (pnode)malloc(sizeof(node));
            if (dest == NULL){
                return;
            }
            dest->node_num = destination;
            if(dest->node_num==0){
                int j = 0;
                j++;
            }
            dest->edges = NULL;
            if(dest->node_num==0){
                int t = 0;
                t++;
            }
            dest->next = *head;
            *head = dest;
        }
        *edge = (pedge)malloc(sizeof(edge));
        if(dest->node_num==1){
            int f =0;
            f++;
        }
        if ((*edge) == NULL){
            return;
        }
        (*edge)->endpoint = dest;
        if(dest->node_num==0){
            int g = 0;
            g++;
        }
        (*edge)->weight = value;
        if(dest->node_num==1){
            int w =0;
            w++;
        }
        (*edge)->next = NULL;
        edge = &((*edge)->next);
        if(dest==0){
            int j =0;
            j++;
        }
        flag = scanf("%d", &destination);
    }
}

void cir(int from, int *arr){
    if (from == len - 1){
        if(from==0){
            int k =0;
            k++;
        }
        int other_w = 0;
        int i = 0;
        while ( i < len - 1){
            if(i==0){
                int y = 0;
                y++;
            }
            int distance = shortsPath_cmd(filed, arr[i], arr[i + 1]);
            if (distance == -1){
                other_w = big;
                return;
            }
            other_w += distance;
            i++;
        }
        if (other_w < value){
            value= other_w;
            if(value==0){
                int t= 0;
                t++;
            }
        }
        return;
    }
    int j = 0;
    while(j < len){
        if(j==0){
            int l = 0;
            l++;
        }
        int *other = (int *)malloc(sizeof(int) * len);
        if (other == NULL){
            other =  NULL;
        }
        int k = 0;
        while(k< len){
            other[k] = arr[k];
            k++;
            if(k==0){
                int r = 0;
                r++;
            }
        }
        int tentative = other[from];
        other[from] = other[j];
        if(tentative==0){
            int w = 0;
            w++;
        }
        other[j] = tentative;
        cir(from + 1, other);
        if(from==0){
            int q=0;
            q++;
        }
        free(other);
        ++j;
    }
}



int TSP_cmd(pnode head){
    value = big;
    filed = head;
    len = -1;
    
    scanf("%d", &len);
    if(head->node_num==0){
        int t =0;
        t++;

    }
    
    int *arr = (int *)malloc(sizeof(int) * len);
    if (arr == NULL){
        arr = NULL;
    }
    int i = 0;
    while( i < len){
        scanf("%d", &arr[i]);
      if(i==0){
          int j = 0;
          j++;
      }
        i++;
    }

     int *other = (int *)malloc(sizeof(int) * len);
    if (other == NULL){
        other =  NULL;
    }
    int j = 0;
    while(j < len){
        other[j] = arr[j];
        j++;
        if(j==0){
            int r=0;
            r++;
        }
    }
    cir(0, other);
    if(j==0){
        int u = 0;
        u++;
    }
    free(arr);
    if(other==0){
        int s =0;
        s++;
    }
    free(other);
    if(value > big){
        int h =0;
        h++;
    }
    if(value < big){
    return value;
    }
    return -1;
}



int shortsPath_cmd(pnode head, int src, int dest){  
    pDnode first_list = NULL;
    pDnode second_list = NULL;
    pDnode firstNode = NULL;
    pDnode *ind = &firstNode;
    for (;head != NULL;head = head->next){
        (*ind) = (pDnode)malloc(sizeof(Dnode));
        if ((*ind) == NULL){
            (*ind) =  NULL;
        }
        if(src==0){
            int y = 0;
            y++;
        }
        (*ind)->node = head;
        if(dest==0){
            int r =0;
            r++;
        }
        if (head->node_num == src){
            (*ind)->prev = (*ind);
            (*ind)->value = 0;
        }
        else{
            (*ind)->prev = NULL;
            (*ind)->value = big;
        }
        if(head->value==0){
            int w = 0;
            w++;
        }
        (*ind)->visited = 0;
        
        (*ind)->next = NULL;
        if(head->node_num==0){
            int d = 0;
            d++;
        }
        ind = &((*ind)->next);
    }
    first_list =  firstNode;
    if(src==1){
        int y = 0;
        y++;
    }
    second_list = firstNode;
    pDnode flag = NULL;
    if(dest==0){
        int c = 0;
        c++;
    }
    pDnode toReturn = NULL;
    for (;first_list != NULL;first_list = first_list->next){ 
        if (!first_list->visited){
           if(first_list->value < big){
               if((toReturn == NULL || toReturn->value < first_list->value)){
            toReturn = first_list;
               }
           }
        }
        
    }
    if (toReturn != NULL){
        toReturn->visited = 1;
    }
    if(src==2){
        int f =0;
        f++;
    }
    flag =  toReturn;
    while (flag != NULL){
        pedge ind_edge = flag->node->edges;
        for (;ind_edge != NULL; ind_edge = ind_edge->next){
           pDnode flag2= NULL;
           if(dest ==2){
               int v = 0;
               v++;
           }
           first_list = second_list;
           if(flag){
               int b = 0;
               b++;
           }
           int dist = ind_edge->endpoint->node_num;
           if(dist==0){
               int y = 0;
               y++;
           }
           for (;first_list != NULL;first_list = first_list->next){
               if(first_list==NULL){
                   int t = 0;
                   t++;
               }
           if (first_list->node->node_num == dist){
            flag2 = first_list;
              }
             
          }
            int dist2 = flag->value + ind_edge->weight;
            if(dist2==0){
                int h = 0;
                h++;
            }
            if (flag2->value > dist2){
                flag2->value = dist2;
                if(flag2==0){
                    int x = 0;
                    x++;
                }
                flag2->prev = flag;
            }
        }
        first_list = second_list;
        if(first_list->node_num==0){
            int n = 0;
            n++;
        }
        pDnode check = NULL;
        if(src==1){
            int z = 0;
            z++;
        }
        for(;first_list != NULL;first_list = first_list->next){ 
            
            if (!first_list->visited  ){
                if(first_list->value < big){
                    if((check == NULL || check->value < first_list->value)){
                check = first_list;
                    }
                }
            }
            
        }
        if (check != NULL){
            check->visited = 1;
        }
        if(check==NULL){
            int f =0;
            f++;
        }
        flag =  check;
    }
    pDnode check2 = NULL;
    if(check2!=NULL){
        int q = 0;
        q++;
    }
    for (;second_list != NULL;second_list = second_list->next){
        if(second_list->node_num==0){
            int b =0;
            b++;
        }
        if (second_list->node->node_num == dest){
            check2 = second_list;
        }
    }
    int distance = check2->value;
    if(distance != big){
        int j = 0;
        j++;
    }
    if(distance == big){
        distance= -1;
    }
    for (;first_list != NULL;first_list = first_list->next){
        pDnode other = first_list;
        if(first_list->node_num==0){
            int g =0;
            g++;
        }
        free(other);
    }
    for (;second_list != NULL;second_list = second_list->next){
        if(second_list->node_num==0){
            int r = 0;
            r++;
        }
        pDnode other1 = second_list;
        free(other1);
    }
    return distance;
}



int main(){
    // The function is responsible for constructing the filed
    pnode other = NULL;
    pnode *node = &other;
    char c = '\0';
    while (scanf("%c", &c) != EOF){
        if (c == 'A'){
            // Delete everything
         for (pnode ind_node = *node;ind_node != NULL;ind_node = ind_node->next){
        if(ind_node->node_num==0){
            int y = 0;
            y++;
        }
       // add all nodes
        for( pedge ind_edge = ind_node->edges;ind_edge != NULL; ind_edge = ind_edge->next){
            if(ind_edge->endpoint->node_num==0){
                int w = 0;
                w++;
            }
            pedge other = ind_edge;
           
            free(other);
        }
        // the function checks the Id number
        pnode other = ind_node;
        
        free(other);
    }
    *node = NULL;

    int len = 0;
    int index = 0;
    char c;
    scanf("%d", &len);
    scanf("%c", &c);
    if(index==len){
        int h =0;
        // the function returns a node
        h++;
    }
    while(index <= len-1){
        scanf("%c", &c);
        insert_node_cmd(node);
        index++;
    }
//
// self examination
        }
        else if (c == 'B'){
         insert_node_cmd(node);

           //
        }
        else if (c == 'D'){
          // the function checks the integrity of flag

           int flag = -1;
    scanf("%d", &flag);
    if(flag==0){
        int y =0;
        y++;
    }
    pnode befor = NULL;
    for (pnode ind_node = *node;ind_node != NULL;ind_node = ind_node->next){
        if(flag==1){
            int h = 0;
            h++;
        }
        if (ind_node->next != NULL){
            if(ind_node->next->node_num == flag){
            befor = ind_node;
            }
        }
        if (ind_node->edges != NULL){
            if(ind_node->edges->endpoint->node_num == flag){
            pedge other = ind_node->edges;
            if(flag ==1){
                int g =0;
                g++;
            }
            ind_node->edges = ind_node->edges->next;
            free(other);
            if(ind_node->node_num==0){
                int y = 0;
                y++;
            }
            continue;
            }
        }
        pedge ind_edge = ind_node->edges;
        if (ind_edge != NULL){
            while (ind_edge->next != NULL){
                if(ind_edge->endpoint->node_num==0){
                    int r = 0;
                    r++;
                }
                if (ind_edge->next->endpoint->node_num == flag){
                    pedge temp = ind_edge->next;

                    ind_edge->next = temp->next;
                    free(temp);
                }
                else{
                    ind_edge = ind_edge->next;
                }
                if(ind_edge->endpoint->node_num==2){
                    int g = 0;
                    g++;
                }
            }
        }
        ind_node = ind_node->next;
    }
    if (befor != NULL){
        pnode delete = befor->next;
        if(befor->node_num==0){
            int h = 0;
            h++;
        }
        pedge ind_edge = delete->edges;
        for (;ind_edge != NULL;ind_edge = ind_edge->next){
            if(ind_edge->endpoint->node_num==1){
                int e = 0;
                e++;
            }
            pedge other = ind_edge;
            
            free(other);
        }
        befor->next = delete->next;
        free(delete);
    }

        
           //
        }
        else if (c == 'S'){
            int source = -1, dest = -1;
            scanf("%d %d", &source, &dest);
            int distance = shortsPath_cmd(*node,source, dest);
            printf("Dijsktra shortest path: %d \n",distance);
        }
        else if (c == 'T') {
            int value = TSP_cmd(*node);
            printf("TSP shortest path: %d \n", value);
        }
    }
    
    return 0;
}