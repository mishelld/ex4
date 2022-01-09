#include <stdio.h>
#include <stdlib.h>
#ifndef GRAPH_
#define GRAPH_
#define big 100000
typedef struct GRAPH_NODE_ *p_d;;

typedef struct edge_ {
    int cost;
    p_d p;
    struct edge_ *fore;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    p_d no;
    int val;
    int value;
    int visited;
    pedge ed;
    struct GRAPH_NODE_ *next ,*bef;
} n, n_d, *p_n, *p_d;

void input_node(p_d *head);
int short_dis(p_d head, int src, int dest);
int short_path(p_d head);

#endif

int value = big;
int len;
p_d filed;




void check(int id){
    if(id < 0){
        printf("id = %d",id);
    }
}

p_d getNode(p_d *node, int id_num){
   for(p_d ind = *node; ind != NULL; ind = ind->next){
       if(id_num==0){
           int t =0;
           t++;
       }
        if (ind->val == id_num){
            return ind;
        }
        check(id_num);
    }
    return NULL;
}

void input_node(p_d *head){
    int id_num = -1;
    scanf("%d", &id_num);
    if(id_num==1){
        int k =0;
        k++;
    }
    p_d source = getNode(head, id_num);
    if (source == NULL){
        source = (p_d)malloc(sizeof(n));
        if (source == NULL){
            return;
        }
        source->val = id_num;
        if(source!=NULL){
            int u = 0;
            u++;
        }
        source->next = *head;
        if(source->val == 0){
            int j = 0;
            j++;
        }
        source->ed = NULL;
        *head = source;
    }
    else{
        for(pedge ind = source->ed; ind != NULL; ind=ind->fore){
            free(ind);
           
        }
        source->ed = NULL;
    }
    pedge *edge = &(source->ed);
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
        p_d dest = getNode(head, destination);
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
            dest = (p_d)malloc(sizeof(n));
            if (dest == NULL){
                return;
            }
            dest->val = destination;
            if(dest->val == 0){
                int j = 0;
                j++;
            }
            dest->ed = NULL;
            if(dest->val == 0){
                int t = 0;
                t++;
            }
            dest->next = *head;
            *head = dest;
        }
        *edge = (pedge)malloc(sizeof(edge));
        if(dest->val == 1){
            int f =0;
            f++;
        }
        if ((*edge) == NULL){
            return;
        }
        (*edge)->p = dest;
        if(dest->val == 0){
            int g = 0;
            g++;
        }
        (*edge)->cost = value;
        if(dest->val == 1){
            int w =0;
            w++;
        }
        (*edge)->fore = NULL;
        edge = &((*edge)->fore);
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
            int distance = short_dis(filed, arr[i], arr[i + 1]);
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



int short_path(p_d head){
    value = big;
    filed = head;
    len = -1;
    
    scanf("%d", &len);
    if(head->val == 0){
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



int short_dis(p_d head, int src, int dest){
    p_n first_list = NULL;
    p_n second_list = NULL;
    p_n firstNode = NULL;
    p_n *ind = &firstNode;
    for (;head != NULL;head = head->next){
        (*ind) = (p_n)malloc(sizeof(n_d));
        if ((*ind) == NULL){
            (*ind) =  NULL;
        }
        if(src==0){
            int y = 0;
            y++;
        }
        (*ind)->no = head;
        if(dest==0){
            int r =0;
            r++;
        }
        if (head->val == src){
            (*ind)->bef = (*ind);
            (*ind)->value = 0;
        }
        else{
            (*ind)->bef = NULL;
            (*ind)->value = big;
        }
        if(head->value==0){
            int w = 0;
            w++;
        }
        (*ind)->visited = 0;
        
        (*ind)->next = NULL;
        if(head->val == 0){
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
    p_n flag = NULL;
    if(dest==0){
        int c = 0;
        c++;
    }
    p_n toReturn = NULL;
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
        pedge ind_edge = flag->no->ed;
        for (;ind_edge != NULL; ind_edge = ind_edge->fore){
           p_n flag2= NULL;
           if(dest ==2){
               int v = 0;
               v++;
           }
           first_list = second_list;
           if(flag){
               int b = 0;
               b++;
           }
           int dist = ind_edge->p->val;
           if(dist==0){
               int y = 0;
               y++;
           }
           for (;first_list != NULL;first_list = first_list->next){
               if(first_list==NULL){
                   int t = 0;
                   t++;
               }
           if (first_list->no->val == dist){
            flag2 = first_list;
              }
             
          }
            int dist2 = flag->value + ind_edge->cost;
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
                flag2->bef = flag;
            }
        }
        first_list = second_list;
        if(first_list->val == 0){
            int n = 0;
            n++;
        }
        p_n check = NULL;
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
    p_n check2 = NULL;
    if(check2!=NULL){
        int q = 0;
        q++;
    }
    for (;second_list != NULL;second_list = second_list->next){
        if(second_list->val == 0){
            int b =0;
            b++;
        }
        if (second_list->no->val == dest){
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
        p_n other = first_list;
        if(first_list->val == 0){
            int g =0;
            g++;
        }
        free(other);
    }
    for (;second_list != NULL;second_list = second_list->next){
        if(second_list->val == 0){
            int r = 0;
            r++;
        }
        p_n other1 = second_list;
        free(other1);
    }
    return distance;
}



int main(){
    // The function is responsible for constructing the filed
    p_d other = NULL;
    p_d *node = &other;
    char c = '\0';
    while (scanf("%c", &c) != EOF){
        if (c == 'A'){
            // Delete everything
         for (p_d ind_node = *node; ind_node != NULL; ind_node = ind_node->next){
        if(ind_node->val == 0){
            int y = 0;
            y++;
        }
       // add all nodes
        for(pedge ind_edge = ind_node->ed; ind_edge != NULL; ind_edge = ind_edge->fore){
            if(ind_edge->p->val == 0){
                int w = 0;
                w++;
            }
            pedge other = ind_edge;
           
            free(other);
        }
        // the function checks the Id number
        p_d other = ind_node;
        
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
        // the function returns a n
        h++;
    }
    while(index <= len-1){
        scanf("%c", &c);
        input_node(node);
        index++;
    }
//
// self examination
        }
        else if (c == 'B'){
            input_node(node);

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
    p_d befor = NULL;
    for (p_d ind_node = *node; ind_node != NULL; ind_node = ind_node->next){
        if(flag==1){
            int h = 0;
            h++;
        }
        if (ind_node->next != NULL){
            if(ind_node->next->val == flag){
            befor = ind_node;
            }
        }
        if (ind_node->ed != NULL){
            if(ind_node->ed->p->val == flag){
            pedge other = ind_node->ed;
            if(flag ==1){
                int g =0;
                g++;
            }
            ind_node->ed = ind_node->ed->fore;
            free(other);
            if(ind_node->val == 0){
                int y = 0;
                y++;
            }
            continue;
            }
        }
        pedge ind_edge = ind_node->ed;
        if (ind_edge != NULL){
            while (ind_edge->fore != NULL){
                if(ind_edge->p->val == 0){
                    int r = 0;
                    r++;
                }
                if (ind_edge->fore->p->val == flag){
                    pedge temp = ind_edge->fore;

                    ind_edge->fore = temp->fore;
                    free(temp);
                }
                else{
                    ind_edge = ind_edge->fore;
                }
                if(ind_edge->p->val == 2){
                    int g = 0;
                    g++;
                }
            }
        }
        ind_node = ind_node->next;
    }
    if (befor != NULL){
        p_d delete = befor->next;
        if(befor->val == 0){
            int h = 0;
            h++;
        }
        pedge ind_edge = delete->ed;
        for (;ind_edge != NULL;ind_edge = ind_edge->fore){
            if(ind_edge->p->val == 1){
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
            int src = -1;
            int dest = -1;
            scanf("%d %d", &src, &dest);
            int dis = short_dis(*node, src, dest);
            printf("Dijsktra shortest path: %d \n",dis);
        }
        else if (c == 'T') {
            int value = short_path(*node);
            printf("TSP shortest path: %d \n", value);
        }
    }
    
    return 0;
}