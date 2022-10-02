# Banking-System

**Goals:** Working with queues and binary search trees as well as designing classes.

Software: C++ (stack, queue, binary search tree, input/out(read,write,and delete))

**Context:** banking application with processes  transactions consists of three phases.
1. The program will read in a string of tractions from a file to in-memory queue.
   These transactions can open accounts, withdraw funds, deposit funds, transfer funds, or to print out the transactional history.
2. The program will read from the queue and process in order.
3. After the queue has been depleted, the program will print out all open account balanced and information. 

A input file named BankTransIn.txt will consist the following:
  - Five types of transactions as a character beginning the line (O(open an account), Withdraw(withdraw fund), Deposit(deposit fund), Transfer(transfer between funds or between clients), History (display history of all transactions), 
  - Client name and account number following by O (open an account).
  - Account number and cash amount following by W, D, and T.
  - Account number following by the H to display the client account history and info.

<img width="814" alt="Class" src="https://user-images.githubusercontent.com/90677197/193437207-e4b3d602-8a3a-471d-bd43-5d76f3c3eaac.png">

Output: successfully. 

Note: if run on command (g++), please run ./a.out BankTransIn.txt or ./a.exe BankTransIn.text to see the result.
