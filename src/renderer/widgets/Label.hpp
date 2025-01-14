#pragma once

#include "IWidget.hpp"
#include "../../helpers/Vector2D.hpp"
#include "../../core/Timer.hpp"
#include "../AsyncResourceGatherer.hpp"
#include <string>
#include <unordered_map>
#include <any>

struct SPreloadedAsset;
class CSessionLockSurface;

class CLabel : public IWidget {
  public:
    CLabel(const Vector2D& viewport, const std::unordered_map<std::string, std::any>& props, CSessionLockSurface* surface_);
    ~CLabel();

    virtual bool draw(const SRenderData& data);

    void         renderSuper();
    void         onTimerUpdate();
    void         plantTimer();

  private:
    std::string                             labelPreFormat;
    IWidget::SFormatResult                  label;

    Vector2D                                viewport;
    Vector2D                                pos;
    Vector2D                                configPos;
    std::string                             resourceID;
    std::string                             pendingResourceID; // if dynamic label
    std::string                             halign, valign;
    SPreloadedAsset*                        asset   = nullptr;
    CSessionLockSurface*                    surface = nullptr;

    CAsyncResourceGatherer::SPreloadRequest request;

    std::shared_ptr<CTimer>                 labelTimer;
};