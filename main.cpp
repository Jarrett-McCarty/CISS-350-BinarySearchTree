// File   : main.cpp
// Author : Jarrett McCarty

#include <iostream>
#include "BinarySearchTree.h"

int main()
{
   
    std::cout << "Testing for BST/BSTNode Classes...\n";
    std::cout << "Creating BSTNode 'n' w/ root = '5'...\n";
    BinarySearchTreeNode * n = new BinarySearchTreeNode(5);
    std::cout << "Testing 'inorder print' for 'n' ... \n";
    print_inorder(n);
    std::cout << "\n\n";
    std::cout << "Inserting '3' into 'n' ...\n";
    insert(n, 3);
    print_inorder(n);
    std::cout << "\n\n";
    std::cout << "Inserting '0' into 'n' ...\n";
    insert(n, 0);
    print_inorder(n);
    std::cout << "\n\n";
    std::cout << "Inserting '1' into 'n' ...\n";
    insert(n, 1);
    print_inorder(n);
    std::cout << "\n\n";
    std::cout << "Inserting '4' into 'n' ...\n";
    insert(n, 4);
    print_inorder(n);
    std::cout << "\n\n";
    std::cout << "Inserting '8' into 'n' ...\n";
    insert(n, 8);
    print_inorder(n);
    std::cout << "\nleftmost key of 'n': " << n->leftmost()->key() << '\n';
    std::cout << "rightmost key of 'n': " << n->rightmost()->key() << '\n';

    std::cout << "\nTesting new BSTNode 'n1' w/ root = '10' ... \n";
    BinarySearchTreeNode * n1 = new BinarySearchTreeNode(10);
    std::cout << "Testing preorder print ... \n";
    print_preorder(n1);
    std::cout << "\n\n";
    std::cout << "Inserting '3' into 'n1' ...\n";
    insert(n1, 3);
    print_preorder(n1);
    std::cout << "\n\n";
    std::cout << "Inserting '0' into 'n1' ...\n";
    insert(n1, 0);
    print_preorder(n1);
    std::cout << "\n\n";
    std::cout << "Inserting '1' into 'n1' ...\n"; 
    insert(n1, 1);
    print_preorder(n1);
    std::cout << "\n\n";
    std::cout << "Inserting '4' into 'n1' ...\n";
    insert(n1, 4);
    print_preorder(n1);
    std::cout << "\n\n";
    std::cout << "Inserting '8' into 'n1' ...\n";
    insert(n1, 8);
    print_preorder(n1);
    std::cout << "\nleftmost key of 'n1': " << n1->leftmost()->key() << '\n';
    std::cout << "rightmost key of 'n1': " << n1->rightmost()->key() << '\n';

    
    std::cout << "\nTesting BST 'bst' ... \n\n";
    BinarySearchTree bst;
    std::cout << "Testing with inorder print ... \n";
    std::cout << "Insertion order: 5, 0, 2, -2, 10, 8, 9, 7\n";
    print_inorder(bst); std::cout << '\n';
    bst.insert(5); print_inorder(bst); std::cout << '\n';
    bst.insert(0); print_inorder(bst); std::cout << '\n';
    bst.insert(2); print_inorder(bst); std::cout << '\n';
    bst.insert(-2); print_inorder(bst); std::cout << '\n';
    bst.insert(10); print_inorder(bst); std::cout << '\n';
    bst.insert(8); print_inorder(bst); std::cout << '\n';
    bst.insert(9); print_inorder(bst); std::cout << '\n';
    bst.insert(7); print_inorder(bst); std::cout << '\n';

    std::cout << "\nTesting new BST 'bst1' ... \n";
    BinarySearchTree bst1;
    std::cout << "Testing with preorder print ... \n";
    std::cout << "Insertion order: 5, 0, 2, -2, 10, 8, 9, 7\n";
    print_preorder(bst1); std::cout << '\n';
    bst1.insert(5); print_preorder(bst1); std::cout << '\n';
    bst1.insert(0); print_preorder(bst1); std::cout << '\n';
    bst1.insert(2); print_preorder(bst1); std::cout << '\n';
    bst1.insert(-2); print_preorder(bst1); std::cout << '\n';
    bst1.insert(10); print_preorder(bst1); std::cout << '\n';
    bst1.insert(8); print_preorder(bst1); std::cout << '\n';
    bst1.insert(9); print_preorder(bst1); std::cout << '\n';
    bst1.insert(7); print_preorder(bst1); std::cout << '\n';


    std::cout << "Attempting a try/catch block for duplicate insertion\n";
    try
    {
        std::cout << "Inserting '7' into 'bst' ... \n";
        bst.insert(7);
    }
    catch (ValueError & e)
    {
        std::cout << e.what();
        std::cout << "pass" << std::endl; // For assignment
    }
    std::cout << "Attempting a try/catch block for removing a value in a BST\n";
    try
    {
        std::cout << "Removing '2' from 'bst1' ... \n";
        bst1.remove(2);
    }
    catch (ValueError & e)
    {
        std::cout << e.what();
    }
    
    std::cout << "Testing inorder print for 'bst1' ... \n";
    print_inorder(bst1); std::cout << '\n';

    std::cout << "Creating new BST 'x' ... \n";
    BinarySearchTree x;

    std::cout << "Assigning 'bst1' to 'x' ... \n";
    x = bst1;

    std::cout << "Testing post-order print for 'x' ... \n";
    print_postorder(x); std::cout <<  '\n';

    std::cout << "Testing if BSTs 'x' and 'bst1' are equal ... \n";
    std::cout << (x == bst1) << '\n';
    std::cout << "Testing if BSTs 'x' and 'bst'  are equal ... \n";
    std::cout << (x == bst) << '\n';

    std::cout << "'bst1' height: " << bst1.height() << '\n';
    //std::cout << "'bst1' select(3): " << bst1.select(3) << '\n';
    std::cout << "'bst1' find(-2): " << bst1.find(-2) << '\n';
    std::cout << "'x' size: " << x.size() << '\n';
    
    std::cout << "Creating array to insert into BST 'ex' ... \n";
    int arr[] = {2, 3, 100, 5, 1};
    BinarySearchTree ex(arr, 5);

    std::cout << "Print inorder 'ex' after assigning array to it ... \n";
    print_inorder(ex); std::cout << '\n';

    std::cout << "Creating new BST 'z' ... \n";
    BinarySearchTree z(ex);
    std::cout << "New BST 'z' with 'ex' assigned in it's copy constructor ... \n";
    print_inorder(z);

    std::cout << "Max key in BST 'z' ... \n";
    std::cout << z.max() << '\n';
    std::cout << "Min key in BST 'z'... \n";
    std::cout << z.min() << '\n';

    std::cout << "Creating vector of 'bst1' values using inorder traveral ... \n";
    std::vector<int> test = bst1.inorder();
    std::cout << "[";
    for (int i = 0; i < test.size(); ++i)
    {
        std::cout << test[i];
        if (i + 1 == test.size()) break;
        std::cout << ", ";
    }
    std::cout << "]\n";


    std::cout << "Creating vector of 'bst1' values using preorder traveral ... \n";
    std::vector<int> test1 = bst1.preorder();
    std::cout << "[";
    for (int i = 0; i < test1.size(); ++i)
    {
        std::cout << test1[i];
        if (i + 1 == test1.size()) break;
        std::cout << ", ";
    }
    std::cout << "]\n";


    std::cout << "Creating vector of 'bst1' values using post-order traveral ... \n";
    std::vector<int> test2 = bst1.postorder();
    std::cout << "[";
    for (int i = 0; i < test2.size(); ++i)
    {
        std::cout << test2[i];
        if (i + 1 == test2.size()) break;
        std::cout << ", ";
    }
    std::cout << "]\n";

    std::cout << "Creating vector of 'bst1' values using breadthfirst traveral ... \n";
    std::vector<int> test3 = bst1.breadthfirst();
    std::cout << "[";
    for (int i = 0; i < test3.size(); ++i)
    {
        std::cout << test3[i];
        if (i + 1 == test3.size()) break;
        std::cout << ", ";
    }
    std::cout << "]\n";

    std::cout << "Creating a range vector from 'bst1' (range: 0-6(values)) ... \n";
    std::vector<int> ran = bst1.range(0, 6);
    std::cout << "[";
    for (int i = 0; i < ran.size(); ++i)
    {
        std::cout << ran[i];
        if (i + 1 == ran.size()) break;
        std::cout << ", ";
    }
    std::cout << "]\n";

    std::cout << "Clearing all created BST(s) 'bst', 'bst1', 'x', 'ex' ... \n";
    bst.clear();
    bst1.clear();
    ex.clear();
    x.clear();

    return 0;
}
