//
//  json.h
//  JSON
//
//  Created by Sergey Rump on 23.09.2015.
//  Copyright (c) 2015 Motorola Solutions. All rights reserved.
//

#ifndef JSON_json_h
#define JSON_json_h
#include "string"
#include "map"

namespace std
{
    typedef map<string,string> json_container;
    class JSON
    {
    private:
        json_container *container;
        static const int baseMaxTokens=16;//basic max tokens number for jsmn
    public:
        JSON(const string& jsonStr);
        JSON(const char* jsonStr);
        ~JSON();
        
        void parse(const string& jsonStr);
        void clear();
        
        string getString(const string& key);
        bool getBool(const string& key);
        int getInt(const string& key);
        long getLong(const string& key);
        float getFloat(const string& key);
        double getDouble(const string& key);
        
        string getString(size_t idx);
        bool getBool(size_t idx);
        int getInt(size_t idx);
        long getLong(size_t idx);
        float getFloat(size_t idx);
        double getDouble(size_t idx);
        
        string toString();
    };
}
#endif
