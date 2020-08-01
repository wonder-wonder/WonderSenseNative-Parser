#ifndef TEST_IMPL_HPP_5ROYLW39
#define TEST_IMPL_HPP_5ROYLW39

#include <gtest/gtest.h>

#include "../parser.hpp"

class ParserTest : public ::testing::Test
{
private:
protected:
  ParserTest();
  virtual ~ParserTest();

  SensorProperty property;
  data_packet_t test_data[c_packet_size];
  char test_byteArray_data[c_data_size];
};

#endif /* end of include guard: TEST_IMPL_HPP_5ROYLW39 */
