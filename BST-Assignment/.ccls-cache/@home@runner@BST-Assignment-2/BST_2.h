//***********************************************************************************
// CSCI 3333.03	Spring 2023
// Instructor: Dr. Andres Figueroa
// Programming Assignment 2: Movies Dataset using BST
// Students Name and SID#: Aaron Ratliff, 20557105
//
//***********************************************************************************

#include <string>
#include <vector>
using namespace std;

struct Node {
  // data fields
  string titleID;
  string movieTitle;
  string region;

  struct Node *left;  // left child
  struct Node *right; // right child
};

class BinarySearchTree {
private:
  int numberNodes; // number of nodes in the tree
  Node *root;      // root of the tree
  Node *newNode(string id, string title, string region) {
    Node *tempNode = new Node;
    tempNode->titleID = id;
    tempNode->movieTitle = title;
    tempNode->region = region;
    tempNode->left = NULL;
    tempNode->right = NULL;
    return tempNode;
  }

public:
  BinarySearchTree();
  void insert(string id, string title, string region, Node *rootNode);
  void inOrder(Node *rootNode);
  Node *search(string title, Node *rootNode);
  int size();
};

BinarySearchTree::BinarySearchTree() {
  numberNodes = 0;
  root = NULL;
}

void BinarySearchTree::insert(string id, string title, string region,
Node *currentNode = NULL) {
  if (currentNode == NULL) {
    currentNode = (*this).root;
  }
  // COMPLETE THIS FUNCITON WITH YOUR CODE HERE
  if(root == NULL) {
      root = newNode(id, title, region);
      numberNodes++;
      return;
  }
  if (title < currentNode->movieTitle) {

    if (currentNode->left == NULL) {
      currentNode->left = newNode(id, title, region);
      numberNodes++;
      cout << "DONE";
      return;
    }
    else {
      insert(id, title, region, currentNode->left);
    }
  }
  // }

  // else if (title > currentNode->movieTitle) {

  //   if (currentNode->right == NULL) {
  //     currentNode->right = newNode(id, title, region);
  //     numberNodes++;
  //     return;
  //   }

  //   else {
  //     insert(id, title, region, currentNode->right);
  //   }
  // }

  // else {
  //   if (id < currentNode->titleID) {
  //     if (currentNode->left == NULL) {
  //       currentNode->left = newNode(id, title, region);
  //       numberNodes++;
  //       return;
  //     }

  //     else {
  //       insert(id, title, region, currentNode->left);
  //     }
  //   }

  //   else if (id > currentNode->titleID) {

  //     if (currentNode->right == NULL) {
  //       currentNode->right = newNode(id, title, region);
  //       numberNodes++;
  //       return;
  //     }

  //     else {
  //       insert(id, title, region, currentNode->right);
  //     }
  //   }

  //   else {
  //     if (region < currentNode->region) {

  //       if (currentNode->left == NULL) {
  //         currentNode->left = newNode(id, title, region);
  //         numberNodes++;
  //         return;
  //       }

  //       else {
  //         insert(id, title, region, currentNode->left);
  //       }
  //     }

  //     else if (region > currentNode->region) {
  //       if (currentNode->right == NULL) {
  //         currentNode->right = newNode(id, title, region);
  //         numberNodes++;
  //         return;
  //       } else {
  //         insert(id, title, region, currentNode->right);
  //       }
  //     }
     //}
}

void BinarySearchTree::inOrder(Node *currentNode = NULL) {
  if (currentNode == NULL) {
    currentNode = (*this).root;
  }
  // COMPLETE THIS FUNCITON WITH YOUR CODE HERE

  inOrder(currentNode->left);
  // cout << currentNode -> movieTitle << endl;
  inOrder(currentNode->right);
}

Node *BinarySearchTree::search(string title, Node *currentNode = NULL) {
  if (currentNode == NULL) {
    currentNode = (*this).root;
  }
  if (title.compare(currentNode->movieTitle) == 0) {
    return currentNode;
  } else if (title.compare(currentNode->movieTitle) > 0) {
    if (currentNode->right != NULL)
      return search(title, currentNode->right);
    else {
      return NULL;
    }

  } else {
    if (currentNode->left != NULL)
      return search(title, currentNode->left);
    else {
      return NULL;
    }
  }
}

int BinarySearchTree::size() { return numberNodes; }