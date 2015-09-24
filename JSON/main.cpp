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
    while (true){test();}
    return 0;
}
