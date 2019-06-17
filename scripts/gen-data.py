#!python

import sys

edges = int(sys.argv[1])
input_file_name = sys.argv[2]
output_file_name = sys.argv[3]

with open(input_file_name, "r") as input_file, open(output_file_name, "w") as output_file:    
  edges_written = 0
  while edges_written < edges:
    line = input_file.readline()[:-1]
    if line[0] != "#" :      
      numbers = map(lambda txt: int(txt), line.split("\t"))      
      vertex_from = numbers[0]
      vertex_to = numbers[1]

      if vertex_from < edges and vertex_to < edges:
        edges_written+=1
        output_file.write("\t%s, %s,\n" % (vertex_from, vertex_to))
  output_file.write("\t0, 0\n")
  

