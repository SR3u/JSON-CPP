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
using namespace std;

JSON::JSON(const string& jsonStr):container(){parse(jsonStr);}
JSON::JSON(const char* jsonStr):container(){parse(jsonStr);}
JSON::~JSON(){clear();}

void JSON::parse(const string& jsonStr)
{
    clear();
    container=new json_container();
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
                    if(idx>1){(*container)[key]=value;}
                }
                else{
                    value=tokValue;
                    if(idx>1){(*container)[key]=value;}
                }
                break;
        }
        idx++;
    }
    
}
void JSON::clear(){if(container!=NULL){delete container;container=NULL;}}

string JSON::toString()
{
    stringstream ss;
    ss<<"{";
    for(auto it = container->cbegin(); it != container->cend(); ++it)
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
    string res;
    ss>>res;
    return res;
}
/*
string JSON::getString(const string& key);
bool JSON::getBool(const string& key);
int JSON::getInt(const string& key);
long JSON::getLong(const string& key);
float JSON::getFloat(const string& key);
double JSON::getDouble(const string& key);

string JSON::getString(size_t idx);
bool JSON::getBool(size_t idx);
int JSON::getInt(size_t idx);
long JSON::getLong(size_t idx);
float JSON::getFloat(size_t idx);
double JSON::getDouble(size_t idx);

//*/