//  This file was automatically generated on Sat Apr 02 11:49:12 2005
//  by libs/config/tools/generate.cpp
//  Copyright John Maddock 2002-4.
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/config for the most recent version.

// Test file for macro BOOST_HAS_TR1_ARRAY
// This file should compile, if it does not then
// BOOST_HAS_TR1_ARRAY should not be defined.
// See file boost_has_tr1_regex.ipp for details

// Must not have BOOST_ASSERT_CONFIG set; it defeats
// the objective of this file:
#ifdef BOOST_ASSERT_CONFIG
#  undef BOOST_ASSERT_CONFIG
#endif

#include <boost/config.hpp>
#include "test.hpp"

#ifdef BOOST_HAS_TR1_ARRAY
#include "boost_has_tr1_regex.ipp"
#else
namespace boost_has_tr1_array = empty_boost;
#endif

int main( int, char *[] )
{
   return boost_has_tr1_array::test();
}

