/*
 * GameConstant.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef GAMECONSTANT_H_
#define GAMECONSTANT_H_

// Define : Resolution
static const int WIDTH 	= 768;
static const int HEIGHT 	= 1280;

// Define : Grid
static const int GRID_SIZE 		= 45; // pixel
static const int NUM_GRID_WIDTH 	= 16;
static const int NUM_GRID_HEIGHT 	= 20;

// Define : Color map
static const int MAP_COLOR_STONE      	= 0x000000;
static const int MAP_COLOR_WOOD      	= 0xC3C3C3;
static const int MAP_COLOR_PLAYER     	= 0xA5524A;
static const int MAP_COLOR_TRAP       	= 0x241CED;
static const int MAP_COLOR_TARGET     	= 0x4ABD63;

static const int MAP_STONE	= 0;
static const int MAP_WOOD 	= 1;
static const int MAP_PLAYER	= 2;
static const int MAP_TRAP		= 3;
static const int MAP_TARGET	= 4;
static const int MAP_WIN = 5;

static int MAX_LEVEL = 68;

static const int PLAYER_MEGABOXZ	= 0;
static const int PLAYER_ROCKBOXZ	= 1;
static const int PLAYER_SPIDERBOXZ	= 2;

static const int GRAVITY_UP 	= 0;
static const int GRAVITY_DOWN	= 1;
static const int GRAVITY_LEFT 	= 2;
static const int GRAVITY_RIGHT 	= 3;

static const int GRAVITY_SPEED = 5;

#endif /* GAMECONSTANT_H_ */
