package 二叉树;

import java.util.Scanner ;
import java.util.LinkedList ;
import java.util.Queue ;

/**
 * 文件大类
 */
public class TreeBuilder {
    /**
     * 主函数
     * @param args 接受来自终端(人为输入)的命令行
     */
    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in) ;
        System.out.print("请输入二叉树的数据个数:") ;
        int length = 0 ;
        length = reader.nextInt() ;
        int[] nums = new int[length] ;
        System.out.println("请开始输入二叉树内的数据:") ;
        for(int i = 0 ; i < length ; i++ ){
            nums[i] = reader.nextInt() ;
        }
        reader.close() ;
        TreeNode root = BuildTree(nums) ;
        System.out.print("深度优先遍历结果:") ;
        DFS(root) ;
        System.out.print("\n广度优先遍历结果:") ;
        BFS(root) ;
    }

    /**
     * 构造二叉树的大类的主要函数
     * @param nums 二叉树节点数据数组
     * @return 二叉树的根节点
     */
    public static TreeNode BuildTree(int[] nums){
        return buildHelper(nums , 0 , nums.length - 1) ;
    }

    /**
     * 实现二叉树构造的辅助类(也是实现递归操作的类)
     * @param nums 二叉树节点数据数组
     * @param start 数组的起始下标
     * @param end 数组的终点下标
     * @return 当前构建树的根节点
     */
    public static TreeNode buildHelper(int[] nums , int start , int end){
        // 范围判断:截断递归的越界情况、从而不用在开始递归之前先进行判断
        if(start > end){
            return null ;
        }
        // 以下为正常情况的具体过程
        // 取数组的中间元素作为根节点
        int mid = start + ( end - start )/ 2 ;
        TreeNode root = new TreeNode(nums[mid]) ;
        // 每次取得数组给定范围内的中点值作为当前节点左右子树的节点值 
        root.left = buildHelper(nums, start, mid - 1) ; // 最开始对应左半部分
        root.right = buildHelper(nums, mid + 1, end) ; // 最开始对应右半部分
        // 每次返回区间中值,递归完成返回即为最开始的根节点,整个过程相当于切分后不断接枝
        return root ;
    }

    /**
     * 深度优先遍历二叉树
     * @param root 深度优先遍历的起始点
     */
    public static void DFS(TreeNode root){
        // 先对当前节点判断 非空则输出节点数据并递归至其左右子树->深度
        if(root == null) return ;
        System.out.print(root.val + " ") ;
        // 这里不用先判断左右子树非空再递归,因为函数内部会判断,为空直接return截断
        DFS(root.left) ;
        DFS(root.right) ;
    }

    /**
     * 广度优先遍历
     * @param root 广度优先遍历的起始节点
     */
    public static void BFS(TreeNode root){
        // 算法思路的核心是遍历时以队列为核心->广度
        if(root == null) return ;
        // 创建一个储存TreeNode对象的队列queue(双向链表)
        Queue<TreeNode> queue = new LinkedList<>() ;
        queue.offer(root) ; // 将根节点入队
        // 以队列为循环对象实现广度优先
        while(!queue.isEmpty()){ // 非空为真
            TreeNode node = queue.poll() ; // 队头元素出队
            System.out.print(node.val + " ") ;
            // 依次检视节点的左右子节点
            if(node.left != null){
                queue.offer(node.left) ;
            }
            if(node.right != null){
                queue.offer(node.right) ;
            }
        }
    }
}

/**
 * 二叉树节点类
 */
class TreeNode{
    int val ; // 节点值
    TreeNode left ; // 左子树
    TreeNode right ; // 右子树
    
    /**
     * 创建一个新的 TreeNode 实例。
     * @param val 节点的值
     */
    TreeNode(int val){
        this.val = val ;
        this.left = null ;
        this.right = null ;
    }
}