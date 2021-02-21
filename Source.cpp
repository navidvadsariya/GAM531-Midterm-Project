#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderinit.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>


void drawLevel1();
void drawLevel2();
void drawLevel3();
void drawLevel4();
void drawLevel5();

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void init(void);
void render();

void tranformations(Shader& ourShader);

// variables
const unsigned int screen_width = 1024;
const unsigned int screen_height = 768;

const GLuint NumVertices = 6;

GLuint VBO, VBO1, VBO2, VBO3, VBO4, VBO5;
GLuint VAO, VAO1, VAO2, VAO3, VAO4, VAO5;
GLuint EBO, EBO1, EBO2, EBO3, EBO4, EBO5;

int row = 0;

int main()
{
    // glfw: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window;
    window = glfwCreateWindow(screen_width, screen_height, "OpenGLTwoTrianglesExternalShaderFiles", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program

    Shader ourShader("shader.vs", "shader.fs"); // you can name your shader files however you like

    init();
 // render loop
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);
        render();
        tranformations(ourShader);
      
        ourShader.use();

       
     

        // glfw: swap buffers
        glfwSwapBuffers(window);
        // gldw: poll for events
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}

void tranformations(Shader& ourShader)
{
    float tempRow = 0.0f;
    ourShader.use();
    //row 1
    for (unsigned int i = 0; i < 11; i++)
    {
        glBindVertexArray(VAO);
        tempRow += 0.161f;

        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(-1.0f + tempRow, 0.95f, 0.0f));
       
        transform = glm::scale(transform, glm::vec3(0.15f, 0.08f, 0.0f));
        ourShader.use();
       
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        drawLevel1();
    }
    tempRow = 0.0f;
    //row 2
    for (unsigned int i = 0; i < 11; i++)
    {
        glBindVertexArray(VAO1);
        tempRow += 0.161f;

        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(-1.0f + tempRow, 0.85f, 0.0f));

        transform = glm::scale(transform, glm::vec3(0.15f, 0.08f, 0.0f));
        ourShader.use();

        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        drawLevel2();
    }
    tempRow = 0.0f;
    //row 3
    for (unsigned int i = 0; i < 11; i++)
    {
        glBindVertexArray(VAO2);
        tempRow += 0.161f;

        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(-1.0f + tempRow, 0.75f, 0.0f));

        transform = glm::scale(transform, glm::vec3(0.15f, 0.08f, 0.0f));
        ourShader.use();

        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        drawLevel3();
    }
    tempRow = 0.0f;
    //row 4
    for (unsigned int i = 0; i < 11; i++)
    {
        glBindVertexArray(VAO3);
        tempRow += 0.161f;

        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(-1.0f + tempRow, 0.65f, 0.0f));

        transform = glm::scale(transform, glm::vec3(0.15f, 0.08f, 0.0f));
        ourShader.use();

        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        drawLevel4();
    }
    tempRow = 0.0f;
    //row 5
    for (unsigned int i = 0; i < 11; i++)
    {
        glBindVertexArray(VAO4);
        tempRow += 0.161f;

        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(-1.0f + tempRow, 0.55f, 0.0f));

        transform = glm::scale(transform, glm::vec3(0.15f, 0.08f, 0.0f));
        ourShader.use();

        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        drawLevel5();
    }
   
    ourShader.use();
}
void drawLevel1()
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, NumVertices, GL_UNSIGNED_INT, 0);
}
void drawLevel2()
{
    glBindVertexArray(VAO1);
    glDrawElements(GL_TRIANGLES, NumVertices, GL_UNSIGNED_INT, 0);
}
void drawLevel3()
{
    glBindVertexArray(VAO2);
    glDrawElements(GL_TRIANGLES, NumVertices, GL_UNSIGNED_INT, 0);
}
void drawLevel4()
{
    glBindVertexArray(VAO3);
    glDrawElements(GL_TRIANGLES, NumVertices, GL_UNSIGNED_INT, 0);
}
void drawLevel5()
{
    glBindVertexArray(VAO4);
    glDrawElements(GL_TRIANGLES, NumVertices, GL_UNSIGNED_INT, 0);
}
void render()
{
    static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };
    glClearBufferfv(GL_COLOR, 0, black);
    glClear(GL_COLOR_BUFFER_BIT);
   
    
}

void init(void)
{
    //1 level
    float vertices1[] = {
        0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f // top left 
    };
    unsigned int indices1[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);

    // position attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute pointer
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //2 level
    float vertices2[] = {
     0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, // top right
        0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f // top left 
    };
    unsigned int indices2[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);
    glGenBuffers(1, &EBO1);
    glBindVertexArray(VAO1);

    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO1);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

    // position attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute pointer
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //3 level
    float vertices3[] = {
      0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f // top left 
    };
    unsigned int indices3[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    glGenVertexArrays(1, &VAO2);
    glGenBuffers(1, &VBO2);
    glGenBuffers(1, &EBO2);
    glBindVertexArray(VAO2);

    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices3), vertices3, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);

    // position attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute pointer
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //4 level
    float vertices4[] = {
      0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f // top left 
    };
    unsigned int indices4[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    glGenVertexArrays(1, &VAO3);
    glGenBuffers(1, &VBO3);
    glGenBuffers(1, &EBO3);
    glBindVertexArray(VAO3);

    glBindBuffer(GL_ARRAY_BUFFER, VBO3);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices4), vertices4, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices4), indices4, GL_STATIC_DRAW);

    // position attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute pointer
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    //5 level
    float vertices5[] = {
      0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 0.0f // top left 
    };
    unsigned int indices5[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };

    glGenVertexArrays(1, &VAO4);
    glGenBuffers(1, &VBO4);
    glGenBuffers(1, &EBO4);
    glBindVertexArray(VAO4);

    glBindBuffer(GL_ARRAY_BUFFER, VBO4);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices5), vertices5, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO4);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices5), indices5, GL_STATIC_DRAW);

    // position attribute pointer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute pointer
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

// user input
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: viewport to window adjustment
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}