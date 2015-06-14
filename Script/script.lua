my_x = 0
my_y = 0
my_range = 0
my_object = 0
size_map = 0

EMPTY, INDESC, DESC = 0, 1, 2
UP, DOWN, RIGHT, LEFT, BOMB, NONE = 0, 1, 2, 3, 4, 5

-- Send the move
function	sendMove(command)
	--luaCall(my_object, "command", command)
	if command == UP then
		ret = luaCall(my_object, "checkCase", my_x, my_y + 1)
		if ret == EMPTY then
			luaCall(my_object, "command", command)
		end
	elseif command == DOWN then
		ret = luaCall(my_object, "checkCase", my_x, my_y - 1)
		if ret == EMPTY then
			luaCall(my_object, "command", command)
		end
	elseif command == LEFT then
		ret = luaCall(my_object, "checkCase", my_x + 1, my_y)
		if ret == EMPTY then
			luaCall(my_object, "command", command)
		end
	elseif command == BOMB then
		luaCall(my_object, "command", BOMB)
	elseif command == RIGHT then
		ret = luaCall(my_object, "checkCase", my_x - 1, my_y - 1)
		if ret == EMPTY then
			luaCall(my_object, "command", command)
		end
	else
		luaCall(my_object, "command", NONE)
	end		
end

function	dropBomb(x, y)
	if my_x < x and my_x + my_range >= x then
		sendMove(BOMB)
	end
	if my_x > x and my_x - my_range <= x then
		sendMove(BOMB)
	end
	if my_y < y and my_y + my_range >= y then
		sendMove(BOMB)
	end
	if my_y > y and my_y - my_range <= y then
		sendMove(BOMB)
	end
	if my_y == y and my_x == y then
		sendMove(BOMB)
	end
	return
end

function	attack_enemy(x, y)
	dropBomb(x, y)
	if my_x < x then
	   ret = luaCall(my_object, "checkCase", my_x + 1, my_y)
	   isSafe(ret, my_x + 1, my_y, LEFT)
	--end
	elseif my_x > x then
		ret = luaCall(my_object, "checkCase", my_x - 1, my_y)
		isSafe(ret, my_x - 1, my_y, RIGHT)
	--end
	elseif my_y < y then
	       ret = luaCall(my_object, "checkCase", my_x, my_y + 1)
	       isSafe(ret, my_x, my_y + 1, UP)
	--end
	elseif my_y > y then
		ret = luaCall(my_object, "checkCase", my_x, my_y - 1)
		isSafe(ret, my_x, my_y - 1, DOWN)
	else
		sendMove(NONE)
	end
end

function	take_bonus(x, y)
	if my_x < x then
	   ret = luaCall(my_object, "checkCase", my_x + 1, my_y)
	   isSafe(ret, my_x + 1, my_y, RIGHT)
	elseif my_x > x then
		ret = luaCall(my_object, "checkCase", my_x - 1, my_y)
		isSafe(ret, my_x - 1, my_y, LEFT)
	elseif my_y < y then
	       ret = luaCall(my_object, "checkCase", my_x, my_y + 1)
	       isSafe(ret, my_x, my_y + 1, UP)
	elseif my_y > y then
		ret = luaCall(my_object, "checkCase", my_x, my_y - 1)
		isSafe(ret, my_x, my_y - 1, DOWN)
	end
end

-- search element
function	search_nearest_element()
	x, y, elem = luaCall(my_object, "radar")
	if elem == 0 then
	   luaCall(my_object, "command", UP)
	elseif elem == 1 then
		attack_enemy(x, y)
	elseif elem == 2 then
	       take_bonus(x, y)
	end
end

-- check if new position is safe or not
function	isSafe(ret, x, y, command)
	if ret == EMPTY then
	   x, y, elem = luaCall(my_object, "checkBomb", x, y)
	   if elem == 0 then
		sendMove(command)
	   end
	end
end


-- avoid bombs and find safe zone
function	avoidBomb(x, y, elem)
	if my_x < x and my_x > 0 then
	   ret = luaCall(my_object, "checkCase", my_x - 1, my_y)
	   isSafe(ret, my_x - 1, my_y, LEFT)
	elseif my_x > x and my_x < size_map then
	       ret = luaCall(my_object, "checkCase", my_x + 1, my_y)
	       isSafe(ret, my_x + 1, my_y, RIGHT)
	elseif my_y < y and my_y > 0 then
		ret = luaCall(my_object, "checkCase", my_x, my_y - 1)
		isSafe(ret, my_x, my_y - 1, DOWN)
	elseif my_y > y and my_y < size_map then
		ret = luaCall(my_object, "checkCase", my_x, my_y + 1)
		isSafe(ret, my_x, my_y + 1, UP)
	end
end


-- Run Script
function	run(object, x, y, range, size)
	my_x = x
	my_y = y
	my_range = range
	elem = 1
	my_object = object
	size_map = size
	x, y, elem = luaCall(object, "checkBomb", my_x)
	if elem > 0 then
	      avoidBomb(x, y, elem)
	end
	search_nearest_element()
end