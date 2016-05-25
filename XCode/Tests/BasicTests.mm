//
//  BasicTests.m
//  json-cpp
//
//  Created by Sergey Rump (SPHERE) on 25.05.2016.
//  Copyright © 2016 sr3u. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XCTest/XCTest.h>
#include "json.h"
#include <string>
using namespace std;

@interface BasicTests : XCTestCase

@end

@implementation BasicTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testBasicParsing
{
    std::string jsonStr="{\"arr\":[1,2,3],\"key\":\"value\",\"obj\":{\"k\":\"v\"},\"bool\":true}";
    std::JSON json(jsonStr);
    XCTAssert(json.getJSON("arr").getInt(1) == 2,"json['arr'][1] != 2");
    XCTAssert(json.getJSON("obj").getString("k") == "v","json['obj']['k'] != 'v'");
    XCTAssert(json.getBool("bool"),"json['bool'] != true");
}

@end