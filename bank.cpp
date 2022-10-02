#include "bank.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// TODO(student)

void Bank::processTransactionFile(const std::string &fileName) {
    ifstream inFile;
    inFile.open(fileName);
    string infor;
    while(getline(inFile, infor)){
        storeinformation.push(infor);
        std::stringstream ss(storeinformation.front());
        storeinformation.pop();
        char charSwitch;
        ss >> charSwitch;
        switch(charSwitch)
        {
            case 'O': 
            {
                string first;
                string last;
                int id;
                ss >> last >> first >> id;  
                Account* newAccount = new Account(first, last, id);
                accounts.insert(newAccount);
            }
            break;
            case 'W':
            {
                 int idTemp, id, index, money;
                 ss >> idTemp >> money;
                 id = idTemp / 10;
                 index = idTemp % 10;
                 Withdraw(id, index, money);
            }
                break;
            case 'D':
            {
                 int idTemp, id, index, money;
                 ss >> idTemp >> money;
                 id = idTemp / 10;
                 index = idTemp % 10;
                 Deposit(id, index, money);
            }
                break;
            case 'T':
            {
                int id1, id2, money, index1, index2;
                ss >> id1 >> money >> id2;
                index1 = id1 % 10;
                index2 = id2 % 10;
                id1 = id1 / 10;
                id2 = id2 / 10;
                Transfer(id1,id2,index1,money,index2);
            }
                break;
            case 'H':
            {  
                 int id;
                 ss >> id;
                 History(id);
            }
                break;
            default:
            accounts.error.emplace_back("ERROR: error input tested when enter invalid case "); 
        }    
    }
    for(const auto & accountCopy : accounts.error)
    { 
        cout << accountCopy << endl;
    }
    cout << endl;
    accounts.display();  
    inFile.close();
}

void Bank::Deposit(int id, int lastdigit, int money) 
{    
    Account* newAccount = nullptr;
    if(accounts.retrieve(id, newAccount))
    {
        newAccount->setFundDeposit(lastdigit, money);
        newAccount->resizeVector();
        string tempString;
        tempString = "D " + to_string(id) + to_string(lastdigit) + " " + to_string(money);
        newAccount->historyTran[lastdigit].push_back(tempString);
    }
    else 
    {
        accounts.error.push_back("ERROR: Could not find Account " + to_string(id) + " Deposit cancelled.");
    }
}

void Bank::Withdraw(int id, int lastdigit, int money) 
{
    Account* newAccount = nullptr;
    if(accounts.retrieve(id, newAccount))
    {
        newAccount->setFundWithDraw(id, lastdigit, money);
    }
    else 
    {
        accounts.error.push_back("ERROR: Could not find Account " + to_string(id) + " Withdraw cancelled.");
    }
}

void Bank::History(int index)
{
    Account* newAccount = nullptr;
    if(accounts.retrieve(index, newAccount))
    {
        newAccount->displayFund();
    }
}
void Bank::Transfer(int id1, int id2, int lastdigit1, int money, int lastdigit2)
{
    Account* newAccount1 = nullptr;
    Account* newAccount2 = nullptr;
    if(accounts.retrieve(id1, newAccount1) && accounts.retrieve(id2, newAccount2))
    {
        newAccount1->setFundWithDraw(id1, lastdigit1, money);
        newAccount1->historyTran[lastdigit1].pop_back();

        newAccount2->setFundDeposit(lastdigit2, money);
        string tempString;
        tempString = "D " + to_string(id2) + to_string(lastdigit2) + " " + to_string(money);
        newAccount2->historyTran[lastdigit2].push_back(tempString);

        string tempString1;
        tempString1 = "T " + to_string(id1) + to_string(lastdigit1) + " " + to_string(money) + " " + to_string(id2) + to_string(lastdigit2);
        newAccount1->historyTran[lastdigit1].push_back(tempString1); 
    }
    else if(!accounts.retrieve(id1, newAccount1))
    {
        accounts.error.push_back("ERROR: Could not find Account " + to_string(id1) + " Transfer cancelled.");
    }
    else 
    {
        accounts.error.push_back("ERROR: Could not find Account " + to_string(id2) + " Transfer cancelled.");
    }
}



