#include <GL/glew.h>

#include "mesh.h"

void initBuffers(Mesh& mesh) {
    glGenVertexArrays(1, &mesh.vao);
    glGenBuffers(1, &mesh.vbo);
    glGenBuffers(1, &mesh.ebo);

    glBindVertexArray(mesh.vao);

    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(Vertex), mesh.vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(unsigned int), mesh.indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void freeBuffers(Mesh& mesh) {
    glDeleteBuffers(1, &mesh.vbo);
    glDeleteBuffers(1, &mesh.ebo);
    glDeleteVertexArrays(1, &mesh.vao);
}

Mesh genCircleMesh(float radius, unsigned int numSegments) {
    Mesh mesh;
    
    // add the center vertex (index 0)
    Vertex center;
    center.position = glm::vec3(0.0f, 0.0f, 0.0f);
    mesh.vertices.push_back(center);
    
    // Create vertices around the circumference
    // Generate exactly numSegments vertices around the circle.
    for (unsigned int i = 0; i < numSegments; ++i) {
        float angle = 2.0f * M_PI * i / numSegments;
        float x = radius * std::cos(angle);
        float y = radius * std::sin(angle);
        Vertex v;
        v.position = glm::vec3(x, y, 0.0f);
        mesh.vertices.push_back(v);
    }
    
    // for each segment, the triangle is: center, current vertex, next vertex.
    for (unsigned int i = 1; i < numSegments; ++i) {
        mesh.indices.push_back(0);           // Center
        mesh.indices.push_back(i);           // Current circumference vertex
        mesh.indices.push_back(i + 1);       // Next circumference vertex
    }
    // Last triangle connects the last vertex with the first vertex in the ring.
    mesh.indices.push_back(0);               // Center
    mesh.indices.push_back(numSegments);     // Last circumference vertex
    mesh.indices.push_back(1);               // First circumference vertex

    return mesh;
}

void draw(Mesh& mesh) {
    glBindVertexArray(mesh.vao);
    glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

