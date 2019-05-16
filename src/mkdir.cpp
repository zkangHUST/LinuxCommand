#include<cstdio>
#include<iostream>
#include<cstring>
#include <sys/stat.h>
#include<unistd.h>
#include<cerrno>
using namespace std;
int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "mkdir: missing operand" << endl;
        cout << "Try 'mkdir --help' for more information." << endl;
        return 0;
    }  else if (string(argv[1]) == "--help") {
        cout << "Usage: mkdir DIRECTORY..." << endl;
        cout << "Create the DIRECTORY(ies), if they do not already exist." << endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        if (mkdir(argv[i]) != 0) {
            cout << "mkdir: cannot create directory \"" << argv[i] << "\": " << strerror(errno) << endl;
        }
    }
    return 0;

}
