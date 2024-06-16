#include <stdlib.h>
#include <stdio.h>
#include "turns.h"
#include "../character/esper.h"

int comp_ap(const void *a, const void *b) {
    float diff = (*(Esper**)b)->ap - (*(Esper**)a)->ap;
    //printf("float : %f", (*(Esper**)a)->ap);
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

void setup_turns(GameList* gl) {
    float min_t = 1000.0f;
    Esper* min_e = NULL;
    for (int i = 0; i < gl->e_cnt; i++) {
        Esper* e = gl->list[i];
        float diff = 100.0f - e->ap;
        // # of ticks to get to max ap, least means esper with next turn
        float t_to_100 = diff / e->gain;
        // printf("%f\n", diff);
        // printf("%f\n", t_to_100);

        if (t_to_100 < min_t) {
            min_t = t_to_100;
            min_e = e;
        }
    }

    for (int i = 0; i < gl->e_cnt; i++) {
        Esper* e = gl->list[i];
        e->ap = e->ap + e->gain * min_t;
    }
    qsort(gl->list, gl->e_cnt, sizeof(Esper*), comp_ap);

    // printf("%s\n", min_e->name);
    // printf("\n");

}

void take_turn(Esper* e) {
    e->ap = 0.0f;
}
