--this file is a framework to make a new game in
deltaTime = 0
local BackGroundColor = Color.new(10,10,10)

function Init()
    Utils.SetFrameRate(60)
    Utils.SetHeight(1024)
    Utils.SetWidth(1024)
end

function Start()
end

function End()
end

function Update(deltaT)
    deltaTime = deltaT

end

function DrawFunc()
    Draw.FillWindowRect(BackGroundColor) --clear display

end

function MouseButtonAction(isLeft, isDown, pos)
    
end

function MouseWheelAction(pos, amount)

end

function MouseMove(pos)
end

function CheckKeyboard()
    
end

function UpdateGrid()
    
end


