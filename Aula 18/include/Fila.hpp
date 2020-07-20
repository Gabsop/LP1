#include <iostream>

template <typename T>
class Fila
{
private:
    int size;
    int top;
    T *elementos;

public:
    Fila(int s)
    {
        this->size = s;
        this->top = -1;
        this->elementos = new T[size];
    }

    ~Fila()
    {
        delete[] elementos;
    }

    void push(T elemento)
    {
        if (top == (size - 1))
        {
            std::cout << "Fila cheia" << std::endl;
        }
        else
        {
            this->elementos[++top] = elemento;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            std::cout << "Fila vazia" << std::endl;
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
    void list()
    {
        if (isEmpty())
        {
            std::cout << "Fila vazia" << std::endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                std::cout << i + 1 << ":" << std::endl;
                elementos[i].display();
                std::cout << "\n";
            }
        }
    }
};