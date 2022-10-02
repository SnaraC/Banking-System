#ifndef BANK_H
#define BANK_H

#include "bstree.h"

#include <queue>
#include <string>

using namespace std;

class Bank {
public:
  void processTransactionFile(const std::string &fileName);
  // //Implements functions here
   void Deposit(int id, int lastdigit, int money);
   void Withdraw(int id, int lastdigit, int money);
   void History(int index);
   void Transfer(int id1, int id2, int lastdigit1, int money, int lastdigit2);

private:
  BSTree accounts;
  queue<string> storeinformation;
};

#endif // BANK_H
