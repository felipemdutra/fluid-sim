#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <string>

struct Window {
    GLFWwindow* nativeWindow = nullptr;

    int width = 800, height = 600;
    std::string title;
};

Window* createWindow(const float width, const float height, const std::string title);
void destroyWindow(Window* window);

int initWindow(Window* window);

bool windowShouldClose(Window* window);
void swapBuffers(Window* window);
void pollEvents();

