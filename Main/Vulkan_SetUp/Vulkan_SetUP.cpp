#include "Vulkan_SetUP.h"

void Vulkan_SetUP::createInstance()
{
    constexpr vk::ApplicationInfo appInfo 
    {
        .pApplicationName = "Moteur?",
        .applicationVersion = VK_MAKE_VERSION(1,0,0),
        .pEngineName = "Moon",
        .engineVersion = VK_MAKE_VERSION(1,0,0),
        .apiVersion = vk::ApiVersion14
    };
}
