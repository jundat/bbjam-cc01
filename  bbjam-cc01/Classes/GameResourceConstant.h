/*
*/
#ifndef _GAME_RESOURCE_CONSTANT_H_
#define _GAME_RESOURCE_CONSTANT_H_

#include "GameConstant.h"
// Define level
//static char* IMG_LEVEL_PRE = "/levels/level1";
//static char* IMG_LEVEL_POST = ".png";
//static char* IMG_LEVEL1 = "/levels/level1.png";

static char* IMG_LEVEL[] = {"",
	"/levels/level1.png",
	"/levels/level2.png",
	"/levels/level3.png",
	"/levels/level4.png",
	"/levels/level5.png",
	"/levels/level6.png",
	"/levels/level7.png",
	"/levels/level8.png",
	"/levels/level9.png",
	"/levels/level10.png",
	"/levels/level11.png",
	"/levels/level12.png",
	"/levels/level13.png",
	"/levels/level14.png",
	"/levels/level15.png",
	"/levels/level16.png",
	"/levels/level17.png",
	"/levels/level18.png",
	"/levels/level19.png",
	"/levels/level20.png",
	"/levels/level21.png",
	"/levels/level22.png",
	"/levels/level23.png",
	"/levels/level24.png",
	"/levels/level25.png",
	"/levels/level26.png",
	"/levels/level27.png",
	"/levels/level28.png",
	};

static int GRAVITY_LEVEL[] = {
      -1,
      GRAVITY_LEFT,  // 1
      GRAVITY_DOWN,    // 2
      GRAVITY_UP,  // 3
      GRAVITY_RIGHT,  // 4
      GRAVITY_LEFT,  // 5
      GRAVITY_LEFT,  // 6
      GRAVITY_DOWN, // 7
      GRAVITY_LEFT,  // 8
      GRAVITY_LEFT,  // 9
      GRAVITY_DOWN,  // 10
      GRAVITY_RIGHT,  // 11
      GRAVITY_LEFT,  // 12
      GRAVITY_RIGHT,  // 13
      GRAVITY_LEFT,  // 14
      GRAVITY_LEFT,  // 15
      GRAVITY_DOWN,  // 16
      GRAVITY_LEFT,  // 17
      GRAVITY_LEFT,  // 18
      GRAVITY_DOWN,  // 19
      GRAVITY_LEFT,  // 20
      GRAVITY_LEFT,  // 21
      GRAVITY_DOWN,  // 22
      GRAVITY_DOWN,  // 23
      GRAVITY_DOWN,  // 24
      GRAVITY_LEFT,  // 25
      GRAVITY_LEFT,  // 26
      GRAVITY_LEFT,  // 27
      GRAVITY_LEFT,  // 28
    };

static bool ALLOW_TYPE_PLAYER[][3] = {
        {true, true, true},  // nothing
        {true, false, false},   // 1
        {true, false, false},   // 2
        {true, false, false},   // 3
        {true, false, false},   // 4
        {true, false, false},   // 5
        {true, false, false},   // 6
        {true, false, false},   // 7
        {true, false, false},   // 8
        {true, false, false},   // 9
        {true, false, false},   // 10
        {true, false, false},   // 11
        {true, false, false},   // 12
        {true, false, false},   // 13
        {true, false, false},   // 14
        {true, false, false},   // 15
        {true, false, false},   // 16
        {true, false, false},   // 17
        {true, false, false},   // 18
        {true, false, false},   // 19
        {true, false, true},   // 20
        {true, true, false},   // 21
        {true, true, false},   // 22
        {true, false, true},   // 23
        {true, true, false},   // 24
        {true, false, true},   // 25
        {true, false, false},   // 26
        {true, true, false},   // 27
        {true, false, true},   // 28
    };

// Define image
static char* IMG_CHARACTER = "character.png";
static char* IMG_ROCKBOXZ = "rockboxz.png";
static char* IMG_SPIDERBOXZ = "spiderboxz.png";
static char* IMG_SCRATCH_1 = "scratch_1.png";
static char* IMG_SCRATCH_2 = "scratch_2.png";

// Define plist
static char* IMGPLIST_CHARACTER = "character.plist";


#endif
