#include "../include/App.h"

int main(int argc, char *argv[])
{
    App aplicativo;
    aplicativo.config();
    return aplicativo.run(argc, argv);
}
