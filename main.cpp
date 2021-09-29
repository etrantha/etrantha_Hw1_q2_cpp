#include <iostream>
#include <string>

using namespace std;

const int n=5;

class Check{
    public:
    Check():checkNum(0), checkAmount(0), checkMemo(" "){checkNum++;} //defualt contructor
    int getCheckNum() const{return checkNum;};
    int getCheckAmount() const{return checkAmount;};
    string getcheckMemo() const{return checkMemo;};
    void setCheckNum(int pCheckNum){checkNum = pCheckNum;}
    void setCheckAmount(int pCheckAmount){checkAmount = pCheckAmount;};
    void setCheckMemo(string pCheckMemo){checkMemo = pCheckMemo;};


    private:
    int checkNum, checkAmount;
    string checkMemo;
};

class CheckBook{
    public:
    Check arr[n];  //create Check array
    CheckBook():balance(0), numofChecks(0), checkLimit(10){};
    CheckBook(int balance1):balance(balance1), numofChecks(0), checkLimit(10){};
    void deposit(float amount);  //in case you want to add funds
    void displayChecks();
    int getallChecks(){return allChecks;}
    bool writeCheck(float amount);
    static int allChecks;





private:
    Check check1;
    float balance;
    int lastDeposit, checkLimit;
    int numofChecks;


};

int CheckBook::allChecks=0; //initialize allchecks with 0


int main() {
    CheckBook cb1(1000), cb2(500);
    for (int i=0; i<10;i++)
    {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }

    cout << "cb1 check details:" << endl;
    cb1.displayChecks();
    cout << "cb2 check details:" << endl;
    cb2.displayChecks();

    cout << cb1.getallChecks() <<endl;
    cout << cb2.getallChecks() <<endl;
    return 0;
}

void CheckBook::deposit(float amount) {
    balance += amount;
    cout << "You're balance is: " << balance << endl;
}

void CheckBook::displayChecks()
{
    size_t n = sizeof(arr)/sizeof(arr[0]);
    for (int i = n-1; i > -1; i--) {
        if(arr[i].getCheckAmount() != 0) {
            cout << "check number:" << arr[i].getCheckNum() << "  amount: " << arr[i].getCheckAmount() << "  memo:"
                 << arr[i].getcheckMemo() << endl;
        }
        else exit;
        }

}


bool CheckBook::writeCheck(float amount) {
    if (numofChecks < checkLimit && allChecks < 10 && amount <= balance) {
        string memo;
        if (arr[0].getCheckAmount() == 0) {
            cout << "memo? " << endl;
            cin >> memo;
            arr[0].setCheckMemo(memo);
            arr[0].setCheckNum(1);
            arr[0].setCheckAmount(amount);
            balance -= amount;
            allChecks++;
            numofChecks++;


        } else if (arr[1].getCheckAmount() == 0) {
            cout << "memo? " << endl;
            cin >> memo;
            arr[1].setCheckMemo(memo);
            arr[1].setCheckNum(2);
            arr[1].setCheckAmount(amount);
            balance -= amount;
            allChecks++;
            numofChecks++;


        } else if (arr[2].getCheckAmount() == 0) {
            cout << "memo? " << endl;
            cin >> memo;
            arr[2].setCheckMemo(memo);
            arr[2].setCheckNum(3);
            arr[2].setCheckAmount(amount);
            balance -= amount;
            allChecks++;
            numofChecks++;


        } else if (arr[3].getCheckAmount() == 0) {
            cout << "memo? " << endl;
            cin >> memo;
            arr[3].setCheckMemo(memo);
            arr[3].setCheckNum(4);
            arr[3].setCheckAmount(amount);
            balance -= amount;
            allChecks++;
            numofChecks++;


        } else if (arr[4].getCheckAmount() == 0) {
            cout << "memo? " << endl;
            cin >> memo;
            arr[4].setCheckMemo(memo);
            arr[4].setCheckNum(5);
            arr[4].setCheckAmount(amount);
            balance -= amount;
            allChecks++;
            numofChecks++;



        }
    } else
        return false;
}



