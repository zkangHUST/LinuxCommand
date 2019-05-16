#include "tools.h"
string trim(const string& src)
{
    string ret;
    vector<string> tmp;
    stringSplit(src, tmp);
    for (vector<string>::iterator it = tmp.begin(); it != tmp.end(); it++) {
        ret += *it;
        if (it != tmp.end() - 1) {
            ret += " ";
        }
    }
    return ret;
}

void stringSplit(const string& src, vector<string>& output)
{
    string::size_type pos1, pos2;
    pos1 = 0;
    pos2 = 0;
    while (pos2 < src.size()) {
        while (isblank(src[pos1])  && pos1 < src.size()) {
            pos1++;
        }
        pos2 = pos1;
        while (!isblank(src[pos2]) && pos2 < src.size()) {
            pos2++;
        }
        if (pos1 < pos2 && pos2 <= src.size()) {
            output.push_back(src.substr(pos1, pos2 - pos1));
        } 
        pos1 = pos2;
    }
}