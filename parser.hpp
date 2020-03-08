#ifndef PARSER_HEADER
#define PARSER_HEADER

#include <cstdint>
#include <string>

struct sensor_data {
  double ax, ay, az;
  double gx, gy, gz;
  double mx, my, mz;
  double temperature;
  double battery;
  double airPressure;
};


struct sensor_property {
  std::uint16_t dataRate;
  std::uint8_t accFsr;
  std::uint16_t gyroFsr;
  float magXcoef, magYcoef, magZcoef;
  std::uint8_t lpf;
};


struct sensor_devInfo {
  std::string manufacturer;
  std::string hardware;
  std::string firmware;
  std::string address;
};


extern void init_parser(void *data);
extern sensor_data *parse(void *data);

#endif /* end of include guard: PARSER_HEADER */
