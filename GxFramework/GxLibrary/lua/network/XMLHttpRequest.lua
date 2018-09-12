
local XMLHttpRequest = class("XMLHttpRequest", function()
    return cc.XMLHttpRequest:new()
end)

function XMLHttpRequest:ctor(url, sucessCallFunc, failCallFunc, method, responseType)

    self.sucessFunc   = sucessCallFunc or function()
    end
    self.failFunc     = failCallFunc or function()
    end
    self.responseType = responseType or cc.XMLHTTPREQUEST_RESPONSE_STRING
    self.timeout      = 5
    self:registerScriptHandler(handler(self, self.onReadStateChange))
    self:open("GET", url)
end

function XMLHttpRequest:onReadStateChange()
    if self.status == 200 then
        self.sucessFunc(cc.exports.cjson.decode(self.responseText))
    else
        self.failFunc(self.status)
    end
end

-- 请求
function XMLHttpRequest:request(url, sucessCallFunc, failCallFunc, uData, responseType)
    local xhr = XMLHttpRequest.new(url, sucessCallFunc, failCallFunc, uData)
    xhr:send()
    return xhr
end

return XMLHttpRequest