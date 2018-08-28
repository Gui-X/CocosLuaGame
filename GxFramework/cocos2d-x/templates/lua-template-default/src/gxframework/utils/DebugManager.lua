local DebugManager = {}
DebugManager.DEBUG_EVENT = "event.handle.debug.error"

local function init()
    cc.bind(DebugManager, "event")
    DebugManager:addEventListener(DebugManager.DEBUG_EVENT, function(event)
        
        print(event.msg )
    
        local layer = display.newLayer(cc.c4b(100, 0, 0, 100))
                        :setContentSize(cc.size(display.width, display.height))
                        :setIgnoreAnchorPointForPosition(false)
                        :setAnchorPoint(cc.p(0.5, 0.5))
                        :setPosition(cc.p(display.cx, display.cy))
                        :addTo(display.getRunningScene(), 9999)
    
        cc.Label:createWithSystemFont(event.msg , "Arial", 16)
            :move(display.cx, 300)
            :setAnchorPoint(0, 1)
            :setPosition(10, display.height - 10)
            :addTo(layer)
    end)
end

DebugManager.emit = function(msg)
    DebugManager:dispatchEvent({name = DebugManager.DEBUG_EVENT, msg = msg})
end

init()

return DebugManager