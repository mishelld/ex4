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
    int weight;
    int isUse;
    pedge edges;
    struct GRAPH_NODE_ *next ,*dad;
} node, Dnode, *pDnode, *pnode;

/*typedef struct Dijkstra_Node
{
    pnode node;
    struct Dijkstra_Node *dad;
    int weight;
    int isUse;
    struct Dijkstra_Node *next;
} Dnode, *pDnode;
*/
void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
int shortsPath_cmd(pnode head, int src, int dest);
int TSP_cmd(pnode head);
//pnode getNode(pnode *head, int id);

#endif
