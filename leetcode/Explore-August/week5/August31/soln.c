/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node_t;

node_t* inorder_succ(node_t* node)
{
    node_t* succ = NULL;
    node_t* parent = node;
    if(node -> right)
    {
        succ = node -> right;
    }
    while(succ -> left)
    {
        parent = succ;
        succ = succ -> left;
    }
    if(succ && succ -> val < parent -> val)
    {
        parent -> left = succ -> right;
    }
    else if (succ && succ -> val > parent -> val)
    {
        parent -> right = succ -> right;
    }
    return succ;
}


struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(!root)
    {
        return root;
    }
    
    if(root -> val == key)
    {
        node_t* temp = root;
        if(!root -> right)
        {
            root = root -> left;
            free(temp);
            return root;
        }
    }
    
    node_t* node = root;
    node_t* parent = NULL;
    while(node && node -> val != key)
    {
        parent = node;
        if(key < node -> val)
        {
            node = node -> left;
        }
    
        else
        {
            node = node -> right;
        }
    }
    if(node == NULL)
    {
        return root;
    }
    
    if(node -> right == NULL && parent)
    {
        if(node -> val < parent -> val)
        {
            parent -> left = node -> left;
        }
        else
        {
            parent -> right = node -> left;
        }
        return root;
    }
    node_t* succ = inorder_succ(node);
    node -> val = succ -> val;
    free(succ);
    return root;
}
