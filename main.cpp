#include <iostream>
#include "Leetcode.h"

using namespace std;
using namespace Leetcode;

int main(){
    
    std::cout << "Hello Leetcode" << std::endl;

    // solution 1
    // https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/
    // Symmetric Tree: given [1,2,2,3,4,4,3]
    int _input1[] = {1, 2, 2, 3, 4, 4, 3};
    int* input = _input1;
    int size = sizeof(_input1)/sizeof(_input1[0]);

    TreeNode* root = nullptr;
    root = TreeNode::build_tree(input, root, 0, size);
    auto answer = (Solution1().isSymmetric(root) == true) ? "true" : "false";
    std::cout << "input is symmetric: " << answer << std::endl;

    // solution 2
    // https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/628/
    // Binary Tree Level Order Traversal: given [3,9,20,null,null,15,7]

    int _input2[] = {3, 9, 20, NULL, NULL, 15, 7};
    input = _input2;
    size = sizeof(_input2)/sizeof(_input2[0]);
    root = TreeNode::build_tree(input, root, 0, size);
    auto result = Solution2().levelOrder(root);

    for(int i = 0; i < result.size() ; i++){
        for(int j = 0; j <result[i].size() ; j++){
            std::cout << "result: i= " << i << ", j= " << j << " : " << result[i][j] << std::endl; 
        }
    }    
}