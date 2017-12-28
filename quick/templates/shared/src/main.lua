package.path = package.path .. ";src/"

local breakSocketHandle, debugXpCall = require("LuaDebug")("localhost", 7003)
cc.Director:getInstance():getScheduler():scheduleScriptFunc(breakSocketHandle, 0.3, false)

function __G__TRACKBACK__(errorMessage)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(errorMessage) .. "\n")
    print(debug.traceback("", 2))
    print("----------------------------------------")
    debugXpCall()
end

cc.FileUtils:getInstance():setPopupNotify(false)
require("app.MyApp").new():run()
