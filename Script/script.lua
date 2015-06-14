my_x = 0
my_y = 0
my_range = 0
my_object = 0
size_map = 0

EMPTY, INDESC, DESC = 0, 1, 2
UP, DOWN, RIGHT, LEFT, BOMB = 0, 1, 2, 3, 4

-- Send the move
function	sendMove(command)
	print("SendMove")
	luaCall(my_object, "command", command)
end

function	dropBomb(x, y)
	print("Drop Bomb")
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
	print("info enemy")
	print(x)
	print(y)
	print("attack enemy")
	dropBomb(x, y)
	if my_x < x then
	   ret = luaCall(my_object, "checkCase", my_x + 1, my_y)
	   isSafe(ret, my_x + 1, my_y, LEFT)
	   print("right if")
	end
	if my_x > x then
		ret = luaCall(my_object, "checkCase", my_x - 1, my_y)
		isSafe(ret, my_x - 1, my_y, RIGHT)
	   print("left if")
	end
	if my_y < y then
	       ret = luaCall(my_object, "checkCase", my_x, my_y + 1)
	       isSafe(ret, my_x, my_y + 1, UP)
	   print("UP if")
	end
	if my_y > y then
		ret = luaCall(my_object, "checkCase", my_x, my_y - 1)
		isSafe(ret, my_x, my_y - 1, DOWN)
	   print("DOwn if")
	end
end

function	take_bonus(x, y)
	print("take bonus")
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

--search enemy test
--function	enemy(x, y)
--	print("enemy v2")
--	ret = luaCall(my_object, "checkCase", my_x + 1, my_y)
--	print(ret)
--	if ret == EMPTY then
--	       print("EMPTY")
--		sendMove(LEFT)
--	end
--	ret = luaCall(my_object, "checkCase", my_x - 1, my_y)
--	print(ret)
--	if ret == EMPTY then
--	   print("Empty second")
--	   sendMove(RIGHT)
--	end
--end

-- search element
function	search_nearest_element()
	print("search_nearest_element")
	x, y, elem = luaCall(my_object, "radar")
	print(x)
	print(y)
	print(elem)
	if elem == 0 then
	   luaCall(my_object, "command", UP)
	elseif elem == 1 then
		attack_enemy(x, y)
	--elseif elem == 2 then
	--       take_bonus(x, y)
	end
end

-- check if new position is safe or not
function	isSafe(ret, x, y, command)
	print("isSafe")
	print(ret)
	print(command)
	if ret == EMPTY then
	   x, y, elem = luaCall(my_object, "checkBomb", x, y)
	   print(elem)
	   if elem == 0 then
		sendMove(command)
	   end
	end
end

-- avoid bombs and find safe zone
function	avoidBomb(x, y, elem)
	print("avoidBomb")
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
	print(ret)
end


-- Run Script
function	run(object, x, y, range, size)
	io.write("Script Loaded\n")
	print(x)
	print(y)
	print(range)
	my_x = x
	my_y = y
	my_range = range
	elem = 1
	my_object = object
	size_map = size
	print("luacall")
	x, y, elem = luaCall(object, "checkBomb", my_x)
	if elem > 0 then
	      avoidBomb(x, y, elem)
	end
	search_nearest_element()
end