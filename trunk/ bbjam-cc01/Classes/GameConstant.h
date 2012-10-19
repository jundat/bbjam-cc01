/*
 * GameConstant.h
 *
 *  Created on: 20 Oct 2012
 *      Author: Loc
 */

#ifndef GAMECONSTANT_H_
#define GAMECONSTANT_H_

// Define : Resolution
static int WIDTH 	= 768;
static int HEIGHT 	= 1280;

// Define : Grid
static int GRID_SIZE 		= 45; // pixel
static int NUM_GRID_WIDTH 	= 16;
static int NUM_GRID_HEIGHT 	= 20;

// Define : Color map
static int MAP_COLOR_STONE      = 0x000000;
static int MAP_COLOR_WOOOD      = 0xC3C3C3;
static int MAP_COLOR_PLAYER     = 0x4A52A5;
static int MAP_COLOR_TRAP       = 0xED1C24;
static int MAP_COLOR_TARGET     = 0x63BD4A;

static int MAP_STONE	= 0;
static int MAP_WOOD 	= 1;
static int MAP_PLAYER	= 2;
static int MAP_TRAP		= 3;
static int MAP_TARGET	= 4;

#endif /* GAMECONSTANT_H_ */
