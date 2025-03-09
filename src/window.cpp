#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "window.h"

static void framebuffer_callback(GLFWwindow* window, int width, int height) {
    (void)window;
    glViewport(0, 0, width, height);
}

Window* createWindow(const float width, const float height, const std::string title) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window* window = new Window;
    if (!window) {
        std::cerr << "Failed to create window! Error allocating memory for window." << std::endl;
        return nullptr;
    }

    window->width = width;
    window->height = height;
    window->title= title;
    
    window->nativeWindow = glfwCreateWindow(window->width, window->height, window->title.c_str(), nullptr, nullptr);

    return window;
}

int initWindow(Window *window) {
    if (!window) {
        std::cerr << "Failed to initialize window! Window is null" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window->nativeWindow);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW!" << std::endl;
        return -1;
    }

    glfwSetFramebufferSizeCallback(window->nativeWindow, framebuffer_callback);

    return 0;
}

void destroyWindow(Window *window) {
    glfwDestroyWindow(window->nativeWindow);
    delete window;

    glfwTerminate();
}

bool windowShouldClose(Window* window) {
    return glfwWindowShouldClose(window->nativeWindow);
}

void swapBuffers(Window* window) {
    glfwSwapBuffers(window->nativeWindow);
}

void pollEvents() {
    glfwPollEvents();
}

