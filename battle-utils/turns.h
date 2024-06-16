#ifndef TURNS_H
#define TURNS_H

#include "../character/esper.h"

// generates a list in order of turns
void setup_turns(GameList* gl);

void take_turn(Esper* e);

#endif
