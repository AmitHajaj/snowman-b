/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Amit Hajaj
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;
/*
    Here I decided to make every "organ" of the snowman in constant value.
*/
// Head option's.
const string H1 =  "\n _===_ \n";
const string H2 =  "\n  ___  \n ..... \n";
const string H3 =  "\n   _   \n  /_\\  \n";
const string H4 =  "\n  ___  \n (_*_) \n";

//Nose option's.
const string N1 = ",";
const string N2 = ".";
const string N3 = "_";
const string N4 = " ";

//Left eye option's.
const string L1 = ".";
const string L2 = "o";
const string L3 = "O";
const string L4 = "-";

//Top\Bottom left hand option's.
const string X1T = " ";
const string X1B = "<";
const string X2T = "\\";
const string X2B = " ";
const string X3T = " ";
const string X3B = "/";
const string X4T = " ";
const string X4B = " ";

//Top\Bottom right hand option's.
const string Y1T = " \n";
const string Y1B = ">\n";
const string Y2T = "/\n";
const string Y2B = " \n";
const string Y3T = " \n";
const string Y3B = "\\\n";
const string Y4T = " \n";
const string Y4B = " \n";

//Torso option's.
const string T1 = "( : )";
const string T2 = "(] [)";
const string T3 = "(> <)";
const string T4 = "(   )";

//Base option's.
const string B1 = " ( : )";
const string B2 = " (\" \")";
const string B3 = " (___)";
const string B4 = " (   )";


// --------GOOD CASES!!!--------//
TEST_CASE("Good snowman code") {
    //Arbitrary good test cases.
    CHECK(snowman(11114411) == string(H1 + X4T + "(" + L1 + N1 + L1 + ")" + Y4T + X4B + T1 + Y4B + B1));
    CHECK(snowman(12341234) == string(H1 + X1T + "(" + L3 + N2 + L4 + ")" + Y2T + X1B + T3 + Y2B + B4));
    CHECK(snowman(11111111) == string(H1 + X1T + "(" + L1 + N1 + L1 + ")" + Y1T + X1B + T1 + Y1B + B1));
    CHECK(snowman(12121212) == string(H1 + X1T + "(" + L1 + N2 + L2 + ")" + Y2T + X1B + T1 + Y2B + B2));
    CHECK(snowman(13242413) == string(H1 + X2T + "(" + L2 + N3 + L4 + ")" + Y4T + X2B + T1 + Y4B + B3));
    CHECK(snowman(41321423) == string(H4 + X1T + "(" + L3 + N1 + L2 + ")" + Y4T + X1B + T2 + Y4B + B3));
    CHECK(snowman(33232124) == string(H3 + X2T + "(" + L2 + N3 + L3 + ")" + Y1T + X2B + T2 + Y1B + B4));
    CHECK(snowman(44444444) == string(H4 + X4T + "(" + L4 + N4 + L4 + ")" + Y4T + X4B + T4 + Y4B + B4));
    CHECK(snowman(44441111) == string(H4 + X1T + "(" + L4 + N4 + L4 + ")" + Y1T + X1B + T1 + Y1B + B1));
    CHECK(snowman(22223333) == string(H2 + X3T + "(" + L2 + N2 + L2 + ")" + Y3T + X3B + T3 + Y3B + B3));
}

// --------BAD CASES!!!--------//
TEST_CASE("Bad snowman code-> Less letter's then needed.") {
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(12));
    CHECK_THROWS(snowman(123));
    CHECK_THROWS(snowman(1234));
    CHECK_THROWS(snowman(12345));
    CHECK_THROWS(snowman(123456));
    CHECK_THROWS(snowman(1234567));
}
TEST_CASE("Bad snowman code-> More letter's then needed."){
    CHECK_THROWS(snowman(123234444));
    CHECK_THROWS(snowman(1234567890));
    CHECK_THROWS(snowman(111111111));
}
TEST_CASE("Bad snowman code-> 8 digit's, but not in range."){
    CHECK_THROWS(snowman(123456789));
    CHECK_THROWS(snowman(12341239));
    CHECK_THROWS(snowman(99999999));
}

TEST_CASE("Bad snowman code-> 8 digit's, but one(we check each space) is not in range."){
    CHECK_THROWS(snowman(12341235));
    CHECK_THROWS(snowman(12341254));
    CHECK_THROWS(snowman(12341534));
    CHECK_THROWS(snowman(12345234));
    CHECK_THROWS(snowman(12351234));
    CHECK_THROWS(snowman(12541234));
    CHECK_THROWS(snowman(15341234));
    CHECK_THROWS(snowman(52341234));
}


TEST_CASE("Bad snowman code-> 8 digit's, in range, but negative value."){
    CHECK_THROWS(snowman(-11111111));
    CHECK_THROWS(snowman(-12341234));
    CHECK_THROWS(snowman(-43214321));
}
TEST_CASE("Bad snowman code-> First 8 digit's are good, but there is one more."){
        CHECK_THROWS(snowman(432143219));
}

