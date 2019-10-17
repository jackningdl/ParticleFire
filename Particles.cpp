
#include "Particles.h"
#include <stdlib.h>

namespace ParticleFire {
    // Through the pixels, particle selected.
    Particles::Particles() {
        m_x = (1.6 * rand()/RAND_MAX) - 1;
        m_y = (1.6 * rand()/RAND_MAX) - 1;

    }

    Particles::~Particles() {

    }

    void Particles::update() {
        const double speed = 0.005;

        m_x += speed;
        m_y += speed;
    }
}