//
//  json.h
//  JSON
//
//  Created by Sergey Rump on 23.09.2015.
//  Copyright (c) 2015 SR3u. All rights reserved.
//
#ifndef JSON_json_h
#define JSON_json_h
#include <string>
#include <map>
namespace std
{
    typedef map<string,string> json_container;
    class JSON
    {
    private:
        json_container container;
        static const int baseMaxTokens=16;//basic max tokens number for jsmn
        void parseObject(int count,void *jsmn_tokens,const char*js);
        void parseArray(int count,void *jsmn_tokens,const char*js);
        bool array;
    public:
        static JSON createArray();
        static JSON createObject();
        
        JSON(const string& jsonStr);
        JSON(const char* jsonStr="{}");
        JSON(const JSON& json);
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
        
        size_t size();
        
        void set(const string& key,const string& val);
        void set(const string& key,const char* val);
        void set(const string& key,const JSON& val);
        void set(const string& key,const bool& val);
        void set(const string& key,const int& val);
        void set(const string& key,const long& val);
        void set(const string& key,const float& val);
        void set(const string& key,const double& val);
        
        void set(const size_t& idx,const string& val);
        void set(const size_t& idx,const char* val);
        void set(const size_t& idx,const JSON& val);
        void set(const size_t& idx,const bool& val);
        void set(const size_t& idx,const int& val);
        void set(const size_t& idx,const long& val);
        void set(const size_t& idx,const float& val);
        void set(const size_t& idx,const double& val);
        
        template <typename T>
        static JSON create(const string& key,const T& val)
        {
            JSON json = JSON::createObject();
            json.set(key, val);
            return json;
        }
        
        template <typename T>
        JSON& append(const string& key,const T& val)
        {
            set(key, val);
            return *this;
        }
        template <typename T>
        JSON& append(const size_t& idx,const T& val)
        {
            set(idx, val);
            return *this;
        }
        string toString()const;
    };
    std::string to_string(const JSON& json);
    
}
#endif
