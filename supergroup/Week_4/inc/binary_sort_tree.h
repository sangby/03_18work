//
// Created by eke_l on 2021/4/21.
//

#include <cstddef>
#include<bits/stdc++.h>
using namespace std;
#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root = NULL;
} BinarySortTree, *BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr, ElemType);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(BinarySortTreePtr, ElemType);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(BinarySortTreePtr, ElemType);

/**
 * BST preorder traversal without recursion
 * @param Node* BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(Node*, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param Node* BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(Node*, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion
 * @param Node* BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(Node*, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param Node* BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(Node*, void (*visit)(NodePtr));

/**
 * BST postorder traversal without recursion
 * @param Node* BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(Node*, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param Node* BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(Node*, void (*visit)(NodePtr));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(BinarySortTreePtr, void (*visit)(NodePtr));


/**
 * @description: 查找某值是否存在,若存在返回其父结点指针
 * @return {*}
 */
Node* BST_search_return_parent_node(BinarySortTreePtr, ElemType);
//堆
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
