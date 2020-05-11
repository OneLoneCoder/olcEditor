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
    void SetFriendlyName(const std::string& sName);
    void UseImage();
    void Update();
    void SetGridSize(const olc::vi2d& size);
    void SetGridOffset(const olc::vi2d& offset);
    void SetGridSpacing(const olc::vi2d& spacing);

    const olc::vi2d& GetGridSize() const;
    const olc::vi2d& GetGridOffset() const;
    const olc::vi2d& GetGridSpacing() const;

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
    olc::vi2d m_vGridOffset;
    olc::vi2d m_vGridSpacing;
    olc::vi2d m_vGridSize = { 16, 16 };
};

