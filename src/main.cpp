#include "main.hpp"

int main(void)
{
	if (init()) running = false;
	if (!running) cout << "Error in initialising window";

	double current_time, last_time, delta;
	while (running)
	{
		last_time = current_time;

		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT) running = false;
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_f) 
				{
					cout << "F key pressed" << endl;
					fast = !fast;
				}
			}
		}
		logic.update(delta);

		if (fast)
		{
			if (Plotter::is_dirty())
			{
				SDL_SetRenderDrawColor(renderer,WHITE,0);
				SDL_RenderClear(renderer);

				Plotter::draw(renderer);

				SDL_RenderPresent(renderer);
			}
		}
		else
		{
			SDL_SetRenderDrawColor(renderer,WHITE,0);
			SDL_RenderClear(renderer);

			logic.draw(renderer);

			SDL_RenderPresent(renderer);

			current_time = SDL_GetTicks();
			delta = (current_time - last_time);
			if (delta < FRAMERATE) SDL_Delay(FRAMERATE - delta);
		}
	}

	destroy();	
	return 0;
}

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) return true;
	window = SDL_CreateWindow("Neural Network Sweepers", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) return true;
	renderer = SDL_CreateRenderer(window,0,SDL_RENDERER_ACCELERATED);
	Plotter::init(10);
	Plotter::new_line(0, 0, 0);
	Plotter::new_line(255, 0, 0);

	if (Config::read_from_file("config.txt")) cout << "Using values from files" << endl;
	else cout << "Failed to read from file, using defaults" << endl;

	cout << "Mutation " << MUTATION_CHANCE << endl;
	cout << "Combine " << COMBINE_CHANCE << endl;
 	cout << "Max perturb " << MAX_PERTURB << endl;

	return false;
}

void destroy()
{	
	SDL_DestroyWindow(window);
	SDL_Quit();
}
