#ifndef BSTREE_H
#define BSTREE_H

#include "account.h"

using namespace std;

class BSTree {
public:

struct Node {
    Account *account;
    Node *right;
    Node *left;
    Node()
    {
      account = nullptr;
      left = nullptr;
      right = nullptr;
    }
};

  // Create BST
  BSTree();

  // Delete all nodes in BST
  ~BSTree(); 

  // Insert new account
  bool insert(Account *account);

  // Retrieve account
  // returns true if successful AND *Account points to account
  bool retrieve(const int &accountNumber, Account *&account) const;

  // Display information on all accounts
  void display() const;

  // delete all information in AccountTree
  void clear();

  // check if tree is empty
  bool isEmpty() const;

  void inOrder(Node* root1) const;

  void postOrderDelete(Node* root2) const;

  vector<string> error;

private:
  Node *root;
};
#endif // BSTREE_H
