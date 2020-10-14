// c++14
#include <iostream>
#include <memory>

struct TreeNode
{
    explicit TreeNode(int value): value(value)
    {
    }

    std::unique_ptr< TreeNode > leftBranch{nullptr};
    std::unique_ptr< TreeNode > rightBranch{nullptr};
    int value{0};
};

/**
 * @brief Find a tree inside another
 * 
 * @param subtree 
 * @param tree 
 * @return true if it is
 */
bool isSubtree(const std::unique_ptr< TreeNode > &subtree, const std::unique_ptr< TreeNode > &tree)
{
    // Found subtree
    if (subtree == nullptr) return true;

    // Reached end of tree without finding the subtree
    else if (tree == nullptr) return false;

    bool yesItIs = false;
    bool leftIs = false;
    bool rightIs = false;

    bool sameValue = ( tree->value == subtree->value );
    if (sameValue)
    {
        // Go deeper in the subtree
        leftIs = isSubtree(subtree->leftBranch, tree->leftBranch);
        rightIs = isSubtree(subtree->rightBranch, tree->rightBranch);
    }
    else
    {
        // Keep the subtree in the root
        leftIs = isSubtree(subtree, tree->leftBranch);
        rightIs = isSubtree(subtree, tree->rightBranch);
    }

    if (leftIs || rightIs)
    {
        yesItIs = true;
    }        

    return yesItIs;
}

/**
 * @brief Recursive tree traversal
 * 
 * @param tree 
 */
void traverse(const std::unique_ptr< TreeNode > &tree)
{
    // its parent was a leave
    if (tree == nullptr) return;

    traverse(tree->leftBranch);
    std::cout<<tree->value<<" ";
    traverse(tree->rightBranch);
}

int main(int argc, char *argv[])
{
    auto tree1 = std::make_unique< TreeNode >(0);
    tree1->leftBranch = std::make_unique< TreeNode >(1);
    tree1->rightBranch = std::make_unique< TreeNode >(2);
    tree1->leftBranch->leftBranch = std::make_unique< TreeNode >(3);
    tree1->leftBranch->rightBranch = std::make_unique< TreeNode >(4);
    tree1->rightBranch->leftBranch = std::make_unique< TreeNode >(5);
    std::cout<<"tree1=";
    traverse(tree1);
    std::cout<<std::endl;

    auto tree2 = std::make_unique< TreeNode >(1);
    tree2->leftBranch = std::make_unique< TreeNode >(3);
    tree2->rightBranch = std::make_unique< TreeNode >(4);
    std::cout<<"tree2=";
    traverse(tree2);
    std::cout<<std::endl;

    auto tree3 = std::make_unique< TreeNode >(2);
    tree3->leftBranch = std::make_unique< TreeNode >(5);
    std::cout<<"tree3=";
    traverse(tree3);
    std::cout<<std::endl;

    auto tree4 = std::make_unique< TreeNode >(2);
    tree4->leftBranch = std::make_unique< TreeNode >(3);
    tree4->rightBranch = std::make_unique< TreeNode >(4);
    std::cout<<"tree4=";
    traverse(tree4);

    std::cout<<std::endl;
    bool yes = isSubtree(tree2, tree1);
    if (yes)
    {
        std::cout<<"tree2 is a subtree of tree1"<<std::endl;
    }

    yes = isSubtree(tree3, tree1);
    if (yes)
    {
        std::cout<<"tree3 is a subtree of tree1"<<std::endl;
    }

    yes = isSubtree(tree4, tree1);
    if (!yes)
    {
        std::cout<<"tree4 is not a subtree of tree1"<<std::endl;
    }

    return EXIT_SUCCESS;
}

//     0
//    / \
//   1   2
//  / \ /
//  3 4 5

//    1
//   / \
//   3 4

//    2
//   /
//  5

//   2
//  / \
// 3   4
