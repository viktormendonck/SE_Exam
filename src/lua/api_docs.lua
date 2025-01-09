---@meta


--global values
---elapsed time since last frame
---@type number
deltaTime = 0.0


--containers

---basic Color container
---@class Color
---@field r integer red component.
---@field g integer green component.
---@field b integer blue component.
Color = {}

---construct color component 
---@param r integer red component.
---@param g integer green component.
---@param b integer blue component.
---@return Color Color Constructed color
function Color.new(r, g, b) end

---basic vector container
---@class Vector2f
---@field x number x component
---@field y number y component
Vector2f = {}

---make new vector
---@param x number x component
---@param y number y component
---@return Vector2f vector Constructed vector
function Vector2f.new(x, y) end

---get distance between vectors
---@param other Vector2f the vector to compare to
---@return number DistanceSquared the squared distance between this and other
function Vector2f.DistSq(other) end

--drawing funcs

--- Static object for various drawing operations.
--- @class Draw
Draw = {}

---set the color for the following draw's
---@param color Color
function Draw.SetColor(color) end

---fill the screen with a single color
---@param color Color
function Draw.FillWindowRect(color) end

---draw a line between the given positions
---@param p1 Vector2f pos 1
---@param p2 Vector2f pos 2
---@return boolean succeeded
function Draw.DrawLine(p1, p2) end

---draw a rectangle using the 2 corner positions
---@param p1 Vector2f top right point
---@param p2 Vector2f bottom left point
---@return boolean succeeded
function Draw.DrawRect(p1, p2) end

---draw a filled rectangle using the corner positions
---@param p1 Vector2f top right point
---@param p2 Vector2f bottom left point
---@param opacity number how much the rect is filled
---@return boolean succeeded
function Draw.DrawRect(p1, p2, opacity) end

---draw a rounded rectangle using the corner positions
---@param p1 Vector2f top right point
---@param p2 Vector2f bottom left point
---@param radius number how much the corners are rounded
---@return boolean succeeded
function Draw.DrawRoundRect(p1, p2, radius) end

---draw a fill rounded rectangle using the corner positions
---@param p1 Vector2f top right point
---@param p2 Vector2f bottom left point
---@param radius number how much the corners are rounded
---@return boolean succeeded
function Draw.FillRoundRect(p1, p2, radius) end

---draw a oval using the 2 corner positions
---@param p1 Vector2f top right point
---@param p2 Vector2f bottom left point
---@return boolean succeeded
function Draw.DrawOval(p1, p2) end

---draw a filled oval using the corner positions
---@param p1 Vector2f top right point
---@param p2 Vector2f bottom left point
---@param opacity number how much the oval is filled
---@return boolean succeeded
function Draw.DrawOval(p1, p2, opacity) end

---draw a arc using the 2 corner positions
---@param p1 Vector2f top right point
---@param p2 Vector2f bottom left point
---@param startDegree integer the direction the arc starts in
---@param angle integer the angle of the arc
---@return boolean succeeded
function Draw.DrawArc(p1, p2,startDegree,angle) end

---draw a filled arc using the corner positions
---@param p1 Vector2f top right point
---@param p2 Vector2f end point
---@param startDegree integer the direction the arc starts in
---@param angle integer the angle of the arc
---@return boolean succeeded
function Draw.FillArc(p1, p2,startDegree,angle) end

---print out a string using the current font
---@param text string what you will be printing
---@param p Vector2f the point where you are drawing the text
---@return boolean succeeded
function Draw.DrawString(text, p) end

---print out a string and stretches it into the given rect
---@param text string what you will be printing
---@param p1 Vector2f top left of the rect
---@param p2 Vector2f bottom right of the rect
---@return boolean succeeded
function Draw.DrawStretchedString(text, p1,p2) end

---return the current used color
---@return Color
function Draw.GetDrawColor() end

---Redraw the screen (should be in the beginning of your draw, doesnt happen in very specific situations)
function Draw.Redraw() end

--engine utils
--- Static object for various engine utilities
---@class Utils
Utils = {}

---Set the title of the game window.
---@param title string The title to set.
function Utils.SetTitle(title) end

---Set the position of the game window.
---@param pos Vector2f The position to set.
function Utils.SetWindowPosition(pos) end

---Set the frame rate of the game.
---@param frameRate integer The frame rate to set.
function Utils.SetFrameRate(frameRate) end

---Set the width of the game window.
---@param width integer The width to set.
function Utils.SetWidth(width) end

---Set the height of the game window.
---@param height integer The height to set.
function Utils.SetHeight(height) end

---Switch the game to fullscreen mode.
---@return boolean succeeded
function Utils.GoFullscreen() end

---Switch the game to windowed mode.
---@return boolean succeeded
function Utils.GoWindowedMode() end

---Show or hide the mouse pointer.
---@param value boolean Whether to show the mouse pointer.
function Utils.ShowMousePointer(value) end

---Quit the game.
function Utils.Quit() end

---Check if the game is in fullscreen mode.
---@return boolean
function Utils.IsFullscreen() end

---Check if a key is currently pressed down.
---@param key integer The key to check.
---@return boolean
function Utils.IsKeyDown(key) end

---Get the title of the game window.
---@return string
function Utils.GetTitle() end

---Get the width of the game window.
---@return integer
function Utils.GetWidth() end

---Get the height of the game window.
---@return integer
function Utils.GetHeight() end

---Get the frame rate of the game.
---@return integer
function Utils.GetFrameRate() end

---Get the frame delay of the game.
---@return integer
function Utils.GetFrameDelay() end