#include <GL/glew.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "renderer.h"
#include "mesh.h"
#include "particle.h"

Shader Renderer::shader;

void Renderer::clear(const float r, const float g, const float b, const float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Renderer::init(int width, int height) {
    if (!shader.init("./src/shaders/vert.glsl", "./src/shaders/frag.glsl")) {
        std::cerr << "Renderer->Error: Failed to initialize shader!" << std::endl;
        return false;
    }

    Particle::mesh = genCircleMesh(0.1f, 20);
    initBuffers(Particle::mesh);

    glm::mat4 projection = glm::perspective(45.0f, (float)width/(float)height, 0.1f, 1000.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, -3.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

    shader.setMat4("projection", projection);
    shader.setMat4("view", view);

    return true;
}

void Renderer::shutdown() {
    freeBuffers(Particle::mesh);
}

void Renderer::drawParticle(Particle &particle) {
    shader.use();

    updateModelMatrix(particle);

    shader.setMat4("model", particle.modelMatrix);
    draw(Particle::mesh);
}

