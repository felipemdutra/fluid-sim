#include <vector>
#include <glm/glm.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
};

struct Mesh {
    unsigned int vao, vbo, ebo;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;
};

Mesh createCircleMesh(float radius, int segments);

