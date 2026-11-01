#include "Application.h"
#include "Vulkan_SetUp/Vulkan_SetUP.h"

void Application::init()
{
    initwindow();
    initVulkan();
}

void Application::run()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }
}

void Application::destroy()
{
    DestroyVulkan();
    DestroyWindow();
}

void Application::initwindow()
{
    glfwInit();
    
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    
    window =  glfwCreateWindow(width, height, "MoonLight", nullptr, nullptr);
}

void Application::initVulkan()
{
    vkSetUp = new Vulkan_SetUP();
    //vkSetUp->window = window;
    vkSetUp->createInstance();
}

void Application::DestroyWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Application::DestroyVulkan()
{
    delete vkSetUp;
    vkSetUp = nullptr;
}

void Application::MainLoop()
{
}

void Application::CleanUp()
{
}
