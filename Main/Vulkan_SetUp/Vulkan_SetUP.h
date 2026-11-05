#pragma once
#include "vk_Parameter.h"
#include "Check/LayerCheck.h"
#include "Check/ExtensionsCheck.h"
#include "Debugmessage.h"

class Vulkan_SetUP
{
public:
    void createInstance();
    
    Parameter* parameter = nullptr;    
    LayerCheck* layer = nullptr;
    ExtensionsCheck* extensions = nullptr;
    Debugmessage* debugmessage = nullptr;
    
private : 
    

    
    
    
};
