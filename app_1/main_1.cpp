#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Blockchain buffCUoin;

    string src;
    string dst;
    string who;
    int coin;

    bool quit = false;
    while(!quit){
        int option;
        cout << "====Main Menu ====" << endl;
        cout << "1. Add a transaction" << endl;
        cout << "2. Verify Blockchain" << endl;
        cout << "3. Mine Pending Transactions" << endl;
        cout << "9. Print Transactions" << endl;
        cout << "n. Quit" << endl;
        cin >> option;
        switch(option){
            case 1:
                cout << "Please State: " << endl;
                cout << "From: ";
                cin >> src;
                cout << "To: ";
                cin >> dst;
                cout << "How many coins: ";
                cin >> coin;
                buffCUoin.addTransaction(src,dst,coin);
            break;
            case 2:
                buffCUoin.isChainValid();
            break;
            case 3:
                cout << "Who's Mining Pending" << endl;
                cin >> who;
                buffCUoin.minePendingTransactions(who);
            break;
            case 9:
                buffCUoin.prettyPrint();
            break;
            default:
                quit = true;
                break;
        }
    }

    /*buffCUoin.prettyPrint(); 

    cout << "ashutosh mining first block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh paid maciej 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 1);

    cout << "ashutosh paid asa 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","asa", 1);
    cout << "asa mining second block ... " << endl;
    buffCUoin.minePendingTransactions("asa");
    buffCUoin.prettyPrint(); 
    
    cout << "asa paid ashutosh 1 BFC ... " << endl;
    buffCUoin.addTransaction("asa","ashutosh", 1);    
    cout << "ashutosh paid maciej 2 BFC ... " << endl;
    buffCUoin.addTransaction("asa","maciej", 2);
    
    cout << "maciej mining third block ... " << endl;
    buffCUoin.minePendingTransactions("maciej");
    buffCUoin.prettyPrint(); 
    
    cout << "ashutosh mining fourth block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    buffCUoin.prettyPrint();*/
    
    return 0;
}