#include <glm/gtc/matrix_transform.hpp>

#include "particle.h"
#include "mesh.h"

Mesh Particle::mesh;

void updateModelMatrix(Particle& particle) {
    particle.modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(particle.pos, 0.0f));
}

Particle::Particle() { }

