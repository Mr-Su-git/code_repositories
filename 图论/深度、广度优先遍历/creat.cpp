#include <iostream>
#include <queue>

using namespace std;

struct node_arc{
    int index_arc ;
    node_arc *next = nullptr ;
};

struct node_ver{
    int index_ver ;
    node_arc *first_edge ;
};

// 适用于有向边的图
class graph{
public :
    graph() ;
    ~graph() ;
    void DFS(int v) ;
    void BFS(int v) ;
private :
    int num_ver , num_arc ;
    node_ver* ver ;
    bool* visited ;
};

graph::graph(){
    // 输入顶点个数和边个数部分
    cout << "请分别输入图的节点个数和边个数:" ;
    bool valid = false ;
    cin >> num_ver >> num_arc ;
    while(!valid){
        if(num_ver >= 1 && num_arc >= 0){
            valid = true ;
        }
        else{
            cout << "您输入的节点数或边个数有误,请重新输入:" ;
            cin >> num_ver >> num_arc ; // 如果输入非法就重新输入
        }
    }
    // 输入节点个数和边个数部分
    ver = new node_ver[num_ver] ;
    visited = new bool[num_ver] ;
    for(int i = 0 ; i < num_ver ; i++){
        visited[i] = false ; // 初始化为未访问
        ver[i].first_edge = nullptr; // 初始化第一条边为空指针
        ver[i].index_ver = i; // 初始化节点索引
    }
    // 输入边:输入格式:按照表中的点每次输入它和与它有边的结点序号 例如最初的节点有三条边 -> 0,1 \ 0,2 \ 0,3
    int i , j ;
    for(int k = 0 ; k < num_arc ; k++){
        cin >> i >> j ;
        node_arc* s = new node_arc ; // 每次录入创建一个新的边节点
        s -> index_arc = j ; // 将边节点对应在数组中的序号录入
        s -> next = ver[i].first_edge ; // 用边节点的尾部接上数组的边部分
        ver[i].first_edge = s ; // 再将整个部分放至数组的边部分
    }
}

// 深度优先遍历 -> 栈的思想(递归)
void graph::DFS(int v){
    visited[v] = true ;
    cout << ver[v].index_ver << " " ;
    node_arc *p = ver[v].first_edge ;
    while(p){
        int j = p -> index_arc ;
        if(!visited[j]){
            DFS(j);
        }
        p = p -> next ; // 将 p 指针指向下一个节点
    }
}

// 广度优先遍历 -> 队列的思想(遍历)
void graph::BFS(int v)
{
    queue<int> q ; // 创建队列
    q.push(v) ;
    visited[v] = true ; // 将访问节点标记为已访问
    cout << ver[v].index_ver ; // 将访问节点加入队列中
    while(!q.empty()){
        v = q.front() ;
        q.pop() ; // 当队列非空,先访问队头元素的分支,队头元素出队
        node_arc *p = ver[v].first_edge ;
        while(p){ //从当前节点开始逐一遍历与之相连的节点
            int j = p -> index_arc ;
            if(!visited[j]){ // 如果未访问过,则将当前节点入队已备后续访问其相关分支，并标记为已访问
                visited[j] = true ;
                q.push(j) ;
                cout << " " << ver[j].index_ver ; // 输出访问节点
            }
            p = p -> next ;
        }
    }
}

graph::~graph() {
    for (int i = 0; i < num_ver; ++i) {
        node_arc* p = ver[i].first_edge ;
        while (p) {
            node_arc* q = p->next ;
            delete p ;
            p = q ;
        }
    }
    delete[] ver ;
    delete[] visited ;
}

int main(){
    class graph obj ;
    int n = 0 ;
    cout << "深度优先遍历结果:";
    obj.DFS(n) ;
    cout << endl << "广度优先遍历结果:";
    obj.BFS(n) ;
    cout << endl ;
    return 0 ;
}