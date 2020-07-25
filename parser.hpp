#ifndef PARSER_HEADER
#define PARSER_HEADER

#include <array>
#include <cstdint>

struct data_packet_t;

struct SensorData {
  double ax, ay, az;
  double gx, gy, gz;
  double mx, my, mz;
  double temperature;
  double battery;
  double airPressure;
};

struct data_packet_t {
  std::int16_t ax, ay, az;   // 6 bytes
  std::int16_t gx, gy, gz;   // 6 bytes
  std::int16_t mx, my, mz;   // 6 bytes
  std::int16_t temperature;  // 2 bytes
  std::int16_t battery;      // 2 bytes
  std::int16_t airPressure;  // 2 bytes //total size:24 bytes
};


struct SensorProperty {
  std::uint8_t accFsr;
  std::uint16_t gyroFsr;
  float magXcoef, magYcoef, magZcoef;
};

constexpr int c_packet_size = 4;
constexpr int c_data_size   = sizeof(data_packet_t) * c_packet_size;

class Parser
{
private:
  SensorProperty mProperty;

public:
  Parser(const SensorProperty &);
  ~Parser();

  const std::array<SensorData, c_packet_size> parse(
      std::uint8_t data[c_data_size]);
};


#endif /* end of include guard: PARSER_HEADER */
