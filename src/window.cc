#include "window.h"
#include <iostream>

using namespace std;

void startInit() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

int windowSetting() {
    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle", nullptr, nullptr);
    
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window))
    {
        processInput(window);


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();
        glfwSwapBuffers(window);

    }
    glfwTerminate();

    return 0;
}

// 输入
void processInput(GLFWwindow* window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void verticle() {
    float vertices[] = {
        -.5f, -.5f, 0.0f,
        .5f, -.5f, 0.0f,
        0.0f, .5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }


    const char* fragmentShaderSource = "#version 330 core\n"
        "layout vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\0";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::LINK\n" << infoLog << std::endl;
    }

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 0. 复制顶点数组到缓冲中供OpenGL使用
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 1. 设置顶点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // 2. 当我们渲染一个物体时要使用着色器程序
    glUseProgram(shaderProgram);
    // 3. 绘制物体
    // someOpenGLFunctionThatDrawsOurTriangle();
}

int traignleShape_vbo() {
    // view
    startInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle", nullptr, nullptr);
    
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



    const float traingle[] = {
        -.5f, -.5f, 0.0f,
        .5f, -.5f, 0.0f,
        0.0f, .5f, 0.0f,
    };

    // 生成并绑定VBO
    GLuint vertex_buffer_object;
    glGenBuffers(1, &vertex_buffer_object);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);

    // VAO
    GLuint vertex_array_object;
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);

    // 定点数据绑定至当前默认的缓冲中
    glBufferData(GL_ARRAY_BUFFER, sizeof(traingle), traingle, GL_STATIC_DRAW);

    // 设置定点属性指针
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

        // 解绑
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // vertex-shader
    const char* vertext_shader_source = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        " gl_Position = vec4(aPos, 1.0);\n"
        "}\n\0";
    
    // frag-sahder
    const char* fragment_shader_source =  "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        " FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";

    // 生成并编译着色器
    // 顶点
    int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertext_shader_source, NULL);
    glCompileShader(vertex_shader);

    int success;
    char info_log[512];

    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
        std::cout << info_log << std::endl;
    }

    // frag
    int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);


    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
        std::cout << info_log << std::endl;
    }

    // vertex, shader链接到同一个
    int shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);

    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
        std::cout << info_log << std::endl;
    }

    // del shader
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    // 线框模式
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while(!glfwWindowShouldClose(window)) {
         processInput(window);

        glClearColor(0.0f, 0.34f, 0.57f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        // use
        glUseProgram(shader_program);
        

        glBindVertexArray(vertex_buffer_object); // VBO
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glDeleteVertexArrays(1, &vertex_array_object);
    glDeleteBuffers(1, &vertex_buffer_object);

    glfwTerminate();

    return 0;
    
}

void traignleShape_vao() {
    const float traingle[] = {
        -.5f, -.5f, 0.0f,
        .5f, -.5f, 0.0f,
        0.0f, .5f, 0.0f,
    };

    GLuint vertex_array_object;
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);
}