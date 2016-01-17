#ifndef LOGIC_H
#define LOGIC_H

#include "entities/mine.hpp"
#include "entities/sweeper.hpp"
#include "entities/control_sweeper.hpp"
#include "network/brain.hpp"
#include "network/matrix.hpp"

#include "controller.hpp"

class SDL_Renderer;

using namespace std;

class Logic
{
	public:
		Logic();
		void update(double delta);
		void draw(SDL_Renderer* renderer);
	private:
		vector<Sweeper> sweepers;
		vector<Mine> mines;
		int ticks;
		int max_fitness;
};

#endif
