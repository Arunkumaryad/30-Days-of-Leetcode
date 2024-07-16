class Solution {
public:
    TreeNode* findlca(TreeNode* root, int source , int destination)
    {
        if(!root)
            return NULL;
        
        if(root->val == source || root->val == destination)
            return root;
        
        auto left =  findlca(root->left,source,destination);
        auto right = findlca(root->right,source,destination);
        
        if(left && right) //if both nodes are found return LCA
            return root;
        
        if(!left && !right )
            return NULL;
        
        return left ? left : right;
    }
    bool dfs(TreeNode*root , int target , string &path)
    {
        if(!root )
            return false;
        //if target is reached return 
        if(root->val == target)
            return true;
        
        path += "L"; // move to left
        if(dfs(root->left, target , path))
            return true; // if path is found no need to traverse anymore
        path.pop_back(); // else backtrack
        
		//similarly for right nodes
        path+="R"; 
        if(dfs(root->right ,target , path))
            return true;
        path.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int source, int destination) {
        
        auto lca = findlca( root , source ,destination); //find the LCA
        //variable to store path
        string path1 = "", path2 = ""; 
        // search for source node
        dfs( lca, source , path1); 
        for(auto &i: path1)
            i = 'U';
        // search for destination node
        dfs(lca, destination, path2); 
        return path1+path2;
    }
};