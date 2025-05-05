#include <iostream>
#include <string>
using namespace std;

class OutOfBoundsException
{
private:
    string message;

public:
    OutOfBoundsException(const string msg) : message(msg) {}
    const char *what() const
    {
        return message.c_str();
    }
};

template <typename T>
class SmartArray
{
private:
    T *data;
    size_t size;

public:
    SmartArray(size_t size) : size(size)
    {
        data = new T[size];
    }

    ~SmartArray()
    {
        delete[] data;
    }

    SmartArray(const SmartArray &other) : size(other.size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    SmartArray &operator=(const SmartArray &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    T &operator[](size_t index)
    {
        if (index >= size)
        {
            throw OutOfBoundsException("Invalid index access attempted!");
        }
        return data[index];
    }

    const T &operator[](size_t index) const
    {
        if (index >= size)
        {
            throw OutOfBoundsException("Invalid index access attempted!");
        }
        return data[index];
    }

    size_t getSize() const
    {
        return size;
    }
};

template <typename T>
void testArray()
{
    size_t size;
    cout << "Array size: ";
    cin >> size;

    SmartArray<T> arr(size);

    cout << "Enter elements: ";
    for (size_t i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    size_t index;
    cout << "Accessing index: ";
    cin >> index;

    try
    {
        cout << "Element at index " << index << ": " << arr[index] << endl;
    }
    catch (const OutOfBoundsException &e)
    {
        cout << "OutOfBoundsException caught: " << e.what() << endl;
    }
}

int main()
{
    cout << "Testing SmartArray with int:\n";
    testArray<int>();

    cout << "\nTesting SmartArray with string:\n";
    cin.ignore();
    testArray<string>();

    return 0;
}