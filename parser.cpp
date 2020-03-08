#include "parser.hpp"
#include <cstdint>

// define
struct data_packet_t {
  short ax, ay, az;   // 6 bytes
  short gx, gy, gz;   // 6 bytes
  short mx, my, mz;   // 6 bytes
  short temperature;  // 2 bytes
  short battery;      // 2 bytes
  short airPressure;  // 2 bytes //total size:24 bytes
};


// values
sensor_property m_property;


// functions
void init_parser(void *data)
{
  m_property = *(sensor_property *)data;
}


constexpr int packet_size = 4;
void parse(void *data)
{
  data_packet_t *data_packets;
  data_packets = (data_packet_t *)malloc(sizeof(data) * 4);
  data_packets = (data_packet_t *)data;

  sensor_data ret[packet_size];
  for (int i = 0; i < packet_size; ++i) {
    ret[i].ax = (data_packets[i].ax * m_property.accFsr / 32768.0);
    ret[i].ay = (data_packets[i].ay * m_property.accFsr / 32768.0);
    ret[i].az = (data_packets[i].az * m_property.accFsr / 32768.0);

    ret[i].gx = (data_packets[i].gx * m_property.gyroFsr / 32768.0);
    ret[i].gy = (data_packets[i].gy * m_property.gyroFsr / 32768.0);
    ret[i].gz = (data_packets[i].gz * m_property.gyroFsr / 32768.0);

    ret[i].mx = (data_packets[i].mx * 0.15 * m_property.magXcoef);
    ret[i].my = (data_packets[i].my * 0.15 * m_property.magYcoef);
    ret[i].mz = (data_packets[i].mz * 0.15 * m_property.magZcoef);

    ret[i].battery     = data_packets[i].battery / 4096.0 * 3.3 * 4.9;
    ret[i].airPressure = data_packets[i].airPressure / 4096.0 * 3.3;
    ret[i].temperature = data_packets[i].temperature / 333.87 + 21.0;
  }
}
