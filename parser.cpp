#include "parser.hpp"

constexpr int INT12_MAX = 4096;

static double accParser(std::int16_t, std::uint8_t);
static double gyroParser(std::int16_t, std::uint8_t);

Parser::Parser(const SensorProperty &property)
{
  mProperty = property;
}


Parser::~Parser() {}


void Parser::setProperty(const SensorProperty &property)
{
  mProperty = property;
}


const std::array<SensorData, c_packet_size> Parser::parse(
    std::uint8_t data[c_data_size])
{
  data_packet_t *data_packets;
  data_packets = reinterpret_cast<data_packet_t *>(data);

  std::array<SensorData, c_packet_size> ret;
  for (int i = 0; i < c_packet_size; ++i) {
    ret[i].ax = accParser(data_packets[i].ax, mProperty.accFsr);
    ret[i].ay = accParser(data_packets[i].ay, mProperty.accFsr);
    ret[i].az = accParser(data_packets[i].az, mProperty.accFsr);

    ret[i].gx = gyroParser(data_packets[i].gx, mProperty.gyroFsr);
    ret[i].gy = gyroParser(data_packets[i].gy, mProperty.gyroFsr);
    ret[i].gz = gyroParser(data_packets[i].gz, mProperty.gyroFsr);

    ret[i].mx = ((data_packets[i].mx * 0.15) * mProperty.magXcoef);
    ret[i].my = ((data_packets[i].my * 0.15) * mProperty.magYcoef);
    ret[i].mz = ((data_packets[i].mz * 0.15) * mProperty.magZcoef);

    ret[i].battery =
        (data_packets[i].battery * 3.3 * 4.9) / static_cast<double>(INT12_MAX);

    ret[i].airPressure =
        (data_packets[i].airPressure * 3.3) / static_cast<double>(INT12_MAX);

    ret[i].temperature = data_packets[i].temperature / 333.87 + 21.0;
  }

  return ret;
}

static double accParser(std::int16_t value, std::uint8_t coef)
{
  // NOTE: the divisor is int16_max. but origin code use int16_max + 1.
  std::int32_t tmp = static_cast<std::int32_t>(value) * coef;
  return static_cast<double>(static_cast<double>(tmp)
                             / static_cast<double>(INT16_MAX));
}

static double gyroParser(std::int16_t value, std::uint8_t coef)
{
  // NOTE: the divisor is int16_max. but origin code use int16_max + 1.
  std::int32_t tmp = static_cast<std::int32_t>(value) * coef;
  return static_cast<double>(static_cast<double>(tmp)
                             / static_cast<double>(INT16_MAX));
}
