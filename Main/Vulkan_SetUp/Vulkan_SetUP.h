#pragma once
#include "../Dependency.h"

class Vulkan_SetUP
{
public:
    void createInstance();
    
    
private : 
    
    vk::raii::Context context;
    vk::raii::Instance instance;
    
    
};
