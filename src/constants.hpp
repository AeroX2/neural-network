#ifndef CONSTANTS_H
#define CONSTANTS_H

static int SCREEN_WIDTH = 640;
static int SCREEN_HEIGHT = 480;

static float FRAMERATE = 1000.0/60.0;

extern int ROLLING_AVERAGE;
extern bool TOURNAMENT;
extern bool COMBINE_TWO_POINT;
extern bool CONTROL_SWEEPER;

extern int POPULATION;
extern int MINE_LEN;
extern int EPOCH_TICK_OVER;
extern int HIT_DISTANCE;
extern int TOURNAMENT_SIZE;

extern float MUTATION_CHANCE;
extern float COMBINE_CHANCE;
extern float MAX_PERTURB;

extern float MAX_SWEEPER_TURN_RATE;

static int BRAIN_INPUT_LEN = 5;
static int BRAIN_OUTPUT_LEN = 2;
extern int BRAIN_HIDDEN_LEN;
static int BRAIN_HIDDEN_LAYER_LEN = 1;

#define WHITE 255,255,255
#define BLACK 0,0,0

#define RED 255,0,0
#define BLUE 0,0,255
#define GREEN 0,255,0

#define ORANGE 255,159,0
#define PURPLE 255,0,255

#endif
