#include "ExtensionsCheck.h"



void ExtensionsCheck::RequiredExtensions()
{
    parameter = new Parameter();

    std::vector requiredExtensions = GetRequiredExtensions();
    auto extensionProperties = parameter->context.enumerateInstanceExtensionProperties();
    
    for (uint32_t i = 0; i < requiredExtensions.size(); ++i)
    {
        auto compareExtensions = [extension = requiredExtensions[i]](auto const& extensionProperty)
        {
            return strcmp(extensionProperty.extensionName, extension) == 0;  
        };
        
        if (std::ranges::none_of(extensionProperties, compareExtensions))
        {
            throw std::runtime_error("Required GLFW extensions not supported : " +std::string(requiredExtensions[i]));
        }
    }
}

std::vector<char const*> ExtensionsCheck::GetRequiredExtensions()
{
    uint32_t glfw_extensions_count = 0;
    auto glfwExtensions = glfwGetRequiredInstanceExtensions(&glfw_extensions_count);
    
    std::vector requiredExtensions =  { vk::EXTDebugUtilsExtensionName};
    std::vector extensions( glfwExtensions, glfwExtensions + glfw_extensions_count );
    
    extensions.append_range(requiredExtensions);
    return extensions;
}
