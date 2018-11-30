#include "shader.h"
#include "../../3rdparty/glm/glm.hpp"

namespace mike { namespace graphics {


 void checkErrors(GLuint shaderId, GLenum statusType, const std::string& errorType)
    {
        auto bufferSize = 512;

        GLint isSuccess;
        GLchar infoLog[bufferSize];

        glGetShaderiv (shaderId, statusType, &isSuccess);
        if (!isSuccess)
        {
            glGetShaderInfoLog (shaderId, bufferSize, nullptr, infoLog);
            throw std::runtime_error ("Shader loading error.\nType: " + errorType + "\nWhat: " + infoLog);
        }
}


  std::string getSource (const std::string& shaderFile)
    {
        std::ifstream shaderSourceFile (shaderFile);
        if (!shaderSourceFile.is_open())
        {
            throw std::runtime_error ("Unable to open the shader file: " + shaderFile);
        }
        shaderSourceFile.exceptions(std::ifstream::badbit);

        std::string source;
        std::stringstream stream;

        try
        {
            stream << shaderSourceFile.rdbuf();
            source = stream.str();
        }
        catch ( std::ifstream::failure& e)
        {
            throw std::runtime_error ("Unable to read the shader file: " + shaderFile);
        }

        return source;
    }

    GLuint compileShader (const char* source, GLenum type)
    {
        auto shaderId = glCreateShader(type);

        glShaderSource  (shaderId, 1, &source, nullptr);
        glCompileShader (shaderId);

        checkErrors(shaderId, GL_COMPILE_STATUS, "Error compiling shader!");

        return shaderId;
    }


GLuint createProgram(GLuint vertexShaderId, GLuint fragmentShaderId)
    {
        auto shaderProgram = glCreateProgram();

        glAttachShader (shaderProgram, vertexShaderId);
        glAttachShader (shaderProgram, fragmentShaderId);
        glLinkProgram  (shaderProgram);

        return shaderProgram;
}


Shader::Shader(const char* vertPath, const char* fragPath)
:vertPath(vertPath)
,fragPath(fragPath)
{
    shaderID = load();
}

Shader::~Shader()
{
    glDeleteProgram(shaderID);
}

void Shader::enable() const
{
    glUseProgram(shaderID);
}

void Shader::disable() const
{
    glUseProgram(0);
}

GLuint Shader::load()
{
        auto vertexSource    = getSource (vertPath);
        auto fragmentSource  = getSource (fragPath);

        auto vertexId   = compileShader(vertexSource.c_str(),   GL_VERTEX_SHADER);
        auto fragmentId = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

        auto shaderProgramId = createProgram(vertexId, fragmentId);

        glDeleteShader(vertexId);
        glDeleteShader(fragmentId);

return shaderProgramId;

}

void Shader::setUniformMat4(const GLchar* name, const glm::mat4& matrix)
{
      glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}


void Shader::setUniform1f(const GLchar* name, const float value)
{
    glUniform1f(getUniformLocation(name),value);
}

void Shader::setUniform2f(const GLchar* name, const glm::vec2& vector)
{
    glUniform2f(getUniformLocation(name),vector.x,vector.y);
}

void Shader::setUniform3f(const GLchar* name, const glm::vec3& vector)
{
    glUniform3f(getUniformLocation(name),vector.x, vector.y, vector.z);
}

void Shader::setUniform4f(const GLchar* name, const glm::vec4& vector)
{
    glUniform4f(getUniformLocation(name),vector.x,vector.y, vector.z, vector.a);
}




void Shader::setUniform1i(const GLchar* name, const int value)
{
    glUniform1i(getUniformLocation(name),value);
}

GLint Shader::getUniformLocation(const GLchar* name)
{
    return glGetUniformLocation(shaderID,name);
}




}}
