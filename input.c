#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    if (argc <= 1) 
    {
        printf ("Enter 1 or more search terms:\n");
        exit (1);
    }
    char* const PYTHON = "/usr/bin/python3";
    char* const PROG_NAME = "preprocessor.py";
    const int BUFF_SIZE = 100;
    char** args= calloc(sizeof(char*), argc + 2);

    args[0] = PYTHON;
    args[1] = PROG_NAME;
    for (int i = 1; i < argc; i++) {
        args[i + 1] = argv[i];
    }

    execv(PYTHON, args);
}