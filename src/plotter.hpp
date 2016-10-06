#ifndef PLOTTER_H
#define PLOTTER_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <math.h>

#include "constants.hpp"

using namespace std;

class Plotter
{
	public:
		static void init(float step_x);
		static void draw(SDL_Renderer* renderer);

		static void new_line(unsigned char r, unsigned char g, unsigned char b);
		static void add_point(int id, float y);
		static void resize(float blub);
		static bool is_dirty();
	private:
		static vector<vector<float>> points;
		static vector<vector<float>> average_points;
		static vector<float> averages;
		static vector<SDL_Color> colors;

		static bool dirty;
		static int step_x;

		static float scale_x;
		static float scale_y;
		static float largest_y;
		static float average;
};

void draw_font(string message, int x, int y);
#endif
