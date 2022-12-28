class Solution {
  public:
    // Function to find largest subtree sum.
    int ans=INT_MIN;
    
    int f(Node* root){
        if(root==NULL) return  0;
        
        int left=f(root->left);
        int right=f(root->right);
        ans=max(ans,left+right+root->data);
        
        return left+right+root->data;
    }
    int findLargestSubtreeSum(Node* root){
        //Write your code here
        int a=f(root);
        return ans;
    }
};
