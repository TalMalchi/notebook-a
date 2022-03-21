#include "doctest.h"
#include <iostream>
#include "Direction.hpp"
#include "Notebook.hpp"
using namespace std;
using namespace ariel; 



TEST_CASE("write"){

Notebook notebook_test;

CHECK_THROWS(notebook_test.write(2,3,6,Direction::Horizontal, "hiii"));
CHECK_THROWS(notebook_test.write(4,5,5,Direction::Horizontal, "aa"));
CHECK_THROWS(notebook_test.write(7,7,6,Direction::Horizontal, "home"));
CHECK_THROWS(notebook_test.write(2,5,20,Direction::Horizontal, "hiii"));
CHECK_THROWS(notebook_test.write(9,5,3,Direction::Horizontal, "fun"));
CHECK_THROWS(notebook_test.write(13,7,9,Direction::Vertical, "sky"));
CHECK_THROWS(notebook_test.write(6,8,6,Direction::Vertical, "aaaa"));
CHECK_THROWS(notebook_test.write(2,9,10,Direction::Vertical, "xyz"));
CHECK_THROWS(notebook_test.write(2,5,3,Direction::Vertical, "hiii"));
CHECK_NOTHROW(notebook_test.write(1,0,3,Direction::Vertical, ""));

}


TEST_CASE("read"){
Notebook notebook_test;
CHECK(notebook_test.read(2,3,6,Direction::Horizontal, 0)== "_");
CHECK(notebook_test.read(2,3,6,Direction::Horizontal, 1)== "a");
CHECK(notebook_test.read(2,3,6,Direction::Horizontal, 2)=="__");
CHECK(notebook_test.read(4,5,5,Direction::Horizontal, 2)=="_s");
CHECK(notebook_test.read(7,7,6,Direction::Horizontal, 5)== "hello");
CHECK(notebook_test.read(2,5,20,Direction::Horizontal,6)=="tal___");

}

TEST_CASE("erase"){

Notebook notebook_test;
//read or write string and then erase it 
CHECK(notebook_test.read(2,5,20,Direction::Horizontal,6)=="tal___");
CHECK_THROWS(notebook_test.erase(2,5,20,Direction::Horizontal, 5));
CHECK_THROWS(notebook_test.write(2,5,3,Direction::Vertical, "hiii"));
CHECK_THROWS(notebook_test.erase(2,5,3,Direction::Horizontal, 7));
CHECK_THROWS(notebook_test.erase(4,5,6,Direction::Horizontal, 8));
CHECK_NOTHROW(notebook_test.erase(2,1,3,Direction::Horizontal, -1));
CHECK_NOTHROW(notebook_test.erase(9,5,3,Direction::Horizontal, 0));
}