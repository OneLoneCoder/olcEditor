#pragma once

#include <wx/glcanvas.h>
#include "common.h"
#include "cMasterContext.h"

class cImageResource
{
public:
    cImageResource(cMasterContext* glContext);
    virtual ~cImageResource();

    bool SetImage(const std::string& sFilename);
    void UseImage();
    void Update();
    const std::string& GetFilePath() const;
    const std::string& GetFriendlyName() const;
    uint32_t GetHardwareID() const;
    uint32_t GetProjectID() const;
    olc::Sprite* GetSprite() const;
   
private:
    cMasterContext* m_gl = nullptr;
    std::unique_ptr<olc::Sprite> m_pSprite = nullptr;
    uint32_t m_nProjectID = 0;
    uint32_t m_nHardwareID = 0;
    std::string m_sFilePath;
    std::string m_sFriendlyName;
};

