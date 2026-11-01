#pragma once
#include "vk_Parameter.h"


class ExtensionsCheck
{
public:
    vk::raii::Instance instance;

    static std::vector<char const *> GetRequiredExtensions();
};
