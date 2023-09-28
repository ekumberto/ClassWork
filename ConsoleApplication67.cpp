#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

class BankAccount {
private:
	string imya;
	string id;
	int balance;
	inint generateID() {
		static int generate = 0;
		return ++generate;
	}
public:
    BankAccount(string Name, int Balance) {
        name = Name;
        balance = Balance;
        id = "N" + to_string(generateID());
    }

    string getId() { return id; }
    string getName() { return name; }
    int getBalance() { return balance; }

    void Deposit(int addBalance) { balance += addBalance; }

    void Withdraw(int WithdrawBalance) {
        if (WithdrawBalance <= balance) {
            balance -= WithdrawBalance;
        }
        else {
            balance = 0;
        }
    }

    void DisplayInfo() {
        cout << "ID аккаунта: " << id << endl;
        cout << "Имя владельца: " << name << endl;
        cout << "Баланс: " << balance << endl;
    }
}; 
class Monobank {
private:
    BankAccount accounts[2];
public:
    Monobank(string Name1, int Balance1, string Name2, int Balance2) {
        accounts[0] = BankAccount(Name1, Balance1);
        accounts[1] = BankAccount(Name2, Balance2);
    }
    void checkInfo(const string& accountId) {
        for (int i = 0; i < 2; ++i) {
            if (accounts[i].getId() == accountId) {
                accounts[i].DisplayInfo();
                return;
            }
        }
    }
    void Transfer(string fromAccountId, string toAccountId, int amount) {
        for (int i = 0; i < 2; ++i) {
          
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Monobank MonoBank("Петя", 1000, "Вася", 500);

    MonoBank.checkInfo("N1");
    MonoBank.checkInfo("N2");

    MonoBank.Transfer("N1", "N2", 200);

    MonoBank.checkInfo("N1");
    MonoBank.checkInfo("N2");

    return 0;
}