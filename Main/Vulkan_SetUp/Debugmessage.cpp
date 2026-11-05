#include "Debugmessage.h"

#ifdef NDEBUG
constexpr bool enableDebugMessage = false;
#else
constexpr bool enableDebugMessage = true;
#endif


void Debugmessage::SetUpDebugmessenger()
{
    if (!enableDebugMessage) return;
    
    
    parameter = new Parameter();
    //severity message
    vk::DebugUtilsMessageSeverityFlagsEXT severity(vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning |
        vk::DebugUtilsMessageSeverityFlagBitsEXT::eError);
   
//type messsage
    vk::DebugUtilsMessageTypeFlagsEXT type( vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral | 
        vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance | 
        vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation);

    
    vk::DebugUtilsMessengerCreateInfoEXT createInfo 
    {
        .messageSeverity = severity ,
        .messageType = type ,
        .pfnUserCallback = &debugMessengerCallback
    };
    debugMessenger = parameter->instance.createDebugUtilsMessengerEXT( createInfo );
    
}

vk::Bool32 Debugmessage::debugMessengerCallback(vk::DebugUtilsMessageSeverityFlagBitsEXT severity,
    vk::DebugUtilsMessageTypeFlagsEXT type, const vk::DebugUtilsMessengerCallbackDataEXT* pCallBackData, void*)
{
    if (severity == vk::DebugUtilsMessageSeverityFlagBitsEXT::eError || severity == vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning)
    {
        std::cerr << "validation layer : type" << to_string(type) << "msg : " << pCallBackData << std::endl;
    }
    return vk::False;
}

