#pragma once
#include "../vk_Parameter.h"

class LayerCheck
{
public:
    Parameter* parameter = nullptr;
    std::vector<const char*> requiredLayers;

    
    void ValidateLayers();
    
private : 
    const std::vector<const char*> ValidationLayers = 
    {
        "VK_LAYER_KHRONOS_validation"
    };
};
