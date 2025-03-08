#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Vertex {
    glm::vec3 position;
};

struct Mesh {
    unsigned int vao, vbo, ebo;

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
};

Mesh genCircleMesh(float radius, unsigned int numSegments);

void initBuffers(Mesh& mesh);
void freeBuffers(Mesh& mesh);

#endif

