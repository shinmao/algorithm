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


public class Solution {
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    public String serialize(TreeNode root) {
        List<TreeNode> list = new ArrayList<>();
        String serial = "";
        
        if(root == null){
            return "{}";
        }
        
        list.add(root);
        // there would be some null before the end of BFS, e.g. 1, 2, null, 3
        for(int i = 0; i < list.size(); i++){
            TreeNode node = list.get(i);
            if(node == null){
                continue;
            }
            list.add(node.left);
            list.add(node.right);
        }
        
        // remove null at the tail
        while(list.get( list.size() - 1 ) == null){
            list.remove( list.size() - 1 );
        }
        
        // concatenate all the elements
        serial += "{";
        serial += list.get(0).val;
        for(int i = 1; i < list.size(); i++){
            serial += ",";
            if(list.get(i) == null){
                serial += "#";   // I have removed all the null at the tail, don't worry
            }else{
                serial += list.get(i).val;
            }
        }
        serial += "}";
        
        return serial.toString();
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    public TreeNode deserialize(String data) {
        
        if(data.length() == 2){
            return null;
        }
        String input = data.substring(1, data.length() - 1);
        String[] element = input.split(",");
        List<TreeNode> list = new ArrayList<>();
        TreeNode root = new TreeNode( Integer.valueOf(element[0]) );
        
        list.add(root);
        int visited = 0;  // this would be the index of root
        boolean left = true;
        for(int i = 1; i < element.length; i++){
            if( i % 2 == 1 ){
                left = true;
            }else{
                left = false;
            }
            
            if(!element[i].equals("#")){    // use equals instead of ==
                TreeNode node = new TreeNode( Integer.valueOf(element[i]) );
                if(left){
                    list.get(visited).left = node;
                }else{
                    list.get(visited).right = node;
                }
                list.add(node);   // don't forget, otherwise, list.get(visited) above would be wrong
            }
            if(!left){
                visited += 1;
            }
        }
        return root;
    }
}