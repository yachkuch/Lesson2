#define BOOST_TEST_MODULE test_version

#include <boost/test/unit_test.hpp>
#include "function_for_sort.cpp"
#include "ipAdress.h"
#include <vector>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
     std::vector<ipAdress> vector_adr = {std::string("1.10.1.1"),std::string("1.2.1.1"),std::string("1.1.1.1")};
     std::vector<ipAdress> vector_normal_2 = {std::string("1.1.1.1"),std::string("1.2.1.1"),std::string("1.10.1.1")};
     std::sort(vector_adr.begin(),vector_adr.end());
     BOOST_CHECK(vector_adr==vector_normal_2);
}

BOOST_AUTO_TEST_CASE(test_version2)
{
     std::vector<ipAdress> vector_adr = {std::string("1.10.1.1"),std::string("1.2.1.1"),std::string("1.1.1.1")};
     std::vector<ipAdress> vector_normal_2 = {std::string("1.1.1.1"),std::string("1.2.1.1"),std::string("1.10.1.1")};
     std::sort(vector_adr.begin(),vector_adr.end());
     BOOST_CHECK(vector_adr==vector_normal_2);
}

BOOST_AUTO_TEST_SUITE_END()