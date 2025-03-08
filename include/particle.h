#include <glm/glm.hpp>

#include "mesh.h"

struct Particle {
    glm::vec2 pos;
    glm::vec2 vel;
    glm::vec2 acc;
    float mass;
    float density;

    static Mesh mesh;
};

