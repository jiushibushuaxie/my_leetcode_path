/*
    邻接表存储图，并进行深度优先遍历
*/

#include <cstdio>
#include <vector>

using namespace std;

struct GraphNode
{
    int label;             //label很重要         //图节点的值,也用于是否访问数组的下标
    vector<GraphNode *> neighbors;  //与图节点相邻的节点，用数组表示
    GraphNode(int x): label(x) {}
};

void DFS_graph(GraphNode* node, int visit[]){   //visit数组表示图节点是否被访问过
    if(visit[node->label]==1){     //访问过,return，结束递归条件
        return;
    }
    visit[ node->label ] =1;            //标记已访问的节点
    printf("%d", node->label);
    for(int i=0; i<node->neighbors.size();++i){
        DFS_graph(node->neighbors[i], visit); 
    }
}

int main() {
    const int MAX_N = 5;   //创建图的节点
    GraphNode* Graph[MAX_N];   //创建包含MAX_N个节点的图节点数组，注意图节点是用GraphNode*表示的
    for(int i=0;i<MAX_N;++i){
        Graph[i] = new GraphNode(i);
    }

    Graph[0]->neighbors.push_back(Graph[4]);
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[4]);

    int visit[MAX_N] = {0};  //用于标记节点是否被访问过
    for(int i=0;i<MAX_N;++i){
        if(!visit[i]){          //没有访问过，就进行打印 以及 DFS搜索
            printf("From label(%d): ", Graph[i]->label);
            DFS_graph(Graph[i],visit);
            printf("\n");
        }
    }

    for(int i=0;i<MAX_N;++i){
        delete Graph[i];
    }
    return 0;
}