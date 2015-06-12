efunction element_at(map, y, x)
return string.byte(map[y + 1], x + 1);
end
-- Search ne nearest elem
function get_nearest_element(map, x, y, elem)
ytmp = -1
xtmp = -1
for yl = 0, #map - 1 do
for xl = 0, #map[yl + 1] - 1 do
if (element_at(map, yl, xl) == elem
and (math.abs(x - xl) + math.abs(y - yl) < math.abs(x - xtmp) + math.abs(y - ytmp) or (xtmp == -1 and ytmp == -1)) and (x ~= xl or y ~= yl or elem ~= PLAYER)) then
-- io.write("x: "..xl.." y: "..yl.."\n")
xtmp = xl
ytmp = yl
end
end
end
return xtmp, ytmp
end
-- check bonus
function check_bonus(map, x, y)
if (element_at(map, y, x) == RANGE_BONUS
or element_at(map, y, x) == SPEED_BONUS or element_at(map, y, x) == BAG_BONUS) then
return true
end
return false
end
