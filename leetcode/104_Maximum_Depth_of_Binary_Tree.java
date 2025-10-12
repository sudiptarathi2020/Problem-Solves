public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution {
    public int maxDepth(TreeNode root) {
        if(root==null)return 0;
        else {
            return Depth(root,1);
        }
    }
    public int Depth(TreeNode root,int curr){
        if(root.left == null && root.right == null){
            return curr;
        }else if(root.left == null && root.right != null){
            return Depth(root.right, curr+1);
        }else if(root.left != null && root.right == null){
            return Depth(root.left, curr+1);
        }else{
            return Math.max(Depth(root.left,curr+1), Depth(root.right, curr+1));
        }

    }
}
