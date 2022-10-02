#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

using namespace std;

const int SIZEMAX = 10;

class Account {
public:
  vector<vector<string>> historyTran;
  Account(string firstName, string lastName, int id);
  string getFirstName();
  string getLastName();
  int getID();
  int getFund(int index);
  int fundSize();
  void resizeVector();
  void setID(int id);
  void setFirstName(string firstname);
  void setLastName(string lastname);
  void setFundDeposit(int i, int money);
  void setFundWithDraw(int id, int i, int money);
  void displayFund();

private:
  int id;
  string firstname; // first name
  string lastname;  // last name
  int fund[SIZEMAX];
};

vector<string> transHistory();

#endif // ACCOUNT_H
