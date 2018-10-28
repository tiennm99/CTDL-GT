#include <iostream>

#include "lab6.h"

int main()
{
    string command = "";
    string filename = "phone.csv";
    AVLTree<Phone> *phoneTree = readPhoneFromFile(filename);
    if (phoneTree == nullptr)
        return 1;
    while (true) {
        system("clear"); // Clear terminal for Linux
        printMenu();
        getline(cin, command);
        if (command == "1") {
            cout << "Input full name:" << endl;
            string str = "";
            getline(cin, str);
            Phone searchData(str);
            AVLNode<Phone> *searchNode = phoneTree->search(searchData);
            if (searchNode == nullptr) {
                cout << "Can't file phone with this name!" << endl;
            } else {
                cout << searchNode->data.name << "'s number is " << searchNode->data.number << endl;
            }
        } else if (command == "2") {
            cout << "Input new name:" << endl;
            string str1 = "";
            getline(cin, str1);
            cout << "Input new number:" << endl;
            string str2 = "";
            getline(cin, str2);
            Phone newData(str1, str2);
            AVLNode<Phone> *newNode = new AVLNode<Phone>(newData);
            if (newNode == nullptr)
                cout << "Error! Out of memory!" << endl;
            else if (phoneTree->insert(newNode))
                cout << "Insert successful!" << endl;
            else
                cout << "Error! Duplicate name!" << endl;
        } else if (command == "3") {
            cout << "Input name to delete:" << endl;
            string str = "";
            getline(cin, str);
            Phone deleteData(str);
            if (phoneTree->remove(deleteData))
                cout << "Delete successful!" << endl;
            else
                cout << "Can't found this name! You must input full name!" << endl;
        } else if (command == "4") {
            cout << phoneTree;
        } else if (command == "0") {
            cout << "Good Bye!" << endl;
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
        writePhoneToFile(filename, phoneTree);
        cout << "Press Enter to continue" << endl;
        cin.get();
    }
    return 0;
}
