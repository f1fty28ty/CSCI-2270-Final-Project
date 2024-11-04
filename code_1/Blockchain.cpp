#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    if(src != "BFC"){
        if(getBalanceOfAddress(src) >= coins){
            Transaction newtrans(src,dst,coins);
            pending.push_back(newtrans);
        }else{
            cout << "You do not have enough dabloons." << endl;
        }
    }else{
        Transaction newtrans(src,dst,coins);
        pending.push_back(newtrans);
    }
    // TODO
}

bool Blockchain::isChainValid() { 
    // TODO
    string dif = string(difficulty, '0');
    string hash;
    for(long unsigned int i = 1; i < chain.size();i++){
        if(chain[i-1].returnHash() != chain[i].returnPrevHash()){
            cout << "invalid prevHash" << endl;
            return false;
        }
        hash = chain[i].returnHash();
        if(hash.substr(0, difficulty) != dif){
            cout << "invalid difficulty numbers" << endl;
            return false;
        } 
    }
    cout << "valid chain" << endl;
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO
    Block pendingBlock(pending,time(nullptr),chain.back().returnHash());
    pendingBlock.mineBlock(difficulty);
    pending.clear();
    chain.push_back(pendingBlock);
    addTransaction("BFC",minerAddress,miningReward);
    
    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    // TODO
    int balance = 0;
    for(long unsigned int i = 0; i < chain.size();i++){
        balance += chain[i].transactionBalance(address);
    }
    return balance;
}

void Blockchain::prettyPrint() {
    // TODO
    for(long unsigned int i = 0; i < chain.size() ;i++){
        cout << chain[i].returnHash() << endl;
        chain[i].printTran();
        cout << "--------------" << endl;
    }
}