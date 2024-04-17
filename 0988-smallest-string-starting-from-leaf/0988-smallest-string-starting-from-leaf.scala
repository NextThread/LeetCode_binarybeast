/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {
    var ans = ""
    def smallestFromLeaf(root: TreeNode): String = {
        ans = ""
        getSmallest(root,new StringBuilder()) 
        ans
    }
    
    def getSmallest(root:TreeNode,res:StringBuilder):Unit = {
        if(root == null) {}
        else {
            val current = (root.value+'a').toChar.toString
            res.append(current)
            if(root.left == null && root.right == null){
                val str = res.reverse.toString
                if(ans.isEmpty || str.compareTo(ans) < 0){
                    ans = str
                }
                
            }
            getSmallest(root.left,res)
            getSmallest(root.right,res)
            res.deleteCharAt(res.length-1)
        }
    }
}