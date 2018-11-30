#include "fileutils.h"
#include <stdexcept>

namespace mike {

    std::string read_file(const char* filepath)
    {
        std::ifstream file(filepath);
        if (!file.is_open())
        {
            throw std::runtime_error ("Unable to open the shader file: " + (std::string)filepath);
        }
        std::string source;
        std::stringstream stream;
        try{
        stream << file.rdbuf();
        source = stream.str();
        }
        catch (std::ifstream::failure& e)
        {

           throw std::runtime_error ("Unable to read the shader file: " + (std::string)filepath);
        }
        return source;
    }




}
