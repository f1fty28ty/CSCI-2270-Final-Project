# CSCI 2270 – Data Structures - Final Project 

Start by carefully reading the write-up contained in `CSCI2270_Spring22_Project.pdf`.

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. Also, include the names of the team-members/authors.

Author: Miles Silveria.

Hello users,

    This program is the basic understandings of a Blockchain and Blockchain Technology. It has everything from adding transactions. being able to check to see is the chain is valid and be able to mine blocks and check if they print in the list of transactions.

    Here are how each function works together with each other.


    Block.cpp

    setPreviousHash(_previousHash) - Basic c++ setter function.

    calculateHash -  uses the toString function to be able to encode with the sha256 library. outputs the new hash.

    toString - first adds all transactions to a string stream by grabbing sender,reciever,and ammount from each transaction. then adds the previousHash, timestamp, and nonce to the string and returns the stringstream as a string.

    mineBlock(difficulty) -  sets a string to the ammount in the difficulty. then compares that number to the ammount at the start of the hash. exp. difficulty == 4 so 0000 see if the first 4 chars in the hash == 0000. adds one to nonce then recalculates the hash again till the first 4 equals 0000.

    ///Helper Functions///
    printTran - prints the transactions of said block
    returnHash - returns hash
    returnPrevHash - returns previous hash
    transactionBalance(address) - gets the balance of all transactions in the block. if the user is receiving money then it adds to balance. if they are sending money, it removes the money if they have the money for it. returns the total balance in that block.


    Blockchain.cpp

    addTransaction(source, destination, coins) - checks to see if src is from BFC, if from BFC then it just adds the new transaction to pending. If it is not from BFC then first check if the src has enough money by running getBalanceOfAddress, if they dont print a warning if not then add that transaction into pending.

    isChainValid - does what mineBlock does for both the difficulty string and substring. we check if the chain is valid by comparing the current block we are on to the last by seeing if the last blocks hash matches the current blocks previousHash, if it does not match return false. move to the next and check if the current block's hash is in line with the difficulty if not then return false. If it passes both return true.

    minePendingTransaction(minerAddress) -  makes a new transaction block with the parameters of all the transactions in pending, the current time, and the hash of the last block in chain. Mine with said new transaction block with the difficulty. Clears the pending vector. ands the new transaction block into pending. runs addTransaction(BFC, minerAddress, miningReward).

    getBalanceOfAddress(address) - sets a blank balance, goes through each block in the chain and runs transactionBalance on each adding that to balance. Returns Balance.

    prettyPrint - prints the hash of the current block in the chain then prints the transactions in that block with printTran.

Feel Free to run ./run_app_1 and play around with the product of this project.