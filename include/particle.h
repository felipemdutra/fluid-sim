#include <glm/glm.hpp>

#include "mesh.h"

struct Particle {
    glm::vec2 pos = glm::vec2();
    glm::vec2 vel = glm::vec2();
    glm::vec2 acc = glm::vec2();
    float mass = 1.0f;
    float density = 1.0f;

    static Mesh mesh;
};

