#include "Vulkan_SetUP.h"

void Vulkan_SetUP::createInstance()
{
    layer = new LayerCheck();
    extensions = new ExtensionsCheck();
    
    constexpr vk::ApplicationInfo appInfo 
    {
        .pApplicationName = "Moteur?",
        .applicationVersion = VK_MAKE_VERSION(1,0,0),
        .pEngineName = "Moon",
        .engineVersion = VK_MAKE_VERSION(1,0,0),
        .apiVersion = vk::ApiVersion14
    };
    
   extensions->RequiredExtensions();
    layer->ValidateLayers();
    

    
    vk::InstanceCreateInfo CreateInfo{
        .pApplicationInfo = &appInfo,
        .enabledLayerCount = static_cast<uint32_t>(layer->requiredLayers.size()),
        .ppEnabledLayerNames = layer->requiredLayers.data(),
        .enabledExtensionCount =  static_cast<uint32_t>(extensions->requiredExtensions.size()),
        .ppEnabledExtensionNames = extensions->requiredExtensions.data()
    };
    parameter->instance = vk::raii::Instance(parameter->context, CreateInfo);
    
    
    debugmessage->SetUpDebugmessenger();
    
}

