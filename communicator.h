#ifndef _COMMUNICATOR_H
#define _COMMUNICATOR_H

#include "move.h"

void initBestMoveProgram(int argc, char *argv[], Inventory *inv, RowType* board);
void outputMove(Move move);

#endif