function	run_ia(x, y, elem)
	io.write("Script Loaded\n")
	my_range = elem
	my_x = x
	my_y = y
	print(x)
	print(y)
	print(elem)
	     repeat
		checkbomb(x, y, elem)
	     until elem == 1
end