#pragma once
#include "../Dependency.h"
#include "ExtensionsCheck.h"

class Vulkan_SetUP
{
public:
    void createInstance();
    
    
private : 
    
    vk::raii::Context context;
    vk::raii::Instance instance;
    
    
    static std::vector<char const *> GetRequiredExtensions();
    
    
};
