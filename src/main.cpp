#include "window.h"

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

    while (!windowShouldClose(window)) {
        windowClear(0.2f, 0.3f, 0.3f, 1.0f);

        swapBuffers(window);
        pollEvents();
    }

    destroyWindow(window);
    return 0;
}

