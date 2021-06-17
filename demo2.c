#include<unistd.h>

int main() {
    char* argv[] = {"/usr/bin/python3", "preprocessor.py", NULL};
    execv(argv[0], argv);
}