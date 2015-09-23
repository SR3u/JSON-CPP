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
        JSON getJSON(const string& key);
        bool getBool(const string& key);
        int getInt(const string& key);
        long getLong(const string& key);
        float getFloat(const string& key);
        double getDouble(const string& key);
        
        string getString(const size_t& idx);
        JSON getJSON(const size_t& idx);
        bool getBool(const size_t& idx);
        int getInt(const size_t& idx);
        long getLong(const size_t& idx);
        float getFloat(const size_t& idx);
        double getDouble(const size_t& idx);
        
        void set(const string& key,const string& val);
        void set(const string& key,const JSON& val);
        void set(const string& key,const bool& val);
        void set(const string& key,const int& val);
        void set(const string& key,const long& val);
        void set(const string& key,const float& val);
        void set(const string& key,const double& val);
        
        void set(const size_t& idx,const string& val);
        void set(const size_t& idx,const JSON& val);
        void set(const size_t& idx,const bool& val);
        void set(const size_t& idx,const int& val);
        void set(const size_t& idx,const long& val);
        void set(const size_t& idx,const float& val);
        void set(const size_t& idx,const double& val);
        
        string toString()const;
    };
    std::string to_string(const JSON& json);
}
#endif
