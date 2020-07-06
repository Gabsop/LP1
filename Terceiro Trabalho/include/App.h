#ifndef APP_H
#define APP_H

#include "Diary.h"
#include <string>

struct App
{
    Diary diary;

    App();
    int run(int argc, char *argv[]);
    void config();
    int show_usage();
    void add();
    void add(const std::string message);
    void list_messages();
    void list_messages(const std::string format);
    void search();
    void search(const std::string &what);
    void interactive();
};
#endif
