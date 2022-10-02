#include "bstree.h"
#include <iostream>

using namespace std;

// Create BST
BSTree::BSTree()
{
   root = nullptr;
}

// Delete all nodes in BST
BSTree::~BSTree() 
{
    clear();
}

// Insert new account
bool BSTree::insert(Account *account) 
{ 
  if(isEmpty()){
    root = new Node();
    root->account = account;
    return true;
  }
  if(retrieve(account->getID(), account))
  {
        error.push_back("ERROR: Account " + to_string(account->getID()) + " is already open. Transaction refused.");
        return false; 
  }
  Node* temp = root;
  Node* curr = nullptr;
  while(temp != nullptr)
    {
        curr = temp;
        if(account->getID() < temp->account->getID())
        {
          temp = temp->left;
        }
        else
        {
          temp = temp->right;
        }
   }

   if(account->getID() < curr->account->getID())
   {
     Node* newNode = new Node();
     newNode->account = account;
     curr->left = newNode;
   }
   if(account->getID() > curr->account->getID())
   {
     Node* newNode = new Node();
     newNode->account = account;
     curr->right = newNode;
   }
   return true;
}
// Retrieve account
// returns true if successful AND *Account points to account
bool BSTree::retrieve(const int &accountNumber, Account *&account) const {
    if(isEmpty())
    {
      return false;
    }
    Node* curr = root;
    while(curr != nullptr)
    {
      if(accountNumber == curr->account->getID())
      {
        account = curr->account;
        return true;
      }
      if(accountNumber < curr->account->getID())   
      {
        curr = curr->left;
      }
      else
      {
        curr = curr->right;
      }
    }
    return false;
}

// Display information on all accounts
void BSTree::display() const 
{
  Node* root1 = root;
  cout << "Processing Done. Final Balances." << endl;
  inOrder(root1);
  cout << "Process finished with exit code 0" << endl;
}

// delete all information in AccountTree
void BSTree::clear() {
    postOrderDelete(root);
}

// check if tree is empty
bool BSTree::isEmpty() const {
   return root == nullptr;
}

void BSTree::inOrder(Node* root1) const
{
  if(root1 == nullptr)
  {
    return;
  }
  inOrder(root1->left);
  cout << root1->account->getLastName() << " " << root1->account->getFirstName() << " Account ID: " << root1->account->getID() << endl;
  for(int i = 0; i < root1->account->fundSize(); i++)
  {
    vector<string> v1 = transHistory();
    cout << "\t" << v1[i] << root1->account->getFund(i) << endl; 
  }
  cout << endl;
  inOrder(root1->right);
}

void BSTree::postOrderDelete(Node* root2) const
{
  if(root2 == nullptr)
  {
    return;
  }
  postOrderDelete(root2->left);
  postOrderDelete(root2->right);
  delete(root2);
}
