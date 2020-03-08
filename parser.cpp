#include "parser.hpp"

struct data_packet_t {
  short ax, ay, az;      // 6 bytes
  short gx, gy, gz;      // 6 bytes
  short mx, my, mz;      // 6 bytes
  short temperature;     // 2 bytes
  short battery;         // 2 bytes
  short pressSensorVol;  // 2 bytes //total size:24 bytes
};

void parse(void *data) {}
