import java.util.*;
/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
// my version with beating only 5% submission
public class Solution {
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    public List<List<Integer>> levelOrder(TreeNode root) {
        // the node waiting for expansion
        Queue<TreeNode> queue = new LinkedList<>();
        // result
        List result = new LinkedList();
        
        if(root == null){
            return result;
        }
        
        queue.offer(root);
        result.add(Arrays.asList(root.val));    // diff
        while(!queue.isEmpty()){
            int size = queue.size();
            List<Integer> semi_list = new LinkedList<>();
            for(int i = 0; i < size; i++){
                TreeNode semi_root = queue.poll();
                if(semi_root.left != null){
                    queue.offer(semi_root.left);
                    
                    semi_list.add(semi_root.left.val);  // diff
                }
                if(semi_root.right != null){
                    queue.offer(semi_root.right);
                    
                    semi_list.add(semi_root.right.val);  // diff
                }
            }
            if(!semi_list.isEmpty()){  // diff
                result.add(semi_list);
            }
        }
        
        return result;
    }
}

// BFS with beating 64% submission
List result = new ArrayList();

if (root == null) {
    return result;
}

Queue<TreeNode> queue = new LinkedList<TreeNode>();
queue.offer(root);

while (!queue.isEmpty()) {
    ArrayList<Integer> level = new ArrayList<Integer>();
    int size = queue.size();
    for (int i = 0; i < size; i++) {
        TreeNode head = queue.poll();
        level.add(head.val);
        if (head.left != null) {
            queue.offer(head.left);
        }
        if (head.right != null) {
            queue.offer(head.right);
        }
    }
    result.add(level);
}

return result;