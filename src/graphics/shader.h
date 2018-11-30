#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include "../utils/fileutils.h"
#include "GL/glew.h"
#include <vector>
#include "../maths/maths.h"
#include "../maths/glm_include.h"


namespace mike { namespace graphics {

    class Shader
    {
    public:
        GLuint shaderID;
        const char *vertPath, *fragPath;
    public:

        Shader(const char* vertPath, const char* fragPath);
        ~Shader();
        void setUniform1f(const GLchar* name, const float value);
        void setUniform2f(const GLchar* name, const glm::vec2& vector);
        void setUniform3f(const GLchar* name, const glm::vec3& vector);
        void setUniform4f(const GLchar* name, const glm::vec4& vector);
        void setUniformMat4(const GLchar* name, const glm::mat4& matrix);
        void setUniform1i(const GLchar* name, const int value);
        void enable() const;
        void disable() const;

    private:
        GLuint load();
        GLint getUniformLocation(const GLchar* name);
    };

} }

#endif // SHADER_H_INCLUDED
