#pragma once
#include "../vk_Parameter.h"


class ExtensionsCheck
{
public:
    
    vk::raii::Instance instance;

    void RequiredExtensions();
    static std::vector<char const *> GetRequiredExtensions();
private : 
    Parameter* parameter = nullptr;
};
