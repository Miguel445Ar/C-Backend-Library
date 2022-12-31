#ifndef __ROUTES_HPP__
#define __ROUTES_HPP__

#include <string>

#define MAX_CHILDREN_SIZE 26
#define SLASH_ASCII 47
#define HYPHEN_ASCII 45

class Routes {
    typedef unsigned long long ull;
public:
    Routes() {
        this->_root = new Node('/');
    }
    void addRoute(const std::string& route);
    bool deleteRoute(const std::string& route);
    bool findRoute(const std::string& route);
private:
    class Node {
    public:
        Node(char value, bool endOfWord = false): _value(value), _endOfWord(endOfWord) {
            this->_children = new Node*[MAX_CHILDREN_SIZE];
            for(unsigned short i = 0; i < MAX_CHILDREN_SIZE; ++i)
                this->_children[i] = nullptr;
        }
        Node* getChild(const unsigned int pos) {
            return this->_children[pos];
        }
        char getValue() {
            return this->_value;
        }
        bool isEndOfWord() {
            return this->_endOfWord;
        }
    private:
        char _value;
        Node** _children;
        Node* _slash;
        Node* _hyphen;
        bool _endOfWord;
    };
    Node* _root;
    ull _size;
};







void Routes::addRoute(const std::string& route) {

}
bool Routes::deleteRoute(const std::string& route) {

}
bool Routes::findRoute(const std::string& route) {

}

#endif