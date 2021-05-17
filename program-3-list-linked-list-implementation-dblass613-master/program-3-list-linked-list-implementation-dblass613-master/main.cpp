#include <iostream>
using namespace std;
#include "LinkedList.h"


int main() {
    LinkedList clientList = LinkedList();
    int option;
    string input="";
    string ok = "";

    do {
        cout<<"Choose an Option: \n 1:Insert \n 2:Delete \n 3:Display \n 4:Sort \n 5:Average \n 6:Median \n 7:Shuffle \n 8:Exit "<<endl;
        cin>> option;
        switch (option) {
            case 1:
                cout << "Enter a non-empty string" << endl;
                cin >> input;
                if (input == "") {
                    cout << "Enter a non-empty string" << endl;
                } else {
                    clientList.InsertAtEnd(input);
                }
                break;
            case 2:
                cout << "Enter the string you wish to delete" << endl;
                cin >> input;
                clientList.Delete(input);
                break;
            case 3:
                clientList.Display();
                break;
            case 4:
                clientList.Sort();
                cout << "Would you like to see your sorted list? Enter Y for yes or N for No" << endl;
                cin>>ok;
                if (ok == "Y") {
                    clientList.Display();
                }
                break;
            case 5:
                cout << clientList.Average() << endl;
                break;
            case 6:
                cout << clientList.Median()<<endl;
                break;
            case 7:
                clientList.Shuffle();
                cout << "Would you like to see your shuffled list? Enter Y for yes or N for No" << endl;
                cin>>ok;
                if (ok == "Y") {
                    clientList.Display();
                }
                break;
            case 8:
                exit(0);
        }
    }while(option!=8);
}