#include "block.h"

void air_init() {
    struct Block air = BLOCK_DEFAULT;
    air.id = AIR;
    air.flags |= B_TRANSPARENT;
    air.flags &= ~SOLID;
    BLOCKS[AIR] = air;
}