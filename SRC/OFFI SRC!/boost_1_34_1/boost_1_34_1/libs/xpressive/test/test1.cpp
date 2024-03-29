///////////////////////////////////////////////////////////////////////////////
// test1.cpp
//
//  Copyright 2004 Eric Niebler. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <algorithm>
#include "./test1.hpp"

///////////////////////////////////////////////////////////////////////////////
// test_main
//   read the tests from the input file and execute them
int test_main( int, char*[] )
{
    typedef std::string::const_iterator iterator_type;
    boost::iterator_range<test_case<iterator_type> const *> rng = get_test_cases<iterator_type>();
    std::for_each(rng.begin(), rng.end(), test_runner<iterator_type>());

    return 0;
}
