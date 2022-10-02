#include "account.h"
#include <iostream>

using namespace std;

Account::Account(string firstName, string lastName, int id)
{
    setID(id);
    setFirstName(firstName);
    setLastName(lastName);
    for(int & f : fund)
    {
        f = 0;
    }
}

int Account::getID()
{
    return id; 
}
void Account::setID(int id)
{
    this->id = id;
}
string Account::getFirstName()
{
    return firstname;
}
void Account::setFirstName(string firstname)
{
    this->firstname = firstname;
}
string Account::getLastName()
{
    return lastname;
}
void Account::setLastName(string lastname)
{
    this->lastname = lastname;
}

void Account::setFundDeposit(int i, int money)
{
    (fund[i] += money);
}

void Account::setFundWithDraw(int id, int i, int money)
{
    if(money <= fund[i]){
        (fund[i] = fund[i] - money);
        string tempString;
        tempString = "W " + to_string(id) + to_string(i) + " " + to_string(money);
        historyTran[i].push_back(tempString);
    }
    else 
    {
        string tempString;
        tempString = "W " + to_string(id) + to_string(i) + " " + to_string(money) + " (FAILED)";
        historyTran[i].push_back(tempString);
    }
}

void Account::displayFund()
{
    cout << "Display Transaction History for " << getLastName() << " " << getFirstName() << " by fund." << endl;
    vector<string> v1 = transHistory();
    for(int i = 0; i < fundSize(); i++){
        cout << v1[i] << getFund(i) << endl; 
        for(auto& history : historyTran[i]){
            cout << "\t" << history << endl;
        }
    }
}

int Account::fundSize()
{
    return SIZEMAX;
}

int Account::getFund(int index)
{
    return fund[index];
}

vector<string> transHistory() {
    vector<string> transHistory;
    transHistory.emplace_back("Money Market: $");
    transHistory.emplace_back("Prime Money Market: $");
    transHistory.emplace_back("Long-Term Bond: $");
    transHistory.emplace_back("Short-Term Bond: $");
    transHistory.emplace_back("500 Index Fund: $");
    transHistory.emplace_back("Capital Value Fund: $");
    transHistory.emplace_back("Growth Equity Fund: $");
    transHistory.emplace_back("Growth Index Fund: $");
    transHistory.emplace_back("Value Fund: $");
    transHistory.emplace_back("Value Stock Index: $");
    return transHistory;
}

void Account::resizeVector()
{
   historyTran.resize(10);
}
