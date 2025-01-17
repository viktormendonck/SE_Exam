deltaTime = 0
local updateCountdown = 0
local maxUpdateCountDown = 0.3
local BackGroundColor = Color.new(10, 10, 10)
local gridLineColor = Color.new(100, 100, 100)
local successColor = Color.new(200,100,100)
local grid
local gridSize = 100
local cellSize = 10
local buttonUpColor = Color.new(128, 128, 128)
local buttonDownColor = Color.new(80,80,80)
local buttonPos = { x = 10, y = 10, size = 100 }
local isRunning = false

function Init()
    Utils.SetFrameRate(60)
    Utils.SetTitle("Conway's game of life")
    Utils.SetHeight(gridSize * cellSize)
    Utils.SetWidth(gridSize * cellSize)
    grid = {}
    for i = 1, gridSize do
        grid[i] = {}
        for j = 1, gridSize do
            --grid[i][j] = math.random(0,1)
            grid[i][j] = 0
        end
    end
end

function Start()
    print("Game of Life started")
    updateCountdown = maxUpdateCountDown
end

function End()
end

function Update(deltaT)
    deltaTime = deltaT
    if updateCountdown < 0.0 then
        UpdateGrid()
        updateCountdown = maxUpdateCountDown
    elseif isRunning then
        updateCountdown = updateCountdown - deltaTime
    end
end

function DrawFunc()
    Draw.FillWindowRect(BackGroundColor) -- clear display
    Draw.SetColor(successColor)
    for i = 1, gridSize do
        for j = 1, gridSize do  
            if grid[i][j] == 1 then
                
                local p1 = Vector2f.new((i - 1) * cellSize, (j - 1) * cellSize)
                local p2 = Vector2f.new(i * cellSize, j * cellSize)
                Draw.FillRect(p1, p2, 255)
            end
        end
    end
    DrawGridLines()
    
    -- Draw the button
    if isRunning then
        Draw.SetColor(buttonDownColor)
    else 
        Draw.SetColor(buttonUpColor)
    end
    local p1 = Vector2f.new(buttonPos.x, buttonPos.y)
    local p2 = Vector2f.new(buttonPos.x + buttonPos.size, buttonPos.y + buttonPos.size)
    
    Draw.FillRect(p1, p2, 255)
    
end



function MouseButtonAction(isLeft, isDown, pos)
    if isLeft and isDown then
        if pos.x >= buttonPos.x and pos.x <= buttonPos.x + buttonPos.size and
           pos.y >= buttonPos.y and pos.y <= buttonPos.y + buttonPos.size then
            isRunning = not isRunning
            print("Game " .. (isRunning and "started" or "paused"))
           elseif not isRunning then
            local gridX = (pos.x / cellSize) + 1
            local gridY = (pos.y / cellSize) + 1
            gridX = gridX - (gridX%1)
            gridY = gridY - (gridY%1)
            if gridX > 0 and gridX <= gridSize and gridY > 0 and gridY <= gridSize then
                grid[gridX][gridY] = 1 - grid[gridX][gridY]
            end
        end
    end
end

function MouseWheelAction(pos, amount)
end

function MouseMove(pos)
end

function CheckKeyboard()
end

function UpdateGrid()
    local newGrid = {}
    for i = 1, gridSize do
        newGrid[i] = {}
        for j = 1, gridSize do
            local aliveNeighbors = CountAliveNeighbors(i, j)
            if grid[i][j] == 1 then
                if aliveNeighbors < 2 or aliveNeighbors > 3 then
                    newGrid[i][j] = 0
                else
                    newGrid[i][j] = 1
                end
            else
                if aliveNeighbors == 3 then
                    newGrid[i][j] = 1
                else
                    newGrid[i][j] = 0
                end
            end
        end
    end
    grid = newGrid
end

function CountAliveNeighbors(x, y)
    local count = 0
    for i = -1, 1 do
        for j = -1, 1 do
            if not (i == 0 and j == 0) then
                local ni = x + i
                local nj = y + j
                if ni > 0 and ni <= gridSize and nj > 0 and nj <= gridSize then
                    count = count + grid[ni][nj]
                end
            end
        end
    end
    return count
end

function DrawGridLines()
    Draw.SetColor(gridLineColor) -- Set grid line color
    for i = 0, gridSize do
        local x = i * cellSize
        local y1 = 0
        local y2 = gridSize * cellSize
        Draw.DrawLine(Vector2f.new(x, y1), Vector2f.new(x, y2))
    end
    for j = 0, gridSize do
        local y = j * cellSize
        local x1 = 0
        local x2 = gridSize * cellSize
        Draw.DrawLine(Vector2f.new(x1, y), Vector2f.new(x2, y))
    end
end