#include "parser.hpp"
#include <cstdint>

struct data_packet_t {
  short ax, ay, az;   // 6 bytes
  short gx, gy, gz;   // 6 bytes
  short mx, my, mz;   // 6 bytes
  short temperature;  // 2 bytes
  short battery;      // 2 bytes
  short airPressure;  // 2 bytes //total size:24 bytes
};


struct sensor_property {
  std::uint16_t dataRate;
  std::uint8_t accFsr;
  std::uint16_t gyroFsr;
  std::uint16_t dataRate;
  float magXcoef, magYcoef, magZcoef;
  std::uint8_t lpf;
};

void init_parser(void *data) {}
void parse(void *data) {}
