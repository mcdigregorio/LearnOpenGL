#include <iostream>
#include <cmath>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "Shader.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    std::cout << "Hello there" << std::endl;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello there", NULL, NULL);
    if (!window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    //I originally had a viewport call here.
    //If added, quad shows up towards bottom left then centers after resizing window
    //Figure out why
    //Resize fires framebuffer_size_callback
    //glViewport(0, 0, 800, 600);
    
    Shader ourShader("../Shader Files/shader.vs", "../Shader Files/shader.fs");
    
    float vertices[] = {
        //positions
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f // top
    };
    
//    unsigned int indices[] = {
//        0, 1, 3, //first triangle
//        1, 2, 3  //second triangle
//    };
    
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    
    while(!glfwWindowShouldClose(window))
    {
        //input
        processInput(window);
        
        //render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        ourShader.use();
        
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
//        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        ourShader.setFloat("outColor", greenValue);
        ourShader.setFloat("xOffset", 0.5);
        
        glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        //Optional, unbind
        glBindVertexArray(0);
        
        //check and call events, swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}
