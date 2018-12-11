// File   : BinarySearchTreeNode.h
// Author : Jarrett McCarty


#ifndef BINARYSEARCHTREENODE_H
#define BINARYSEARCHTREENODE_H

#include <iostream>
#include <vector>
#include <assert.h>

class BinarySearchTreeNode
{
public:
    /* Defualt Constructor */
    BinarySearchTreeNode()
        : parent_(NULL), left_(NULL), right_(NULL)
    {}
    /* Constructor */
BinarySearchTreeNode(int key, BinarySearchTreeNode * parent=NULL,
                     BinarySearchTreeNode * left=NULL,
                     BinarySearchTreeNode * right=NULL)
    : key_(key), parent_(parent), left_(left), right_(right)
    {}
    /* Returns key */
    int key() const
    {
        return key_;
    }
    /* Returns reference of a key */
    int & key()
    {
        return key_;
    }
    /* return parent pointer */
    BinarySearchTreeNode * parent() const
    {
        return parent_;
    }
    /* return reference of parent pointer */
    BinarySearchTreeNode * & parent()
    {
        return parent_;
    }
    /* return root pointer */
    BinarySearchTreeNode * root() 
    {
        BinarySearchTreeNode * p = this;
        if (p->is_root())
        {
            return p;
        }
        while (p->parent() != NULL)
        {
            p = p->parent();
        }
        return p;
    }
    /* return pointer to left node of a given root node */
    BinarySearchTreeNode * left() const
    {
        return left_;
    }
    /* return reference of left pointer  */
    BinarySearchTreeNode * & left() 
    {
        return left_;
    }
    
// Returns pointer to the leftmost node of the subtree with this
// node as root.
    BinarySearchTreeNode * leftmost()  
    {
        BinarySearchTreeNode * p = this;
        if (p == NULL) return NULL;
        while (p->left() != NULL)
        {
            p = p->left();
        }
        return p;
    }
    /* same as left */
    BinarySearchTreeNode * right() const
    {
        return right_;
    }
    BinarySearchTreeNode * & right()
    {
        return right_;
    }
    
// Returns pointer to the rightmost node of the subtree with this
// node as root.
    BinarySearchTreeNode * rightmost() 
    {
        BinarySearchTreeNode * p = this;
        if (p == NULL) return NULL;
        while (p->right() != NULL)
        {
            p = p->right();
        }
        return p;
    }
// Returns true if the node is a leaf node, i.e., the left
// and right are both NULL.
    bool is_leaf() const
    {
        return ((this->right_ == NULL && this->left_ == NULL) ? true : false);
    }
// Returns true if the node is not a leaf node
    bool is_nonleaf() const
    {
        return !(is_leaf());
    }
// Returns true if the parent is NULL
    bool is_root()
    {
        if (this->parent_ == NULL)
        {
            return true;
        }
        return false;
    }


private:
    int key_;
    BinarySearchTreeNode * parent_;
    BinarySearchTreeNode * left_;
    BinarySearchTreeNode * right_;
    
};

/* Functions that accept a BSTNode object */
std::ostream & operator<<(std::ostream &,const BinarySearchTreeNode &);
void print_inorder(const BinarySearchTreeNode *);
void print_preorder(const BinarySearchTreeNode *);
void print_postorder(const BinarySearchTreeNode *);
BinarySearchTreeNode * insert(BinarySearchTreeNode * &, int);
BinarySearchTreeNode * remove(BinarySearchTreeNode * , int);
void remove_from_tree(BinarySearchTreeNode * & p);
bool match_tree(const BinarySearchTreeNode *, const BinarySearchTreeNode * ); 
int max(BinarySearchTreeNode *);
int min(BinarySearchTreeNode *);
BinarySearchTreeNode * successor(BinarySearchTreeNode *);
BinarySearchTreeNode * find(BinarySearchTreeNode *, int);
int size(BinarySearchTreeNode *);
int depth_util(BinarySearchTreeNode *, BinarySearchTreeNode *, int);
int height(BinarySearchTreeNode *);
int maxi(int, int);
void clear(BinarySearchTreeNode *);
std::vector<int> inorder(BinarySearchTreeNode *);
std::vector<int> preorder(BinarySearchTreeNode *);
std::vector<int> postorder(BinarySearchTreeNode *);
//BinarySearchTreeNode * select(BinarySearchTreeNode *, int);
void range(BinarySearchTreeNode *, int, int, std::vector<int> &);
std::vector<int> breadthfirst(BinarySearchTreeNode *);
void bfutil(BinarySearchTreeNode *, int, std::vector<int> &);

#endif


