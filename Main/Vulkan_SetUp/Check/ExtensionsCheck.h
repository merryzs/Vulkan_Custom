#pragma once
#include "../vk_Parameter.h"


class ExtensionsCheck
{
public:
    

    
    void RequiredExtensions();
    std::vector<const char* > requiredExtensions;
    static std::vector<char const *> GetRequiredExtensions();
private : 
    
    
    Parameter* parameter = nullptr;
};
