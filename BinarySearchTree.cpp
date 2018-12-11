// File   : BinarySearchTree.cpp
// Author : Jarrett McCarty

#include "BinarySearchTree.h"

void print_inorder(const BinarySearchTree & root)
{
    ::print_inorder(root.root());
}
void print_preorder(const BinarySearchTree & root)
{
    ::print_preorder(root.get_root());
}
void print_postorder(const BinarySearchTree & root)
{
    ::print_postorder(root.get_root());
}

