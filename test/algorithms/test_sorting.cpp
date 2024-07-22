#include <boost/test/included/unit_test.hpp>

#include "../../src/algorithms/sorting/bubble_sort.h"

BOOST_AUTO_TEST_SUITE( test_search )

BOOST_AUTO_TEST_CASE( test_bubble_sort ) {
  int32_t A[] = {5, 2, 4, 6, 1, 3};
  int32_t exp_array[] = {1, 2, 3, 4, 5, 6};
  int32_t obs, exp;
  uint8_t len = 6;

  bubble_sort(A, len);
  for (uint8_t i; i < len; i++) {
    obs = A[i];
    exp = exp_array[i];
    BOOST_ASSERT(obs == exp);
  }

  int32_t B[] = {31, 41, 59, 26, 41, 58};
  int32_t exp_array2[] = {26, 31, 41, 41, 58, 59};
  bubble_sort(B, len);
  for (uint8_t i; i < len; i++) {
    obs = B[i];
    exp = exp_array2[i];
    BOOST_ASSERT(obs == exp);
  }

  int32_t C[] = {6, 5, 4, 3, 2, 1};
  bubble_sort(C, len);
  for (uint8_t i; i < len; i++) {
    obs = C[i];
    exp = exp_array[i];
    BOOST_ASSERT(obs == exp);
  }

  len = 8;
  int32_t D[] = {5, 2, 4, 7, 1, 3, 2, 6};
  int32_t exp_array3[] = {1, 2, 3, 4, 5, 6, 7};
  bubble_sort(D, len);
  for (uint8_t i; i < len; i++) {
    obs = D[i];
    exp = exp_array3[i];
    BOOST_ASSERT(obs == exp);
  }

  int32_t E[] = {3, 41, 52, 26, 38, 57, 9, 49};
  int32_t exp_array4[] = {3, 9, 26, 38, 41, 49, 52, 57};
  bubble_sort(E, len);
  for (uint8_t i; i < len; i++) {
    obs = E[i];
    exp = exp_array[i];
    BOOST_ASSERT(obs == exp);
  }
}

BOOST_AUTO_TEST_SUITE_END()

