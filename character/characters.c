#include "characters.h"
#include "esper.h"

// master list of all espers in the game and their base stats at lvl 60
Esper espers[] = {
    {
        .name = "ZEUS",
        .hp = 12233,
        .atk = 1224,
        .def = 861,
        .spd = 101,
        .crate = 0.1f,
        .cdmg = 1.5f,
        .acc = 0.0f,
        .resist = 0.2f
    },
    {
        .name = "CLARA",
        .hp = 15777,
        .atk = 849,
        .def = 992,
        .spd = 106,
        .crate = 0.1f,
        .cdmg = 1.5f,
        .acc = 0.0f,
        .resist = 0.2f
    }
};

int num_espers = sizeof(espers) / sizeof(Esper);


