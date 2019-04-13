#!/usr/bin/python3
import myrandom
import numpy as np
import math as ma
import random as rd

def rock_paper_scissors():
 rand = rd.randint(1,3)
 if rand == 1:
    return ("rock")
 elif rand == 2:
    return ("paper")
 elif rand == 3:
    return ("scissors")

def main():
	numsim=1000000
	r = 0;
	p = 0;
	s = 0;
	for i in range (numsim):
		if myrandom.rock_paper_scissors() == "rock":
	   		r += 1
		elif myrandom.rock_paper_scissors() == "paper":
	   		p += 1
		else:
	   		s += 1
	line = "{:>8}\t{:<0}\n{:>8}\t{:<0}\n{:<0}\t{:<0}".format("rock", r, "paper", p, "scissors", s)
	print(line)

if __name__ == "__main__":
  main()
