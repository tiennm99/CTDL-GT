#include "UnrolledLinkedList.h"

void UnrolledLinkedList::add(int val)
{
    if (tail == nullptr) {
        tail = new Node(nodeSize);
        ++numOfNodes;
        head = tail;
    } else if (tail->isFull()) {
        Node *newNode = new Node(nodeSize);
        ++numOfNodes;
        newNode->prev = tail;
        tail->next = newNode;
        int hsize = getHalfNodeSize();
        memmove(newNode->elements, tail->elements + hsize, (nodeSize - hsize) * sizeof(int));
        tail->numElements = hsize;
        newNode->numElements = nodeSize - hsize;
        tail = newNode;
    }
    tail->add(val);
    ++size;
}

int UnrolledLinkedList::getAt(int pos)
{
    if (pos < 0 || pos >= size)
        throw "IndexOutOfBoundsException";
    int cnt = 0;
    Node *temp = head;
    while (cnt + temp->numElements <= pos) {
        cnt += temp->numElements;
        temp = temp->next;
    }
    return temp->elements[pos - cnt];
}

void UnrolledLinkedList::setAt(int pos, int val)
{
    if (pos < 0 || pos >= size)
        throw "IndexOutOfBoundsException";
    int cnt = 0;
    Node *temp = head;
    while (cnt + temp->numElements <= pos) {
        cnt += temp->numElements;
        temp = temp->next;
    }
    temp->elements[pos - cnt] = val;
}

void UnrolledLinkedList::insertAt(int pos, int val)
{
    if (pos < 0 || pos > size)
        throw "IndexOutOfBoundsException";
    if (pos == size) {
        add(val);
        return;
    }
    int cnt = 0;
    Node *temp = head;
    while (cnt + temp->numElements <= pos) {
        cnt += temp->numElements;
        temp = temp->next;
    }
    if (temp->isFull()) {
        Node *newNode = new Node(nodeSize);
        ++numOfNodes;
        if (temp == tail)
            tail = newNode;
        else
            temp->next->prev = newNode;
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        int hsize = getHalfNodeSize();
        if (pos - cnt >= hsize) {
            memmove(newNode->elements, temp->elements + hsize, (nodeSize - hsize) * sizeof(int));
            temp->numElements = hsize;
            newNode->numElements = nodeSize - hsize;
            newNode->insertAt(pos - cnt - hsize, val);
        } else {
            memmove(newNode->elements, temp->elements + hsize - 1, (nodeSize - hsize + 1) * sizeof(int));
            temp->numElements = hsize - 1;
            newNode->numElements = nodeSize - hsize + 1;
            temp->insertAt(pos - cnt, val);
        }
    } else {
        temp->insertAt(pos - cnt, val);
    }
    ++size;
}

void UnrolledLinkedList::deleteAt(int pos)
{
    if (pos < 0 || pos >= size)
        throw "IndexOutOfBoundsException";
    int cnt = 0;
    Node *temp = head;
    while (cnt + temp->numElements <= pos) {
        cnt += temp->numElements;
        temp = temp->next;
    }
    temp->removeAt(pos - cnt);
    --size;
    if (size == 0) {
        delete head;
        --numOfNodes;
        head = nullptr;
        tail = nullptr;
        return;
    }
    if (temp->isUnderHalfFull()) {
        int hsize = getHalfNodeSize();
        if (temp == head) {
            Node *next = temp->next;
            if (next != nullptr) {
                if (next->numElements <= hsize) {
                    memmove(temp->elements + temp->numElements, next->elements, next->numElements * sizeof(int));
                    temp->numElements += next->numElements;
                    temp->next = next->next;
                    if (next == tail)
                        tail = temp;
                    else
                        temp->next->prev = temp;
                    delete next;
                    --numOfNodes;
                } else {
                    temp->add(next->elements[0]);
                    next->removeAt(0);
                }
            }
        } else {
            Node *prev = temp->prev;
            if (prev->numElements <= hsize) {
                memmove(prev->elements + prev->numElements, temp->elements, temp->numElements * sizeof(int));
                prev->numElements += temp->numElements;
                prev->next = temp->next;
                if (temp == tail)
                    tail = prev;
                else
                    prev->next->prev = prev;
                delete temp;
                --numOfNodes;
            } else {
                temp->insertAt(0, prev->elements[prev->numElements - 1]);
                prev->removeAt(prev->numElements - 1);
            }
        }
    }
}

int UnrolledLinkedList::firstIndexOf(int val)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr) {
        for (int i = 0; i < temp->numElements; ++i) {
            if (temp->elements[i] == val)
                return cnt + i;
        }
        cnt += temp->numElements;
        temp = temp->next;
    }
    return -1;
}

int UnrolledLinkedList::lastIndexOf(int val)
{
    int cnt = size;
    Node *temp = tail;
    while (temp != nullptr) {
        cnt -= temp->numElements;
        for (int i = temp->numElements - 1; i >= 0; --i) {
            if (temp->elements[i] == val)
                return cnt + i;
        }
        temp = temp->prev;
    }
    return -1;
}

bool UnrolledLinkedList::contains(int val)
{
    Node *temp = head;
    while (temp != nullptr) {
        for (int i = 0; i < temp->numElements; ++i) {
            if (temp->elements[i] == val)
                return true;
        }
        temp = temp->next;
    }
    return false;
}

void UnrolledLinkedList::reverse()
{
    if (size < 2)
        return;
    Node *temp = head;
    while (temp != nullptr) {
        Node *prev = temp->prev;
        Node *next = temp->next;
        temp->reverse();
        temp->next = prev;
        temp->prev = next;
        temp = next;
    }
    temp = head;
    head = tail;
    tail = temp;
}

int *UnrolledLinkedList::toArray()
{
    int *arr = new int[size];
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr) {
        memcpy(arr + cnt, temp->elements, temp->numElements * sizeof(int));
        cnt += temp->numElements;
        temp = temp->next;
    }
    return arr;
}
