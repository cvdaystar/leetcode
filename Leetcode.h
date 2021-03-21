/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>

using namespace std;

namespace Leetcode{

    class TreeNode {
        private:

            static TreeNode* build(int* input, int start, int end){
                auto mid = (start + end)/2;
                TreeNode* parent = new TreeNode(*(input + (start + end)/2));
                parent->left = build(input, start, mid - 1);
                parent->right = build(input, mid + 1, end);
            }

        public:
            int val;
            TreeNode* left = nullptr;
            TreeNode* right = nullptr;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

            static TreeNode* build_tree(int* input, TreeNode* parent, int index, int size){

                if(index < size){

                    parent = new TreeNode(*(input + index));

                    parent->left = build_tree(input, parent->left, 2 * index + 1, size);
                    parent->right = build_tree(input, parent->right, 2 * index + 2, size);         

                }

                return parent;

            }            
    };

    // https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/
    // https://leetcode.com/submissions/detail/470570889/?from=explore&item_id=627
    class Solution1 {
        
    public:

        Solution1(){}

        bool isSymmetric(TreeNode* left_branch, TreeNode* right_branch){

            // both nullptr check
            if(!left_branch && !right_branch)
                return true;
            // nullptr, non-nullptr check            
            if( (left_branch == nullptr && right_branch != nullptr) || (left_branch != nullptr && right_branch == nullptr) )
                return false;

            // node value and next-level children(2) symmetry check
            return left_branch->val == right_branch->val && isSymmetric(left_branch->right, right_branch->left) && isSymmetric(left_branch->left, right_branch->right);
        }

        bool isSymmetric(TreeNode* root) {
            if(!root){
                return true;
            }else{
                return isSymmetric(root->left, root->right);
            }
        }
    };

    // https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/
    // https://leetcode.com/submissions/detail/470599162/?from=explore&item_id=628
    class Solution2 {

    public:

        Solution2(){}

        void buildLevelOrder(TreeNode* parent, int order, std::vector<std::vector<int>>& orders){

            // store parent's order
            if(parent != nullptr){

                auto size = orders.size();

                std::vector<int>* vec = nullptr;

                if (order >= size){
                    std::vector<int> _vec;
                    orders.push_back(_vec);
                }

                vec = &orders[order];

                vec->push_back(parent->val);
                // store childrens' order
                buildLevelOrder(parent->left, order + 1, orders);
                buildLevelOrder(parent->right, order + 1, orders);                
            }
          
        }

        vector<vector<int>> levelOrder(TreeNode* root) {
            std::vector<std::vector<int>> result{};
            buildLevelOrder(root, 0, result);
            return result;
        }      

    };
}