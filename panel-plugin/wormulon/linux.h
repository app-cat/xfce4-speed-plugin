#include "../net.h"

void init_osspecific(netdata* data);
int checkinterface(netdata* data);
int get_stat(netdata* data);

#define BUFSIZE 256