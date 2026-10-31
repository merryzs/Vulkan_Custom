#include "ExtensionsCheck.h"



std::vector<char const*> ExtensionsCheck::GetRequiredExtensions()
{
    uint32_t glfw_extensions_count = 0;
    auto glfwExtensions = glfwGetRequiredInstanceExtensions(&glfw_extensions_count);
    
    std::vector requiredExtensions =  { vk::EXTDebugUtilsExtensionName};
    std::vector extensions( glfwExtensions, glfwExtensions + glfw_extensions_count );
    
    extensions.append_range(requiredExtensions);
    return extensions;
}