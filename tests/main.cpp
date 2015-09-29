//
//  main.cpp
//  JSON
//
//  Created by Sergey Rump on 23.09.2015.
//  Copyright (c) 2015 Motorola Solutions. All rights reserved.
//

#include <iostream>
#include "json.h"
void test(void)
{
    std::string jsonStr="{\"arr\":[1,2,3],\"key\":\"value\",\"obj\":{\"k\":\"v\"},\"bool\":true}";
    std::JSON json(jsonStr);
    std::cout <<json.toString()<<"\n";
    json.parse(json.toString());
    std::cout <<json.toString()<<"\n";
}
int main(int argc, const char * argv[])
{
    //while (true){test();}
    std::string jsonStr="{\"arr\":[1,2,3],\"key\":\"value\",\"obj\":{\"k\":\"v\"},\"bool\":true}";
    std::JSON json(jsonStr);
    std::cout <<json.toString()<<"\n";
    std::JSON obj=json.getJSON("obj");
    obj.set("kk", "vv");
    json.set("obj",obj);
    std::string tmp=json.toString();
    std::JSON temp(json.toString());
    std::cout <<temp.toString()<<"\n";
    std::JSON arr=json.getJSON("arr");
    arr.set(4, 44);
    std::cout <<arr.toString()<<"\n";
    json.set("arr", arr);
    std::cout <<json.toString()<<"\n";
    std::cout<<arr.getString(0)<<"\n";
    std::cout<<arr.getString(1)<<"\n";
    std::cout<<arr.getString(2)<<"\n";
    return 0;
}
