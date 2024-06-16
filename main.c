#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "character/esper.h"
#include "character/characters.h"
#include "battle-utils/turns.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // read team files and generate teams 
    char line[256];

    GameList t1;
    GameList t2;
    int t1_sz = 0;
    int t2_sz = 0;


    // get first line, team1 count and team2 count
    fgets(line, sizeof(line), file);

    char buffer[256];
    strcpy(buffer, line);

    char* token = strtok(buffer, " ");
    t1_sz = atoi(token);
    token = strtok(NULL, " ");
    t2_sz = atoi(token);
    t1.e_cnt = t1_sz;
    t1.list = (Esper**)malloc(t1.e_cnt * sizeof(Esper));
    t2.e_cnt = t2_sz;
    t2.list = (Esper**)malloc(t2.e_cnt * sizeof(Esper));

    // iterate through lines and create espers
    Esper e_l1[t1_sz];
    for (int i = 0; i < t1_sz; i++) {
        fgets(line, sizeof(line), file);
        strcpy(buffer, line);
        e_l1[i] = esper_init(buffer); 
        if (e_l1[i].hp == -1) {
            printf("Esper not found: %s\n", e_l1[i].name);
            return 1;
        }
        t1.list[i] = &e_l1[i];
        
    }

    Esper e_l2[t2_sz];
    for (int i = 0; i < t2_sz; i++) {
        fgets(line, sizeof(line), file);
        strcpy(buffer, line);
        e_l2[i] = esper_init(buffer); 
        if (e_l2[i].hp == -1) {
            printf("Esper not found: %s\n", e_l2[i].name);
            return 1;
        }
        t2.list[i] = &e_l2[i]; 
    }
    fclose(file);


    // build gamelist from the two teams
    GameList gl;
    gl.e_cnt = t1.e_cnt + t2.e_cnt;
    gl.list = (Esper**)malloc(gl.e_cnt * sizeof(Esper));

    for (int i = 0; i < gl.e_cnt; i++) {
        if (i < t1.e_cnt) {
            gl.list[i] = t1.list[i];
        } else {
            gl.list[i] = t2.list[i - t1.e_cnt];
        }
    }

    setup_turns(&gl);
    take_turn(gl.list[0]);
    setup_turns(&gl);

    for (int i = 0; i < gl.e_cnt; i++) {
        printf("ap: %s - %f\n", gl.list[i]->name, gl.list[i]->ap);
    }

    
    free(t1.list);
    free(t2.list);
    free(gl.list);
    return 0;
}
