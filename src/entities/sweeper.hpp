#ifndef SWEEPER_H
#define SWEEPER_H

#include <SDL2/SDL.h>

#include "../constants.hpp"
#include "vector.hpp"
#include "mine.hpp"
#include "../network/brain.hpp"

class Vector;

class Sweeper
{
	public:
		static Sweeper* create(Vector p, Brain brain);
		virtual ~Sweeper() {};

		virtual void update(Mine mine);
		virtual void draw(SDL_Renderer* renderer);
		void new_position();

		Vector& get();
		Brain& get_brain();
		void set_brain(Brain b);
		bool is_best();
		void set_best(bool best);
	protected:
		Sweeper(Vector p, Brain brain);
		double speed;
		double rotation;
		bool best;
		Vector v;
		Vector p;
		SDL_Rect rectangle;
		Brain brain;
};

#endif
