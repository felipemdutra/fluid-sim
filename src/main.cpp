#include "window.h"
#include "renderer.h"

#define WIDTH 1000
#define HEIGHT 800 

int main() {
    Window* window = createWindow(WIDTH, HEIGHT, "Hello, World!");
    if (!window) {
        return 1;
    }

    if (initWindow(window) < 0) {
        return 1;
    }

    if (!Renderer::init(WIDTH, HEIGHT)) {
        return 1;
    }

    Particle p;
    p.pos = glm::vec3(0.0f, 0.0f, 0.0f);

    while (!windowShouldClose(window)) {
        Renderer::clear(0.2f, 0.3f, 0.3f, 1.0f);

        Renderer::drawParticle(p);

        swapBuffers(window);
        pollEvents();
    }

    Renderer::shutdown();
    destroyWindow(window);
    return 0;
}

