#include <iostream>

template <typename T>
class Vector_supermercado
{
private:
    int size;
    int top;

public:
    T *elementos;

    Vector_supermercado()
    {
        this->size = 20;
        this->top = -1;
        this->elementos = new T[size];
    }

    ~Vector_supermercado()
    {
        delete[] elementos;
    }

    int sizeVector()
    {
        return top + 1;
    }
    void push(T elemento)
    {
        if (top == (size - 1))
        {
            std::cout << "Aumentar tamanho" << std::endl;
            int newSize = size + 2;

            T *aux = new T[newSize];

            for (size_t i = 0; i < size; i++)
            {
                aux[i] = elementos[i];
            }
            delete[] elementos;
            this->elementos = new T[newSize];
            for (size_t i = 0; i < newSize; i++)
            {
                elementos[i] = aux[i];
            }
            delete[] aux;
            this->elementos[++top] = elemento;
        }
        else
        {
            this->elementos[++top] = elemento;
        }
    }

    void
    pop()
    {
        if (top == -1)
        {
            std::cout << "Vector vazio" << std::endl;
        }
        else
        {
            this->elementos[top--];
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    T back()
    {
        return this->elementos[top];
    }
    void clear()
    {
        delete[] elementos;
        this->elementos = new T[size];
    }
};