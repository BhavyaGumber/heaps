class Solution {
  public:
  bool isCBT(struct Node*root, int i,int nodeCount){
      if(root==NULL)return true;
      if(i>=nodeCount)return false;
      else{
         bool left=isCBT(root->left,2*i+1, nodeCount);
         bool right = isCBT(root->right, 2*i+2,nodeCount);
          return (left && right);
      }
      
  }
 bool isMaxOrder(struct Node *root){
      if(root->left==NULL && root->right==NULL)return true;
      if(root->right==NULL){
          return (root->data > root->left->data);
      }
      else{
          
          return (root->data > root->left->data && root->data>root->right->data) && isMaxOrder(root->left) && isMaxOrder(root->right);
      }
  }
  int countNode(struct Node*root){
      if(root==NULL){
          return 0;
          
      }
      int ans = 1+ countNode(root->left)+countNode(root->right);
      return ans;
  }
    bool isHeap(struct Node* tree) {
        // code here
        int i=0;
        int totalCount = countNode(tree);
        if(isCBT(tree, i,totalCount) && isMaxOrder(tree)){
            return true;
        }
        return false;
    }
};
