//
//  Shader.hpp
//  LearnOpenGL
//
//  Created by Michael DiGregorio on 3/17/23.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    unsigned int ID;
    
    Shader(const char* vertexPath, const char* fragmentPath);
    
    //Use/activate the shader
    void use();
    //Utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
};

#endif /* Shader_hpp */
