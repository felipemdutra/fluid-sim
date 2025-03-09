#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "particle.h"

namespace Renderer {
    extern Shader shader;

    bool init(int width, int height);
    void shutdown();

    void clear(const float r, const float g, const float b, const float a);

    void drawParticle(Particle& particle);
}

#endif

