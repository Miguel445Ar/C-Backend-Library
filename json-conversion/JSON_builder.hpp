#ifndef __JSON_BUILDER_HPP__
#define __JSON_BUILDER_HPP__

#include "JSON_data.hpp"


namespace JSON_Builder {
    JSON_Data* createJsonInteger(const int number) {
        JSON_Data* data = new JSON_Data;
        data->type = JSON_Data::JSON_INT;
        data->value.integer = number;
        return data;
    }
    JSON_Data* createJsonFloat(const float decimal) {
        JSON_Data* data = new JSON_Data;
        data->type = JSON_Data::JSON_FLOAT;
        data->value.decimal = decimal;
        return data;
    }
    JSON_Data* createJsonString(const string& text) {
        JSON_Data* data = new JSON_Data;
        data->type = JSON_Data::JSON_STRING;
        data->value.text = new string(text);
        return data;
    }
    JSON_Data* createJsonNull() {
        JSON_Data* data = new JSON_Data;
        data->type = JSON_Data::JSON_NULL;
        data->value.null = nullptr;
        return data;
    }
    JSON_Data* createJsonBoolean(const bool boolean) {
        JSON_Data* data = new JSON_Data;
        data->type = JSON_Data::JSON_BOOL;
        data->value.boolean = boolean;
        return data;
    }
    JSON_Data* createJsonList() {
        JSON_Data* data = new JSON_Data;
        data->type = JSON_Data::JSON_NULL;
        data->value.list = new vector<JSON_Data*>();
        return data;
    }
    JSON_Data* createJsonObject() {
        JSON_Data* data = new JSON_Data;
        data->type = JSON_Data::JSON_OBJECT;
        data->value.object = new unordered_map<string,void*>();
        return data;
    }
    
}

#endif