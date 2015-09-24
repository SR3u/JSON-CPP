//
//  json.cpp
//  JSON
//
//  Created by Sergey Rump on 23.09.2015.
//  Copyright (c) 2015 Motorola Solutions. All rights reserved.
//

#include "json.h"
#include "jsmn/jsmn.h"
#include <sstream>
#include <algorithm>
using namespace std;

JSON::JSON(const string& jsonStr):container(){parse(jsonStr);}
JSON::JSON(const char* jsonStr):container(){parse(jsonStr);}
JSON::~JSON(){clear();}

void JSON::parse(const string& jsonStr)
{
    array=false;
    clear();
    int count=JSMN_ERROR_NOMEM;
    const char *js=jsonStr.c_str();
    int curCount=baseMaxTokens;
    jsmntok_t *tokens=NULL;
    jsmn_parser p;
    while(count==JSMN_ERROR_NOMEM)
    {
        if(tokens!=NULL){free(tokens);}
        tokens=(jsmntok_t*)malloc(curCount*sizeof(jsmntok_t));
        jsmn_init(&p);
        count = jsmn_parse(&p, js, strlen(js), tokens, curCount);
        if(count==JSMN_ERROR_NOMEM){curCount*=2;continue;}
    }
    switch(tokens[0].type)
    {
        case JSMN_OBJECT:
            parseObject(count, (void*)tokens, js);
            break;
        case JSMN_ARRAY:
            parseArray(count, (void*)tokens, js);
            break;
        default: break;
    }
    free(tokens);
}
void JSON::parseObject(int count,void *jsmn_tokens,const char*js)
{
    array=false;
    jsmntok_t *tokens=(jsmntok_t*)jsmn_tokens;
    string key,value;
    int idx=1;
    for (int i = 1; i<count; i++)
    {
        jsmntok_t token=tokens[i];
        switch (tokens[i].type)
        {
            case JSMN_ARRAY:
            case JSMN_OBJECT:
                while(tokens[i].end<=token.end){i++;}
                i--;
            default:
                char *buf=(char*)malloc(sizeof(char)*(token.size+1));
                sprintf(buf,"%.*s", token.end - token.start, js + token.start);
                string tokValue(buf);
                free(buf);
                if(idx%2==1){
                    key=tokValue;
                    if(idx>1){container[key]=value;}
                }
                else{
                    value=tokValue;
                    if(idx>1){container[key]=value;}
                }
                break;
        }
        idx++;
    }
}
void JSON::parseArray(int count,void *jsmn_tokens,const char*js)
{
    array=true;
    jsmntok_t *tokens=(jsmntok_t*)jsmn_tokens;
    int idx=1;
    for (int i = 1; i<count; i++)
    {
        jsmntok_t token=tokens[i];
        switch (tokens[i].type)
        {
            case JSMN_ARRAY:
            case JSMN_OBJECT:
                while(tokens[i].end<=token.end){i++;}
                i--;
            default:
                char *buf=(char*)malloc(sizeof(char)*(token.size+1));
                sprintf(buf,"%.*s", token.end - token.start, js + token.start);
                string tokValue(buf);
                free(buf);
                container[to_string(idx)]=tokValue;
                break;
        }
        idx++;
    }
}
void JSON::clear(){container.clear();array=false;}

string JSON::toString()const
{
    stringstream ss;
    if(array){
        ss<<"[";
        for(auto it = container.cbegin(); it != container.cend(); ++it)
        {
            const string &value=it->second;
            switch (value[0]) {
                case '[':
                case '{':
                    ss <<'"'<<value << ",";
                    break;
                default:
                    ss <<'"'<< value << "\",";
                    break;
            }
        }
        ss<<"]";
    }
    else{
        ss<<"{";
        for(auto it = container.cbegin(); it != container.cend(); ++it)
        {
            const string &key=it->first;
            const string &value=it->second;
            switch (value[0]) {
                case '[':
                case '{':
                    ss <<'"'<< key<<"\":" << value << ",";
                    break;
                default:
                    ss <<'"'<< key<<"\":\"" << value << "\",";
                    break;
            }
        }
        ss<<"}";
    }
    return ss.str();
}
string to_string(const JSON& json)
{
    return json.toString();
}
string JSON::getString(const string& key)
{
    return container[key];
}
JSON JSON::getJSON(const string& key)
{
    JSON json(getString(key));
    return json;
}
bool JSON::getBool(const string& key)
{
    try {
    int i=getInt(key);
    if(i!=0){return true;}
    }
    catch (const invalid_argument&e){}
    string str=getString(key);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str=="true";
}
int JSON::getInt(const string& key){return stoi(getString(key));}
long JSON::getLong(const string& key){return stol(getString(key));}
float JSON::getFloat(const string& key){return stof(getString(key));}
double JSON::getDouble(const string& key){return stod(getString(key));}

string JSON::getString(const size_t& idx){return getString(to_string(idx));}
JSON JSON::getJSON(const size_t& idx){return getJSON(to_string(idx));}
bool JSON::getBool(const size_t& idx){return getBool(to_string(idx));}
int JSON::getInt(const size_t& idx){return stoi(getString(idx));}
long JSON::getLong(const size_t& idx){return getLong(to_string(idx));}
float JSON::getFloat(const size_t& idx){return getFloat(to_string(idx));}
double JSON::getDouble(const size_t& idx){return getDouble(to_string(idx));}


void JSON::set(const string& key,const string& val)
{
    container[key]=val;
}
void JSON::set(const string& key,const char* val)
{
    set(key, string(val));
}
void JSON::set(const string& key,const JSON& val)
{
    set(key,val.toString());
}
void JSON::set(const string& key,const bool& val)
{
    stringstream tmp;
    tmp<<boolalpha<<val;
    set(key,tmp.str());
}
void JSON::set(const string& key,const int& val){set(key,to_string(val));}
void JSON::set(const string& key,const long& val){set(key,to_string(val));}
void JSON::set(const string& key,const float& val){set(key,to_string(val));}
void JSON::set(const string& key,const double& val){set(key,to_string(val));}

void JSON::set(const size_t& idx,const string& val){set(to_string(idx),val);}
void JSON::set(const size_t& idx,const char* val){set(to_string(idx),string(val));}
void JSON::set(const size_t& idx,const JSON& val){set(idx,val.toString());}
void JSON::set(const size_t& idx,const bool& val)
{
    stringstream tmp;
    tmp<<boolalpha<<val;
    set(idx,tmp.str());
}
void JSON::set(const size_t& idx,const int& val){set(idx,to_string(val));}
void JSON::set(const size_t& idx,const long& val){set(idx,to_string(val));}
void JSON::set(const size_t& idx,const float& val){set(idx,to_string(val));}
void JSON::set(const size_t& idx,const double& val){set(idx,to_string(val));}