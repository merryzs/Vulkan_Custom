#pragma once
#include "ExtensionsCheck.h"
#include "vk_Parameter.h"

class Debugmessage
{
public:
    
    ExtensionsCheck* extensionsCheck = nullptr;
    
    void SetUpDebugmessenger();
    
    static VKAPI_ATTR vk::Bool32 VKAPI_CALL debugMessengerCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT severity,
        vk::DebugUtilsMessageTypeFlagsEXT Type,
        const vk::DebugUtilsMessengerCallbackDataEXT* pCallBackData,
        void *);
    
    vk::raii::DebugUtilsMessengerEXT debugMessenger = nullptr;
    
    Parameter* parameter = nullptr;
};
