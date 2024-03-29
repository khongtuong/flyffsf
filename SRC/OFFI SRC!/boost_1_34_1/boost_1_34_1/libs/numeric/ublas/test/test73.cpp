//
//  Copyright (c) 2000-2002
//  Joerg Walter, Mathias Koch
//
//  Permission to use, copy, modify, distribute and sell this software
//  and its documentation for any purpose is hereby granted without fee,
//  provided that the above copyright notice appear in all copies and
//  that both that copyright notice and this permission notice appear
//  in supporting documentation.  The authors make no representations
//  about the suitability of this software for any purpose.
//  It is provided "as is" without express or implied warranty.
//
//  The authors gratefully acknowledge the support of
//  GeNeSys mbH & Co. KG in producing this work.
//

#include "test7.hpp"

// Test matrix expression templates
template<class M, int N>
struct test_my_matrix {
    typedef typename M::value_type value_type;

    template<class MP>
    void test_with (MP &m1, MP &m2, MP &m3) const {
        {
            value_type t;

            // Copy and swap
            initialize_matrix (m1);
            initialize_matrix (m2);
            m1 = m2;
            std::cout << "m1 = m2 = " << m1 << std::endl;
            m1.assign_temporary (m2);
            std::cout << "m1.assign_temporary (m2) = " << m1 << std::endl;
            m1.swap (m2);
            std::cout << "m1.swap (m2) = " << m1 << " " << m2 << std::endl;

            // Zero assignment
            m1 = ublas::zero_matrix<> (m1.size (), m1.size2 ());
            std::cout << "m1.zero_matrix = " << m1 << std::endl;
            m1 = m2;

            // Unary matrix operations resulting in a matrix
            initialize_matrix (m1);
            m2 = - m1;
            std::cout << "- m1 = " << m2 << std::endl;
            m2 = ublas::conj (m1);
            std::cout << "conj (m1) = " << m2 << std::endl;

            // Binary matrix operations resulting in a matrix
            initialize_matrix (m1);
            initialize_matrix (m2);
            m3 = m1 + m2;
            std::cout << "m1 + m2 = " << m3 << std::endl;
            m3 = m1 - m2;
            std::cout << "m1 - m2 = " << m3 << std::endl;

            // Scaling a matrix
            t = N;
            initialize_matrix (m1);
            m2 = value_type (1.) * m1;
            std::cout << "1. * m1 = " << m2 << std::endl;
            m2 = t * m1;
            std::cout << "N * m1 = " << m2 << std::endl;
            initialize_matrix (m1);
            m2 = m1 * value_type (1.);
            std::cout << "m1 * 1. = " << m2 << std::endl;
            m2 = m1 * t;
            std::cout << "m1 * N = " << m2 << std::endl;

            // Some assignments
            initialize_matrix (m1);
            initialize_matrix (m2);
            m2 += m1;
            std::cout << "m2 += m1 = " << m2 << std::endl;
            m2 -= m1;
            std::cout << "m2 -= m1 = " << m2 << std::endl;
            m2 = m2 + m1;
            std::cout << "m2 = m2 + m1 = " << m2 << std::endl;
            m2 = m2 - m1;
            std::cout << "m2 = m1 - m1 = " << m2 << std::endl;
            m1 *= value_type (1.);
            std::cout << "m1 *= 1. = " << m1 << std::endl;
            m1 *= t;
            std::cout << "m1 *= N = " << m1 << std::endl;

            // Transpose
            initialize_matrix (m1);
            m2 = ublas::trans (m1);
            std::cout << "trans (m1) = " << m2 << std::endl;

            // Hermitean
            initialize_matrix (m1);
            m2 = ublas::herm (m1);
            std::cout << "herm (m1) = " << m2 << std::endl;

            // Matrix multiplication
            initialize_matrix (m1);
            initialize_matrix (m2);
            m3 = ublas::prod (m1, m2);
            std::cout << "prod (m1, m2) = " << m3 << std::endl;
        }
    }
    void operator () () const {
        {
            M m1 (N, N), m2 (N, N), m3 (N, N);
            test_with (m1, m2, m3);

#ifdef USE_RANGE
            ublas::matrix_range<M> mr1 (m1, ublas::range (0, N), ublas::range (0, N)),
                                   mr2 (m2, ublas::range (0, N), ublas::range (0, N)),
                                   mr3 (m3, ublas::range (0, N), ublas::range (0, N));
            test_with (mr1, mr2, mr3);
#endif

#ifdef USE_SLICE
            ublas::matrix_slice<M> ms1 (m1, ublas::slice (0, 1, N), ublas::slice (0, 1, N)),
                                   ms2 (m2, ublas::slice (0, 1, N), ublas::slice (0, 1, N)),
                                   ms3 (m3, ublas::slice (0, 1, N), ublas::slice (0, 1, N));
            test_with (ms1, ms2, ms3);
#endif
        }
    }
};

// Test matrix
void test_matrix () {
    std::cout << "test_matrix" << std::endl;

#ifdef USE_MATRIX
#ifdef USE_BOUNDED_ARRAY
#ifdef USE_FLOAT
    std::cout << "boost::numeric::interval<float>, bounded_array" << std::endl;
    test_my_matrix<ublas::matrix<boost::numeric::interval<float>, ublas::row_major, ublas::bounded_array<boost::numeric::interval<float>, 3 * 3> >, 3 > () ();
#endif

#ifdef USE_DOUBLE
    std::cout << "boost::numeric::interval<double>, bounded_array" << std::endl;
    test_my_matrix<ublas::matrix<boost::numeric::interval<double>, ublas::row_major, ublas::bounded_array<boost::numeric::interval<double>, 3 * 3> >, 3 > () ();
#endif
#endif

#ifdef USE_UNBOUNDED_ARRAY
#ifdef USE_FLOAT
    std::cout << "boost::numeric::interval<float>, unbounded_array" << std::endl;
    test_my_matrix<ublas::matrix<boost::numeric::interval<float>, ublas::row_major, ublas::unbounded_array<boost::numeric::interval<float> > >, 3 > () ();
#endif

#ifdef USE_DOUBLE
    std::cout << "boost::numeric::interval<double>, unbounded_array" << std::endl;
    test_my_matrix<ublas::matrix<boost::numeric::interval<double>, ublas::row_major, ublas::unbounded_array<boost::numeric::interval<double> > >, 3 > () ();
#endif
#endif

#ifdef USE_STD_VECTOR
#ifdef USE_FLOAT
    std::cout << "boost::numeric::interval<float>, std::vector" << std::endl;
    test_my_matrix<ublas::matrix<boost::numeric::interval<float>, ublas::row_major, std::vector<boost::numeric::interval<float> > >, 3 > () ();
#endif

#ifdef USE_DOUBLE
    std::cout << "boost::numeric::interval<double>, std::vector" << std::endl;
    test_my_matrix<ublas::matrix<boost::numeric::interval<double>, ublas::row_major, std::vector<boost::numeric::interval<double> > >, 3 > () ();
#endif
#endif
#endif

#ifdef USE_VECTOR_OF_VECTOR
#ifdef USE_BOUNDED_ARRAY
#ifdef USE_FLOAT
    std::cout << "boost::numeric::interval<float>, bounded_array" << std::endl;
    test_my_matrix<ublas::vector_of_vector<boost::numeric::interval<float>, ublas::row_major, ublas::bounded_array<ublas::bounded_array<boost::numeric::interval<float>, 3>, 3 + 1> >, 3 > () ();
#endif

#ifdef USE_DOUBLE
    std::cout << "boost::numeric::interval<double>, bounded_array" << std::endl;
    test_my_matrix<ublas::vector_of_vector<boost::numeric::interval<double>, ublas::row_major, ublas::bounded_array<ublas::bounded_array<boost::numeric::interval<double>, 3>, 3 + 1> >, 3 > () ();
#endif
#endif

#ifdef USE_UNBOUNDED_ARRAY
#ifdef USE_FLOAT
    std::cout << "boost::numeric::interval<float>, unbounded_array" << std::endl;
    test_my_matrix<ublas::vector_of_vector<boost::numeric::interval<float>, ublas::row_major, ublas::unbounded_array<ublas::unbounded_array<boost::numeric::interval<float> > > >, 3 > () ();
#endif

#ifdef USE_DOUBLE
    std::cout << "boost::numeric::interval<double>, unbounded_array" << std::endl;
    test_my_matrix<ublas::vector_of_vector<boost::numeric::interval<double>, ublas::row_major, ublas::unbounded_array<ublas::unbounded_array<boost::numeric::interval<double> > > >, 3 > () ();
#endif
#endif

#ifdef USE_STD_VECTOR
#ifdef USE_FLOAT
    std::cout << "boost::numeric::interval<float>, std::vector" << std::endl;
    test_my_matrix<ublas::vector_of_vector<boost::numeric::interval<float>, ublas::row_major, std::vector<std::vector<boost::numeric::interval<float> > > >, 3 > () ();
#endif

#ifdef USE_DOUBLE
    std::cout << "boost::numeric::interval<double>, std::vector" << std::endl;
    test_my_matrix<ublas::vector_of_vector<boost::numeric::interval<double>, ublas::row_major, std::vector<std::vector<boost::numeric::interval<double> > > >, 3 > () ();
#endif
#endif
#endif
}
