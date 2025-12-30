#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/regex.hpp>

#include "lib.h"

int main()
{
    using namespace boost::lambda;

    std::cout << "Version: " << version() << std::endl;
    std::cout << "Hello, world!" << std::endl; 

    std::string line = "Hello World";
    boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

    boost::smatch matches;
    if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    else  std::cout << "Not match" << std::endl;


}