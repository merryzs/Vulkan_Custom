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
    
   
    

    
    vk::InstanceCreateInfo CreateInfo{
        .pApplicationInfo = &appInfo,
        .enabledLayerCount = static_cast<uint32_t>(requiredLayer.size()),
        .ppEnabledLayersNames = requiredLayer.data(),
        .enabledExtensionCount =  static_cast<uint32_t>(requiredExtensions.size()),
        .ppEnabledExtensionNames = glfwExtensions
    };
    extensions_check->instance = vk::raii::Instance(parameter->context,CreateInfo);
}

