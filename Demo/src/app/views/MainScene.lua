require "gxframework.utils.protobuf"

local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    self:createResourceNode("layer/update/login_layer.csb")
    -- add background image
    display.newSprite("HelloWorld.png")
    :move(display.center)
    :addTo(self)

    -- add HelloWorld label
    cc.Label:createWithSystemFont("Hello World", "Arial", 40)
    :move(display.cx, display.cy + 200)
    :addTo(self)

    math.randomseed(os.time())
    cc.Label:createWithBMFont("fnt_cn2.fnt", cc.MD5:get("xxx", false))
        :move(display.cx, display.cy + math.random(100, 300))
        :addTo(self)

    local url = "http://115.182.62.13:7011/login13.html?type=3&account=hb02@qq.com&password=96e79218965eb72c92a549dd5a330112&machineId=Gx10003&phone=windows&sysver=windows&sign=b8c7eedbd2b96b2b5b25cebf63969834&day=17739&channel=1"
    -- url = "http://ftp.apnic.net/stats/apnic/delegated-apnic-latest"
    -- local jsondata = {}
    -- for i=1, 10000000 do
    --     jsondata[i] = "xx"
    -- end
    -- local time = cc.exports.socket.gettime()
    -- local str  = cc.exports.json.encode(jsondata)
    -- print("xxGx:" .. socket.gettime() - time)
    -- time = cc.exports.socket.gettime()

    -- local obj = cc.exports.json.decode(str)

    -- time = cc.exports.socket.gettime() - time
    -- print("xxGx:" .. time)
    local xhr =  cc.XMLHttpRequest:new()
    xhr.responseType = cc.XMLHTTPREQUEST_RESPONSE_STRING
    xhr:open("GET", url)
    -- 状态改变时调用
    local function onReadyStateChange()
        -- 显示状态文本
        local statusString = "Http Status Code:"..xhr.statusText
        local a = cc.exports.mime.unb64(xx)
        local data = cc.exports.cjson.decode(xhr.response)
        print("xxGx:" .. xhr.response)
    end
    -- 注册脚本回调方法
    xhr:registerScriptHandler(onReadyStateChange)
    xhr:send()
end

function MainScene:onEnterTransitionFinish()
    self:runAction(cc.Sequence:create(
        cc.DelayTime:create(0.1),
        cc.CallFunc:create(handler(self, self.parseProtocal))
    ))
end

function MainScene:parse()

    local json = require("cjson")
    local filePath  = cc.FileUtils:getInstance():fullPathForFilename("info.json")
    local f = io.open( filePath, "r" )
    local t = f:read( "*all" )
    f:close()
    if nil ~= t and "" ~= t then
         local jsonData = json.decode( t )
         if jsonData == nil then
             print("Json error")
         end
         
         for k,v in pairs( jsonData ) do
             print(k, v)
         end
      else
         print("data was empty")
      end
    -- local data = require("app.views.info")


end

function MainScene:parseProtocal()

    local pbFilePath = cc.FileUtils:getInstance():fullPathForFilename("common.pb")
    release_print("PB file path: "..pbFilePath)
 
    local buffer = read_protobuf_file_c(pbFilePath)    
    protobuf.register(buffer) --注:protobuf 是因为在protobuf.lua里面使用module(protobuf)来修改全局名字
    
    pbFilePath = cc.FileUtils:getInstance():fullPathForFilename("task.pb")
    release_print("PB file path: "..pbFilePath)
 
    buffer = read_protobuf_file_c(pbFilePath)
    protobuf.register(buffer) --注:protobuf 是因为在protobuf.lua里面使用module(protobuf)来修改全局名字
 
    local stringbuffer = protobuf.encode("protobuf.task.Achievement",
        {    
            status = 2,    
            id = 12345,    
            value = 3  
        })    
       
    local slen = string.len(stringbuffer)    
    local temp = ""    
    for i=1, slen do    
        temp = temp .. string.format("0xX, ", string.byte(stringbuffer, i))    
    end
    local result = protobuf.decode("protobuf.task.Achievement", stringbuffer)

    cc.exports.DebugManager.emit(temp .. "\n" .. result.status)

end

return MainScene
