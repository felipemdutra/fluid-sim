#ifndef PARTICLE_H
#define PARTICLE_H

#include <glm/glm.hpp>

class Mesh;

struct Particle {
    glm::vec2 pos = glm::vec2();
    glm::vec2 vel = glm::vec2();
    glm::vec2 acc = glm::vec2();

    glm::mat4 modelMatrix = glm::mat4(1.0f);

    float mass = 1.0f;
    float density = 1.0f;

    static Mesh mesh;

    Particle();
};

void updateModelMatrix(Particle& particle);

#endif

