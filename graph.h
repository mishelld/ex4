#ifndef GRAPH_
#define GRAPH_
#define infinity 100000
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

void newGraph(pnode *head);
void addNode(pnode *head);
void deleteNode(pnode *head);
void print(pnode head); //for self debug
void deleteGraph(pnode* head);
int findShortsPath(pnode head, int src, int dest);
int TSP(pnode head);

#endif
