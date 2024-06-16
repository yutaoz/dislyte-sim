#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "esper.h"
#include "characters.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Esper esper_init(char* buffer) {

    // find matching esper
    char* token = strtok(buffer, " ");
    char* name = token;

    
    bool found = false;
    Esper esp;
    for (int i = 0; i < num_espers; i++) {
        int result = strcmp(token, espers[i].name);
        
        if (result == 0) {
            esp = espers[i];
            found = true;
            break;
        } 
    }

    // hacky error handling, maybe we use dynamic memory and return NULL for pointer values?
    if (!found) {
        esp.name = name;
        esp.hp = -1;
        return esp;
    }

    printf("\n");

    printf("Esper: %s\n", esp.name);

    // update hp
    token = strtok(NULL, " ");
    printf("HP -> %d + %d = %d\n", esp.hp, atoi(token), esp.hp + atoi(token));
    esp.hp = esp.hp + atoi(token);
    esp.hp_per = 100.0f;

    // update atk
    token = strtok(NULL, " ");
    printf("ATK -> %d + %d = %d\n", esp.atk, atoi(token), esp.atk + atoi(token));
    esp.atk = esp.atk + atoi(token);

    // update def
    token = strtok(NULL, " ");
    printf("DEF -> %d + %d = %d\n", esp.def, atoi(token), esp.def + atoi(token));
    esp.def = esp.def + atoi(token);
    
    // update spd
    token = strtok(NULL, " ");
    printf("SPD -> %d + %d = %d\n", esp.spd, atoi(token), esp.spd + atoi(token));
    esp.spd = esp.spd + atoi(token);

    // once we have spd, we can also do gain and ap
    esp.gain = (float) esp.spd / 100;
    esp.ap = 0;

    // update crate
    token = strtok(NULL, " ");
    printf("C RATE -> %.2f + %.2f = %.2f\n", esp.crate, atof(token), esp.crate + atof(token));
    esp.crate = esp.crate + atof(token);

    // update cdmg
    token = strtok(NULL, " ");
    printf("C DMG -> %.2f + %.2f = %.2f\n", esp.cdmg, atof(token), esp.cdmg + atof(token));
    esp.cdmg = esp.cdmg + atof(token);

    // update acc
    token = strtok(NULL, " ");
    printf("ACC -> %.2f + %.2f = %.2f\n", esp.acc, atof(token), esp.acc + atof(token));
    esp.acc = esp.acc + atof(token);

    // update resist
    token = strtok(NULL, " ");
    printf("RESIST -> %.2f + %.2f = %.2f\n", esp.resist, atof(token), esp.resist + atof(token));
    esp.resist = esp.resist + atof(token);

    printf("\n");

    return esp;
}
