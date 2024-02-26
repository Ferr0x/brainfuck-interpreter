#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 30000
#define MAX_VALUE 255
#define MIN_CELLS 0
#define MIN_VALUE 0

typedef struct{
    int cells[MAX_CELLS];
    int value[MAX_CELLS];
    int position;
}Celles;

void compute(char character, Celles *c){
    switch (character){
        case '+':
            c->value[c->position]++;
            if(c->value[c->position]+1 ==  MAX_VALUE){
                c->value[c->position] = 0;       
            }
            break;
        case '-':
            c->value[c->position]--;
            if(c->value[c->position]+1 ==  MIN_VALUE){
                c->value[c->position] = 0;       
            }
            break;
        case '>':
            c->position++;
            if(c->position == MAX_CELLS){
                c->position = 0;
            }
            break;
        case '<':
            c->position--;
            if(c->position == MIN_CELLS){
                c->position = 0;
            }
            printf("%d\n",c->position);
            break;
        case '.':
            putchar(c->value[c->position]);
            break;
            
        default:

            break;
    
    }
}
void error(char *message){
    printf("ERROR: %s\n", message);

}

int main(int argc, char *argv[]){
    Celles c;
    if(argc > 2){
        error("Utils max 1 file");
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        error("Utils cannot open file");
        return EXIT_FAILURE;
    }

    char character;
    while ((character = fgetc(file)) != EOF) {
        compute(character,c.cells);

    }
    fclose(file);
    //printf("%d\n",c.position);
    // printf("%d\n",c.value[0]);
    // printf("%d\n",c.value[1]);
    // printf("%d\n",c.value[2]);

    return EXIT_SUCCESS;
}