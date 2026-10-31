#pragma once



class Application
{
public:
    
    void init();
    void run();
    void destroy();
    
private : 
    
    void initwindow();
    void initVulkan();
    void MainLoop();
    void CleanUp(); 
    
};
