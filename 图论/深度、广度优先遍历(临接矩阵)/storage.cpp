#include <iostream>

using namespace std ;

// 适用于无向边的图
class sre{
public :
    sre() ;
    ~sre() ;
    void reset() ; // 不同种遍历操作前的复位操作
    void BFS(int v) ; // 广度优先遍历
    void DFS(int v) ; // 深度优先遍历
private :
    int num_node , num_arc ; // 节点数与边的个数
    int **node ; // 储存节点与边信息的邻接矩阵,这里默认输入的节点有序且从0开始
    bool *visited ; // 记录节点是否被访问过的数组
    int *queue ; // 广度遍历运用到的队列
};

int main(){
    sre obj ;
    cout << "广度优先遍历结果为:" ;
    obj.BFS(0) ;
    obj.reset() ; // 标记数组复位操作
    cout << endl << "深度优先遍历结果为:" ;
    obj.DFS(0) ;
    return 0 ;
}

sre::sre()
{
    // 输入节点个数与边个数部分
    cout << "请分别输入节点与边的个数:" ;
    cin >> num_node >> num_arc ;
    bool valid = false ;
    while(!valid){
        if(num_node >= 1 && num_arc >= 0){
            valid = true ;
        }
        else{
            cout << "您输入的节点个数或边个数有误,请重新输入:" ;
            cin >> num_node >> num_arc ; // 如果输入非法就重新输入
        }
    }
    // 输入节点个数与边个数部分
    // 访问数组与队列初始化
    visited = new bool[num_node] ;
    for(int i = 0 ; i < num_node ; i++){
        visited[i] = false ;
    }
    queue = new int[num_node] ;
    // 访问数组与队列初始化
    // 临接矩阵初始化
    node = new int*[num_node] ;
    for(int i = 0 ; i < num_node ; i++){
        node[i] = new int[num_node] ;
    }
    for(int i = 0 ; i < num_node ; i++){
        for(int j = 0 ;j < num_node ; j++){
            node[i][j] = 0 ;
        }
    }
    // 临接矩阵初始化
    // 记录边的信息
    cout << "请开始输入边对应的节点:" << endl ;
    for(int i = 0 ; i < num_arc ; i++){
        int n = 0 , k = 0 ;
        cin >> n >> k ;
        node[n][k] = node[k][n] = 1 ;
    }
    // 记录边的信息
}

// 析构 释放占用的内存
sre::~sre()
{
    // 两个一维数组直接delete释放
    delete [] visited ;
    delete [] queue ;
    // 二维数组需要先逐一释放行指针占用的空间,再释放数组的头指针
    for(int i = 0; i < num_node; i++) {
        delete [] node[i];
    }
    delete [] node;
}

// 复位 将所有节点均标记为未访问过
void sre::reset()
{
    for(int i = 0 ; i < num_node ; i++){
        visited[i] = false ;
    }
}

// 广度优先遍历(队列 -> 遍历)
void sre::BFS(int v)
{
    int front = -1 , rear = -1 ; // 初始化队列
    cout << v << ' ' ;
    visited[v] = true ; // 输出访问节点信息并标记已访问
    queue[++rear] = v ; // 被访问节点入队
    while(front!=rear){ // 当队列非空
        v = queue[++front] ; // 队头出队
        for(int j = 0 ; j < num_node ; j++){ // 开始一一寻找与其存在边且未访问的节点
            if(node[v][j] == 1 && visited[j] == 0){
                cout << j << ' ' ;
                visited[j] = true ; // 找到则输出、标记已访问
                queue[++rear] = j ; // 入队,以备后续从其身边再寻找同样符合条件的节点
            }
        }
    }
    // 如果存在未访问的节点，则从该节点开始继续遍历
    for(int i = 0; i < num_node; i++){
        if(!visited[i]){
            BFS(i);
        }
    }
}

// 深度优先遍历(栈 -> 递归)
void sre::DFS(int v)
{
    // 访问当前节点，并将其标记为已访问
    cout << v << ' ' ;
    visited[v] = true ;

    // 遍历所有未访问过的邻居节点
    for(int j = 0 ; j < num_node ; j++){
        if(visited[j] == false && node[v][j] == 1 ){
            // 如果符合条件则向下继续遍历
            DFS(j) ;
        }
    }

    // 在递归调用之后更新visited数组
    visited[v] = true ;
}