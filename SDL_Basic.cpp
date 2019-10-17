#include <iostream>
#include <iomanip>
#include <math.h>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Swarm.h"


using namespace std;
using namespace ParticleFire;

int main() {

    srand(time(NULL));

    Screen screen;

    if (screen.init() == false) {
        cout << "Error initiating SDL." << endl;
    }

    Swarm swarm;

    // create particle, update, check.
    while(true) {

        // counting the seconds it takes to drive the change through sin().
        // The sin(time_elapsed) ranges from -1 to 1.
        int time_elapsed = SDL_GetTicks();
        // The color index ranges from 0 to 255, make the color reside in this range.
        double red_change = (1 + sin(time_elapsed * 0.001)) * 128;
        double green_change = (1 + sin(time_elapsed * 0.003)) * 128;
        double blue_change = (1 + sin(time_elapsed * 0.009)) * 128;

        const Particles * pParticles = swarm.getParticles();
        for (int i = 0; i < Swarm::PARTICLES_NUMBER; i++) {
            Particles particle = pParticles[i];

            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 1.6;
            int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 1.6;

            screen.setPixel(x, y, red_change, green_change, blue_change);
        }

        screen.update();
        if(screen.processEvent() == false) {
            break;
        }
    }

    screen.finish();
}