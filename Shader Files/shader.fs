#version 330 core

out vec4 FragColor;
in vec3 ourColor;

void main()
{
    FragColor = vec4(ourColor, 1.0f);
}

//const char *fragmentShaderSource = "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "in vec3 ourColor;\n"
//
//    "void main()\n"
//    "{\n"
//    "   FragColor = vec4(ourColor, 1.0);\n"
//    "}\0";
