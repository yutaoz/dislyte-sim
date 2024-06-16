#ifndef ESPER_H
#define ESPER_H

typedef struct {
    const char* name;
    int hp;
    int atk;
    int def;
    int spd;
    float crate;
    float cdmg;
    float acc;
    float resist;
    float hp_per;

    float gain;
    float ap;
} Esper;

typedef struct {
    Esper** list;
    int e_cnt;
} GameList;

// initializes esper struct from line read from file
Esper esper_init(char* buffer);

#endif
