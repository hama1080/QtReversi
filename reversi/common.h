#pragma once

#include <utility>
#include <vector>
using namespace std;
#define Vec2d pair<unsigned int, unsigned int> 

#define UpperLeft	Vec2d(-1,  1)
#define Upper		Vec2d( 0,  1)
#define UpperRight	Vec2d( 1,  1)
#define CenterLeft	Vec2d(-1,  0)
#define CenterRight	Vec2d( 1,  0)
#define LowerLeft	Vec2d(-1, -1)
#define Lower		Vec2d( 0, -1)
#define LowerRight	Vec2d( 1, -1)

extern const vector<Vec2d> kDirectionList;

enum class Mode {
	Default = 0,
	Multi,
	LargeScale,
};
