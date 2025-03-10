#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <string>

class Shader {
    private:
        unsigned int id;

        bool checkCompileErrors(unsigned int shader, std::string type);
        bool checkLinkErrors(unsigned int shaderProgram);

    public:
        bool init(const char* vertexPath, const char* fragmentPath);

        void use();

        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;

        void setVec3(const std::string &name, glm::vec3 value) const;
        void setMat4(const std::string &name, glm::mat4 value) const;
};

#endif

