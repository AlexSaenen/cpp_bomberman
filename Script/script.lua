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
	luaCall(object, "command", command)
end

-- search element
function	search_nearest_element()
	print("search_nearest_element")
	x, y, elem = luaCall(object, "radar")
	if elem == 0 then
	   luaCall(object, "command", UP)
	end
end

-- check if new position is safe or not
function	isSafe(ret, x, y, command)
	print("isSafe")
	if ret == EMPTY then
	   x, y, elem = luaCall(object, "checkBomb", x, y)
	   if elem == 0 then
		sendMove(command)
	   end
	end
end

-- avoid bombs and find safe zone
function	avoidBomb(x, y, elem)
	print("avoidBomb")
	if my_x < x and my_x > 0 then
	   ret = luaCall(object, "checkCase", my_x - 1, my_y)
	   isSafe(ret, my_x - 1, my_y, LEFT)
	elseif my_x > x and my_x < size_map then
	       ret = luaCall(object, "checkCase", my_x + 1, my_y)
	       isSafe(ret, my_x + 1, my_y, RIGHT)
	elseif my_y < y and my_y > 0 then
		ret = luaCall(object, "checkCase", my_x, my_y - 1)
		isSafe(ret, my_x, my_y - 1, DOWN)
	elseif my_y > y and my_y < size_map then
		ret = luaCall(object, "checkCase", my_x, my_y + 1)
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
	--while elem > 0 do
	      x, y, elem = luaCall(object, "checkBomb", my_x, my_y)
	      print(x)
	      print(y)
	      print(elem)
	      if elem > 0 then
		      avoidBomb(x, y, elem)
	      end
	--end
	search_nearest_element()
end