#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>
#include "string"
#include "vector"
#include <cmath>

static const int ScreenWidth = 1000;
static const int ScreenHeight = 1000;
static const int D_RectangleSpace = 100;
static const float D_PlayerSpeed = 10;
static const float D_NPCSpeed = 6;

static const int D_BouncerHeight = 50;
static const int D_BouncerWidth = 125;

static const int D_NPCHeight = 50;
static const int D_NPCWidth = 125;


static const float D_BallSpeed = 5;
static const int D_BallDiameter = 20;
static const int D_BallRadius = D_BallDiameter / 2;

static const int D_BallDestructorRange = 50;

static int DONE = 0;

