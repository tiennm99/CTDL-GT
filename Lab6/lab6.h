#ifndef LAB6_H
#define LAB6_H

#include <fstream>
#include <iostream>
#include <sstream>

#include "avltree.h"
#include "phone.h"

AVLTree<Phone> *readPhoneFromFile(string filename)
{
    AVLTree<Phone> *newTree = nullptr;
    ifstream file;
    file.open(filename, ios::in);
    if (!file.is_open()) {
        cout << "Can't open file!" << endl;
    } else {
        newTree = new AVLTree<Phone>;
        string line;
        while (getline(file, line)) {
            AVLNode<Phone> *newNode = new AVLNode<Phone>;
            string str;
            stringstream ss;
            ss.str(line);
            getline(ss, str, ',');
            newNode->data.name = str;
            getline(ss, str);
            newNode->data.number = str;
            newTree->insert(newNode);
        }
        file.close();
    }
    return newTree;
}

void writePhoneToFile(string filename, AVLTree<Phone> *tree)
{
    ofstream file;
    file.open(filename, ios::out);
    file << tree;
    file.close();
}

void printMenu()
{
    cout << "========MENU========" << endl;
    cout << "Enter your command:" << endl;
    cout << "1. Search phone with name." << endl;
    cout << "2. Insert new phone." << endl;
    cout << "3. Delete phone with name." << endl;
    cout << "4. Print phone list." << endl;
    cout << "0. Exit program." << endl;
}

#endif // LAB6_H
