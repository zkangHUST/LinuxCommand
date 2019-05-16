#include<iostream>
#include "tools.h"
#include<cerrno>
#include<cstring>
using namespace std;
int main(int argc,char* argv[])
{
    if (argc < 2) {
        cout << "rm: missing operand\nTry 'rm --help' for more information.";
        return 0;
    }
    if (string(argv[1]) == "--help") {
        cout << "Usage: rm [FILE]..." << endl;
        cout << "Remove (unlink) the FILE(s)." << endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        if (remove(argv[i]) != 0) {
            cout << "rm: " << strerror(errno) << endl;
        }
    }
    return 0;
}