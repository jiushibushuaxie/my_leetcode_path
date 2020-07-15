/*
    宽度优先遍历，需要用到队列，且为非递归
*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct GraphNode
{
    int label;          //label很重要            //第几个图节点,也用于是否访问数组的下标
    vector<GraphNode *> neighbors;  //与图节点相邻的节点，用数组表示
    GraphNode(int x): label(x) {}
};

void BFS_graph(GraphNode* node, int visit[]){   //visit数组表示图节点是否被访问过
    queue<GraphNode*> Q;          // 建立队列
    Q.push(node);               //  什么都不管，先push进队列
    visit[node->label] =1;            //标记为访问过的节点
    while(!Q.empty()){      
        GraphNode* top_node = Q.front(); //得到队头图节点
        Q.pop();                         //得到队头后马上pop
        printf("%d", top_node->label);
        for(int i=0;i<top_node->neighbors.size();++i){
            if(!visit[top_node->neighbors[i]->label]){          //邻接图节点没有访问过,push到队列中
                Q.push(top_node->neighbors[i]);
                visit[ top_node->neighbors[i]->label ] =1;      //并标记为已访问，进了队列就标记为已访问
            }
        }
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
            BFS_graph(Graph[i],visit);
            printf("\n");
        }
    }

    for(int i=0;i<MAX_N;++i){
        delete Graph[i];
    }
    return 0;
}