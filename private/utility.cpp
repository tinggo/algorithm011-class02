#include <string>
#include <assert.h>
#include <list>
#include <iostream>

using namespace std;

void strToLower(char* str, size_t size) {
    int len = strlen(str);
    for(int i = 0; i < size && i < len; ++i)
        str[i] = tolower(str[i]);
}

void strToUpper(char* str, size_t size) {
    int len = strlen(str);
    for(int i = 0; i < size && i < len; ++i)
        str[i] = tolower(str[i]);
}

string& strToLower(string& str) {
    for(char& c : str)
        c = tolower(c);
    return str;
}

string& stdToUpper(string& str) {
    for(char&c : str)
        c = toupper(c);
    return str;
}

string& normalizePath(string& path) {
    list<string> folder;
    string temp = "";
    for(int i = 0; i < path.length(); ++i) {
        if(path[i] == '\\')
            path[i] = '/';
        if(path[i] != '/')
            temp.push_back(path[i]);
        else {
            folder.push_back(temp);
            temp = "";
            if(i == path.length() - 1)
                path.pop_back();
        }
    }
    auto prev = folder.end();
    for(auto it = folder.begin(); it != folder.end();) {
        if(*it == ".." && prev != folder.end()) {
            folder.erase(prev--);
            folder.erase(it++);
        }
        else
            prev = it++;

    }
    path = "";
    for(auto it = folder.begin(); it != folder.end(); ++it) {
        if(it != folder.begin())
            path += "/";
        path += *it;
    }
    return path;
}

string& replaceAll(string& str, const string& src, const string& des) {
    int index = -1;
    while((index = str.find(src)) != -1)
        str.replace(index, src.length(), des);
    return str;
}

string& replaceFirst(string& str, const string& src, const string& des) {
    int index = str.find(src);
    if(index != -1)
        str.replace(index, src.length(), des);
    return str;
}

string& replaceLast(string& str, const string& src, const string& des) {
    int index = str.rfind(src);
    if(index != -1)
        str.replace(index, src.length(), des);
    return str;
}


int main() {
    string path = "";
    cout << normalizePath(path) << endl;
    path = "c:/";
    cout << normalizePath(path) << endl;
    path = "c:/a/../";
    cout << normalizePath(path) <<endl;
    path = "c:\\a/../c\\d/";
    cout << normalizePath(path) <<endl;
    path = "aaabbbcccbbbddd";
    string src = "bbb";
    string des = "";
    cout << replaceAll(path,src,des) <<endl;
    path = "aaabbbcccbbbddd";
    cout << replaceFirst(path,src,des) <<endl;
    path = "aaabbbcccbbbddd";
    cout << replaceLast(path,src,des) <<endl;
    system("pause");
    return 0;
}