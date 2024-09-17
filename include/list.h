#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class List
{
public:
    List(int initialCapacity = 1) : capacity(initialCapacity), size(0)
    {
        data = new T[capacity];
    }

    ~List()
    {
        delete[] data;
    }

    int getSize()
    {
        return size;
    }

    int getCapacity()
    {
        return capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    T &operator[](int index)
    {
        if (index < size && index >= 0 && size > 0)
        {
            return data[index];
        }
        else
        {
            throw std::out_of_range("ERROR: IndexOutOfBounds");
        }
    }

    void clear()
    {
    }

    void append(const T &element)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        data[size] = element;
        size++;
    }

    T pop()
    {
        if (size > 0)
        {
            T temp = data[size - 1];
            std::cerr << data[size - 1] << '\n';
            size--;
            if (capacity / 2 > size)
            {
                resize(capacity / 2);
            }
            return temp;
        }
        else
        {
            throw std::out_of_range("pop(): IndexOutOfBounds");
        }
    }

    void insert(int index, const T &element)
    {
        if (index < size && index >= 0 && size > 0)
        {

            if (size == capacity)
            {
                resize(capacity * 2);
            }
            for (int i = size; i >= index; i--)
            {
                data[i + 1] = data[i];
            }
            data[index] = element;
            size++;
        }
        else
        {
            throw std::out_of_range("insert(): IndexOutOfBounds");
        }
    }

    void remove(int index)
    {
        if (index < size && index >= 0 && size > 0)
        {
            for (int i = index; i < size - 1; i++)
            {
                T temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
            size--;
            if (capacity / 2 > size)
            {
                resize(capacity / 2);
            }
        }
        else
        {
            throw std::out_of_range("remove(): IndexOutOfBounds ");
        }
    }

    void clear()
    {
        }

    void print()
    {
        std::cout << "Capacity: " << capacity << '\n';
        std::cout << "Size: " << size << '\n';
        std::cout << '[';
        for (int i = 0; i < size; i++)
        {
            if (i == size - 1)
            {
                std::cout << data[i];
            }
            else
            {
                std::cout << data[i] << ',';
            }
        }
        std::cout << "]\n";
    }

private:
    T *data;
    size_t size;
    size_t capacity;

    void resize(int newCapacity)
    {
        if (newCapacity > size)
        {
            T *temp = new T[newCapacity];
            for (int i = 0; i < size; i++)
            {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity = newCapacity;
        }
        else
        {
            throw std::out_of_range("resize(): IndexOutOfBounds ");
        }
    }
};

#endif // LIST_H
