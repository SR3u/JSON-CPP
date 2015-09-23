//
//  main.cpp
//  JSON
//
//  Created by Sergey Rump on 23.09.2015.
//  Copyright (c) 2015 Motorola Solutions. All rights reserved.
//

#include <iostream>
#include "json.h"
int main(int argc, const char * argv[])
{
    std::string jsonStr="{\"arr\":[1,2,3],\"key\":\"value\",\"obj\":{\"k\":\"v\"},}";
    //"{\"key\":\"value\",\"obj\":{\"k\":\"v\"},\"arr\":[1,2,3]}";
    std::JSON json(jsonStr);
    std::cout <<json.toString()<<"\n";
    json.parse(json.toString());
    std::cout <<json.toString()<<"\n";
    return 0;
}
