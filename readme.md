# CSCI 2270 – Data Structures - Final Project

Start by carefully reading the write-up contained in `CSCI2270_Spring22_Project.pdf`.

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. Also, include the names of the team members/authors.

**Author:** Miles Silveria

---

## Introduction

Hello users,

This program provides a basic understanding of blockchain technology, featuring functionalities such as adding transactions, validating the blockchain, mining blocks, and displaying a list of transactions. Below is a detailed description of how each component and function works together.

---

## Program Overview

### Block.cpp

1. **setPreviousHash(_previousHash)** - A standard C++ setter function.
  
2. **calculateHash** - Uses the `toString` function to encode with the SHA-256 library, outputting a new hash.

3. **toString** - Aggregates all transactions into a string stream by retrieving sender, receiver, and amount from each transaction. Adds the `previousHash`, `timestamp`, and `nonce` to the string and returns it.

4. **mineBlock(difficulty)** - Sets a string based on the specified `difficulty`, then compares that to the start of the hash. For example, if `difficulty == 4`, it checks if the first 4 characters of the hash are `0000`. The nonce increments, and the hash recalculates until the condition is met.

#### Helper Functions
- **printTran** - Prints the transactions of the specified block.
- **returnHash** - Returns the block's hash.
- **returnPrevHash** - Returns the previous hash.
- **transactionBalance(address)** - Calculates the balance of all transactions in the block. Adds to balance if the user receives money and subtracts if they are the sender, provided they have sufficient funds.

### Blockchain.cpp

1. **addTransaction(source, destination, coins)** - Checks if the source is from BFC. If yes, it adds the new transaction to `pending`. Otherwise, it verifies the source has enough funds by running `getBalanceOfAddress`. If not, it prints a warning; otherwise, it adds the transaction to `pending`.

2. **isChainValid** - Validates the blockchain by verifying the `difficulty` string and comparing each block’s hash with its predecessor’s. Returns `false` if any mismatch occurs; otherwise, returns `true` if the chain passes both checks.

3. **minePendingTransaction(minerAddress)** - Creates a new transaction block with all `pending` transactions, the current time, and the hash of the last block in the chain. Mines the new block with the specified `difficulty`, clears `pending`, and adds the mined block to the chain. Finally, adds a mining reward transaction for the miner.

4. **getBalanceOfAddress(address)** - Initializes balance, iterates through each block in the chain, runs `transactionBalance`, and adds to the cumulative balance. Returns the total balance.

5. **prettyPrint** - Prints the hash of each block in the chain and displays the transactions using `printTran`.

---

## Usage

Feel free to execute `./run_app_1` to experiment with the features of this blockchain project.
