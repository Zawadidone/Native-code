#!/usr/bin/python

from random import choice

def check_key(key):
    char_sum = 0
    for c in key:
        char_sum += ord(c)
    return char_sum

key = ""
while True:
    key += choice("abcdefghijklmnopqrstuvwxyz123456789")
    s = check_key(key)

    if s == 916:
        print("Found valid key:", key)
    elif  s > 916:
        key = ""
