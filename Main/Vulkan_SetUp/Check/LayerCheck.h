#pragma once
#include "../vk_Parameter.h"

class LayerCheck
{
public:
    Parameter* parameter = nullptr;
    
    void ValidateLayers();
    
private : 
    std::vector<const char*> requiredLayers;
    const std::vector<const char*> ValidationLayers = 
    {
        "VK_LAYER_KHRONOS_validation"
    };
};
