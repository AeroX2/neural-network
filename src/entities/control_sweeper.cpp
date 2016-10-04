#include "control_sweeper.hpp"

Control_Sweeper::Control_Sweeper(Vector p, Brain brain) : Sweeper(p, brain)
{
	this->p = p;

	rectangle.x = p.x;
	rectangle.y = p.y;
	rectangle.w = 10;
	rectangle.h = 10;

	rotation = 0.0;
	speed = CONTROL_SWEEPER_SPEED;

	fitness = 0;
}

void Control_Sweeper::update(Mine mine) 
{
	Vector temp = mine.get() - p;
	rotation = atan2(temp.y, temp.x);

	v.x = cos(rotation) * speed;
	v.y = sin(rotation) * speed;

	if (v.x > MAX_SWEEPER_SPEED) v.x = MAX_SWEEPER_SPEED; 
	else if (v.x < -MAX_SWEEPER_SPEED) v.x = -MAX_SWEEPER_SPEED; 
	if (v.y > MAX_SWEEPER_SPEED) v.y = MAX_SWEEPER_SPEED; 
	else if (v.y < -MAX_SWEEPER_SPEED) v.y = -MAX_SWEEPER_SPEED; 

	p += v;
	rectangle.x = round(p.x);
	rectangle.y = round(p.y);

	fitness += get_brain().get_fitness();
	get_brain().set_fitness(0);
}

void Control_Sweeper::draw(SDL_Renderer* renderer) 
{
	SDL_SetRenderDrawColor(renderer, PURPLE, 255);
	SDL_RenderFillRect(renderer, &rectangle);
}

int Control_Sweeper::get_fitness()
{
	return this->fitness;
}

void Control_Sweeper::set_fitness(int fitness)
{
	this->fitness = fitness;
}

Control_Sweeper* Control_Sweeper::create(Vector p, Brain brain)
{
	return new Control_Sweeper(p, brain);
}
