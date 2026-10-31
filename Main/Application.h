#pragma once
#include "Vulkan_SetUp/Vulkan_SetUP.h"

class Application
{
public:
    
    GLFWwindow* window = nullptr;
    Vulkan_SetUP* vkSetUp = nullptr;
    
    int width = 1280;
    int height = 720;
   
    
    void init();
    void run();
    void destroy();
    
private : 
    
    void initwindow();
    void initVulkan();
    void DestroyWindow();
    void DestroyVulkan();
    void MainLoop();
    void CleanUp(); 
    
};
