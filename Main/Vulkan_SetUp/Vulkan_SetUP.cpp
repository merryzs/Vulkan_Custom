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
    
    std::vector requiredExtensions = GetRequiredExtensions();
    auto extensionProperties = context.enumerateInstanceExtensionProperties();
    
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

