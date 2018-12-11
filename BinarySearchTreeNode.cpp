// File   : BinarySearchTreeNode.cpp
// Author : Jarrett McCarty


#include "BinarySearchTreeNode.h"

/* Overloaded output operator */
std::ostream & operator<<(std::ostream & cout, const BinarySearchTreeNode & node)
{
    cout << "<Node: " << &node
         << ", key:" << node.key()
         << ", parent:" << node.parent()
         << ", left:" << node.left()
         << ", right:" << node.right() << '>';
    return cout;
}

/* Inorder, preorder, and postorder outputs, dereferencing the node */
void print_inorder(const BinarySearchTreeNode * node)
{
    if (node != NULL)
    {
        print_inorder(node->left());
        std::cout << (*node) << '\n';
        print_inorder(node->right());
    }
}
void print_preorder(const BinarySearchTreeNode * node)
{
    if (node != NULL)
    {
        std::cout << (*node) << '\n';
        print_preorder(node->left());
        print_preorder(node->right());
    }
}
void print_postorder(const BinarySearchTreeNode * node)
{
    if (node != NULL)
    {
        print_postorder(node->left());
        print_postorder(node->right());
        std::cout << (*node) << '\n';
    }
}

/* Insert a node into the tree */
BinarySearchTreeNode * insert(BinarySearchTreeNode * & node, int x)
{
    if (node == NULL) return node = new BinarySearchTreeNode(x);

    if (find(node, x)) return NULL;
    if (x < node->key())
    {
        BinarySearchTreeNode * l = insert(node->left(), x);
        node->left() = l;
 
        l->parent() = node;
    }
    else if (x > node->key())
    {
        BinarySearchTreeNode * r = insert(node->right(), x);
        node->right() = r;
 
        r->parent() = node;
    }
    
    return node;
    
}

/* find successor of given node */
BinarySearchTreeNode * successor(BinarySearchTreeNode * node)
{
    if(node->right() != NULL)
    {
        int x = min(node->right());
        return find(node, x);
    }
    else
    {
        BinarySearchTreeNode * parent = node->parent();
    		
        while(parent != NULL)
        {
            if(parent->key() > node->key())
            {    
                break;
            }
            
            parent = parent->parent();
        }
    	
        return parent;
    }
}

/* remove node from tree */
BinarySearchTreeNode * remove(BinarySearchTreeNode * node, int x)
{
    BinarySearchTreeNode * temp, * succ;

    if(node == NULL)
    {
        return node;
    }
    if(x < node->key())
    {
        node->left() = remove(node->left(), x);
    }
    else if(x > node->key())
    {
        node->right() = remove(node->right(), x);
    }
    else
    {
        if(node->left() != NULL && node->right() != NULL)
        {
            succ = node->right();
            while(succ->left())
            {
                succ = succ->left();
            }
            node->key() = succ->key();
            node->right() = remove(node->right(), succ->key());
        }
        else
        {
            temp = node;
            if(node->left() != NULL)
            {
                node = node->left();
            }
            else if(node->right() != NULL)
            {
                node = node->right();
            }
            else
            {
                node = NULL;
            }
            delete temp;
        }
    }
    return node;
    
}
bool match_tree(const BinarySearchTreeNode *lhs, const BinarySearchTreeNode * rhs)
{
    if(lhs == NULL && rhs == NULL)
    {
        return true;
    }
    if(lhs == NULL || rhs == NULL)
    {
        return false;
    }
    if(lhs->key() != rhs->key())
    {
        return false;
    }
    return (match_tree(lhs->left(), rhs->left()) && 
            match_tree(lhs->right(), rhs->right()));
}

int max(BinarySearchTreeNode * node) 
{
    while (node->right() != NULL)
    {
        node = node->right();
    }
    return node->key();
}

int min(BinarySearchTreeNode * node) 
{
    while (node->left() != NULL)
    {
        node = node->left();
    }
    return node->key();
}
BinarySearchTreeNode * find(BinarySearchTreeNode * ret, int x)
{
    while(ret->key() != x)
    {
        if(ret != NULL)
        {
            if(ret->key() > x)
            {
                ret = ret->left();
            }
            else
            {                
                ret = ret->right();
            }
            if(ret == NULL)
            {
                return NULL;
            }
        }			
    }
    return ret;
}

int size(BinarySearchTreeNode * node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return(size(node->left()) + 1 + size(node->right()));
    }
}

int depth_util(BinarySearchTreeNode * root, BinarySearchTreeNode * data, int level)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->key() == data->key())
    {
        return level;
    }
    int downlevel = depth_util(root->left(), data, level + 1);
    if (downlevel != 0)
    {
        return downlevel;
    }
    downlevel = depth_util(root->right(), data, level + 1);
    return downlevel;
    
}

int height(BinarySearchTreeNode * node)
{
    if(node == NULL) return 0;
    else
    {
        return 1 + maxi(height(node->left()), height(node->right()));
    }
}
int maxi(int x, int y)
{
    if (x >= y) return x;
    else return y;
}
void clear(BinarySearchTreeNode * node)
{
    if(node != NULL)
    {
        clear(node->left());
        clear(node->right());
        delete node;
        node = NULL;
    }
}

std::vector<int> inorder(BinarySearchTreeNode * node)
{
    std::vector<int> r;
    if (node == NULL)
    {
        return r;
    }
    std::vector<int> x;
    if (node->left() != NULL)
    {
        x = inorder(node->left());
        r.insert(r.end(), x.begin(), x.end());
    }
    r.push_back(node->key());
    if (node->right() != NULL)
    {
        x = inorder(node->right());
        r.insert(r.end(), x.begin(), x.end());
    }
    return r;
}
std::vector< int > preorder(BinarySearchTreeNode * node) 
{
    std::vector<int> r;
    if (node == NULL)
    {
        return r;
    }
    std::vector<int> x;
    r.push_back(node->key());
    if (node->left() != NULL)
    {
        x = preorder(node->left());
        r.insert(r.end(), x.begin(), x.end());
    }
    if (node->right() != NULL)
    {
        x = preorder(node->right());
        r.insert(r.end(), x.begin(), x.end());
    }
    return r;
}
std::vector<int> postorder(BinarySearchTreeNode * node) 
{
    std::vector<int> ret;
    if (node == NULL)
    {
        return ret;
    }
    std::vector<int> x;
    if (node->left() != NULL)
    {
        x = postorder(node->left());
        ret.insert(ret.end(), x.begin(), x.end());
    }
    if (node->right() != NULL)
    {
        x = postorder(node->right());
        ret.insert(ret.end(), x.begin(), x.end());
    }
    ret.push_back(node->key());
    
    return ret;
}
std::vector<int> breadthfirst(BinarySearchTreeNode * node)
{
    std::vector<int> x;
    int h = height(node);
    int i;
    for (i = 1; i <= h; i++)
    {
        bfutil(node, i, x);
    }
    return x;
}
void bfutil(BinarySearchTreeNode * node, int i, std::vector<int> & temp)
{
    if (node == NULL)
    {
        return;
    }
    if (i == 1)
    {
        temp.push_back(node->key());
    }
    else if (i > 1)
    {
        bfutil(node->left(), i-1, temp);
        bfutil(node->right(), i-1, temp);
    }
}
// TODO: BROKEN
/*
BinarySearchTreeNode * select(BinarySearchTreeNode * node, int k)
{
    if (node == NULL)
    {
        return NULL;
    }

    BinarySearchTreeNode * temp = select(node->left(), k);
    std::cout << temp << '\n';
    if (temp != NULL && k == 0)
    {
        return temp;
    }
    k -= 1;
    return select(node->right(), k);
}
*/
void range(BinarySearchTreeNode * node, int m, int M, std::vector<int> & ret)
{
    if (!node) return;
    if(m > M) return;

    range(node->left(), m, M, ret);
    range(node->right(), m, M, ret);

    if(node->key() >= m && node->key() <= M)
    {
        ret.push_back(node->key());
    }
    
}

