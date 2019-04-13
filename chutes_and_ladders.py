#!/usr/bin/python3
import myrandom

def move(starting_space, distance):
  #slides = top -> bot
  s_top  = [16, 47, 49, 56, 62, 64, 87, 93, 95, 98]
  s_bot  = [ 6, 26, 11, 53, 19, 60, 24, 73, 75, 78] 
  #ladder = bot -> top
  l_bot  = [ 1,  4, 9 , 21, 28, 36, 51, 71, 80 ] 
  l_top  = [38, 14, 31, 42, 84, 44, 67, 91, 100]
  new_pos = 0
  if starting_space + distance > 100:
    new_pos = starting_space
  else:
    new_pos = starting_space + distance
  
  for i in range(len(s_top)):
    if new_pos == s_top[i]:
      new_pos = s_bot[i]

  for j in range (len(l_top)):
    if new_pos == l_bot[j]:
      new_pos = l_top[j]
    
  return new_pos

def play_chutes_and_ladders(should_print):
  curr_pos = 0
  moves_performed = 0
  prev_pos = 0
  while curr_pos != 100:
    moves_performed += 1
    steps = myrandom.chutes_and_ladders_spinner()
    new_pos = move(curr_pos, steps)
    prev_pos = curr_pos
    curr_pos = new_pos
    if should_print == True:
      print("{:<0}\t{:<0}\t{:<0}".format(prev_pos, steps, new_pos))
  
  #print(moves_performed)  
  return moves_performed

if __name__ == "__main__":
  play_chutes_and_ladders(False)
 
