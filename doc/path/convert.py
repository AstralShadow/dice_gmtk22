#!/usr/bin/python

file = open("map_path.svg")
svg = file.read()
file.close()

path_el = svg.find("<path");
init_point = svg.find("d=\"M ", path_el)
init_point += len("d=\"M ")
end_point = svg.find("\" />", init_point)

content = svg[init_point : end_point - init_point]

file = open("output.txt", "w")
file.write(content)
file.close()


