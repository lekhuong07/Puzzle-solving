#!/usr/bin/python3
import numpy as np
import math as ma
import random as rd
import myrandom


def main():
  if myrandom.rock_paper_scissors() == "rock":
    print ("rock")
  elif myrandom.rock_paper_scissors() == "paper":
    print ("paper")
  else:
    print ("scissors")

if __name__ == "__main__":
  main()

