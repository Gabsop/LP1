#include <iostream>

int* function() 
{
    int a = 15;
    int* pointer = &a;
    return pointer;
}

int main (int argc, char *argv[])
{
    // * = Declarar ponteiro e acessar valor dele
    // & = Declarar referêcia e apontar o ponteiro para uma posição na memória
    
    int n = 10;
    int &n2 = n;

    int* n3 = function();

    std::cout << *n3 << std::endl;

    return 0;
}
