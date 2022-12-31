#ifndef __JSON_DATA_HPP__
#define __JSON_DATA_HPP__

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::vector;
using std::unordered_map;
using std::string;



struct JSON_Data {
    enum JSON_Type {
        JSON_INT,
        JSON_FLOAT,
        JSON_STRING,
        JSON_NULL,
        JSON_BOOL,
        JSON_LIST,
        JSON_OBJECT
    };
    JSON_Type type;
    union jsonval {
        int integer;
        float decimal;
        string* text;
        void* null;
        bool boolean;
        vector<JSON_Data*>* list;
        unordered_map<string,void*>* object;
    };
    jsonval value;
};

#endif