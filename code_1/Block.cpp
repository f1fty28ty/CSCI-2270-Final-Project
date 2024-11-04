#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    // TODO
    previousHash = _previousHash;
}

string Block::calculateHash() {
    // TODO
    string input = toString();
    string output = sha256(input);
    return output;   
}

void Block::mineBlock(unsigned int difficulty) {
    // TODO
    string dif = string(difficulty, '0');
    while(hash.substr(0, difficulty) != dif){
        nonce++;
        hash = calculateHash(); 
    } 
}

string Block::toString() {
    stringstream ss;
    for(long unsigned int i = 0; i < transactions.size();i++){
        ss << transactions[i].getSender();
        ss << transactions[i].getReceiver();
        ss << transactions[i].getAmount();

    }
    ss << previousHash << timestamp << nonce;
    return ss.str();
     
}
void Block::printTran(){
    for(long unsigned int i = 0; i < transactions.size();i++){
        cout << transactions[i].toString() << endl;
    }
}

string Block::returnPrevHash(){
    return previousHash;
}

string Block::returnHash(){
    return hash;
}

int Block::transactionBalance(string address){
    int balance = 0;
    for(long unsigned int j = 0; j < transactions.size();j++){
        if(address == transactions[j].getReceiver()){
            balance += transactions[j].getAmount();
        }
        if(address == transactions[j].getSender()){
            if(balance >= transactions[j].getAmount()){
                balance -= transactions[j].getAmount();
            }
        } 
    }
    return balance;
}