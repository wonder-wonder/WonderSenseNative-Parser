#include "parser.hpp"

constexpr int INT12_MAX = 4096;


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
    ret[i].ax = (static_cast<double>(data_packets[i].ax * mProperty.accFsr)
                 / static_cast<double>(INT16_MAX + 1));

    ret[i].ay = (static_cast<double>(data_packets[i].ay * mProperty.accFsr)
                 / static_cast<double>(INT16_MAX + 1));

    ret[i].az = (static_cast<double>(data_packets[i].az * mProperty.accFsr)
                 / static_cast<double>(INT16_MAX + 1));

    ret[i].gx = (static_cast<double>(data_packets[i].gx * mProperty.gyroFsr)
                 / static_cast<double>(INT16_MAX + 1));

    ret[i].gy = (static_cast<double>(data_packets[i].gy * mProperty.gyroFsr)
                 / static_cast<double>(INT16_MAX + 1));

    ret[i].gz = (static_cast<double>(data_packets[i].gz * mProperty.gyroFsr)
                 / static_cast<double>(INT16_MAX + 1));

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
