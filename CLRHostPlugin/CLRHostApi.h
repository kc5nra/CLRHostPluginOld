#pragma once

#include <string>
#include <map>

#include "CLRApiCommon.h"
#include "CLRObjectRef.h"
#include "CLRImageSourceFactory.h"

class CLRHostApi 
{
private:
    std::map<std::wstring, CLRImageSourceFactory *> imageSourceFactories;

public:
    ~CLRHostApi();
public:
    CLR_API void AddSettingsPane(CLRObjectRef &clrObjectReference);
    CLR_API void AddImageSourceFactory(CLRObjectRef &clrObjectReference);
	CLR_API void SetSceneName(const TCHAR * sceneName, bool bPost);
	CLR_API const TCHAR * GetSceneName();

public:
    std::map<std::wstring, CLRImageSourceFactory *> &GetImageSourceFactories() { return imageSourceFactories; }
};