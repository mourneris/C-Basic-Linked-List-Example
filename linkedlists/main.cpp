#include <iostream>

using namespace std;

template <typename T>
class LinkedList{

private:
    struct Node{
        T data;
        Node* next;
    };

    Node* head;
    Node* current;
    Node* last;

public:
    LinkedList(){
        head = NULL;
        current = head;
        last = head;
    }

    ~LinkedList(){
        current = head;
        Node* nextDel;

        while(current != NULL){
            nextDel = current->next;
            delete current;
            current = nextDel;
        }
    }

    void addNew(T value){
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            current = head;
        }
        else{
            last->next = newNode;
        }

        last = newNode;
    }

    // Moves the current pointer to the next node in the sequence.
    // If the next node is NULL, then it points back to the first.
    void next(){
        if(current->next != NULL)
            current = current->next;
        else
            current = head;
    }

    T getCurrent(){ return current->data; }

    void printCurrent(){ cout << this->getCurrent() << endl; }

    void printlCurrent() {
        cout << this->getCurrent() << endl;
        this->next();
    }
};

int main()
{
    LinkedList<int>* intList = new LinkedList<int>;

    intList->addNew(5);
    intList->addNew(7);
    intList->addNew(9);

    for(int i = 0; i < 5; i++)
        intList->printlCurrent();

    delete intList;

    return 0;
}
