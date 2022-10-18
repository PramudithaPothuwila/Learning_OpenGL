#define GLEW_STATIC

#include <iostream>
#include <string>
#include "Gl/glew.h"
#include "GLFW/glfw3.h"
#include <fstream>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "VertexBufferLayout.h"
#include "Texture.h"


int main()
{
    GLFWwindow* window;
    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(800, 800, "OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewInit();
    {
        float positions[] =
        {
            -0.5f,-0.5f, 0.0f, 0.0f,
             0.5f,-0.5f, 1.0f, 0.0f,
             0.5f, 0.5f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.0f, 1.0f
        };

        unsigned int indices[] =
        {
            0, 1, 2,
            2, 3, 0
        };

        GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
        GLCall(glEnable(GL_BLEND));

        VertexArray va;
    	VertexBuffer vb(positions, 4 * 4 * sizeof(float));

        VertexBufferLayout layout;
        layout.Push<float>(2);
        layout.Push<float>(2);
        va.AddBuffer(vb, layout);

        IndexBuffer ib(indices, 6);


        Shader shader("res/shaders/Basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);

        Texture texture("res/textures/geometric wolf.png");
        texture.Bind();
        shader.SetUniform1i("u_Texture", 0);

        glUseProgram(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        float r = 0;
        float rate = 0.05f;

        Renderer renderer;

        while (!glfwWindowShouldClose(window))
        {
            renderer.Clear();
            
            shader.Bind();
            shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
            
            renderer.Draw(va, ib, shader);
            
            if (r > 1)
                rate = -0.05f;
            if (r < 0)
                rate = 0.05f;
            r += rate;
            glfwSwapBuffers(window);
            
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}
	 