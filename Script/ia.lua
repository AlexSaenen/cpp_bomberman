-- function test lua_register
function	test(one, two, three)
	io.write("Script ....\n")
	a, b, c = visible()
	print(a)
	print(b)
	print(c)
end

-- Start IA
function	run(x, y, elem)
	io.write("Script Loaded\n")
	my_range = elem
	my_x = x
	my_y = y
	print(x)
	print(y)
	print(elem)
	     repeat
		x, y, elem = checkbomb(my_x, my_y, my_range)
		print(x)
		print(y)
		print(elem)
		--avoidBomb(x, y)
	     until elem != 0
end