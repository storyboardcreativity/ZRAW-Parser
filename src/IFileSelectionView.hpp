#pragma once

#include <string>

#include <Event.h>
#include <IUserControl.hpp>

class IFileSelectionView : public IUserControl
{
public:
    DECLARE_EVENT(void, std::string path) EventOutputPathSelection;

    typedef enum CompressionMode_e
    {
        None,
        LosslessJPEG
    } CompressionMode_t;
    DECLARE_EVENT(void, CompressionMode_t mode) EventCompressionModeSelection;

    typedef enum RawScaleMode_e
    {
        Full,
        Half,
        Quarter
    } RawScaleMode_t;
    DECLARE_EVENT(void, RawScaleMode_t mode) EventRawScaleModeSelection;

    virtual void SetSelectedOutputPathFieldText(std::string path) = 0;

    virtual void SetStatusText(std::string text, bool isOk) = 0;

    virtual void SetActivity(bool isActive) = 0;

    virtual void SetCompressionMode(CompressionMode_t mode) = 0;

    virtual void SetRawScaleMode(RawScaleMode_t mode) = 0;
};
