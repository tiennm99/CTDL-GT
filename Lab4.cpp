#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    ~Node() {}
};

enum ErrorCode {
    SUCCESS,
    FAIL,
    OVERFLOW,
    UNDERFLOW
};

class Stack
{
private:
    Node *sTop;
    int sCount;
public:
    Stack()
    {
        this->sTop = nullptr;
        this->sCount = 0;
    }
    ~Stack()
    {
        if (!this->isEmpty())
            this->clear();
    }
    ErrorCode create();
    ErrorCode push(int data);
    ErrorCode pop();
    ErrorCode top(int &data);
    bool isEmpty();
    bool isFull();
    ErrorCode clear();
    int size();
};

ErrorCode Stack::create()
{
    if (!this->isEmpty())
        return this->clear();
    return SUCCESS;
}

ErrorCode Stack::push(int data)
{
    if (this->isFull())
        return OVERFLOW;
    Node *temp = new Node(data, this->sTop);
    this->sTop = temp;
    temp = nullptr;
    this->sCount++;
    return SUCCESS;
}

ErrorCode Stack::pop()
{
    if (this->isEmpty())
        return UNDERFLOW;
    Node *temp = this->sTop;
    this->sTop = this->sTop->next;
    delete temp;
    temp = nullptr;
    this->sCount--;
    return SUCCESS;
}

ErrorCode Stack::top(int &data)
{
    if (this->isEmpty()) {
        data = 0;
        return FAIL;
    }
    data = this->sTop->data;
    return SUCCESS;
}

bool Stack::isEmpty()
{
    return (this->sCount == 0);
}

bool Stack::isFull()
{
    Node *temp = new Node;
    if (temp != nullptr) {
        delete temp;
        temp = nullptr;
        return false;
    }
    return true;
}

ErrorCode Stack::clear()
{
    while (!this->isEmpty()) {
        this->pop();
    }
    return SUCCESS;
}

int Stack::size()
{
    return this->sCount;
}

class Queue
{
private:
    Node *qFront;
    Node *qRear;
    int qCount;
public:
    Queue()
    {
        this->qFront = nullptr;
        this->qRear = nullptr;
        this->qCount = 0;
    }
    ~Queue()
    {
        if (!this->isEmpty())
            this->clear();
    }
    ErrorCode create();
    ErrorCode enqueue(int data);
    ErrorCode dequeue();
    ErrorCode queueFront(int &data);
    ErrorCode queueRear(int &data);
    bool isFull();
    bool isEmpty();
    ErrorCode clear();
    int size();
};

ErrorCode Queue::create()
{
    if (!this->isEmpty())
        return this->clear();
    return SUCCESS;
}

ErrorCode Queue::enqueue(int data)
{
    if (this->isFull())
        return OVERFLOW;
    Node *temp = new Node(data, this->qRear);
    qRear = temp;
    temp = nullptr;
    if (this->isEmpty()) {
        qFront = qRear;
    }
    this->qCount++;
    return SUCCESS;
}

ErrorCode Queue::dequeue()
{
    if (this->isEmpty())
        return UNDERFLOW;
    Node *temp = nullptr;
    if (this->qCount == 1) {
        this->qRear = nullptr;
    } else {
        temp = this->qRear;
        while (temp->next != this->qFront)
            temp = temp->next;
    }
    delete this->qFront;
    this->qFront = temp;
    this->qCount--;
    return SUCCESS;
}

ErrorCode Queue::queueFront(int &data)
{
    if (this->isEmpty()) {
        data = 0;
        return FAIL;
    }
    data = this->qFront->data;
    return SUCCESS;
}

ErrorCode Queue::queueRear(int &data)
{
    if (this->isEmpty()) {
        data = 0;
        return FAIL;
    }
    data = this->qRear->data;
    return SUCCESS;
}

bool Queue::isEmpty()
{
    return (this->qCount == 0);
}

bool Queue::isFull()
{
    Node *temp = new Node;
    if (temp != nullptr) {
        delete temp;
        temp = nullptr;
        return false;
    }
    return true;
}

ErrorCode Queue::clear()
{
    while (!this->isEmpty())
        this->dequeue();
    return SUCCESS;
}

int Queue::size()
{
    return this->qCount;
}

void stackToQueue(Stack &s, Queue &q)
{
    q.create();
    while (!s.isEmpty()) {
        int data;
        s.top(data);
        q.enqueue(data);
        s.pop();
    }
}

void queueToStack(Queue &q, Stack &s)
{
    s.create();
    Queue qTemp;
    Stack sTemp;
    while (!q.isEmpty()) {
        int data;
        q.queueFront(data);
        sTemp.push(data);
        qTemp.enqueue(data);
        q.dequeue();
    }
    while (!qTemp.isEmpty()) {
        int data;
        qTemp.queueFront(data);
        q.enqueue(data);
        qTemp.dequeue();
    }
    while (!sTemp.isEmpty()) {
        int data;
        sTemp.top(data);
        s.push(data);
        sTemp.pop();
    }
}

void printStack(Stack &s) //print Stack from top to base
{
    Stack sTemp;
    while (!s.isEmpty()) {
        int data;
        s.top(data);
        cout << data << " ";
        sTemp.push(data);
        s.pop();
    }
    while (!sTemp.isEmpty()) {
        int data;
        sTemp.top(data);
        s.push(data);
        sTemp.pop();
    }
    cout << endl;
}

void printQueue(Queue &q) //print Queue from front to rear
{
    Stack sTemp;
    Queue qTemp;
    while (!q.isEmpty()) {
        int data;
        q.queueFront(data);
        cout << data << " ";
        sTemp.push(data);
        qTemp.enqueue(data);
        q.dequeue();
    }
    while (!qTemp.isEmpty()) {
        int data;
        qTemp.queueFront(data);
        q.enqueue(data);
        qTemp.dequeue();
    }
    cout << endl;
}

int main()
{
    string errorCodeString[] = {
        "SUCCESS",
        "FAIL",
        "OVERFLOW",
        "UNDERFLOW"
    };
    string output;
    ErrorCode errorCode;
    int data;
    cout << "Init Stack:" << endl;
    Stack s;
    Queue q;
    Stack sTemp;
    Queue qTemp;
    for (int i = 0; i < 10; ++i) {
        s.push(i);
        printStack(s);
    }
    cout << "Size of Stack: " << s.size() << endl;
    output = s.isFull() ? "YES" : "NO";
    cout << "Is Stack full?: " << output << endl;
    cout << "Clear and print Stack:" << endl;
    s.clear();
    printStack(s);
    output = s.isEmpty() ? "YES" : "NO";
    cout << "Is Stask empty?: " << output << endl;
    errorCode = s.pop();
    cout << "ErrorCode when pop Stack again: "
         << errorCodeString[errorCode] << endl;
    errorCode = s.top(data);
    cout << "ErrorCode when top an empty Stack: "
         << errorCodeString[errorCode] << endl;
    cout << "Init Queue:" << endl;
    for (int i = 0; i < 10; ++i) {
        q.enqueue(i);
        printQueue(q);
    }
    cout << "Size of Queue: " << q.size() << endl;
    output = q.isFull() ? "YES" : "NO";
    cout << "Is Queue full?: " << output << endl;
    cout << "Clear and print Queue:" << endl;
    q.clear();
    printQueue(q);
    output = q.isEmpty() ? "YES" : "NO";
    cout << "Is Queue empty?: " << output << endl;
    errorCode = q.dequeue();
    cout << "ErrorCode when dequeue Queue again: "
         << errorCodeString[errorCode] << endl;
    errorCode = q.queueFront(data);
    cout << "ErrorCode when queueFront an empty Queue: "
         << errorCodeString[errorCode] << endl;
    errorCode = q.queueRear(data);
    cout << "ErrorCode when queueRear an empty Queue: "
         << errorCodeString[errorCode] << endl;
    cout << "Init Stack and Queue again:" << endl;
    for (int i = 0; i < 10; i++) {
        s.push(i);
        q.enqueue(i);
    }
    cout << "Stack: ";
    printStack(s);
    cout << "Queue: ";
    printQueue(q);
    cout << "Use stackToQueue to create new Queue:" << endl;
    stackToQueue(s, qTemp);
    cout << "New Queue: ";
    printQueue(qTemp);
    cout << "Stack after: ";
    printStack(s);
    cout << "Use queueToStack to create new Stack" << endl;
    queueToStack(q, sTemp);
    cout << "New Stack: ";
    printStack(sTemp);
    cout << "Queue after: ";
    printQueue(q);
    return 0;
}
