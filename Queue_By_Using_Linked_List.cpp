#include <iostream>

using namespace std;

class Node
{
private:
    Node* next;
    Node* prev;
    int val;
public:
    Node(int value) : val(value),next(nullptr), prev(nullptr) {}
    friend class Queue;
};
class Queue
{
private:
    Node* head;
    Node* tail;
    Node* current;
public:
    Queue() : head(nullptr), tail(nullptr), current(nullptr) {}
    bool is_list_empty()
    {
        return head == nullptr;
    }
    void push(int value)
    {
        Node* new_item = new Node(value);
        if(is_list_empty())
        {
            head = new_item;
            tail = new_item;
            head->next = new_item;
            head->prev = new_item;
            current = new_item;
        }
        else
        {
            new_item->next = head;
            new_item->prev = tail;
            head->prev = new_item;
            tail->next = new_item;
            tail = new_item;
            current = new_item;
        }
    }
    void pop()
    {
        if(is_list_empty())
        {
            cout << "QUEUE IS EMPTY" << endl;
            return;
        }
        else
        {
            if(head == tail)
            {
                delete head;
                head = tail = current = nullptr;
            }
            else
            {
                Node* temp = head;
                head = head->next;
                tail->next = head;
                head->prev = tail;
                current = tail;
                delete temp;
            }
        }
    }
    void display()
    {
        if(is_list_empty())
        {
            cout << "QUEUE IS EMPTY" << endl;
            return;
        }
        else
        {
            Node* temp = head;
            do
            {
                cout << temp->val << endl;
                temp = temp->next;
            }
            while(temp != head);
        }
    }
    void get_current()
    {
        if(current == nullptr)
        {
            cout << "NO CURRENT" << endl;
            return;
        }
        else
        {
            cout << "THE CURRENT NODE WITH THE VALUE IS: " << current->val << endl;
        }
    }
    void get_next()
    {
        if(current == nullptr)
        {
            cout << "NO CURRENT NEXT" << endl;
            return;
        }
        else
        {
            current = current->next;
            get_current();
        }
    }
    void get_prev()
    {
        if(current == nullptr)
        {
            cout << "NO CURRENT NEXT" << endl;
            return;
        }
        else
        {
            current = current->prev;
            get_current();
        }
    }
    ~Queue()
    {
        Node* temp = head;
        do
        {
            Node* next_node = temp->next;
            delete temp;
            temp = next_node;
        }
        while(temp != head);
    }
};
int main()
{
    Queue obj;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.pop();
    obj.display();
    obj.get_current();
    obj.get_next();
    obj.get_prev();
    return 0;
}
