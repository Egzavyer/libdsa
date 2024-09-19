#ifndef DARRAY_H
#define DARRAY_H

#include <cstddef>
#include <stdexcept>
#include <iostream>

template<typename T>
class DArray {
public:
    explicit DArray(const int initialCapacity = 1) {
        capacity = initialCapacity;
        size = 0;
        data = new T[capacity];
    }

    ~DArray() {
        delete[] data;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    T &operator[](int index) {
        if (index < size && index >= 0 && size > 0) {
            return data[index];
        } else {
            throw std::out_of_range("ERROR: IndexOutOfBounds");
        }
    }

    void append(const T &element) {
        size++;
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size - 1] = element;
    }

    T pop() {
        if (size > 0) {
            T temp = data[size - 1];
            size--;
            if (capacity / 2 > size) {
                resize(capacity / 2);
            }
            return temp;
        } else {
            throw std::out_of_range("pop(): IndexOutOfBounds");
        }
    }

    void insert(int index, const T &element) {
        if ((index < size || size == 0) && index >= 0) {
            size++;
            if (size == capacity) {
                resize(capacity * 2);
            }
            for (int i = size; i >= index; i--) {
                data[i + 1] = data[i];
            }
            data[index] = element;
        } else if (index == size) {
            append(element);
        } else {
            throw std::out_of_range("insert(): IndexOutOfBounds");
        }
    }

    void remove(const int index) {
        if (index < size && index >= 0 && size > 0) {
            for (size_t i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            size--;
            if (capacity / 2 > size) {
                resize(capacity / 2);
            }
        } else {
            throw std::out_of_range("remove(): IndexOutOfBounds ");
        }
    }

    void clear() {
        size = 0;
    }

    void shrinkToFit() {
        if (size < capacity) {
            resize(size);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const DArray<T>& arr) {
        os << "Capacity: " << arr.capacity << '\n';
        os << "Size: " << arr.size << '\n';
        os << '[';
        for (size_t i = 0; i < arr.size; i++) {
            if (i > 0) os << ',';
            os << arr.data[i];
        }
        os << "]\n";
        return os;
    }

    DArray(const DArray& other) {
        capacity = other.getCapacity();
        size = other.getSize();
        data = new T[capacity];

        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    DArray& operator=(const DArray& other) {
        if (this != other) {
            delete[] data;
            capacity = other.getCapacity();
            size = other.getSize();
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

private:
    T *data;
    size_t size;
    size_t capacity;

    void resize(const int newCapacity) {
        if (newCapacity > size) {
            T *temp = new T[newCapacity];
            for (size_t i = 0; i < size; ++i) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity = newCapacity;
        } else {
            throw std::out_of_range("resize(): IndexOutOfBounds ");
        }
    }
};

#endif // DARRAY_H
