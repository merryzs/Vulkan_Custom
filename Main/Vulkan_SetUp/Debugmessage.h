#pragma once
#include "vk_Parameter.h"

class Debugmessage
{
public:
    
    void SetUpDebugmessenger();
    

    
    vk::raii::DebugUtilsMessengerEXT debugMessenger = nullptr;
    
    Parameter* parameter = nullptr;
    
private:
    
    static VKAPI_ATTR vk::Bool32 VKAPI_CALL debugMessengerCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT severity,
    vk::DebugUtilsMessageTypeFlagsEXT type,
    const vk::DebugUtilsMessengerCallbackDataEXT* pCallBackData,
    void *);
};
