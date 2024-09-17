#ifndef LLIST_H
#define LLIST_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
struct Node
{
    T val;
    Node *next;
};

template <typename T>
class LList
{
private:
    Node<T> *head;
    int size;

public:
    LList()
    {
        head = nullptr;
        size = 0;
    }

    void insertFront(T value)
    {
        Node<T> *newNode = new Node<T>();
        newNode->val = value;
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertEnd(T value)
    {

        Node<T> *newNode = new Node<T>();
        newNode->val = value;
        newNode->next = nullptr;

        if (head != nullptr)
        {
            getLast()->next = newNode;
        }
        else
        {
            head = newNode;
        }
        size++;
    }

    void insertAt(int index, T value)
    {
        if (index <= size && index > 0)
        {
            Node<T> *newNode = new Node<T>();
            newNode->val = value;
            newNode->next = nullptr;

            Node<T> *curNode = getNode(index - 1);
            newNode->next = curNode->next;
            curNode->next = newNode;
            size++;
        }
        else
        {
            throw std::out_of_range("insertAt(): IndexOutOfBounds");
        }
    }

    void deleteFront()
    {
        if (head == nullptr)
            throw std::runtime_error("deleteFront(): EmptyList");

        Node<T> *temp = head->next;
        delete head;
        head = temp;
        size--;
    }

    void deleteEnd()
    {
        if (head == nullptr)
            throw std::runtime_error("deleteEnd(): EmptyList");

        Node<T> *temp = getNode(size - 2);
        Node<T> *lastNode = temp->next;
        delete lastNode;
        temp->next = nullptr;
        size--;
    }

    void deleteAt(int index)
    {
        if (index <= size && index > 0)
        {
            if (index == 0)
            {
                deleteFront();
            }
            else if (index == size)
            {
                deleteEnd();
            }
            else
            {
                Node<T> *curNode = getNode(index);
                Node<T> *prevNode = getNode(index - 1);
                prevNode->next = curNode->next;
                size--;
            }
        }
        else
        {
            throw std::out_of_range("insertAt(): IndexOutOfBounds");
        }
    }

    Node<T> *getHead()
    {
        return head;
    }

    Node<T> *getLast()
    {
        Node<T> *curNode = head;

        while (curNode->next != nullptr)
        {
            curNode = curNode->next;
        }
        return curNode;
    }

    Node<T> *getNode(int index)
    {
        Node<T> *curNode = head;
        for (int i = 0; i < index; i++)
        {
            curNode = curNode->next;
        }
        return curNode;
    }

    int getSize()
    {
        return size;
    }

    void print()
    {
        Node<T> *curNode = head;
        while (curNode != nullptr)
        {
            std::cout << curNode->val;
            if (curNode->next != nullptr)
                std::cout << " -> ";
            curNode = curNode->next;
        }
        std::cout << '\n';
    }
};

#endif // LLIST_H