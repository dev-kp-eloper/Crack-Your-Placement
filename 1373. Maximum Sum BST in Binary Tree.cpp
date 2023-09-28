//Link - https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

class NodeValue{
public:
  int minValue;
  int maxValue;
  int maxSum;

NodeValue(int minValue,int maxValue,int maxSum) {
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->maxSum = maxSum;
  }

};

class Solution {

    int maxS = 0;

    NodeValue maxSum(TreeNode* root) {

    if (!root) return NodeValue(INT_MAX,INT_MIN,0);

    auto left = maxSum(root->left);
    auto right = maxSum(root->right);

    if (left.maxValue < root->val && root->val < right.minValue) {

        int sum = left.maxSum + right.maxSum + root->val;
        maxS = max(maxS, sum);

        return NodeValue(min(root->val, left.minValue),
                        max(root->val, right.maxValue), sum);
    }

    return NodeValue(INT_MIN,INT_MAX,max(left.maxSum,right.maxSum));

}

public:
    int maxSumBST(TreeNode* root) {
        maxSum(root);
        return maxS > 0 ? maxS : 0;
    }
};
