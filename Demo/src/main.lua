
require "config"

if DEBUG == 2 then --如果是模拟器，开启debug模式
	local breakSocketHandle, debugXpCall = require("LuaDebugjit")("localhost", 7004)
	cc.Director:getInstance():getScheduler():scheduleScriptFunc(function()
		breakSocketHandle();
	end, 0.3, false)
	G_DebugXpCall = debugXpCall
end

require "mime.core"
require "socket"
require "cjson"
require "cocos.init"
cc.exports.DebugManager = require "gxframework.utils.DebugManager"

local function main()
    require("app.MyApp"):create():run()
end

__G__TRACKBACK__ = function(msg)
    cc.exports.DebugManager.emit(debug.traceback( msg, 2))

    if G_DebugXpCall then
        G_DebugXpCall()
    end
end

local status, msg = xpcall(main, __G__TRACKBACK__)
