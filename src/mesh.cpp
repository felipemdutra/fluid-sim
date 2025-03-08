#include "mesh.h"

Mesh createCircleMesh(float radius, unsigned int numSegments) {
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

