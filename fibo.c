#include <stdio.h>
#include <stdlib.h>
#include "lisp.h"
#include "fibo.h"

#include <propeller.h>
#define ARENA_SIZE 9000

int inchar() {
    return -1;
}
void outchar(int c) {
    putchar(c);
}
void outstr(const char *s) {
    while (*s != 0) putchar(*s++);
}
int peekchar() { return -1; }

static intptr_t getcnt_fn()
{
    return CNT;
}
// wait for ms millisconds
static intptr_t waitms_fn(intptr_t ms)
{
    usleep(ms * 1000);
    return ms;
}
static intptr_t pinout_fn(intptr_t pin, intptr_t onoff)
{
    unsigned mask = 1<<pin;
    DIRA |= mask;
    if (onoff) {
        OUTA |= mask;
    } else {
        OUTA &= ~mask;
    }
    return OUTA;
}
static intptr_t pinin_fn(intptr_t pin)
{
    unsigned mask=1<<pin;
    DIRA &= ~mask;
    return (INA & mask) ? 1 : 0;
}

LispCFunction defs[] = {
    { "getcnt",    "n",   (GenericFunc)getcnt_fn },
    { "pinout",    "nnn", (GenericFunc)pinout_fn },
    { "pinin",     "nn",  (GenericFunc)pinin_fn },
    { "waitms",    "nn", (GenericFunc)waitms_fn },
};

char arena[ARENA_SIZE];

int
main(int argc, char **argv)
{
    Cell *err;
    int i;
    
    err = Lisp_Init(arena, sizeof(arena));
    for (i = 0; err && defs[i].name; i++) {
        err = Lisp_DefineCFunc(&defs[i]);
    }
    if (err == NULL) {
        printf("Initialization of interpreter failed!\n");
        return 1;
    }
    Lisp_Run(fibo_lsp, 0);
    return 0;
}
