#ifndef PARSER_HEADER
#define PARSER_HEADER

struct sensor_data {
  double ax, ay, az;
  double gx, gy, gz;
  double mx, my, mz;
  double temp;
  double battery;
  double press;
};

extern void parse(void *data);

#endif /* end of include guard: PARSER_HEADER */
