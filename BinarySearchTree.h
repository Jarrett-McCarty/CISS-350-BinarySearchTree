// File   : BinarySearchTree.h
// Author : Jarrett McCarty

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <vector>
#include "BinarySearchTreeNode.h"

class ValueError
{
public:
    const char * what () const throw()
    {
        return "ValueError\n";
    }
};

class BinarySearchTree
{
public:
BinarySearchTree()
    : root_(NULL)
    {}
    BinarySearchTree(int x[], int size)
    {
        root_ = NULL;
        for(int i = 0; i < size; ++i)
        {
            insert(x[i]);
        }
    }
    BinarySearchTree(const BinarySearchTree & bst)
    {
        root_ = NULL;
        copy(bst.root_);
    }
    ~BinarySearchTree()
    {
        clear();
    }
    void copy(BinarySearchTreeNode * p)
    {
        insert(p->key());
        
        if(p->left() != NULL)
        {
            copy(p->left());
        }
        if (p->right() != NULL)
        {
            copy(p->right());
        }
    }
    BinarySearchTreeNode * root() const
    {
        return root_;
    }
    BinarySearchTree & operator=(const BinarySearchTree & bst)
        {
            if(this != &bst)
            {
                clear();
                BinarySearchTreeNode * c = bst.root_;
                copy(c);
            }
            return *this;
        }
    BinarySearchTreeNode * get_root() const
    {
        return root_;
    }
    void clear()
    {
        ::clear(root_);
    }
// Returns true if the tree is empty
    bool is_empty() const
    {
        return (root_ == NULL);
    }
// Returns the height of the tree. Note that the height of an
// empty tree is -1.
    int height() const
    {
        if (is_empty()) return -1;
        else
        {
            return ::height(root_);
        } 
    }
// Returns the depth of the node pointer p parameter. This is the number
// of edges from the root to the node that p points to.
    int depth(BinarySearchTreeNode * p)
    {
        return ::depth_util(root_, p, 1);
    }
    
// Returns the number of nodes in this tree.
    int size() const
    {
        return ::size(root_);
    }
// Returns a pointer to the node containing x. If x is not in the tree,
// NULL is returned.
    BinarySearchTreeNode * find(int x)
    {
        BinarySearchTreeNode * ret = root_;
        return ::find(ret, x);
    }
// Returns the minimum value in the tree. If the tree is empty,
// a ValueError exception object is thrown.
    int min() const
    {
        if (is_empty()) throw ValueError();
        return ::min(root_);
    }
// Returns the maximum value in the tree. If the tree is empty,
// a ValueError exception object is thrown.
    int max() const
    {
        if (is_empty()) throw ValueError();
        return ::max(root_);
    }
// Returns true if *this and t are the same trees, i.e., the
// values and structure of *this and t are the same.
    bool operator ==(const BinarySearchTree & t)
    {
        return ::match_tree(root_, t.get_root());
    }
// Inserts x into the tree. If x is already in the tree, a ValueError
// exception object is thrown.
    void insert(int x)
    {
        bool success = false;
        if (::insert(root_, x) != NULL)
        {
            success = true;
        }
        if (!success) throw ValueError();
    }
// Remove x from the tree. If x is not in the tree, a ValueError
// exception object is thrown.
    void remove(int x)
    {
        bool success = false;
        if (::remove(root_, x) != NULL)
        {
            success = true;
        }
        if (!success) throw ValueError();
    }
// Returns a vector of integers built by traversing the tree
// using inorder traversal
    std::vector< int > inorder() const
    {
        return ::inorder(root_);
    }
// Returns a vector of integers built by traversing the tree
// using preorder traversal
    std::vector< int > preorder() const
    {
        return ::preorder(root_);
    }
// Returns a vector of integers built by traversing the tree
// using postorder traversal
    std::vector< int > postorder() const
    {
        return ::postorder(root_);
    }
// Returns a vector of integers built by traversing the tree    
// using breadth first traversal
    std::vector< int > breadthfirst() const
    {
        return ::breadthfirst(root_);
    }
// Return pointer to k-th ordered node
// [HINT: Use a traversal]
// TODO: BROKEN
/*
    BinarySearchTreeNode * select(int k)
    {
        return
    }
*/
// Return vector of integers in tree with key values <= m and < M.
    std::vector< int > range(int m, int M)
    {
        std::vector< int > ret;
        ::range(root_, m, M, ret);
        return ret;
    }


private:
BinarySearchTreeNode * root_;
};



void print_inorder(const BinarySearchTree & bst);
void print_preorder(const BinarySearchTree & bst);
void print_postorder(const BinarySearchTree & bst);



#endif

