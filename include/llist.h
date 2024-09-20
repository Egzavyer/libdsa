#ifndef LLIST_H
#define LLIST_H

#include <stdexcept>
#include <iostream>

template<typename T>
struct Node {
    T val;
    Node *next;
};

template<typename T>
class LList {
    Node<T> *head;
    Node<T> *tail;
    size_t size;

public:
    LList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LList() {
        while (head != nullptr) {
            const Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertFront(T value) {
        auto *newNode = new Node<T>();
        newNode->val = value;
        newNode->next = head;

        if (head == nullptr) {
            tail = newNode;
        }

        head = newNode;
        size++;
    }

    void insertEnd(T value) {
        auto *newNode = new Node<T>();
        newNode->val = value;
        newNode->next = nullptr;

        if (head != nullptr) {
            tail->next = newNode;
            tail = newNode;
        } else {
            head = newNode;
            tail = newNode;
        }
        size++;
    }

    void insertAt(const int index, T value) {
        if (index <= size && index >= 0) {
            if (index == 0) {
                insertFront(value);
            } else if (index == size) {
                insertEnd(value);
            } else {
                auto *newNode = new Node<T>();
                newNode->val = value;
                newNode->next = nullptr;

                Node<T> *curNode = getNode(index - 1);
                newNode->next = curNode->next;
                curNode->next = newNode;
                size++;
            }
        } else {
            throw std::out_of_range("insertAt(): IndexOutOfBounds");
        }
    }

    void deleteFront() {
        if (head == nullptr)
            throw std::runtime_error("deleteFront(): EmptyList");

        Node<T> *temp = head->next;
        delete head;
        head = temp;
        if (size == 1) {
            tail = head;
        }
        size--;
    }

    void deleteEnd() {
        if (head == nullptr)
            throw std::runtime_error("deleteEnd(): EmptyList");

        Node<T> *temp = getNode(size - 2);
        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }

    void deleteAt(const int index) {
        if (index <= size && index >= 0) {
            if (index == 0) {
                deleteFront();
            } else if (index == size) {
                deleteEnd();
            } else {
                Node<T> *curNode = getNode(index);
                Node<T> *prevNode = getNode(index - 1);
                prevNode->next = curNode->next;
                size--;
            }
        } else {
            throw std::out_of_range("deleteAt(): IndexOutOfBounds");
        }
    }

    Node<T> *getHead() {
        return head;
    }

    Node<T> *getTail() {
        return tail;
    }

    Node<T> *getNode(const int index) {
        Node<T> *curNode = head;
        for (int i = 0; i < index; i++) {
            curNode = curNode->next;
        }
        return curNode;
    }

    size_t getSize() const {
        return size;
    }

    friend std::ostream& operator<<(std::ostream& os, const LList<T>& l) {
        Node<T> *curNode = l.head;
        os << "Head: " << l.head->val << "\n";
        os << "Tail: " << l.tail->val << "\n";
        while (curNode != nullptr) {
            if (curNode != l.head) os << " -> ";
            os << curNode->val;
            curNode = curNode->next;
        }
        os << '\n';
        return os;
    }

    LList(const LList& other) : head(nullptr), tail(nullptr), size(0) {
        for (Node<T>* curr = other.head; curr != nullptr; curr = curr->next) {
            insertEnd(curr->val);
        }
    }

    LList& operator=(const LList& other) {
        if (this != &other) {
            while (head != nullptr) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }

            head = nullptr;
            tail = nullptr;
            size = 0;

            for (Node<T>* curr = other.head; curr != nullptr; curr = curr->next) {
                insertEnd(curr->val);
            }
        }
        return *this;
    }
};

#endif // LLIST_H
