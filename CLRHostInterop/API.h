#pragma once

#include "ImageSource.h"
#include "SettingsPane.h"
#include "AbstractWPFSettingsPane.h"
#include "ImageSourceFactory.h"

using namespace System::Threading;
using namespace CLROBS;

class CLRHostApi;

namespace CLROBS 
{
    
    public ref class API
    {
    private:
        static API^ instance = nullptr;
    public:
        static property API^ Instance
        {
        public:
            API^ get() { return instance; }
        }
    private:
        CLRHostApi *clrHostApi;

    public:
        
        API(long long api)
        {
            instance = this;
            
            if (Application::Current == nullptr) {
                Application::Application().ShutdownMode = ShutdownMode::OnExplicitShutdown;
            }

            this->clrHostApi = reinterpret_cast<CLRHostApi *>(api);
        }

    public:
        void AddSettingsPane(SettingsPane^ settingsPane);
        void AddImageSourceFactory(ImageSourceFactory^ imageSourceFactory);
        IntPtr API::GetMainWindowHandle();
        void Log(System::String^ format, ...array<System::Object^> ^arguments);
        System::String^ GetPluginDataPath();
        void SetChangedSettings(bool isChanged);
        int GetMaxFPS();

		void SetSceneName(System::String^ sceneName, bool bPost);
		System::String^ GetSceneName();
    };
};