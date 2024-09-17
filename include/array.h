#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class Array
{
public:
    Array(int initialCapacity = 1)
    {
        capacity = initialCapacity;
        size = 0;
        data = new T[capacity];
    }

    ~Array()
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
        if (index >= size || size == 0)
        {
            throw std::out_of_range("ERROR: IndexOutOfBounds");
        }
        return data[index];
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
            data[size - 1].~T();
            size--;
            if (capacity / 2 > size)
            {
                resize(capacity / 2);
            }
            return temp;
        }
        else
        {
            throw std::out_of_range("ERROR: IndexOutOfBounds");
        }
    }

    void insert(int index, const T &element)
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
        T *temp = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCapacity;
    }
};

#endif // ARRAY_H
