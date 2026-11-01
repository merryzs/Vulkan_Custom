#include "Debugmessage.h"


void Debugmessage::SetUpDebugmessenger()
{
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
    debugMessenger = extensionsCheck->instance.createDebugUtilsMessengerEXT( createInfo );
    
}
