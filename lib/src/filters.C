/* Modem for MIPS   AJF	  January 1995
   Filter constructor & destructor */

#include <stdlib.h>
#include <stdio.h>
#include "private.h"
#include "complex.h"
#include "filters.h"

filter::filter(fspec* xfs) {
  fs = xfs;
  int np = fs->np;
  v = new float[np + 1];
  if (v == NULL) {
    fprintf(stderr, "OutOfMemoryException filter\n");
    exit(-1);
  }
  for (int i = 0; i <= np; i++)
    v[i] = 0.0;
  sum = 0.0;
  ptr = 0; /* mvg avg filters only */
}

filter::~filter() {
  delete v;
}
