#include "LayerCheck.h"

#ifdef  NDEBUG 
constexpr bool enablevalidationLayers = false;
#else
constexpr bool enablevalidationLayers = true;
#endif

void LayerCheck::ValidateLayers()
{
    parameter = new Parameter();
    if (enablevalidationLayers)
    {
        requiredLayers.assign_range(ValidationLayers);
    }
    
    auto layerProperties = parameter->context.enumerateInstanceLayerProperties();
    auto unsupportedLayer = std::ranges::find_if(requiredLayers, [&layerProperties](auto const &requiredLayers )
    {
        return std::ranges::none_of(layerProperties, [requiredLayers] (auto const &LayerProperty)
        {
            return strcmp(LayerProperty.layerName, requiredLayers) == 0;
        });
    });
    
    if (unsupportedLayer != requiredLayers.end())
    {
        throw std::runtime_error("Unsupported layer " + std::string(*unsupportedLayer));
    }

}
